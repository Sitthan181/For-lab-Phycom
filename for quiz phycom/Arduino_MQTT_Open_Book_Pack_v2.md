# Arduino Physical Computing Final — Open Book Pack
อ้างอิงจาก Mock Exam + Lab Sensor ของผู้ใช้ + MQTT_Keypad / MQTT_LCD / mqtt(2).ino

## อ่านก่อนสอบ: ใช้ไฟล์นี้อย่างไร
- โค้ด MQTT ตัวอย่างของเพื่อนใช้ `#include <WiFiS3.h>` และ `#include <MQTTClient.h>` โดยสร้าง `MQTTClient mqtt = MQTTClient(256);`
- มี `connectToMQTT()`, `mqtt.publish(...)`, `mqtt.subscribe(...)`, `mqtt.onMessage(messageReceived)` และ `mqtt.loop()` อยู่แล้ว
- ไฟล์ตัวอย่างเดิมเชื่อม `mqtt-dashboard.com:1883` ซึ่งเป็น broker สาธารณะใน Lab ไม่ใช่หลักฐานว่าบอร์ดต้องใช้ค่านั้นตอนสอบ
- Mock webpage แสดง Host `phycom.it.kmitl.ac.th`, Port `8884`; อย่าสรุปเองว่า Arduino ต้องใช้ TCP port 8884 เพราะเว็บอาจใช้ WebSocket ส่วน Arduino อาจต้องใช้ TCP port คนละค่า ตรวจคำสั่ง/เอกสารจากอาจารย์หรือหน้าเว็บสอบก่อน
- ในโค้ดเพื่อนมี Wi-Fi credentials จริงอยู่ ห้ามเอาไปใส่เอกสารที่แชร์ต่อ หากเป็นรหัสที่ยังใช้งานจริง ควรเปลี่ยนรหัส Wi-Fi

---

## 1. Mock Exam — Topic และ Logic

แทน `YOUR_STUDENT_ID` ด้วยรหัสนักศึกษาตามรูปแบบที่เว็บกำหนด

| ข้อ | Topic | ข้อมูล/เงื่อนไข |
|---|---|---|
| Publish Temperature | `YOUR_STUDENT_ID/temp` | ส่งอุณหภูมิ `tempC` |
| Publish Potentiometer | `YOUR_STUDENT_ID/light` | ส่งค่า Analog `potValue` ช่วง 0–1023 |
| Publish Ultrasonic | `YOUR_STUDENT_ID/food` | ถ้าระยะ `length > 20` cm ส่งข้อความ `off` |
| Subscribe Color LED | `YOUR_STUDENT_ID/venus` | 36–50 แดง, 26–35 ฟ้า, 10–25 เขียว |

ช่วงค่าที่อยู่นอก 10–50 ไม่ได้ระบุพฤติกรรมไว้ในภาพ Mock ให้ทำตามโจทย์จริงหากมีคำสั่งเพิ่ม

---

## 2. โครง MQTT จาก Lab ของเพื่อน

ส่วนสำคัญจาก `mqtt(2).ino` / `MQTT_Keypad.ino` / `MQTT_LCD.ino`:

```cpp
#include <WiFiS3.h>
#include <MQTTClient.h>

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

// ตอนเชื่อมต่อ MQTT:
mqtt.begin(MQTT_BROKER_ADDRESS, MQTT_PORT, network);
mqtt.onMessage(messageReceived); // ตั้ง handler ฝั่งรับ
mqtt.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD);
mqtt.subscribe(SUBSCRIBE_TOPIC);

// ส่งข้อมูล:
mqtt.publish(PUBLISH_TOPIC, payload);

// ใน loop:
mqtt.loop();

// callback:
void messageReceived(String &topic, String &payload) {
  // ใช้ topic และ payload ที่ได้รับ
}
```

ชื่อตัวแปร `MQTT_BROKER_ADDRESS`, `MQTT_PORT`, credentials และ Topic ต้องประกาศให้ตรงกับตัวแปรที่ใช้ในโค้ดจริง

### ความหมายที่ต้องจำ
- `mqtt.begin(...)` = ตั้ง broker / port / network ให้ MQTT client
- `mqtt.connect(...)` = เชื่อมต่อ broker
- `mqtt.publish(topic, payload)` = ส่งข้อมูล
- `mqtt.subscribe(topic)` = ขอรับข้อความจาก topic
- `mqtt.onMessage(messageReceived)` = กำหนดฟังก์ชัน callback เมื่อมีข้อความเข้า
- `mqtt.loop()` = ให้ไลบรารีประมวลผล MQTT และเรียก callback
- `messageReceived(String &topic, String &payload)` = ตัวรับชื่อ Topic และเนื้อหาข้อความ

