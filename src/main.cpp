#include <Arduino.h>

// กำหนดขาเชื่อมต่อ
const int potPin = 36;    // GPIO36 (A0) สำหรับ Potentiometer
const int ledPins[8] = { 23, 19, 18, 5, 17, 16, 4, 0 };  // GPIO 8 ตัวสำหรับ LED (D23, D19, D18, D5, D17, D16, D4, D0)

// ฟังก์ชัน setup() จะทำงานเมื่อเริ่มต้นโปรแกรม
void setup() {
  // ตั้งค่า GPIO สำหรับ LED 8 ตัวให้เป็น OUTPUT
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // เริ่มการเชื่อมต่อ Serial สำหรับการดีบัก
  Serial.begin(115200);
}

// ฟังก์ชัน loop() จะทำงานวนซ้ำไปเรื่อย ๆ
void loop() {
  // อ่านค่าจาก Potentiometer (ค่า ADC จะอยู่ในช่วง 0-4095)
  int potValue = analogRead(potPin);

  // แปลงค่าจาก Potentiometer (0-4095) ให้เป็นค่าเปอร์เซ็นต์ (0-100)
  int percentage = map(potValue, 0, 4095, 0, 100);

  // แสดงค่าเปอร์เซ็นต์บน Serial Monitor
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  Serial.print("  Percentage: ");
  Serial.println(percentage);

  // คำนวณจำนวน LED ที่จะเปิดจากเปอร์เซ็นต์
  int ledsToLightUp = map(percentage, 0, 100, 0, 8);  // แปลงเปอร์เซ็นต์เป็นจำนวน LED

  // เปิด LED ตามจำนวนที่คำนวณ
  for (int i = 0; i < 8; i++) {
    if (i < ledsToLightUp) {
      digitalWrite(ledPins[i], HIGH);  // เปิด LED
    } else {
      digitalWrite(ledPins[i], LOW);   // ปิด LED
    }
  }

  // หน่วงเวลาเล็กน้อยเพื่อไม่ให้การอ่านค่าเร็วเกินไป
  delay(50);
}
