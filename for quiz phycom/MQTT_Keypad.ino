/*
 * Sender. Read the 4x4 keypad and publish each key.
 * Partner runs MQTT_LCD and subscribes to the same topic.
 *
 * Keypad ribbon, left to right, keys facing you:
 *   R1 R2 R3 R4 C1 C2 C3 C4
 *   pin 9, 8, 7, 6, 5, 4, 3, 2
 *
 * Keys:
 *   1 2 3 A
 *   4 5 6 B
 *   7 8 9 C
 *   * 0 # D
 */

#include <WiFiS3.h>
#include <MQTTClient.h>

const char WIFI_SSID[] = "Nevergonnagiveyouup";
const char WIFI_PASSWORD[] = "99999999";

const char MQTT_BROKER_ADRRESS[] = "mqtt-dashboard.com";
const int MQTT_PORT = 1883;
const char MQTT_CLIENT_ID[] = "phuripat-keypad";
const char MQTT_USERNAME[] = "";
const char MQTT_PASSWORD[] = "";

const char PUBLISH_TOPIC[] = "phuripat/keypad";

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

char scanKey() {
  char found = 0;
  byte count = 0;

  for (byte r = 0; r < ROWS; r++) {
    digitalWrite(rowPins[r], LOW);
    delayMicroseconds(100);
    for (byte c = 0; c < COLS; c++) {
      if (digitalRead(colPins[c]) == LOW) {
        found = keys[r][c];
        count++;
      }
    }
    digitalWrite(rowPins[r], HIGH);
  }

  // 1 and 4 are the same column. More than one closed key is a short, not a press.
  if (count != 1) {
    return 0;
  }
  return found;
}

char readPress() {
  static char stable = 0;
  static char candidate = 0;
  static byte seen = 0;
  static unsigned long lastScan = 0;

  if (millis() - lastScan < 20) {
    return 0;
  }
  lastScan = millis();

  char now = scanKey();
  if (now == candidate) {
    if (seen < 4) {
      seen++;
    }
  } else {
    candidate = now;
    seen = 1;
  }

  if (seen < 4) {
    return 0;
  }
  if (candidate == 0) {
    stable = 0;
    return 0;
  }
  if (candidate == stable) {
    return 0;
  }

  stable = candidate;
  return candidate;
}

void setup() {
  Serial.begin(9600);
  delay(1500);

  for (byte r = 0; r < ROWS; r++) {
    pinMode(rowPins[r], OUTPUT);
    digitalWrite(rowPins[r], HIGH);
  }
  for (byte c = 0; c < COLS; c++) {
    pinMode(colPins[c], INPUT_PULLUP);
  }

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

  char key = readPress();
  if (!key) {
    return;
  }

  Serial.print("Key: ");
  Serial.println(key);

  if (!mqtt.connected()) {
    connectToMQTT();
  }

  char message[2] = {key, '\0'};
  mqtt.publish(PUBLISH_TOPIC, message);
  Serial.print("Published to ");
  Serial.println(PUBLISH_TOPIC);
}

void connectToMQTT() {
  mqtt.begin(MQTT_BROKER_ADRRESS, MQTT_PORT, network);

  Serial.print("Connecting to MQTT");
  while (!mqtt.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
    Serial.print(".");
    delay(100);
  }
  Serial.println();
  Serial.println("MQTT connected");
}
