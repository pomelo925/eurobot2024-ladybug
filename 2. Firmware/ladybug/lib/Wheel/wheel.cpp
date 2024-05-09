#include <Arduino.h>
#include <wheel.h>
#include <triple_vl53.h>
#include <single_vl53.h>
#include <glv.h>

WHEEL Wheel;

/**
 * @brief  初始化 WHEEL
 */
void WHEEL::setup(){
  pinMode(MOTOR_L, OUTPUT);
  pinMode(MOTOR_R, OUTPUT);
}


/**
 * @brief 計時，直走，避障，單/三VL53
 * @param time 行走時間 
 * @param single_vl53 單 vl53 設 true，三 vl53 設 false
 */
void WHEEL::moveDirectAvoid(const float time, const bool single_vl53){
  unsigned long startTime = millis();
  unsigned long targetTime = time * 1000 ; // 0.6 為時間誤差係數

  Serial.print("[WHEEL] Move Direct : ");
  Serial.print(time);
  Serial.print(" sec\n");

  volatile bool _isBlocked=false;
  static TaskHandle_t checkObstacleTaskHandle = NULL;
  void* _isBlockedPtr = const_cast<void*>(static_cast<const void*>(const_cast<bool*>(&_isBlocked)));

  struct Params {
    volatile bool* _isBlocked;
    bool single_vl53;
  };
  Params params = { &_isBlocked, single_vl53 };
  void* paramsPtr = &params;

  static auto checkObstacleTask = [](void* parameter) {
    Params* params = static_cast<Params*>(parameter);
    volatile bool* _isBlocked = params->_isBlocked;
    bool single_vl53 = params->single_vl53;

    while (true) {
      if(single_vl53? Single_vl53.checkObstacle():Triple_vl53.checkObstacle()) {
        *_isBlocked = true;
        Serial.println("aaa");
        digitalWrite(MOTOR_L, LOW);
        digitalWrite(MOTOR_R, LOW);
      }
      else *_isBlocked = false;
      vTaskDelay(pdMS_TO_TICKS(1));
    }
  };

  if (!checkObstacleTaskHandle) xTaskCreatePinnedToCore(checkObstacleTask, "CheckObstacleTask", 10000, paramsPtr, 1, &checkObstacleTaskHandle, 1);
  
  while(millis() - startTime < targetTime){
    while(_isBlocked){
      if(!_isBlocked) break;
    };

    digitalWrite(MOTOR_R, HIGH); digitalWrite(MOTOR_L, HIGH);
    delay(3);
    digitalWrite(MOTOR_R, LOW); digitalWrite(MOTOR_L, LOW);
    delay(2);
  }

  if (checkObstacleTaskHandle) {
    vTaskDelete(checkObstacleTaskHandle);
    checkObstacleTaskHandle = NULL;
  }

  digitalWrite(MOTOR_L, LOW);
  digitalWrite(MOTOR_R, LOW);

}


/**
 * @brief 計時，直走
 * @param time 行走時間
 */
void WHEEL::moveDirect(const float time){
  unsigned long startTime = millis();
  unsigned long targetTime = time * 1000 ; // 0.6 為時間誤差係數

  Serial.print("[WHEEL] Move Direct : ");
  Serial.print(time);
  Serial.print(" sec\n");
  
  while(millis() - startTime < targetTime){
    digitalWrite(MOTOR_R, HIGH); digitalWrite(MOTOR_L, HIGH);
    delay(3);
    digitalWrite(MOTOR_R, LOW); digitalWrite(MOTOR_L, LOW);
    delay(2);
  }

  digitalWrite(MOTOR_L, LOW);
  digitalWrite(MOTOR_R, LOW);
}



/**
 * @brief 計時，順時鐘走，避障，三VL53
 * @param time 行走時間
 */