**สำคัญ:** โค้ดนี้เป็น API ของไลบรารี `MQTTClient.h` ที่อยู่ในไฟล์เพื่อน ไม่ใช่ API ของ `ArduinoMqttClient` ที่ใช้ชื่อฟังก์ชันต่างกัน

---

## 3. Lab Temperature TMP36

โค้ดเดิมจาก `Termo with jor.txt`:

```cpp
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);
const int sensorPin = A0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Temperature:");
}

void loop() {
  int raw = analogRead(sensorPin);
  float voltage = raw * 5.0 / 1024.0;
  float tempC = (voltage - 0.5) * 100.0;

  lcd.setCursor(0, 1);
  lcd.print(tempC, 2);
  lcd.print(" C   ");
  delay(500);
}
```

จำตัวแปร:
- `raw` = Analog reading
- `voltage` = คำนวณแรงดัน
- `tempC` = อุณหภูมิ Celsius ตามสูตร TMP36 ของ Lab

สำหรับข้อ Publish ให้นำสูตรอ่านค่าไปใช้ แล้วส่ง `tempC` ไปที่ `YOUR_STUDENT_ID/temp`.

---

## 4. Lab Potentiometer

โค้ดเดิมจาก `Potentiometer Analog Reading.txt`:

```cpp
const int ledPin = 3;
const int potPin = A0;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);
  int brightness = potValue / 4;
  analogWrite(ledPin, brightness);
}
```

- ส่ง `potValue` เพื่อส่งค่าดิบ 0–1023 ตามโจทย์
- `brightness` คือค่าที่หาร 4 แล้ว ใช้ปรับ LED ช่วงประมาณ 0–255 ไม่ใช่ค่าที่ Mock ขอ

---

## 5. Lab Ultrasonic HC-SR04

โค้ดเดิมจาก `Ultrasmooth with jor.txt`:

```cpp
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT); // Trigger
  pinMode(4, INPUT);  // Echo
  lcd.init();
  lcd.backlight();
}

void loop() {
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);

  double pulseWidth = pulseIn(4, HIGH);
  double length = 0.0340 * pulseWidth / 2;

  lcd.setCursor(0, 0);
  lcd.print("Length: ");
  lcd.print((int) length);
  lcd.print(" cm");
  delay(400);
  lcd.clear();
}
```

สำหรับข้อสอบ:
```cpp
if (length > 20) {
  mqtt.publish(FOOD_TOPIC, "off");
}
```
เงื่อนไขนี้ส่ง `off` เฉพาะเมื่อมากกว่า 20 cm ตามภาพ Mock ไม่ใช่เมื่อเท่ากับ 20

---

## 6. Template A — Publish อุณหภูมิ (ต่อเข้ากับ MQTT skeleton)

**ใช้เมื่อยืนยันค่าการเชื่อมต่อของ Arduino แล้วเท่านั้น** แก้ค่าทุกช่อง `FILL_IN_*` ให้ตรงกับข้อกำหนดสอบ

```cpp
#include <WiFiS3.h>
#include <MQTTClient.h>

const char WIFI_SSID[] = "FILL_IN_WIFI_SSID";
const char WIFI_PASSWORD[] = "FILL_IN_WIFI_PASSWORD";

// ใส่ค่าที่อาจารย์/หน้าเว็บกำหนดสำหรับ Arduino TCP MQTT
const char MQTT_BROKER_ADDRESS[] = "FILL_IN_ARDUINO_MQTT_HOST";
const int MQTT_PORT = 1883; // ตัวอย่าง Lab เดิมเท่านั้น: ตรวจค่าจริงก่อนสอบ
const char MQTT_CLIENT_ID[] = "FILL_IN_UNIQUE_CLIENT_ID";
const char MQTT_USERNAME[] = "";
const char MQTT_PASSWORD[] = "";

const char TEMP_TOPIC[] = "YOUR_STUDENT_ID/temp";

const int SENSOR_PIN = A0;
WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

void connectToMQTT() {
  mqtt.begin(MQTT_BROKER_ADDRESS, MQTT_PORT, network);
  while (!mqtt.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD)) {
    delay(500);
  }
}

void setup() {
  Serial.begin(9600);

  while (WiFi.begin(WIFI_SSID, WIFI_PASSWORD) != WL_CONNECTED) {
    delay(5000);
  }

  connectToMQTT();
}

void loop() {
  mqtt.loop();

  int raw = analogRead(SENSOR_PIN);
  float voltage = raw * 5.0 / 1024.0;
  float tempC = (voltage - 0.5) * 100.0;

  char payload[20];
  dtostrf(tempC, 1, 2, payload);
  mqtt.publish(TEMP_TOPIC, payload);

  Serial.print("Published temp: ");
  Serial.println(payload);
  delay(2000);
}
```

