#ifndef _ACTUATOR_H_
#define _ACTUATOR_H_

#define GPIO4 4

#include <ESP32Servo.h>


class SERVO {
public:
  void moveTo(const float angle);

  SERVO(int pin): pin(pin) {
    ESP32PWM::allocateTimer(0);
    esp_servo.attach(pin);
  };

private:
  int pin;
  Servo esp_servo;

  void attach_check();

// 速度控制內部參數 
  float currentAngle = 0.0;
  float targetAngle = 0.0;
  float speed = 0.0;
  unsigned long lastUpdateTime = 0;
};

extern SERVO ESP_Servo;

#endif