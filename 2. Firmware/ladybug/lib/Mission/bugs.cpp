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
    Wheel.moveDirectAvoid2_tripleVL53(5.5);
    return;
  }

// OFFICIAL OK
  if(color == _BLUE){
    Wheel.moveDirectAvoid2_tripleVL53(5.5);
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
    Wheel.moveDirect2(6);
    return;
  }

// OFFICIAL OK
  if(color == _BLUE){
    Wheel.moveDirect2(6);
    return;
  }
}


void BUGS::ID_4_run(const int color){
  Serial.println("\n[MISSION] ID 3 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirectAvoid2_tripleVL53(5.5);
    return;
  }

// OFFICIAL OK
  if(color == _BLUE){
    Wheel.moveDirectAvoid2_tripleVL53(5.5);
    return;
  }
}


void BUGS::ID_5_run(const int color){
  Serial.println("\n[MISSION] ID 5 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirect(1.6);
    ESP_Servo.moveTo(10);
    return;
  }

// OFFICIAL OK
  if(color == _BLUE){
    Wheel.moveDirect(5);
    ESP_Servo.moveTo(10);
    return;
  }

}

void BUGS::ID_6_run(const int color){
  Serial.println("\n[MISSION] ID 6 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirect(3);
    ESP_Servo.moveTo(180);
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
     Wheel.moveDirect(1.2);
    ESP_Servo.moveTo(180);
    return;
  }

}

void BUGS::ID_7_run(const int color){
  Serial.println("\n[MISSION] ID 7 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirectAvoid(12, false);
    return;
  }

// OFFICIAL
  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
    Wheel.moveDirectAvoid2_tripleVL53(2);
    delay(1000);
    Wheel.rotateCounterClockwise(1.6);
    Wheel.moveDirectAvoid2_tripleVL53(2.5);
    return;
  }
}

void BUGS::ID_8_run(const int color){
  Serial.println("\n[MISSION] ID 8 Run !!\n");
  
  if(color == _YELLOW){
    return;
  }

// OFFICIAL WRITTEN
  if(color == _BLUE){
    Wheel.moveDirectAvoid2_tripleVL53(2);
    delay(1000);
    Wheel.rotateCounterClockwise(2);
    Wheel.moveDirectAvoid2_tripleVL53(1.8);
    delay(500);
    Wheel.rotateClockwise(0.3);
    Wheel.moveDirectAvoid2_tripleVL53(0.8);
    return;
  }

}

void BUGS::ID_9_run(const int color){
  Serial.println("\n[MISSION] ID 9 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirectAvoid2_tripleVL53(20);
    return;
  }

// OFFICIAL OK
  if(color == _BLUE){
    Wheel.moveDirectAvoid2_tripleVL53(1.3);
    Wheel.rotateCounterClockwise(1);
    Wheel.moveDirectAvoid2_tripleVL53(1.6);
    return;
  }
}

void BUGS::ID_10_run(const int color){
  Serial.println("\n[MISSION] ID 10 Run !!\n");

  if(color == _YELLOW){
    Wheel.rotateClockwise(3);
    Wheel.rotateCounterClockwise(3);
    return;
  }

  // OFFICIAL WRITTEN
  if(color == _BLUE){
    Wheel.rotateCounterClockwise(0.65);
    delay(500);
    Wheel.moveDirectAvoid2_tripleVL53(1.2);
    return;
  }

}

void BUGS::ID_11_run(const int color){
  Serial.println("\n[MISSION] ID 11 Run !!\n");

  if(color == _YELLOW){
    return;
  }

  if(color == _BLUE){
    Wheel.moveDirectAvoid(3, true);
    return;
  }

}

void BUGS::ID_12_run(const int color){
  Serial.println("\n[MISSION] ID 12 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirectAvoid(2, true);
    return;
  }

  if(color == _BLUE){
    Wheel.moveDirectAvoid(13, true);
    return;
  }

}