# Physical Computing Final — Arduino + MQTT Open-book Cheat Sheet

สรุปจาก Mock Exam และ Lab ที่ส่งมา ใช้เปิดดูระหว่างสอบได้

> **ข้อจำกัดสำคัญ:** Lab ที่ได้รับมีโค้ดอ่าน Sensor/แสดง LCD แต่ไม่มีโค้ด MQTT ดังนั้นส่วน MQTT ด้านล่างเป็นโครงสร้างและจุดที่ต้องเติม ไม่ใช่โค้ดสมบูรณ์ที่รับประกันว่าอัปโหลดได้ทันที ต้องใช้ชื่อไลบรารีและวิธี connect/publish/subscribe ตามที่อาจารย์สอน

## 1. สรุป Mock Exam

| ข้อ | งาน | Topic | สิ่งที่ต้องทำ |
|---|---|---|---|
| Publish 1 | Temperature Sensor (TMP36 ตาม Lab) | `YOUR_STUDENT_ID/temp` | ส่งค่าอุณหภูมิ |
| Publish 2 | Potentiometer | `YOUR_STUDENT_ID/light` | ส่งค่า Analog 0–1023 |
| Publish 3 | Ultrasonic | `YOUR_STUDENT_ID/food` | ถ้าระยะ `> 20 cm` ให้ส่งข้อความ `off` |
| Subscribe | Color LED | `YOUR_STUDENT_ID/venus` | รับตัวเลขแล้วเลือกสี |

แทน `YOUR_STUDENT_ID` ด้วยรหัสนักศึกษาตามรูปแบบที่เว็บสอบกำหนด

Subscribe ตาม Mock:
- 36–50 → Red LED
- 26–35 → Blue LED
- 10–25 → Green LED
- นอกช่วง: ภาพ Mock ไม่ได้ระบุพฤติกรรมไว้ ให้ทำตามโจทย์จริงถ้ามีรายละเอียดเพิ่ม

## 2. Temperature Sensor (TMP36) — จาก Lab

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
- `raw` = ค่า Analog ดิบ
- `voltage` = แรงดันที่คำนวณได้
- `tempC` = อุณหภูมิ Celsius

ถ้าโจทย์ให้ Publish อุณหภูมิ ให้ส่ง `tempC` ไม่ใช่ `raw`.

```cpp
int raw = analogRead(A0);
float voltage = raw * 5.0 / 1024.0;
float tempC = (voltage - 0.5) * 100.0;

// TODO: Publish tempC ไปที่ "YOUR_STUDENT_ID/temp"
```

## 3. Potentiometer — จาก Lab

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

- `potValue` โดยทั่วไปมีค่า 0–1023 บน Arduino Uno
- `brightness = potValue / 4` ใช้แปลงเป็นค่าความสว่างประมาณ 0–255
- Mock ต้องการค่า 0–1023 ดังนั้นให้ Publish `potValue` ไม่ใช่ `brightness`.

```cpp
int potValue = analogRead(A0);
// TODO: Publish potValue ไปที่ "YOUR_STUDENT_ID/light"
```

## 4. Ultrasonic HC-SR04 — จาก Lab

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

- Trigger = D2, Echo = D4
- `pulseWidth` = ระยะเวลาที่ Echo เป็น HIGH
- `length` = ระยะทาง cm

Logic ตาม Mock:

```cpp
digitalWrite(2, HIGH);
delayMicroseconds(10);
digitalWrite(2, LOW);

unsigned long pulseWidth = pulseIn(4, HIGH);
float length = 0.0340 * pulseWidth / 2;

if (length > 20) {
  // TODO: Publish ข้อความ "off" ไปที่ "YOUR_STUDENT_ID/food"
}
```

โจทย์ระบุ `> 20` ไม่ใช่ `>= 20` เว้นแต่โจทย์จริงเปลี่ยน

## 5. MQTT — หลักการที่ต้องต่อกับโค้ดจริงของวิชา

### Publish
1. เชื่อมต่อเครือข่ายและ MQTT Broker
2. สร้าง Topic ตาม Student ID
3. อ่านค่าจาก Sensor
4. Publish ค่าหรือข้อความไปยัง Topic

โครงสร้างแนวคิด ไม่ใช่โค้ดที่คอมไพล์ได้กับทุกไลบรารี:

```cpp
// TODO: ใช้คำสั่ง connect ของไลบรารีที่เรียน
// TODO: Publish ค่าไปที่ Topic ที่กำหนด
```

