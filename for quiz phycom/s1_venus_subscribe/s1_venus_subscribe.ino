/*
  SUBSCRIBE ข้อ 1: รับค่าจาก  68070181/venus  แล้วแสดงสี Color LED
       36 - 50 -> แดง | 26 - 35 -> ฟ้า | 10 - 25 -> เขียว | นอกช่วง -> ดับ
  Board: Arduino UNO R4 WiFi   Libraries: WiFiS3, MQTT (MQTTClient.h)

  แก้ตอนสอบ:  topic -> TOPIC_VENUS | ช่วง -> TEMP_MAX, RED_MIN, BLUE_MIN, GREEN_MIN
              สี -> updateLed() (setLed(R,G,B) 1 = ติด) | ขา -> PIN_R/G/B
  LED เป็น Common Anode: ขา common ต่อ 5V, LOW = ติด, HIGH = ดับ
  ต่อ broker ไม่ติด: ลอง MQTT_PORT 1883 / เปิด USE_TLS
  ClientID ห้ามซ้ำกับ client_xxxx บนเว็บ
*/
#include <WiFiS3.h>
#include <MQTTClient.h>

const char WIFI_SSID[]     = "YOUR_HOTSPOT_SSID";      // <-- แก้
const char WIFI_PASSWORD[] = "YOUR_HOTSPOT_PASSWORD";  // <-- แก้

const char MQTT_HOST[]      = "phycom.it.kmitl.ac.th";
const int  MQTT_PORT        = 8884;                    // ถ้าต่อไม่ติดลอง 1883
const char MQTT_CLIENT_ID[] = "arduino_68070181_s1";
const char MQTT_USERNAME[]  = "";
const char MQTT_PASSWORD[]  = "";
// #define USE_TLS

#define TOPIC_VENUS "68070181/venus"

#define PIN_R 9                            // RGB LED (Common Anode) - แก้ให้ตรงที่ต่อจริง
#define PIN_G 10
#define PIN_B 11

const float TEMP_MAX  = 50;                // เกินนี้ = ดับ
const float RED_MIN   = 36;                // 36 - 50 -> แดง
const float BLUE_MIN  = 26;                // 26 - 35 -> ฟ้า
const float GREEN_MIN = 10;                // 10 - 25 -> เขียว (ต่ำกว่า 10 = ดับ)

#ifdef USE_TLS
WiFiSSLClient network;
#else
WiFiClient network;
#endif
MQTTClient mqtt = MQTTClient(256);

void setLed(bool r, bool g, bool b) {      // Common Anode: LOW = ติด
  digitalWrite(PIN_R, r ? LOW : HIGH);
  digitalWrite(PIN_G, g ? LOW : HIGH);
  digitalWrite(PIN_B, b ? LOW : HIGH);
}

void updateLed(float t) {
  if (t > TEMP_MAX)        setLed(0, 0, 0);   // เกินช่วง -> ดับ
  else if (t >= RED_MIN)   setLed(1, 0, 0);   // แดง
  else if (t >= BLUE_MIN)  setLed(0, 0, 1);   // ฟ้า
  else if (t >= GREEN_MIN) setLed(0, 1, 0);   // เขียว
  else                     setLed(0, 0, 0);   // ต่ำกว่าช่วง -> ดับ
}

void messageReceived(String &topic, String &payload) {
  Serial.println("RX " + topic + " = " + payload);
  if (topic == TOPIC_VENUS) {
    updateLed(payload.toFloat());
  }
}

void connectWiFi() {
  int status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED) {
    Serial.print("Connecting WiFi: ");
    Serial.println(WIFI_SSID);
    status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    delay(5000);
  }
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void connectMQTT() {
  mqtt.begin(MQTT_HOST, MQTT_PORT, network);
  mqtt.onMessage(messageReceived);

  Serial.print("Connecting MQTT");
  while (!mqtt.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
    Serial.print(".");
    delay(500);
  }
  Serial.println(" connected");

  if (mqtt.subscribe(TOPIC_VENUS)) {
    Serial.println("Subscribed: " TOPIC_VENUS);
  } else {
    Serial.println("Subscribe FAILED");
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  setLed(0, 0, 0);

  connectWiFi();
  connectMQTT();
}

void loop() {
  mqtt.loop();
  if (!mqtt.connected()) connectMQTT();
}
