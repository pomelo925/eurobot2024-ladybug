#include <Arduino.h>
#include <optical.h>
#include <path.h>
#include <actuator.h>
#include <wheel.h>
// #include <infrared.h>

#define LED_PIN 2

#include <ESP32Servo.h>


Servo myservo;  // 創建一個 Servo 物件
int pos = 0;    // 伺服馬達的初始位置

void setup() {
  Serial.begin(115200);
  Serial.println("setup");
  pinMode(LED_PIN, OUTPUT);
  // VL53_setup();
  myservo.attach(4);
  // Allow allocation of all timers
	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);

  // pinMode(18, INPUT);
  // pinMode(26, INPUT);

}

void loop() {
  // Serial.print("GPIO18 state:");
  // Serial.println(digitalRead(18));
  // Serial.print("GPIO26 state:");
  // Serial.println(digitalRead(26));
  digitalWrite(LED_PIN, HIGH);
  delay(400);
  digitalWrite(LED_PIN, LOW);
  delay(300);

	if (!myservo.attached()) {
		myservo.setPeriodHertz(50); // standard 50 hz servo
		myservo.attach(4, 1000, 2000); // Attach the servo after it has been detatched
	}
	myservo.write(0);
  delay(500);
  myservo.write(50);
  delay(500);
  myservo.write(100);
  delay(500);
}