void WHEEL::rotateClockwise(const float time){
  unsigned long startTime = millis();
  unsigned long targetTime = time * 1000; 

  Serial.print("[WHEEL] Rotate Clockwise : ");
  Serial.print(time);
  Serial.print(" sec\n");

  static TaskHandle_t checkObstacleTaskHandle = NULL;
  volatile bool _isBlocked=false;
  void* _isBlockedPtr = const_cast<void*>(static_cast<const void*>(const_cast<bool*>(&_isBlocked)));

  auto checkObstacleTask = [](void* parameter) {
    volatile bool* _isBlocked = static_cast<volatile bool*>(parameter);

    while (true) {
      if(Triple_vl53.checkObstacle()) {
        *_isBlocked = true;
        digitalWrite(MOTOR_L, LOW);
        digitalWrite(MOTOR_R, LOW);
      }
      else *_isBlocked = false;
      vTaskDelay(pdMS_TO_TICKS(1));
    }
  };

  if (!checkObstacleTaskHandle) xTaskCreatePinnedToCore(checkObstacleTask, "CheckObstacleTask", 10000, _isBlockedPtr, 1, &checkObstacleTaskHandle, 1);

  while(millis() - startTime < targetTime){
    unsigned long waitingTimeStart = millis();
    while(_isBlocked){
      if(!_isBlocked) break;
    };
    targetTime += ( millis() - waitingTimeStart );
  
    digitalWrite(MOTOR_L, HIGH); digitalWrite(MOTOR_R, LOW);
    delay(50);
    digitalWrite(MOTOR_L, LOW);
    delay(150);

    vTaskDelay(pdMS_TO_TICKS(1));
  }

  if (checkObstacleTaskHandle) {
    vTaskDelete(checkObstacleTaskHandle);
    checkObstacleTaskHandle = NULL;
  }

  digitalWrite(MOTOR_L, LOW);
  digitalWrite(MOTOR_R, LOW);
}


/**
 * @brief 計時，逆時鐘走，避障，三VL53
 * @param time 行走時間
 */
void WHEEL::rotateCounterClockwise(const float time){
  unsigned long startTime = millis();
  unsigned long targetTime = time * 1000; 

  Serial.print("[WHEEL] Rotate Clockwise : ");
  Serial.print(time);
  Serial.print(" sec\n");

  static TaskHandle_t checkObstacleTaskHandle = NULL;
  volatile bool _isBlocked=false;
  void* _isBlockedPtr = const_cast<void*>(static_cast<const void*>(const_cast<bool*>(&_isBlocked)));

  auto checkObstacleTask = [](void* parameter) {
    volatile bool* _isBlocked = static_cast<volatile bool*>(parameter);

    while (true) {
      if(Triple_vl53.checkObstacle()) {
        *_isBlocked = true;
        digitalWrite(MOTOR_L, LOW);
        digitalWrite(MOTOR_R, LOW);
      }
      else *_isBlocked = false;
      vTaskDelay(pdMS_TO_TICKS(1));
    }
  };

  if (!checkObstacleTaskHandle) xTaskCreatePinnedToCore(checkObstacleTask, "CheckObstacleTask", 10000, _isBlockedPtr, 1, &checkObstacleTaskHandle, 1);

  while(millis() - startTime < targetTime){
    unsigned long waitingTimeStart = millis();
    while(_isBlocked){
      if(!_isBlocked) break;
    };
    targetTime += ( millis() - waitingTimeStart );
  
    digitalWrite(MOTOR_R, HIGH); digitalWrite(MOTOR_L, LOW);
    delay(50);
    digitalWrite(MOTOR_R, LOW);
    delay(150);

    vTaskDelay(pdMS_TO_TICKS(1));
  }

  if (checkObstacleTaskHandle) {
    vTaskDelete(checkObstacleTaskHandle);
    checkObstacleTaskHandle = NULL;
  }

  digitalWrite(MOTOR_L, LOW);
  digitalWrite(MOTOR_R, LOW);
}


/**
 * @brief 計時，直走，避障，三VL53，光閘校正
 * @param time 時間
 */
