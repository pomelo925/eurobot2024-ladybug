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
    Wheel.moveDirect(20, false);
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
    Wheel.moveDirect2(20);
    return;
  }

}

void BUGS::ID_2_run(const int color){
  Serial.println("\n[MISSION] ID 2 Run !!\n");
  if(color == _YELLOW){
    Serial.print("[MISSION] COLOR: Yellow\n");
    Wheel.moveDirect2(20);

    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
    Wheel.moveDirect2(20);
    return;
  }

}

void BUGS::ID_3_run(const int color){
  Serial.println("\n[MISSION] ID 3 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION] COLOR: Yellow\n");
    Wheel.moveDirect(12, false);
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
    Wheel.moveDirect2(20);
    return;
  }

}

void BUGS::ID_4_run(const int color){
  Serial.println("\n[MISSION] ID 3 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION] COLOR: Yellow\n");
    Wheel.moveDirect(12, false);
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
    Wheel.moveDirect2(20);
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
    Wheel.moveDirect(15, true);
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
    Wheel.moveDirect(15, true);
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

  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
    Wheel.moveDirect2(20);
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

  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
    Wheel.moveDirect(20, false);
    return;
  }

}

void BUGS::ID_10_run(const int color){
  Serial.println("\n[MISSION] ID 10 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION] COLOR: Yellow\n");

    // Wheel.moveDirect(3, false);
    Wheel.rotateClockwise(3, false);
    Wheel.rotateCounterClockwise(3, true);
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

    Wheel.moveDirect(5, true);
    Wheel.rotateClockwise(4, true);
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION] COLOR: Blue\n");
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

    Wheel.moveDirect(2, true);

    return;
  }

}