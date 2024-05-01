#include <Arduino.h>
#include <wheel.h>
#include <triple_vl53.h>

WHEEL Wheel;


void WHEEL::setup(){
  pinMode(DIGITAL_GPIO_05, OUTPUT);
  pinMode(DIGITAL_GPIO_16, OUTPUT);
}


bool WHEEL::checkObstacle() {
  vl53.read();
  for(auto &value : vl53.VL53_data) {
    if(value <= 200 && value > 0) return true;
  }
  return false;
}


void WHEEL::moveDirect(float time){
  unsigned long startTime = millis();
  unsigned long targetTime = time * 1000; 

  Serial.print("\n[WHEEL] Move Direct : ");
  Serial.print(time);
  Serial.print(" sec\n");

  while(millis() - startTime < targetTime){
    if(WHEEL_PRINT){
      char buffer[50];
      sprintf(buffer, "TIME: %lu/%lu", millis()-startTime, targetTime);
      Serial.print("\r");
      Serial.print(buffer);
    }

    if(checkObstacle()) {
      digitalWrite(DIGITAL_GPIO_05, LOW);
      digitalWrite(DIGITAL_GPIO_16, LOW);

      unsigned long waitingTimeStart = millis();
      while(checkObstacle());
      targetTime += ( millis() - waitingTimeStart );
    }

    digitalWrite(DIGITAL_GPIO_16, HIGH);
    digitalWrite(DIGITAL_GPIO_05, HIGH);
  }

  digitalWrite(DIGITAL_GPIO_05, LOW);
  digitalWrite(DIGITAL_GPIO_16, LOW);

  if(WHEEL_PRINT) Serial.print(" \n");
}



void WHEEL::rotateClockwise(float time){
  unsigned long startTime = millis();
  unsigned long targetTime = time * 1000; 

  Serial.print("\n[WHEEL] Rotate Clockwise\n");

  while(millis() - startTime < targetTime){
  if(WHEEL_PRINT){
    char buffer[50];
    sprintf(buffer, "TIME: %lu/%lu", millis()-startTime, targetTime);
    Serial.print("\r");
    Serial.print(buffer);
  }

  // OBSTACLE
    // if(!isSafe()){ 
    //   analogWrite(ANALOG_GPIO_0, 0);
    //   digitalWrite(DIGITAL_GPIO_16, LOW);

    //   unsigned long waitingTimeStart = millis();
    //   while(!isSafe()); 
    //   startTime += ( millis() - waitingTimeStart ); 
    // }
  
    digitalWrite(DIGITAL_GPIO_05, HIGH);
    digitalWrite(DIGITAL_GPIO_16, LOW);
  }

  digitalWrite(DIGITAL_GPIO_05, LOW);
  digitalWrite(DIGITAL_GPIO_16, LOW);

  if(WHEEL_PRINT) Serial.print(" \n");
}



void WHEEL::rotateCounterClockwise(float time){

  unsigned long startTime = millis();
  unsigned long targetTime = time * 1000; 

  Serial.print("\n[WHEEL] Rotate Counter Clockwise\n");

  while(millis() - startTime < targetTime){
  if(WHEEL_PRINT){
    char buffer[50];
    sprintf(buffer, "TIME: %lu/%lu", millis()-startTime, targetTime);
    Serial.print("\r");
    Serial.print(buffer);
  }

    digitalWrite(DIGITAL_GPIO_05, LOW);
    digitalWrite(DIGITAL_GPIO_16, HIGH);
  }

  digitalWrite(DIGITAL_GPIO_05, LOW);
  digitalWrite(DIGITAL_GPIO_16, LOW);

  if(WHEEL_PRINT) Serial.print(" \n");
}