void WHEEL::moveDirectAvoid2_tripleVL53(const float time){
  Serial.print("\n[WHEEL][Move Direct 2] Start !\n");

/* Calculate Total Steps*/
  unsigned long startTime = millis();
  unsigned long targetTime = time * 1000; 

/* FreeRTOS*/
  static TaskHandle_t leftTaskHandle = NULL;
  static TaskHandle_t rightTaskHandle = NULL;
  static TaskHandle_t checkObstacleTaskHandle = NULL;

  int L_steps=0, R_steps=0;
  volatile bool _isBlocked=false;
  void* _isBlockedPtr = const_cast<void*>(static_cast<const void*>(const_cast<bool*>(&_isBlocked)));

  auto countLeftStepsTask = [] (void* parameter) {
    int* L_steps = static_cast<int*>(parameter);
    bool prev_glv_l = Glv.get_glv_l();
    
    while (true) {
      bool curr_glv_l = Glv.get_glv_l();
      if (prev_glv_l && !curr_glv_l) (*L_steps)++;
      prev_glv_l = curr_glv_l;
      vTaskDelay(pdMS_TO_TICKS(1));
    }
  };

  auto countRightStepsTask = [] (void* parameter) {
    int* R_steps = static_cast<int*>(parameter);
    bool prev_glv_r = Glv.get_glv_r();
    
    while (true) {
      bool curr_glv_r = Glv.get_glv_r();
      if (prev_glv_r && !curr_glv_r) (*R_steps)++;
      prev_glv_r = curr_glv_r;
      vTaskDelay(pdMS_TO_TICKS(1));
    }
  };

  auto checkObstacleTask = [](void* parameter) {
    volatile bool* _isBlocked = static_cast<volatile bool*>(parameter);

    while (true) {
      if(Triple_vl53.checkObstacle()) {
        *_isBlocked = true;
        digitalWrite(MOTOR_L, LOW);
        digitalWrite(MOTOR_R, LOW);
      }
      else *_isBlocked = false;
      vTaskDelay(pdMS_TO_TICKS(1));
    }
  };

/* tasks for L/R wheel step counting */
  if (!leftTaskHandle) xTaskCreatePinnedToCore(countLeftStepsTask, "LeftStepsTask", 2000, &L_steps, 1, &leftTaskHandle, 0);
  if (!rightTaskHandle) xTaskCreatePinnedToCore(countRightStepsTask, "RightStepsTask", 2000, &R_steps, 1, &rightTaskHandle, 0);
  if (!checkObstacleTaskHandle) xTaskCreatePinnedToCore(checkObstacleTask, "CheckObstacleTask", 10000, _isBlockedPtr, 1, &checkObstacleTaskHandle, 1);

/* Wait until both L/R steps reach the target */   
  while (millis() - startTime < targetTime) {
    unsigned long waitingTimeStart = millis();
    while(_isBlocked){
      if(!_isBlocked) break;
    };
    targetTime += ( millis() - waitingTimeStart );

    // Serial.print("L_steps: "); Serial.print(L_steps);
    // Serial.print("\tR_stweps: "); Serial.print(R_steps);
    // Serial.print("\r");

    if (L_steps < R_steps) {
      digitalWrite(MOTOR_L, HIGH); digitalWrite(MOTOR_R, LOW);
      delay(5);
      digitalWrite(MOTOR_L, LOW);
      delay(5);
    } else if (R_steps < L_steps) {
      digitalWrite(MOTOR_L, LOW); digitalWrite(MOTOR_R, HIGH);
      delay(5);
      digitalWrite(MOTOR_R, LOW);
      delay(5);
    } else {
      digitalWrite(MOTOR_L, HIGH); digitalWrite(MOTOR_R, HIGH);
      delay(4);
      digitalWrite(MOTOR_L, LOW); digitalWrite(MOTOR_R, LOW);
      delay(15);
    }
    vTaskDelay(pdMS_TO_TICKS(1));
  }

/* Finish */
  if (leftTaskHandle) {
    vTaskDelete(leftTaskHandle);
    leftTaskHandle = NULL;
  }
  if (rightTaskHandle) {
    vTaskDelete(rightTaskHandle);
    rightTaskHandle = NULL;
  }
  if (checkObstacleTaskHandle) {
    vTaskDelete(checkObstacleTaskHandle);
    checkObstacleTaskHandle = NULL;
  }

  digitalWrite(MOTOR_L, LOW); digitalWrite(MOTOR_R, LOW);
  Serial.print("[WHEEL][Move Direct 2] Finish !\n");
}


