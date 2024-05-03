#include <Arduino.h>
#include <iostream> 

#include <bugs.h>
#include <wheel.h>
#include <actuator.h>

BUGS Bugs;

/**
 * @brief 瓢蟲任務劇本
 */
void BUGS::ID_1_run(int color){
  Serial.println("\n[MISSION] ID 1 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirect(5);
    Wheel.rotateClockwise(1);
    Wheel.rotateCounterClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  if(color == _BLUE){
    Wheel.moveDirect(5);
    Wheel.rotateCounterClockwise(1);
    Wheel.rotateClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  Serial.print("\n[MISSION][E] No such color\n");
  return;
}


void BUGS::ID_2_run(int color){
  Serial.println("\n[MISSION] ID 2 Run !!\n");
  if(color == _YELLOW){
    Wheel.moveDirect(5);
    Wheel.rotateClockwise(1);
    Wheel.rotateCounterClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  if(color == _BLUE){
    Wheel.moveDirect(5);
    Wheel.rotateCounterClockwise(1);
    Wheel.rotateClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  Serial.print("\n[MISSION][E] No such color\n");
  return;
}

void BUGS::ID_3_run(int color){
  Serial.println("\n[MISSION] ID 3 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirect(5);
    Wheel.rotateClockwise(1);
    Wheel.rotateCounterClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  if(color == _BLUE){
    Wheel.moveDirect(5);
    Wheel.rotateCounterClockwise(1);
    Wheel.rotateClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  Serial.print("\n[MISSION][E] No such color\n");
  return;
}

void BUGS::ID_4_run(int color){
  Serial.println("\n[MISSION] ID 3 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirect(5);
    Wheel.rotateClockwise(1);
    Wheel.rotateCounterClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  if(color == _BLUE){
    Wheel.moveDirect(5);
    Wheel.rotateCounterClockwise(1);
    Wheel.rotateClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  Serial.print("\n[MISSION][E] No such color\n");
  return;
}

void BUGS::ID_5_run(int color){
  Serial.println("\n[MISSION] ID 5 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirect(5);
    Wheel.rotateClockwise(1);
    Wheel.rotateCounterClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  if(color == _BLUE){
    Wheel.moveDirect(5);
    Wheel.rotateCounterClockwise(1);
    Wheel.rotateClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  Serial.print("\n[MISSION][E] No such color\n");
  return;
}

void BUGS::ID_6_run(int color){
  Serial.println("\n[MISSION] ID 6 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirect(5);
    Wheel.rotateClockwise(1);
    Wheel.rotateCounterClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  if(color == _BLUE){
    Wheel.moveDirect(5);
    Wheel.rotateCounterClockwise(1);
    Wheel.rotateClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  Serial.print("\n[MISSION][E] No such color\n");
  return;
}

void BUGS::ID_7_run(int color){
  Serial.println("\n[MISSION] ID 7 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirect(5);
    Wheel.rotateClockwise(1);
    Wheel.rotateCounterClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  if(color == _BLUE){
    Wheel.moveDirect(5);
    Wheel.rotateCounterClockwise(1);
    Wheel.rotateClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  Serial.print("\n[MISSION][E] No such color\n");
  return;
}

void BUGS::ID_8_run(int color){
  Serial.println("\n[MISSION] ID 8 Run !!\n");
  
  if(color == _YELLOW){
    Wheel.moveDirect(5);
    Wheel.rotateClockwise(1);
    Wheel.rotateCounterClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  if(color == _BLUE){
    Wheel.moveDirect(5);
    Wheel.rotateCounterClockwise(1);
    Wheel.rotateClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  Serial.print("\n[MISSION][E] No such color\n");
  return;
}

void BUGS::ID_9_run(int color){
  Serial.println("\n[MISSION] ID 9 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirect(5);
    Wheel.rotateClockwise(1);
    Wheel.rotateCounterClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  if(color == _BLUE){
    Wheel.moveDirect(5);
    Wheel.rotateCounterClockwise(1);
    Wheel.rotateClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  Serial.print("\n[MISSION][E] No such color\n");
  return;
}

void BUGS::ID_10_run(int color){
  Serial.println("\n[MISSION] ID 10 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirect(5);
    Wheel.rotateClockwise(1);
    Wheel.rotateCounterClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  if(color == _BLUE){
    Wheel.moveDirect(5);
    Wheel.rotateCounterClockwise(1);
    Wheel.rotateClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  Serial.print("\n[MISSION][E] No such color\n");
  return;
}

void BUGS::ID_11_run(int color){
  Serial.println("\n[MISSION] ID 11 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirect(5);
    Wheel.rotateClockwise(1);
    Wheel.rotateCounterClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  if(color == _BLUE){
    Wheel.moveDirect(5);
    Wheel.rotateCounterClockwise(1);
    Wheel.rotateClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  Serial.print("\n[MISSION][E] No such color\n");
  return;
}

void BUGS::ID_12_run(int color){
  Serial.println("\n[MISSION] ID 12 Run !!\n");

  if(color == _YELLOW){
    Wheel.moveDirect(5);
    Wheel.rotateClockwise(1);
    Wheel.rotateCounterClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  if(color == _BLUE){
    Wheel.moveDirect(5);
    Wheel.rotateCounterClockwise(1);
    Wheel.rotateClockwise(1);
    ESP_Servo.moveTo(40);
    delay(1000);
    ESP_Servo.moveTo(120);
    return;
  }

  Serial.print("\n[MISSION][E] No such color\n");
  return;
}