#include <wheel.h>
#include <Arduino.h>

WHEEL Wheel;

void WHEEL::moveDirect(float time, int mode){
  unsigned long startTime = millis();
  unsigned long targetTime = time * 1000; 

/** 調整 digital write 的頻率參數 **/
  unsigned long lastSwitchTime = 0; // 新增此行來追蹤上次切換的時間
  bool isHigh = false; // 新增此行來追蹤當前狀態
/** **/


  while(millis() - startTime < targetTime){
  // OBSTACLE
    // if(!isSafe()){ 
    //   analogWrite(ANALOG_GPIO_0, 0);
    //   digitalWrite(DIGITAL_GPIO_16, LOW);

    //   unsigned long waitingTimeStart = millis();
    //   while(!isSafe()); 
    //   startTime += ( millis() - waitingTimeStart ); 
    // }
  
  // MODE
    if(mode == 1){ // FULL SPEED
      analogWrite(ANALOG_GPIO_0, 255);
      digitalWrite(DIGITAL_GPIO_16, HIGH);
    }
    else if(mode == 2){ // HALF SPEED
      analogWrite(ANALOG_GPIO_0, 120);

      // 檢查超過秒數
      if(millis() - lastSwitchTime >= _DIGITAL_HALF_SEC_MS){
        isHigh = !isHigh; // 切換狀態
        digitalWrite(DIGITAL_GPIO_16, isHigh ? HIGH : LOW); 
        lastSwitchTime = millis(); 
      }
    }
  }

  analogWrite(ANALOG_GPIO_0, 0);
  digitalWrite(DIGITAL_GPIO_16, LOW);

  Serial.println("moveDirect terminates.");
}

void WHEEL::rotateClockwise(float time, int mode){
  unsigned long startTime = millis();
  unsigned long targetTime = time * 1000; 

/** 調整 digital write 的頻率參數 **/
  unsigned long lastSwitchTime = 0; // 新增此行來追蹤上次切換的時間
  bool isHigh = false; // 新增此行來追蹤當前狀態
/** **/


  while(millis() - startTime < targetTime){
    Serial.print("\rPassing Time: ");
    Serial.print(millis() - startTime);    
    Serial.print("               Target Time: ");
    Serial.print(targetTime);
  // OBSTACLE
    // if(!isSafe()){ 
    //   analogWrite(ANALOG_GPIO_0, 0);
    //   digitalWrite(DIGITAL_GPIO_16, LOW);

    //   unsigned long waitingTimeStart = millis();
    //   while(!isSafe()); 
    //   startTime += ( millis() - waitingTimeStart ); 
    // }
  
  // MODE
    if(mode == 1){ // FULL SPEED
      analogWrite(ANALOG_GPIO_0, 255);
      digitalWrite(DIGITAL_GPIO_16, LOW);
    }
    else if(mode == 2){ // HALF SPEED
      analogWrite(ANALOG_GPIO_0, 120);
      digitalWrite(DIGITAL_GPIO_16, LOW);
    }
  }

  analogWrite(ANALOG_GPIO_0, 0);
  digitalWrite(DIGITAL_GPIO_16, LOW);
}

void WHEEL::rotateCounterClockwise(float time, int mode){
  unsigned long startTime = millis();
  unsigned long targetTime = time * 1000; 

/** 調整 digital write 的頻率參數 **/
  unsigned long lastSwitchTime = 0; // 新增此行來追蹤上次切換的時間
  bool isHigh = false; // 新增此行來追蹤當前狀態
/** **/


  while(millis() - startTime < targetTime){
  // OBSTACLE
    // if(!isSafe()){ 
    //   analogWriteL_GPIO_(ANALOG_GPIO_0, 0);
    //   digitalWrite(DIGITA16, LOW);

    //   unsigned long waitingTimeStart = millis();
    //   while(!isSafe()); 
    //   startTime += ( millis() - waitingTimeStart ); 
    // }
  
  // MODE
    if(mode == 1){ // FULL SPEED
      analogWrite(ANALOG_GPIO_0, 0);
      digitalWrite(DIGITAL_GPIO_16, HIGH);
    }
    else if(mode == 2){ // HALF SPEED
      analogWrite(ANALOG_GPIO_0, 0);
    // 檢查超過秒數
      if(millis() - lastSwitchTime >= _DIGITAL_HALF_SEC_MS){
        isHigh = !isHigh; // 切換狀態
        digitalWrite(DIGITAL_GPIO_16, isHigh ? HIGH : LOW); 
        lastSwitchTime = millis(); 
      }
    }
  }

  analogWrite(ANALOG_GPIO_0, 0);
  digitalWrite(DIGITAL_GPIO_16, LOW);
}
