/*
  PUBLISH ข้อ 3: อ่านระยะ Ultrasonic (cm) -> publish ไป  68070181/food
                 ถ้า > 20 cm ให้ publish คำว่า off ไปที่ topic เดียวกัน
  Board: Arduino UNO R4 WiFi   Libraries: WiFiS3, MQTT (MQTTClient.h)

  แก้ตอนสอบ:  topic -> TOPIC_DIST | ระยะ -> DIST_LIMIT_CM | ขา -> PIN_TRIG, PIN_ECHO
  SEND_NUMBER_WITH_OFF = 1 : ส่งเลขทุกรอบ + ส่ง "off" เพิ่มเมื่อ > 20
  SEND_NUMBER_WITH_OFF = 0 : > 20 ส่ง "off" อย่างเดียว, <= 20 ส่งเลข
  ต่อ broker ไม่ติด: ลอง MQTT_PORT 1883 / เปิด USE_TLS
  ClientID ห้ามซ้ำกับ client_xxxx บนเว็บ
*/
#include <WiFiS3.h>
#include <MQTTClient.h>

const char WIFI_SSID[]     = "YOUR_HOTSPOT_SSID";      // <-- แก้
const char WIFI_PASSWORD[] = "YOUR_HOTSPOT_PASSWORD";  // <-- แก้

const char MQTT_HOST[]      = "phycom.it.kmitl.ac.th";
const int  MQTT_PORT        = 8884;                    // ถ้าต่อไม่ติดลอง 1883
const char MQTT_CLIENT_ID[] = "arduino_68070181_q3";
const char MQTT_USERNAME[]  = "";
const char MQTT_PASSWORD[]  = "";
// #define USE_TLS

#define TOPIC_DIST "68070181/food"
#define PIN_TRIG 2                         // HC-SR04 Trig (ตาม lab)
#define PIN_ECHO 4                         // HC-SR04 Echo (ตาม lab)
#define DIST_LIMIT_CM 20
#define SEND_NUMBER_WITH_OFF 1
const unsigned long PUBLISH_INTERVAL = 2000;

#ifdef USE_TLS
WiFiSSLClient network;
#else
WiFiClient network;
#endif
MQTTClient mqtt = MQTTClient(256);
unsigned long lastPublishTime = 0;

float readDistanceCm() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  long pulse = pulseIn(PIN_ECHO, HIGH, 30000);  // timeout 30 ms
  if (pulse == 0) return 999;                   // ไม่มี echo = ไกลมาก
  return pulse * 0.034 / 2;
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
  Serial.print("Connecting MQTT");
  while (!mqtt.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
    Serial.print(".");
    delay(500);
  }
  Serial.println(" connected");
}

void setup() {
  Serial.begin(9600);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  connectWiFi();
  connectMQTT();
}

void loop() {
  mqtt.loop();
  if (!mqtt.connected()) connectMQTT();

  if (millis() - lastPublishTime > PUBLISH_INTERVAL) {
    float d = readDistanceCm();
#if SEND_NUMBER_WITH_OFF
    mqtt.publish(TOPIC_DIST, String((int)d));
    if (d > DIST_LIMIT_CM) mqtt.publish(TOPIC_DIST, "off");
#else
    if (d > DIST_LIMIT_CM) mqtt.publish(TOPIC_DIST, "off");
    else                   mqtt.publish(TOPIC_DIST, String((int)d));
#endif
    Serial.print("TX dist=");
    Serial.println(d);
    lastPublishTime = millis();
  }
}
