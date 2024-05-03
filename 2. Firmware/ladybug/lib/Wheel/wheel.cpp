#include <Arduino.h>
#include <wheel.h>
#include <triple_vl53.h>
#include <glv.h>

WHEEL Wheel;

void WHEEL::setup(){
  pinMode(MOTOR_L, OUTPUT);
  pinMode(MOTOR_R, OUTPUT);
}


bool WHEEL::checkObstacle() {
  Triple_vl53.read();
  for(auto &value : Triple_vl53.VL53_data) {
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
      digitalWrite(MOTOR_L, LOW);
      digitalWrite(MOTOR_R, LOW);

      unsigned long waitingTimeStart = millis();
      while(checkObstacle());
      targetTime += ( millis() - waitingTimeStart );
    }

    digitalWrite(MOTOR_R, HIGH);
    digitalWrite(MOTOR_L, HIGH);
  }

  digitalWrite(MOTOR_L, LOW);
  digitalWrite(MOTOR_R, LOW);

  if(WHEEL_PRINT) Serial.print(" \n");
}


void WHEEL::rotateClockwise(float time){
  unsigned long startTime = millis();
  unsigned long targetTime = time * 1000; 

  Serial.print("\n[WHEEL] Rotate Clockwise : ");
  Serial.print(time);
  Serial.print(" sec\n");

  while(millis() - startTime < targetTime){
  if(WHEEL_PRINT){
    char buffer[50];
    sprintf(buffer, "TIME: %lu/%lu", millis()-startTime, targetTime);
    Serial.print("\r");
    Serial.print(buffer);
  }

  // OBSTACLE
    if(checkObstacle()) {
      digitalWrite(MOTOR_L, LOW);
      digitalWrite(MOTOR_R, LOW);

      unsigned long waitingTimeStart = millis();
      while(checkObstacle());
      targetTime += ( millis() - waitingTimeStart );
    }
  
    digitalWrite(MOTOR_L, HIGH);
    digitalWrite(MOTOR_R, LOW);
  }

  digitalWrite(MOTOR_L, LOW);
  digitalWrite(MOTOR_R, LOW);

  if(WHEEL_PRINT) Serial.print(" \n");
}


void WHEEL::rotateCounterClockwise(float time){


  unsigned long startTime = millis();
  unsigned long targetTime = time * 1000; 

  Serial.print("\n[WHEEL] Rotate Counter Clockwise : ");
  Serial.print(time);
  Serial.print(" sec\n");

  while(millis() - startTime < targetTime){
    if(WHEEL_PRINT){
      char buffer[50];
      sprintf(buffer, "TIME: %lu/%lu", millis()-startTime, targetTime);
      Serial.print("\r");
      Serial.print(buffer);
    }

  // OBSTACLE
    if(checkObstacle()) {
      digitalWrite(MOTOR_L, LOW);
      digitalWrite(MOTOR_R, LOW);

      unsigned long waitingTimeStart = millis();
      while(checkObstacle());
      targetTime += ( millis() - waitingTimeStart );
    }
  
    digitalWrite(MOTOR_L, LOW);
    digitalWrite(MOTOR_R, HIGH);
  }

  digitalWrite(MOTOR_L, LOW);
  digitalWrite(MOTOR_R, LOW);

  if(WHEEL_PRINT) Serial.print(" \n");
}




void WHEEL::moveDirect2(float dist){
  Serial.print("\n[WHEEL][Move Direct 2]\n");

  int numOfCheckpoint = (4*(dist/_wheel_perimeter))/_checkpoint_steps;

  while(numOfCheckpoint--) {
  
    stepsCheckpoint(_checkpoint_steps);
    delay(500);
  }
}


void WHEEL::rotateClockwise2(float angle){
  
}


void WHEEL::rotateCounterClockwise2(float angle){

}


void WHEEL::zero_cali(){
  // Right Side Calibration
  Serial.println("\n[WHEEL] Calibrating R ...");
  while(Glv.get_glv_r()){
    digitalWrite(MOTOR_R, HIGH);
    delay(5);
    digitalWrite(MOTOR_R, LOW);
    delay(50);
  }

  // Left Side Calibration
  Serial.println("[WHEEL] Calibrating L ...\n");
  while(Glv.get_glv_l()){
    digitalWrite(MOTOR_L, HIGH);
    delay(5);
    digitalWrite(MOTOR_L, LOW);
    delay(50);
  }
}


void WHEEL::stepsCheckpoint(int _checkpoint_steps){
  static TaskHandle_t leftTaskHandle = NULL;
  static TaskHandle_t rightTaskHandle = NULL;
  int L_steps=0, R_steps=0;

  auto countLeftStepsTask = [] (void* parameter) {
    int* L_steps = static_cast<int*>(parameter);
    while (true) {
      bool prev_glv_l = Glv.get_glv_l();
      bool curr_glv_l = prev_glv_l;
      while (prev_glv_l == curr_glv_l) {
        curr_glv_l = Glv.get_glv_l();
        vTaskDelay(pdMS_TO_TICKS(1));
      }
      (*L_steps)++;
    }
  };

  auto countRightStepsTask = [] (void* parameter) {
    int* R_steps = static_cast<int*>(parameter);
    while (true) {
      bool prev_glv_r = Glv.get_glv_r();
      bool curr_glv_r = prev_glv_r;
      while (prev_glv_r == curr_glv_r) {
        curr_glv_r = Glv.get_glv_r();
        vTaskDelay(pdMS_TO_TICKS(1));
      }
      (*R_steps)++;
    }
  };

  // Create tasks for left and right wheel step counting
  if (!leftTaskHandle) xTaskCreatePinnedToCore(countLeftStepsTask, "LeftStepsTask", 1000, &L_steps, 1, &leftTaskHandle, 0);
  if (!rightTaskHandle) xTaskCreatePinnedToCore(countRightStepsTask, "RightStepsTask", 1000, &R_steps, 1, &rightTaskHandle, 0);


  // Wait until both left and right steps reach the target
  while (L_steps < _checkpoint_steps || R_steps < _checkpoint_steps) {

    Serial.print(">> L_steps: "); Serial.print(L_steps);
    Serial.print("\tR_steps: "); Serial.print(R_steps);
    Serial.print("\r");

    if (L_steps < R_steps) {
      digitalWrite(MOTOR_L, HIGH);
      digitalWrite(MOTOR_R, LOW);
      delay(35);
      digitalWrite(MOTOR_L, LOW);
      delay(10);
    } else if (R_steps < L_steps) {
      digitalWrite(MOTOR_L, LOW);
      digitalWrite(MOTOR_R, HIGH);
      delay(15);
      digitalWrite(MOTOR_R, LOW);
      delay(10);
    } else {
      digitalWrite(MOTOR_L, HIGH);
      digitalWrite(MOTOR_R, HIGH);
    }
    vTaskDelay(pdMS_TO_TICKS(1));
  }
  digitalWrite(MOTOR_L, LOW);
  digitalWrite(MOTOR_R, LOW);
}