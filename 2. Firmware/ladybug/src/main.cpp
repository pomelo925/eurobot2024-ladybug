#include <Arduino.h>

#include <actuator.h>
#include <wheel.h>
#include <infrared.h>
#include <mission.h>

#define LADYBUG_ID 1
#define MOTOR_DIRECTION_PIN 

// params：Ladybug ID
MISSION Mission(LADYBUG_ID);

void setup() {
  Serial.begin(115200);
}

void loop(){
  Mission.run();
}

// #include <Arduino.h>

// void setup() {
//   Serial.begin(115200);

//   pinMode(0, OUTPUT);
//   pinMode(16, OUTPUT);
// }

// void loop(){
//   digitalWrite(16, LOW); 
//   analogWrite(0,255);
// }