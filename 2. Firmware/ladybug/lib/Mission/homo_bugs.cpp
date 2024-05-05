#include <homo_bugs.h>

#include <Arduino.h>
#include <iostream> 

#include <bugs.h>
#include <wheel.h>
#include <actuator.h>

HOMO_BUGS Homo_bugs;

/**
 * @brief 瓢蟲任務劇本，檢錄避障版本 
 */
void HOMO_BUGS::ID_1_run(int color){
  Serial.print("\n[MISSION][HOMO] ID 1 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION][HOMO] COLOR: Yellow\n");
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION][HOMO] COLOR: Blue\n");
    return;
  }

  return;
}


void HOMO_BUGS::ID_2_run(int color){
  Serial.println("\n[MISSION][HOMO] ID 2 Run !!\n");
  if(color == _YELLOW){
    Serial.print("[MISSION][HOMO] COLOR: Yellow\n");
    Wheel.moveDirect(3, false);
    Wheel.rotateClockwise(3, false);
    Wheel.rotateCounterClockwise(3, false);

    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION][HOMO] COLOR: Blue\n");
    return;
  }

  
  return;
}

void HOMO_BUGS::ID_3_run(int color){
  Serial.println("\n[MISSION][HOMO] ID 3 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION][HOMO] COLOR: Yellow\n");

    Wheel.zero_cali();
    Wheel.moveDirect2(1.2);
    Wheel.rotateClockwise2(4);
    Wheel.moveDirect2(0.4);
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION][HOMO] COLOR: Blue\n");
    return;
  }

  
  return;
}

void HOMO_BUGS::ID_4_run(int color){
  Serial.println("\n[MISSION][HOMO] ID 3 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION][HOMO] COLOR: Yellow\n");
    Wheel.zero_cali();

    Wheel.moveDirect(5, false);
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION][HOMO] COLOR: Blue\n");

    Wheel.zero_cali();
    Wheel.moveDirect2(1.2);
    Wheel.rotateClockwise2(4);
    Wheel.moveDirect2(0.4);

    return;
  }

  
  return;
}

void HOMO_BUGS::ID_5_run(int color){
  Serial.println("\n[MISSION][HOMO] ID 5 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION][HOMO] COLOR: Yellow\n");

    Wheel.moveDirect(5, true);
    Wheel.rotateClockwise(4, true);
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION][HOMO] COLOR: Blue\n");
    return;
  }

  
  return;
}

void HOMO_BUGS::ID_6_run(int color){
  Serial.println("\n[MISSION][HOMO] ID 6 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION][HOMO] COLOR: Yellow\n");

    Wheel.moveDirect(2, true);
    Wheel.rotateClockwise(2, true);
    Wheel.rotateCounterClockwise(2, true);
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION][HOMO] COLOR: Blue\n");
    Wheel.moveDirect(10, true);
    return;
  }

  
  return;
}

void HOMO_BUGS::ID_7_run(int color){
  Serial.println("\n[MISSION][HOMO] ID 7 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION][HOMO] COLOR: Yellow\n");
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION][HOMO] COLOR: Blue\n");
    return;
  }

  
  return;
}

void HOMO_BUGS::ID_8_run(int color){
  Serial.println("\n[MISSION][HOMO] ID 8 Run !!\n");
  
  if(color == _YELLOW){
    Serial.print("[MISSION][HOMO] COLOR: Yellow\n");
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION][HOMO] COLOR: Blue\n");
    return;
  }

  
  return;
}

void HOMO_BUGS::ID_9_run(int color){
  Serial.println("\n[MISSION][HOMO] ID 9 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION][HOMO] COLOR: Yellow\n");
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION][HOMO] COLOR: Blue\n");
    return;
  }

  
  return;
}

void HOMO_BUGS::ID_10_run(int color){
  Serial.println("\n[MISSION][HOMO] ID 10 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION][HOMO] COLOR: Yellow\n");

    // Wheel.moveDirect(3, false);
    Wheel.rotateClockwise(3, false);
    Wheel.rotateCounterClockwise(3, true);
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION][HOMO] COLOR: Blue\n");

    Wheel.moveDirect(13, false);
    return;
  }

  
  return;
}

void HOMO_BUGS::ID_11_run(int color){
  Serial.println("\n[MISSION][HOMO] ID 11 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION][HOMO] COLOR: Yellow\n");

    Wheel.moveDirect(5, true);
    Wheel.rotateClockwise(4, true);
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION][HOMO] COLOR: Blue\n");
    return;
  }

  
  return;
}

void HOMO_BUGS::ID_12_run(int color){
  Serial.println("\n[MISSION][HOMO] ID 12 Run !!\n");

  if(color == _YELLOW){
    Serial.print("[MISSION][HOMO] COLOR: Yellow\n");

    Wheel.moveDirect(5, true);
    Wheel.rotateClockwise(4, true);
    return;
  }

  if(color == _BLUE){
    Serial.print("[MISSION][HOMO] COLOR: Blue\n");
    return;
  }

  
  return;
}