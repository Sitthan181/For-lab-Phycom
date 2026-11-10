/*
  PHYCOM QUIZ - Arduino UNO R4 WiFi + MQTT   (student 68070181)
  Libraries: WiFiS3 (built in), MQTT by Joel Gaehwiler (MQTTClient.h)

  ===================== CHEAT SHEET (แก้ตอนสอบ) =====================
  โจทย์เปลี่ยน topic / รหัสนักศึกษา   -> แก้ STUDENT_ID หรือ TOPIC_xxx
  โจทย์เปลี่ยนช่วงอุณหภูมิ / สี        -> แก้ RED_MIN, BLUE_MIN, GREEN_MIN, TEMP_MAX
                                          และสีใน updateLed() (setLed(R,G,B) 1 = ติด)
  โจทย์เปลี่ยนระยะ 20 cm               -> แก้ DIST_LIMIT_CM
  อยากส่ง off อย่างเดียว (ไม่ส่งเลข)    -> SEND_NUMBER_WITH_OFF = 0
  โจทย์เปลี่ยนความถี่การส่ง            -> แก้ PUBLISH_INTERVAL (ms)
  ขาไม่ตรงกับที่ต่อจริง                -> แก้ PIN_xxx ด้านล่าง
  ต่อ broker ไม่ติด                    -> ลอง MQTT_PORT 1883 / เปิด USE_TLS
  ClientID ต้องไม่ซ้ำกับของเว็บ (client_xxxx) ไม่งั้นโดนเตะหลุด
  LED เป็น Common Anode: ขา common ต่อ 5V, LOW = ติด, HIGH = ดับ
  ===================================================================
*/

#include <WiFiS3.h>
#include <MQTTClient.h>

// ---------- WiFi (hotspot) ----------
const char WIFI_SSID[]     = "YOUR_HOTSPOT_SSID";      // <-- แก้
const char WIFI_PASSWORD[] = "YOUR_HOTSPOT_PASSWORD";  // <-- แก้

// ---------- MQTT (ตามที่เว็บสอบให้) ----------
const char MQTT_HOST[]      = "phycom.it.kmitl.ac.th";
const int  MQTT_PORT        = 8884;                    // ถ้าต่อไม่ติดลอง 1883
const char MQTT_CLIENT_ID[] = "arduino_68070181";      // ห้ามซ้ำกับ client_xxxx บนเว็บ
const char MQTT_USERNAME[]  = "";
const char MQTT_PASSWORD[]  = "";

// #define USE_TLS   // เอา // ออกถ้า broker ต้องใช้ TLS

// ---------- Topics ----------
#define STUDENT_ID  "68070181"
#define TOPIC_TEMP  STUDENT_ID "/temp"
#define TOPIC_LIGHT STUDENT_ID "/light"
#define TOPIC_DIST  STUDENT_ID "/food"
#define TOPIC_VENUS STUDENT_ID "/venus"

// ---------- Pins (ปรับให้ตรงกับที่ต่อจริง) ----------
#define PIN_TEMP A0     // TMP36
#define PIN_POT  A1     // ตัวต้านทานปรับค่าได้ (ใน lab เดิมใช้ A0)
#define PIN_TRIG 2      // HC-SR04 Trig (ตาม lab)
#define PIN_ECHO 4      // HC-SR04 Echo (ตาม lab)
#define PIN_R    9      // RGB LED (Common Anode)
#define PIN_G    10
#define PIN_B    11

// ---------- Settings ----------
const unsigned long PUBLISH_INTERVAL = 2000;  // ms
#define DIST_LIMIT_CM 20
#define SEND_NUMBER_WITH_OFF 1   // 1 = ส่งเลขทุกรอบ และส่ง "off" เพิ่มเมื่อ > 20 cm
                                 // 0 = ระยะ > 20 ส่ง "off" อย่างเดียว, ระยะ <= 20 ส่งเลข

// ช่วงอุณหภูมิ -> สี (Subscribe)
const float TEMP_MAX  = 50;   // เกินนี้ = ดับ
const float RED_MIN   = 36;   // 36 - 50  -> แดง
const float BLUE_MIN  = 26;   // 26 - 35  -> ฟ้า(น้ำเงิน)
const float GREEN_MIN = 10;   // 10 - 25  -> เขียว   (ต่ำกว่า 10 = ดับ)

#ifdef USE_TLS
WiFiSSLClient network;
#else
WiFiClient network;
#endif
MQTTClient mqtt = MQTTClient(256);

unsigned long lastPublishTime = 0;

// ---------- LED (Common Anode: LOW = ติด) ----------
void setLed(bool r, bool g, bool b) {
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

// ---------- Sensors ----------
float readTempC() {
  int raw = analogRead(PIN_TEMP);
  float voltage = raw * 5.0 / 1024.0;
  return (voltage - 0.5) * 100.0;             // TMP36
}

int readPot() {
  return analogRead(PIN_POT);                 // 0-1023
}

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

// ---------- WiFi / MQTT ----------
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

void messageReceived(String &topic, String &payload) {
  Serial.println("RX " + topic + " = " + payload);
  if (topic == TOPIC_VENUS) {
    updateLed(payload.toFloat());
  }
}

// ---------- Publish ----------
void publishAll() {
  // 1) อุณหภูมิ
  float t = readTempC();
  mqtt.publish(TOPIC_TEMP, String(t, 1));

  // 2) ตัวต้านทานปรับค่าได้ (0-1023)
  int pot = readPot();
  mqtt.publish(TOPIC_LIGHT, String(pot));

  // 3) Ultrasonic (cm)
  float d = readDistanceCm();
#if SEND_NUMBER_WITH_OFF
  mqtt.publish(TOPIC_DIST, String((int)d));
  if (d > DIST_LIMIT_CM) mqtt.publish(TOPIC_DIST, "off");
#else
  if (d > DIST_LIMIT_CM) mqtt.publish(TOPIC_DIST, "off");
  else                   mqtt.publish(TOPIC_DIST, String((int)d));
#endif

  Serial.print("TX temp=");  Serial.print(t, 1);
  Serial.print(" pot=");     Serial.print(pot);
  Serial.print(" dist=");    Serial.println(d);
}

// ---------- Arduino ----------
void setup() {
  Serial.begin(9600);

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  setLed(0, 0, 0);

  connectWiFi();
  connectMQTT();
}

void loop() {
  mqtt.loop();

  if (!mqtt.connected()) {
    connectMQTT();
  }

  if (millis() - lastPublishTime > PUBLISH_INTERVAL) {
    publishAll();
    lastPublishTime = millis();
  }
}
