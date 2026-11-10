/*
 * Receiver. Subscribe and show the keypad value on a 16x2 I2C LCD.
 * Partner runs MQTT_Keypad and publishes to the same topic.
 *
 * LCD:
 *   VCC -> 5V
 *   GND -> GND
 *   SDA -> A4
 *   SCL -> A5
 * Address is usually 0x27. If the screen stays blank, change LCD_ADDR to 0x3F.
 */

#include <WiFiS3.h>
#include <MQTTClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const char WIFI_SSID[] = "Nevergonnagiveyouup";
const char WIFI_PASSWORD[] = "99999999";

const char MQTT_BROKER_ADRRESS[] = "mqtt-dashboard.com";
const int MQTT_PORT = 1883;
const char MQTT_CLIENT_ID[] = "phuripat-lcd";
const char MQTT_USERNAME[] = "";
const char MQTT_PASSWORD[] = "";

const char SUBSCRIBE_TOPIC[] = "phuripat/keypad";
const byte LCD_ADDR = 0x27;

LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);
String line = "";

void setup() {
  Serial.begin(9600);
  delay(1500);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Waiting...");

  int status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED) {
    Serial.print("Connecting to ");
    Serial.println(WIFI_SSID);
    status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    delay(10000);
  }
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  connectToMQTT();
}

void loop() {
  mqtt.loop();
}

void connectToMQTT() {
  mqtt.begin(MQTT_BROKER_ADRRESS, MQTT_PORT, network);
  mqtt.onMessage(messageReceived);

  Serial.print("Connecting to MQTT");
  while (!mqtt.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
    Serial.print(".");
    delay(100);
  }
  Serial.println();

  if (mqtt.subscribe(SUBSCRIBE_TOPIC)) {
    Serial.print("Subscribed to ");
  } else {
    Serial.print("Failed to subscribe to ");
  }
  Serial.println(SUBSCRIBE_TOPIC);
}

void messageReceived(String &topic, String &payload) {
  static unsigned long lastMs = 0;
  if (millis() - lastMs < 200) {
    return;
  }
  lastMs = millis();

  Serial.print("Received: ");
  Serial.println(payload);

  if (payload == "*") {
    line = "";
  } else if (line.length() >= 16) {
    line = payload;
  } else {
    line += payload;
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Keypad:");
  lcd.setCursor(0, 1);
  lcd.print(line);
}