/**
 * @brief 計時，直走，避障，單VL53，光閘校正
 * @param time 時間
 */
void WHEEL::moveDirectAvoid2_singleVL53(const float time){
  Serial.print("\n[WHEEL][Move Direct 2] Start !\n");

/* Calculate Total Steps*/
  unsigned long startTime = millis();
  unsigned long targetTime = time * 1000; 

/* FreeRTOS*/
  static TaskHandle_t leftTaskHandle = NULL;
  static TaskHandle_t rightTaskHandle = NULL;
  static TaskHandle_t checkObstacleTaskHandle = NULL;

  int L_steps=0, R_steps=0;
  volatile bool _isBlocked=false;
  void* _isBlockedPtr = const_cast<void*>(static_cast<const void*>(const_cast<bool*>(&_isBlocked)));

  auto countLeftStepsTask = [] (void* parameter) {
    int* L_steps = static_cast<int*>(parameter);
    bool prev_glv_l = Glv.get_glv_l();
    
    while (true) {
      bool curr_glv_l = Glv.get_glv_l();
      if (prev_glv_l && !curr_glv_l) (*L_steps)++;
      prev_glv_l = curr_glv_l;
      vTaskDelay(pdMS_TO_TICKS(1));
    }
  };

  auto countRightStepsTask = [] (void* parameter) {
    int* R_steps = static_cast<int*>(parameter);
    bool prev_glv_r = Glv.get_glv_r();
    
    while (true) {
      bool curr_glv_r = Glv.get_glv_r();
      if (prev_glv_r && !curr_glv_r) (*R_steps)++;
      prev_glv_r = curr_glv_r;
      vTaskDelay(pdMS_TO_TICKS(1));
    }
  };

  auto checkObstacleTask = [](void* parameter) {
    volatile bool* _isBlocked = static_cast<volatile bool*>(parameter);

    while (true) {
      if(Single_vl53.checkObstacle()) {
        *_isBlocked = true;
        digitalWrite(MOTOR_L, LOW);
        digitalWrite(MOTOR_R, LOW);
      }
      else *_isBlocked = false;
      vTaskDelay(pdMS_TO_TICKS(1));
    }
  };

/* tasks for L/R wheel step counting */
  if (!leftTaskHandle) xTaskCreatePinnedToCore(countLeftStepsTask, "LeftStepsTask", 2000, &L_steps, 1, &leftTaskHandle, 0);
  if (!rightTaskHandle) xTaskCreatePinnedToCore(countRightStepsTask, "RightStepsTask", 2000, &R_steps, 1, &rightTaskHandle, 0);
  if (!checkObstacleTaskHandle) xTaskCreatePinnedToCore(checkObstacleTask, "CheckObstacleTask", 10000, _isBlockedPtr, 1, &checkObstacleTaskHandle, 1);

/* Wait until both L/R steps reach the target */   
  while (millis() - startTime < targetTime) {
    unsigned long waitingTimeStart = millis();
    while(_isBlocked){
      if(!_isBlocked) break;
    };
    targetTime += ( millis() - waitingTimeStart );

    // Serial.print("L_steps: "); Serial.print(L_steps);
    // Serial.print("\tR_stweps: "); Serial.print(R_steps);
    // Serial.print("\r");

    if (L_steps < R_steps) {
      digitalWrite(MOTOR_L, HIGH); digitalWrite(MOTOR_R, LOW);
      delay(5);
      digitalWrite(MOTOR_L, LOW);
      delay(5);
    } else if (R_steps < L_steps) {
      digitalWrite(MOTOR_L, LOW); digitalWrite(MOTOR_R, HIGH);
      delay(5);
      digitalWrite(MOTOR_R, LOW);
      delay(5);
    } else {
      digitalWrite(MOTOR_L, HIGH); digitalWrite(MOTOR_R, HIGH);
      delay(5);
      digitalWrite(MOTOR_L, LOW); digitalWrite(MOTOR_R, LOW);
      delay(20);
    }
    vTaskDelay(pdMS_TO_TICKS(1));
  }

/* Finish */
  if (leftTaskHandle) {
    vTaskDelete(leftTaskHandle);
    leftTaskHandle = NULL;
  }
  if (rightTaskHandle) {
    vTaskDelete(rightTaskHandle);
    rightTaskHandle = NULL;
  }
  if (checkObstacleTaskHandle) {
    vTaskDelete(checkObstacleTaskHandle);
    checkObstacleTaskHandle = NULL;
  }

  digitalWrite(MOTOR_L, LOW); digitalWrite(MOTOR_R, LOW);
  Serial.print("[WHEEL][Move Direct 2] Finish !\n");
}



