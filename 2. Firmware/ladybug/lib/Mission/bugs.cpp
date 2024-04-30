#include <Arduino.h>
#include <iostream> 

#include <bugs.h>
#include <wheel.h>
#include <actuator.h>

BUGS Bugs;

void BUGS::ID_1_run(){
  Serial.println("\n[MISSION] ID 1 Run !!\n");

  Wheel.moveDirect(3);
  Wheel.rotateClockwise(3);
  Wheel.rotateCounterClockwise(3);
  ESP_Servo.moveTo(0);
  delay(5000);
  ESP_Servo.moveTo(180);
}


void BUGS::ID_2_run(){
  Serial.println("\n[MISSION] ID 2 Run !!\n");

  Wheel.moveDirect(5);
}

void BUGS::ID_3_run(){
  Serial.println("\n[MISSION] ID 3 Run !!\n");
}

void BUGS::ID_4_run(){
  Serial.println("\n[MISSION] ID 4 Run !!\n");
}

void BUGS::ID_5_run(){
  Serial.println("\n[MISSION] ID 5 Run !!\n");
}

void BUGS::ID_6_run(){
  Serial.println("\n[MISSION] ID 6 Run !!\n");
}

void BUGS::ID_7_run(){
  Serial.println("\n[MISSION] ID 7 Run !!\n");
}

void BUGS::ID_8_run(){
  Serial.println("\n[MISSION] ID 8 Run !!\n");
}

void BUGS::ID_9_run(){
  Serial.println("\n[MISSION] ID 9 Run !!\n");
}

void BUGS::ID_10_run(){
  Serial.println("\n[MISSION] ID 10 Run !!\n");
}

void BUGS::ID_11_run(){
  Serial.println("\n[MISSION] ID 11 Run !!\n");
}

void BUGS::ID_12_run(){
  Serial.println("\n[MISSION] ID 12 Run !!\n");
}