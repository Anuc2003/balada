#include <Arduino.h>

const int potPin = 36;  // ขาของ potentiometer
const int ledPins[] = {23, 19, 18, 5, 17, 16, 4, 0};  // ขา LED
const int numLEDs = 8;  // จำนวน LED

void setup() {
  for (int i = 0; i < numLEDs; i++) pinMode(ledPins[i], OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int potValue = analogRead(potPin);  // อ่านค่าจาก potentiometer
  int ledsToLightUp = map(potValue, 0, 4095, 0, numLEDs);  // คำนวณจำนวน LED ที่เปิด

  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], (i < ledsToLightUp) ? HIGH : LOW);  // เปิด/ปิด LED
  }

  Serial.print("Potentiometer: "); Serial.print(potValue);
  Serial.print("  LEDs: "); Serial.println(ledsToLightUp);

  delay(100);  // หน่วงเวลา
}
