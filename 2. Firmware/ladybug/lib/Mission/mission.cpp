#include <Arduino.h>
#include <mission.h>

/**
 * @brief 根據 _id 執行對應 Bug 任務
 */
void MISSION::run(){
  switch(_id) {
  case 1: 
    Bugs.ID_1_run(); break;
  case 2:
    Bugs.ID_2_run(); break;
  case 3: 
    Bugs.ID_3_run(); break;
  case 4:
    Bugs.ID_4_run(); break;
  case 5: 
    Bugs.ID_5_run(); break;
  case 6:
    Bugs.ID_6_run(); break;
  case 7: 
    Bugs.ID_7_run(); break;
  case 8:
    Bugs.ID_8_run(); break;
  case 9: 
    Bugs.ID_9_run(); break;
  case 10:
    Bugs.ID_10_run(); break;
  case 11: 
    Bugs.ID_11_run(); break;
  case 12:
    Bugs.ID_12_run(); break;
  default:
    Serial.println("[MISSION][E] No such BugID");
  }
}

