#include <Arduino.h>
#include <iostream>

#include <bugs.h>
#include <wheel.h>
#include <actuator.h>
#include <infrared.h>
#include <actuator.h>
BUGS Bugs;

void BUGS::ID_1_run(){
  Wheel.moveDirect(3,1);
  Wheel.rotateClockwise(3,1);
  ESP_Servo.moveTo(0);
  delay(5000);
  ESP_Servo.moveTo(180);
}


void BUGS::ID_2_run(){

}

void BUGS::ID_3_run(){
  
}

void BUGS::ID_4_run(){
  
}

void BUGS::ID_5_run(){
  
}

void BUGS::ID_6_run(){

}

void BUGS::ID_7_run(){
  
}

void BUGS::ID_8_run(){
  
}

void BUGS::ID_9_run(){
  
}

void BUGS::ID_10_run(){
  
}

void BUGS::ID_11_run(){
  
}

void BUGS::ID_12_run(){
  
}