#include <Arduino.h>
#include <mission.h>
#include <triple_vl53.h>
#include <single_vl53.h>
#include <wheel.h>

/**
 * @brief 初始化不同 ID 的瓢蟲劇本
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
    Single_vl53.setup();
    Bugs.ID_4_run(_color); break;

  case 5: 
    Single_vl53.setup();
    Bugs.ID_5_run(_color); break;

  case 6:
    Single_vl53.setup();
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
    Single_vl53.setup();
    Bugs.ID_11_run(_color); break;

  case 12:
    Single_vl53.setup();
    Bugs.ID_12_run(_color); break;
    
  default:
    Serial.print("\n[MISSION][E] No such BugsID\n");
  }             
  
}

