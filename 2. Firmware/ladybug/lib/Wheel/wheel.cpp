#include <Arduino.h>
#include <wheel.h>

WHEEL Wheel;

void WHEEL::setup(){
  pinMode(ANALOG_GPIO_0, OUTPUT);
  pinMode(DIGITAL_GPIO_16, OUTPUT);
}

void WHEEL::moveDirect(float time){
  unsigned long startTime = millis();
  unsigned long targetTime = time * 1000; 

/** 調整 digital write 的頻率參數 **/
  unsigned long lastSwitchTime = 0; // 新增此行來追蹤上次切換的時間
  bool isHigh = false; // 新增此行來追蹤當前狀態
/** **/

  Serial.println("[WHEEL] MoveDirect");
  Serial.print("Target Time : ");
  Serial.println(targetTime);

  while(millis() - startTime < targetTime){
    Serial.print("\rPass: ");
    Serial.println(millis() - startTime);
  // OBSTACLE
  //   if(!isSafe()){   // isSafe 來自 vl53
  //     analogWrite(ANALOG_GPIO_0, 0);
  //     digitalWrite(DIGITAL_GPIO_16, LOW);

  //     unsigned long waitingTimeStart = millis();
  //     while(!isSafe()); 
  //     startTime += ( millis() - waitingTimeStart ); 
  //   }
  

    digitalWrite(DIGITAL_GPIO_16, HIGH);
    analogWrite(ANALOG_GPIO_0, 255);
  }

  analogWrite(ANALOG_GPIO_0, 0);
  digitalWrite(DIGITAL_GPIO_16, LOW);

  Serial.println("moveDirect terminates.");
}

void WHEEL::rotateClockwise(float time){
  unsigned long startTime = millis();
  unsigned long targetTime = time * 1000; 

/** 調整 digital write 的頻率參數 **/
  unsigned long lastSwitchTime = 0; // 新增此行來追蹤上次切換的時間
  bool isHigh = false; // 新增此行來追蹤當前狀態
/** **/

  Serial.println("[WHEEL] rotateClockwise");

  while(millis() - startTime < targetTime){
  // OBSTACLE
    // if(!isSafe()){ 
    //   analogWrite(ANALOG_GPIO_0, 0);
    //   digitalWrite(DIGITAL_GPIO_16, LOW);

    //   unsigned long waitingTimeStart = millis();
    //   while(!isSafe()); 
    //   startTime += ( millis() - waitingTimeStart ); 
    // }
  
    analogWrite(ANALOG_GPIO_0, 255);
    digitalWrite(DIGITAL_GPIO_16, LOW);
  }

  analogWrite(ANALOG_GPIO_0, 0);
  digitalWrite(DIGITAL_GPIO_16, LOW);
}

void WHEEL::rotateCounterClockwise(float time){
  unsigned long startTime = millis();
  unsigned long targetTime = time * 1000; 

/** 調整 digital write 的頻率參數 **/
  unsigned long lastSwitchTime = 0; // 新增此行來追蹤上次切換的時間
  bool isHigh = false; // 新增此行來追蹤當前狀態
/** **/

  Serial.println("[WHEEL] rotateCounterClockwise");

  while(millis() - startTime < targetTime){
  // OBSTACLE
    // if(!isSafe()){ 
    //   analogWriteL_GPIO_(ANALOG_GPIO_0, 0);
    //   digitalWrite(DIGITA16, LOW);

    //   unsigned long waitingTimeStart = millis();
    //   while(!isSafe()); 
    //   startTime += ( millis() - waitingTimeStart ); 
    // }
  
    analogWrite(ANALOG_GPIO_0, 0);
    digitalWrite(DIGITAL_GPIO_16, HIGH);
    
  }

  analogWrite(ANALOG_GPIO_0, 0);
  digitalWrite(DIGITAL_GPIO_16, LOW);
}
