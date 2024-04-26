#include <Arduino.h>
#include <mission.h>

/**
 * @brief 根據 _id 執行對應 Bug 任務
 */
void MISSION::run(){
  switch(_id) {
    case 1: 
      Bug1.update(); break;
    default:
      Serial.println("[MISSION][E] No such BugID");
  }
}

