#include <Arduino.h>
#include <mission.h>
#include <triple_vl53.h>

/**
 * @brief 根據 _id 執行對應 Bugs 任務
 */
void MISSION::run(){
  switch(_id) {
  case 1: 
    Triple_vl53.setup();
    Bugs.ID_1_run(_color); break;

  case 2:
    Triple_vl53.setup();
    Bugs.ID_2_run(_color); break;

  case 3: 
    Triple_vl53.setup();
    Bugs.ID_3_run(_color); break;

  case 4:
    Triple_vl53.setup();
    Bugs.ID_4_run(_color); break;

  case 5: 
    Triple_vl53.singleSetup();
    Bugs.ID_5_run(_color); break;

  case 6:
    Triple_vl53.singleSetup();
    Bugs.ID_6_run(_color); break;

  case 7: 
    Triple_vl53.setup();
    Bugs.ID_7_run(_color); break;

  case 8:
    Triple_vl53.setup();
    Bugs.ID_8_run(_color); break;

  case 9: 
    Triple_vl53.setup();
    Bugs.ID_9_run(_color); break;

  case 10:
    Triple_vl53.setup();
    Bugs.ID_10_run(_color); break;

  case 11: 
    Triple_vl53.singleSetup();
    Bugs.ID_11_run(_color); break;

  case 12:
    Triple_vl53.singleSetup();
    Bugs.ID_12_run(_color); break;

  default:
    Serial.print("\n[MISSION][E] No such BugsID\n");
  }             
}

