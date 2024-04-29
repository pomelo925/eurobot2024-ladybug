#include <Arduino.h>

#include <wheel.h>
#include <mission.h>

#define LADYBUG_ID 1

// params：Ladybug ID
MISSION Mission(LADYBUG_ID);

void setup() {
  Serial.begin(115200);
}

void loop(){
  Mission.run();
  delay(6000000);
}


/***** 分隔線 *****/

//#include <Arduino.h>
//
//void setup() {
//  Serial.begin(115200);
//  pinMode(0, OUTPUT);
//  pinMode(16, OUTPUT);
//}
//
//void loop(){ 
//  analogWrite(0,255);
//  delay(500);
//  digitalWrite(16, HIGH);
//  delay(500);
//  digitalWrite(16, LOW); 
//}