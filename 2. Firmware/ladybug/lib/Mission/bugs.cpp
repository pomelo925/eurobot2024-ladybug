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
    Serial.print("[MISSION] COLOR: Yellow\n");
    return;
  }

// OFFICIAL
  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
    Wheel.moveDirect2(2);
    delay(1000);
    Wheel.rotateClockwise(1.6);
    Wheel.moveDirect2(2.5);
    return;
  }

}


void BUGS::ID_2_run(const int color){
  Serial.println("\n[MISSION] ID 2 Run !!\n");
  if(color == _YELLOW){
    Serial.print("[MISSION] COLOR: Yellow\n");
    Wheel.moveDirect2(0.04*3.1415926);

    return;
  }

// OFFICIAL OK
  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
    Wheel.moveDirect2(2);
    delay(1000);
    Wheel.rotateClockwise(2);
    Wheel.moveDirect2(1.8);
    delay(500);
    Wheel.rotateCounterClockwise(0.3);
    Wheel.moveDirect2(0.8);
    return;
  }
}


void BUGS::ID_3_run(const int color){
  Serial.println("\n[MISSION] ID 3 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION] COLOR: Yellow\n");
    Wheel.moveDirect2(30);
    return;
  }

// OFFICIAL OK
  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
    Wheel.moveDirect2(1.3);
    Wheel.rotateCounterClockwise(1);
    Wheel.moveDirect2(1.6);
    return;
  }
}


void BUGS::ID_4_run(const int color){
  Serial.println("\n[MISSION] ID 3 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION] COLOR: Yellow\n");
    return;
  }

// OFFICIAL OK
  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
    Wheel.rotateCounterClockwise(0.65);
    delay(500);
    Wheel.moveDirect2(1.2);
    return;
  }
}


void BUGS::ID_5_run(const int color){
  Serial.println("\n[MISSION] ID 5 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION] COLOR: Yellow\n");

    Wheel.moveDirect(5, true);
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
    Wheel.moveDirect(3, true);
    return;
  }

}

void BUGS::ID_6_run(const int color){
  Serial.println("\n[MISSION] ID 6 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION] COLOR: Yellow\n");

    Wheel.moveDirect(2, true);
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
    Wheel.moveDirect(3, true);
    return;
  }

}

void BUGS::ID_7_run(const int color){
  Serial.println("\n[MISSION] ID 7 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION] COLOR: Yellow\n");
    Wheel.moveDirect(12, false);
    return;
  }

// OFFICIAL
  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
    Wheel.moveDirect2(2);
    delay(1000);
    Wheel.rotateCounterClockwise(1.6);
    Wheel.moveDirect2(2.5);
    return;
  }
}

void BUGS::ID_8_run(const int color){
  Serial.println("\n[MISSION] ID 8 Run !!\n");
  
  if(color == _YELLOW){
    Serial.print("[MISSION] COLOR: Yellow\n");
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
    return;
  }

}

void BUGS::ID_9_run(const int color){
  Serial.println("\n[MISSION] ID 9 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION] COLOR: Yellow\n");
    Wheel.moveDirect2(20);
    return;
  }

// OFFICIAL OK
  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
    Wheel.moveDirect2(1.3);
    Wheel.rotateClockwise(1);
    Wheel.moveDirect2(1.6);
    return;
  }
}

void BUGS::ID_10_run(const int color){
  Serial.println("\n[MISSION] ID 10 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION] COLOR: Yellow\n");

    // Wheel.moveDirect(3, false);
    Wheel.rotateClockwise(3);
    Wheel.rotateCounterClockwise(3);
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");

    Wheel.moveDirect(13, false);
    return;
  }

}

void BUGS::ID_11_run(const int color){
  Serial.println("\n[MISSION] ID 11 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION] COLOR: Yellow\n");
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
    Wheel.moveDirect(3, true);
    return;
  }

}

void BUGS::ID_12_run(const int color){
  Serial.println("\n[MISSION] ID 12 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION] COLOR: Yellow\n");
    Wheel.moveDirect(2, true);
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
    Wheel.moveDirect(3, true);
    return;
  }

}