หมายเหตุ: การเชื่อม Wi-Fi แบบนี้เป็นตัวอย่างพื้นฐานตามรูปแบบ Lab ไม่ได้เพิ่มระบบ reconnect ที่ครอบคลุมทุกกรณี

---

## 7. Template B — Publish Potentiometer

โค้ดด้านล่างสมมติว่าใช้ Wi-Fi/MQTT setup แบบเดียวกับ Template A แล้ว ให้คัดส่วนประกาศ/เชื่อมต่อจาก A มาใช้ และแทน `loop()` ด้วย:

```cpp
const char LIGHT_TOPIC[] = "YOUR_STUDENT_ID/light";
const int POT_PIN = A0;

void loop() {
  mqtt.loop();

  int potValue = analogRead(POT_PIN);

  char payload[12];
  itoa(potValue, payload, 10);
  mqtt.publish(LIGHT_TOPIC, payload);

  Serial.print("Published light: ");
  Serial.println(payload);
  delay(500);
}
```

หากนำส่วนนี้ไปประกอบกับ Template A ให้ย้าย `LIGHT_TOPIC` และ `POT_PIN` ไปประกาศไว้ระดับ global ด้านบน และคง `setup()`/`connectToMQTT()` ไว้เพียงชุดเดียว

---

## 8. Template C — Publish "off" จาก Ultrasonic

ใช้ `setup()`/การเชื่อมต่อจาก Template A โดยประกาศ Pin และ Topic เพิ่มที่ global:

```cpp
const int TRIG_PIN = 2;
const int ECHO_PIN = 4;
const char FOOD_TOPIC[] = "YOUR_STUDENT_ID/food";
```

เพิ่มใน `setup()`:
```cpp
pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
```

ใช้ `loop()` นี้แทน loop ของ Template A:

```cpp
void loop() {
  mqtt.loop();

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long pulseWidth = pulseIn(ECHO_PIN, HIGH);
  float length = 0.0340 * pulseWidth / 2.0;

  Serial.print("Distance cm: ");
  Serial.println(length);

  if (length > 20) {
    mqtt.publish(FOOD_TOPIC, "off");
    Serial.println("Published: off");
  }

  delay(400);
}
```

โค้ดนี้จะ Publish `off` ซ้ำทุกครั้งที่เข้าเงื่อนไขในแต่ละรอบ ถ้าโจทย์กำหนดรูปแบบการส่งเพิ่มเติมให้ทำตามโจทย์จริง

---

## 9. Template D — Subscribe แล้วเลือกสี LED

ใช้ `setup()`/Wi-Fi/MQTT connect จาก Template A แล้วเพิ่ม subscribe callback:

```cpp
const char VENUS_TOPIC[] = "YOUR_STUDENT_ID/venus";

// เปลี่ยน pin ให้ตรงกับ Color LED ในวงจรสอบ
const int RED_PIN = FILL_IN_RED_PIN;
const int BLUE_PIN = FILL_IN_BLUE_PIN;
const int GREEN_PIN = FILL_IN_GREEN_PIN;

void allOff() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
}

void messageReceived(String &topic, String &payload) {
  payload.trim();
  int value = payload.toInt();

  Serial.print("Topic: ");
  Serial.println(topic);
  Serial.print("Payload: ");
  Serial.println(payload);

  if (topic != VENUS_TOPIC) return;

  allOff();

  if (value >= 36 && value <= 50) {
    digitalWrite(RED_PIN, HIGH);
  } else if (value >= 26 && value <= 35) {
    digitalWrite(BLUE_PIN, HIGH);
  } else if (value >= 10 && value <= 25) {
    digitalWrite(GREEN_PIN, HIGH);
  }
}
```

เพิ่มใน `connectToMQTT()` หลัง connect สำเร็จ:
```cpp
mqtt.onMessage(messageReceived);
mqtt.subscribe(VENUS_TOPIC);
```

และให้ `loop()` มี:
```cpp
void loop() {
  mqtt.loop();
}
```