/**
 * @brief 計時，直走，光閘校正
 * @param time 時間
 */
void WHEEL::moveDirect2(const float time){
/* Calculate Total Steps*/
  unsigned long startTime = millis();
  unsigned long targetTime = time * 1000; 

/* FreeRTOS*/
  static TaskHandle_t leftTaskHandle = NULL;
  static TaskHandle_t rightTaskHandle = NULL;

  int L_steps=0, R_steps=0;

  auto countLeftStepsTask = [] (void* parameter) {
    int* L_steps = static_cast<int*>(parameter);
    bool prev_glv_l = Glv.get_glv_l();
    
    while (true) {
      bool curr_glv_l = Glv.get_glv_l();
      if (prev_glv_l && !curr_glv_l) (*L_steps)++;
      prev_glv_l = curr_glv_l;
      vTaskDelay(pdMS_TO_TICKS(1));
    }
  };

  auto countRightStepsTask = [] (void* parameter) {
    int* R_steps = static_cast<int*>(parameter);
    bool prev_glv_r = Glv.get_glv_r();
    
    while (true) {
      bool curr_glv_r = Glv.get_glv_r();
      if (prev_glv_r && !curr_glv_r) (*R_steps)++;
      prev_glv_r = curr_glv_r;
      vTaskDelay(pdMS_TO_TICKS(1));
    }
  };


/* tasks for L/R wheel step counting */
  if (!leftTaskHandle) xTaskCreatePinnedToCore(countLeftStepsTask, "LeftStepsTask", 2000, &L_steps, 1, &leftTaskHandle, 0);
  if (!rightTaskHandle) xTaskCreatePinnedToCore(countRightStepsTask, "RightStepsTask", 2000, &R_steps, 1, &rightTaskHandle, 0);

/* Wait until both L/R steps reach the target */   
  while (millis() - startTime < targetTime) {
    unsigned long waitingTimeStart = millis();
    targetTime += ( millis() - waitingTimeStart );

    if (L_steps < R_steps) {
      digitalWrite(MOTOR_L, HIGH); digitalWrite(MOTOR_R, LOW);
      delay(5);
      digitalWrite(MOTOR_L, LOW);
      delay(5);
    } else if (R_steps < L_steps) {
      digitalWrite(MOTOR_L, LOW); digitalWrite(MOTOR_R, HIGH);
      delay(5);
      digitalWrite(MOTOR_R, LOW);
      delay(5);
    } else {
      digitalWrite(MOTOR_L, HIGH); digitalWrite(MOTOR_R, HIGH);
      delay(5);
      digitalWrite(MOTOR_L, LOW); digitalWrite(MOTOR_R, LOW);
      delay(20);
    }
    vTaskDelay(pdMS_TO_TICKS(1));
  }

/* Finish */
  if (leftTaskHandle) {
    vTaskDelete(leftTaskHandle);
    leftTaskHandle = NULL;
  }
  if (rightTaskHandle) {
    vTaskDelete(rightTaskHandle);
    rightTaskHandle = NULL;
  }

  digitalWrite(MOTOR_L, LOW); digitalWrite(MOTOR_R, LOW);
  Serial.print("[WHEEL][Move Direct 2] Finish !\n");
}