ถ้าไลบรารีที่เรียนใช้ `beginMessage / print / endMessage` รูปแบบส่งข้อมูลจะประมาณนี้:

```cpp
mqtt.beginMessage(TOPIC);
mqtt.print(value);
mqtt.endMessage();
```

ตรวจสอบก่อนว่าไลบรารีใน Lab ใช้ API นี้จริงหรือไม่

### Subscribe
1. เชื่อมต่อ MQTT
2. Subscribe `YOUR_STUDENT_ID/venus`
3. เมื่อมีข้อความเข้ามา อ่าน Payload
4. แปลง Payload เป็นตัวเลข
5. ใช้ `if / else if` เลือกสี LED

```cpp
// TODO: รับ payload จาก MQTT แล้วแปลงเป็นตัวเลข value

if (value >= 36 && value <= 50) {
  // TODO: เปิด Red LED
} else if (value >= 26 && value <= 35) {
  // TODO: เปิด Blue LED
} else if (value >= 10 && value <= 25) {
  // TODO: เปิด Green LED
}
```

ถ้า Payload เป็นข้อความ `"36"` ต้องแปลงเป็นตัวเลขก่อนเปรียบเทียบ เช่น `toInt()` เมื่อใช้ชนิด `String`.

## 6. Pin และข้อควรระวังจาก Lab

| อุปกรณ์ | ขา |
|---|---|
| TMP36 | A0 |
| Potentiometer | A0, LED D3 |
| HC-SR04 | Trigger D2, Echo D4 |
| LCD | ตามไลบรารีและวงจรใน Lab |

โค้ด LCD สองไฟล์ใช้คนละไลบรารี: `Adafruit_LiquidCrystal lcd(0)` กับ `LiquidCrystal_I2C lcd(0x20, 16, 2)` อย่าสลับใช้โดยไม่ตรวจอุปกรณ์จริง

ถ้าโจทย์มีหลาย Sensor อย่าลืมตรวจว่าต่อคนละขาตามวงจรจริง ไม่ใช่ใช้ A0 ร่วมกันโดยไม่ตั้งใจ

## 7. Checklist ตอนสอบ

- [ ] กรอก Student ID ตามรูปแบบที่เว็บกำหนด
- [ ] Mock แสดง Host `phycom.it.kmitl.ac.th`, Port `8884` — ตรวจตามหน้าเว็บสอบจริง
- [ ] ใช้ Client ID ตามที่เว็บสร้างให้/กำหนด
- [ ] ตรวจ Topic: `/temp`, `/light`, `/food`, `/venus`
- [ ] Temperature ส่ง `tempC`
- [ ] Potentiometer ส่ง `potValue` ช่วง 0–1023
- [ ] Ultrasonic ส่งข้อความ `off` เมื่อ `length > 20`
- [ ] Subscribe Topic ถูกต้องและแปลง Payload เป็นตัวเลข
- [ ] ตรวจ pin mapping และ logic HIGH/LOW ของ Color LED
- [ ] ทดสอบทีละส่วน และดู error ใน Serial Monitor ถ้าอนุญาต

## 8. Troubleshooting

**เชื่อมต่อไม่ได้:** ตรวจ Host/Port, Student ID, Client ID และวิธีเชื่อมต่อ/ไลบรารีที่อาจารย์กำหนด อย่าเดาพอร์ตหรือเปลี่ยน TLS เอง

**Publish แล้วเว็บไม่เห็น:** ตรวจ Topic สะกดตรงกัน, ชนิดข้อมูลที่ส่ง และสถานะการเชื่อมต่อ MQTT

**Subscribe แล้ว LED ไม่เปลี่ยน:** ตรวจ Topic, Payload, การแปลงข้อความเป็นตัวเลข, ช่วงค่า และขา LED

**อุณหภูมิผิด:** ตรวจทิศทาง TMP36 และสูตรจาก Lab; อย่าสับสนระหว่าง `raw`, `voltage`, `tempC`.

## 9. สิ่งที่ยังขาด

ไฟล์ Lab ที่ได้รับยังไม่มีโค้ด MQTT connect/publish/subscribe และไม่มี pin mapping ของ Color LED ในชุดสอบ จึงต้องอาศัยโค้ด/คำสั่งจาก Lab ที่อาจารย์สอนจริงเพื่อเติมส่วน MQTT ให้สมบูรณ์ ก่อนสอบควรหา:
1. ชื่อไลบรารี MQTT
2. ตัวอย่าง connect/publish/subscribe
3. วิธีรับ Payload/callback
4. ขา RGB/Color LED และการเปิดปิดสี