ใน `setup()` ต้องเรียก `pinMode(..., OUTPUT)` ให้ขา LED ทั้งสามขา และควรเรียก `allOff()` หลังตั้งค่า pinMode แล้ว

**ข้อสำคัญเรื่อง LED:** ตัวอย่างนี้สมมติว่า LED เป็น Active HIGH (HIGH = เปิด) และ LOW = ปิด ถ้าเป็น Common Anode หรือวงจรจริงใช้ logic กลับด้าน ต้องกลับค่าใน `allOff()` และคำสั่งเปิดสีให้ตรงกับวงจรสอบ นอกจากนี้สีฟ้าของ RGB LED อาจใช้ขา Blue channel ไม่ใช่ Green channel

**การแปลง Payload:** `toInt()` ใช้ได้เมื่อข้อความเป็นเลข เช่น `"36"`. ถ้าข้อความไม่ใช่ตัวเลข `toInt()` อาจได้ 0; ถ้าโจทย์จริงมี payload รูปแบบอื่น ให้ตรวจตามนั้น

---

## 10. Pin ที่ปรากฏใน Lab

| Lab | Pin |
|---|---|
| TMP36 | A0 |
| Potentiometer | A0, LED D3 |
| HC-SR04 | Trigger D2, Echo D4 |
| LCD I2C ในไฟล์หนึ่ง | SDA A4, SCL A5 (ตาม comment ใน MQTT_LCD) |

โค้ด LCD สองไฟล์ใช้คนละไลบรารีและ address ต่างกัน: `Adafruit_LiquidCrystal lcd(0)` กับ `LiquidCrystal_I2C lcd(0x20, 16, 2)` หรือไฟล์เพื่อนที่ใช้ `0x27`. ต้องยึดอุปกรณ์จริงและ Lab ที่ใช้

---

## 11. Checklist ก่อนส่ง

- [ ] ใส่ Student ID ลงใน Topic ทุกตัว
- [ ] ยืนยัน host/port ที่ Arduino ต้องใช้ ไม่เอา WebSocket port มาใช้เป็น TCP MQTT โดยอัตโนมัติ
- [ ] ยืนยันว่าใช้ broker/credentials ตามข้อสอบ
- [ ] Publish temperature เป็น `tempC`
- [ ] Publish potentiometer เป็น `potValue` 0–1023
- [ ] Ultrasonic ส่งข้อความ `off` เมื่อ `length > 20`
- [ ] Subscribe `YOUR_STUDENT_ID/venus`
- [ ] ตรวจ Payload เป็นตัวเลขก่อนเลือกสี
- [ ] ตรวจ pin mapping และ active-high/active-low ของ LED
- [ ] เปิด Serial Monitor ดูสถานะ connect / topic / payload หากอนุญาต

## 12. Debug อย่างรวดเร็ว

**MQTT connect ไม่ผ่าน**
- ตรวจ broker host และ TCP port ที่กำหนดสำหรับ Arduino
- ตรวจ Client ID ไม่ซ้ำกับอุปกรณ์อื่น
- ตรวจ username/password ถ้า broker ต้องใช้
- ตรวจว่าบอร์ดเชื่อม Wi-Fi แล้ว

**Publish แล้วเว็บไม่เห็น**
- Topic ต้องตรงกันทุกตัวอักษรและใช้ Student ID ของตัวเอง
- ตรวจ payload ที่พิมพ์ใน Serial
- ตรวจ broker ที่ Arduino เชื่อมกับ broker ที่หน้าเว็บกำลังดูว่าเป็นระบบเดียวกัน

**Subscribe แล้วไม่ทำงาน**
- เรียก `mqtt.onMessage(messageReceived)` ก่อนรับข้อความ
- Subscribe topic ที่ถูกต้อง
- ต้องมี `mqtt.loop()` ทำงานอย่างต่อเนื่อง
- ตรวจช่วงตัวเลขและขา LED

---

## สิ่งที่ยังต้องยืนยันก่อนสอบ
1. Arduino ใช้ broker host/port อะไรจริงกับเว็บ `phycom.it.kmitl.ac.th` (port 8884 ในหน้าเว็บอาจเป็น WebSocket)
2. ใช้ username/password หรือไม่
3. Pin mapping ของ Color LED และเป็น Active HIGH หรือ Active LOW
4. ชื่อ Student ID ใน Topic ต้องใส่ตัวเลขแบบใด

ถ้าได้ 4 อย่างนี้จากหน้าเว็บ/TA แล้ว ให้แก้ placeholder ใน template ก่อนสอบ และลองคอมไพล์ด้วยบอร์ด/ไลบรารีจริง