/**
 * @brief 計步，避障，調用 FreeRTOS 更新 VL530x，光閘閉迴路校正
 * @param steps steps 數量，光閘由 true 轉為 false 的間距視為一個 step
 */
void WHEEL::rotateClockwise2(const int steps){
  Serial.print("[WHEEL][Rotate Clockwise 2] Start !\n");
  // force_zero_cali();

  int falseCount = 0;
  bool previousState = Glv.get_glv_r();

  digitalWrite(MOTOR_L, LOW);

  while(true){
    bool currentState = Glv.get_glv_r();
    
    digitalWrite(MOTOR_R, HIGH); delay(15);
    digitalWrite(MOTOR_R, LOW); delay(200);
    
    if(previousState && !currentState){
      falseCount++;
      delay(500);
    }
    
    if(falseCount >= steps) break;
    previousState = currentState;
  }
  
  Serial.print("[WHEEL][Rotate Clockwise 2] Finish !\n");
}


/**
 * @brief 計步，避障直走，調用 FreeRTOS 更新 VL530x，光閘閉迴路校正
 * @param steps steps 數量，光閘由 true 轉為 false 的間距視為一個 step
 */
void WHEEL::rotateCounterClockwise2(const int steps){
  Serial.print("[WHEEL][Rotate Counter Clockwise 2] Start !\n");
  
  force_zero_cali();

  int falseCount = 0;
  bool previousState = Glv.get_glv_l();

  digitalWrite(MOTOR_R, LOW);
  while(true){
    bool currentState = Glv.get_glv_l();

    digitalWrite(MOTOR_L, HIGH); delay(35);
    digitalWrite(MOTOR_L, LOW); delay(200);
    
    if(previousState && !currentState){
      falseCount++;
      delay(50);
    }
    if(falseCount >= steps) break;
    previousState = currentState;
  }
  
  Serial.print("[WHEEL][Rotate Counter Clockwise 2] Finish !\n");
}


/**
 * @brief 懸空零點校正，使兩輪皆處於 false 狀態
 */
void WHEEL::zero_cali(){
  Serial.println("[WHEEL] Calibrating ...");
  
  // Right Side Calibration
  while(Glv.get_glv_r()){
    digitalWrite(MOTOR_R, HIGH); delay(4);
    digitalWrite(MOTOR_R, LOW); delay(100);
  }

  // Left Side Calibration
  while(Glv.get_glv_l()){
    digitalWrite(MOTOR_L, HIGH); delay(4);
    digitalWrite(MOTOR_L, LOW); delay(100);
  }

  Serial.println("[WHEEL] Calibration Done !");
}



/**
 * @brief 負載強制零點校正，使兩輪皆處於 false 狀態
 */
void WHEEL::force_zero_cali(){
  Serial.println("[WHEEL] Force Calibrating ...");
  
  // Right Side Calibration
  while(Glv.get_glv_r()){
    digitalWrite(MOTOR_R, HIGH); delay(35);
    digitalWrite(MOTOR_R, LOW); delay(300);
  }

  // Left Side Calibration
  while(Glv.get_glv_l()){
    digitalWrite(MOTOR_L, HIGH); delay(35);
    digitalWrite(MOTOR_L, LOW); delay(300);
  }

  Serial.println("[WHEEL] Force Calibration Done !");
}