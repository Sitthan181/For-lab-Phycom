/*
  PUBLISH ข้อ 2: อ่านตัวต้านทานปรับค่าได้ (0-1023) -> publish ไป  68070181/light
  Board: Arduino UNO R4 WiFi   Libraries: WiFiS3, MQTT (MQTTClient.h)

  แก้ตอนสอบ:  topic -> TOPIC_LIGHT | ขา -> PIN_POT | ความถี่ -> PUBLISH_INTERVAL
  ต่อ broker ไม่ติด: ลอง MQTT_PORT 1883 / เปิด USE_TLS
  ClientID ห้ามซ้ำกับ client_xxxx บนเว็บ
*/
#include <WiFiS3.h>
#include <MQTTClient.h>

const char WIFI_SSID[]     = "YOUR_HOTSPOT_SSID";      // <-- แก้
const char WIFI_PASSWORD[] = "YOUR_HOTSPOT_PASSWORD";  // <-- แก้

const char MQTT_HOST[]      = "phycom.it.kmitl.ac.th";
const int  MQTT_PORT        = 8884;                    // ถ้าต่อไม่ติดลอง 1883
const char MQTT_CLIENT_ID[] = "arduino_68070181_q2";
const char MQTT_USERNAME[]  = "";
const char MQTT_PASSWORD[]  = "";
// #define USE_TLS

#define TOPIC_LIGHT "68070181/light"
#define PIN_POT     A0                     // pot (ตาม lab)
const unsigned long PUBLISH_INTERVAL = 2000;

#ifdef USE_TLS
WiFiSSLClient network;
#else
WiFiClient network;
#endif
MQTTClient mqtt = MQTTClient(256);
unsigned long lastPublishTime = 0;

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
  Serial.print("Connecting MQTT");
  while (!mqtt.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
    Serial.print(".");
    delay(500);
  }
  Serial.println(" connected");
}

void setup() {
  Serial.begin(9600);
  connectWiFi();
  connectMQTT();
}

void loop() {
  mqtt.loop();
  if (!mqtt.connected()) connectMQTT();

  if (millis() - lastPublishTime > PUBLISH_INTERVAL) {
    int pot = analogRead(PIN_POT);         // 0-1023 ส่งค่าดิบ
    mqtt.publish(TOPIC_LIGHT, String(pot));
    Serial.print("TX light=");
    Serial.println(pot);
    lastPublishTime = millis();
  }
}
