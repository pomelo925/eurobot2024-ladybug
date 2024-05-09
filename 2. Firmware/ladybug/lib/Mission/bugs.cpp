#include <Arduino.h>
#include <iostream> 

#include <bugs.h>
#include <wheel.h>
#include <actuator.h>

BUGS Bugs;

/**
 * @brief 瓢蟲任務劇本，正式比賽版本 
 */

void BUGS::ID_1_run(const int color){
  Serial.print("\n[MISSION] ID 1 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirect_glv_time(5.5);
    return;
  }

// OFFICIAL OK
  if(color == _BLUE){
    Wheel.moveDirect_glv_time(5.5);
    return;
  }

}


void BUGS::ID_2_run(const int color){
  Serial.println("\n[MISSION] ID 2 Run !!\n");

  if(color == _YELLOW){
    return;
  }

  if(color == _BLUE){
    return;
  }
}


void BUGS::ID_3_run(const int color){
  Serial.println("\n[MISSION] ID 3 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirect_glv_time(6);
    return;
  }

// OFFICIAL OK
  if(color == _BLUE){
    Wheel.moveDirect_glv_time(6);
    return;
  }
}


void BUGS::ID_4_run(const int color){
  Serial.println("\n[MISSION] ID 3 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirectAvoid_tripleVL53_glv_time(5.5);
    return;
  }

// OFFICIAL OK
  if(color == _BLUE){
    Wheel.moveDirectAvoid_tripleVL53_glv_time(5.5);
    return;
  }
}


void BUGS::ID_5_run(const int color){
  Serial.println("\n[MISSION] ID 5 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirect_time(1.6);
    ESP_Servo.moveTo(10);
    return;
  }

// OFFICIAL OK
  if(color == _BLUE){
    Wheel.moveDirect_time(5);
    ESP_Servo.moveTo(10);
    return;
  }

}

void BUGS::ID_6_run(const int color){
  Serial.println("\n[MISSION] ID 6 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirect_time(3);
    ESP_Servo.moveTo(180);
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
    Wheel.moveDirect_time(1.2);
    ESP_Servo.moveTo(180);
    return;
  }

}

void BUGS::ID_7_run(const int color){
  Serial.println("\n[MISSION] ID 7 Run !!\n");

  if(color == _YELLOW){
    return;
  }

  if(color == _BLUE){
    return;
  }
}

void BUGS::ID_8_run(const int color){
  Serial.println("\n[MISSION] ID 8 Run !!\n");
  
  if(color == _YELLOW){
    return;
  }

  if(color == _BLUE){
    return;
  }

}

void BUGS::ID_9_run(const int color){
  Serial.println("\n[MISSION] ID 9 Run !!\n");

  if(color == _YELLOW){
    return;
  }

  if(color == _BLUE){
    return;
  }
}

void BUGS::ID_10_run(const int color){
  Serial.println("\n[MISSION] ID 10 Run !!\n");

  if(color == _YELLOW){
    return;
  }

  if(color == _BLUE){
    return;
  }

}

void BUGS::ID_11_run(const int color){
  Serial.println("\n[MISSION] ID 11 Run !!\n");

  if(color == _YELLOW){
    return;
  }

  if(color == _BLUE){
    return;
  }

}

void BUGS::ID_12_run(const int color){
  Serial.println("\n[MISSION] ID 12 Run !!\n");

  if(color == _YELLOW){
    return;
  }

  if(color == _BLUE){
    return;
  }

}