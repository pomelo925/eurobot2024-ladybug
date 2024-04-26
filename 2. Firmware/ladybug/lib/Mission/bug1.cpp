#include <Arduino.h>

#include <bug1.h>
#include <iostream>

#include <wheel.h>
#include <actuator.h>

Bug1StateMachine Bug1;

/**
 * @brief 連結各 STATE 與其對應 FUNCTION
 */
void Bug1StateMachine::setup(){
  setStateMap(_STATE_ONE, std::bind(&Bug1StateMachine::_action_1, this));
  setStateMap(_STATE_TWO, std::bind(&Bug1StateMachine::_action_2, this));
  setStateMap(_STATE_THREE, std::bind(&Bug1StateMachine::_action_3, this));
  
  _currentState=_STATE_ONE;
}

// 走到目標點
void Bug1StateMachine::_action_1(){
  Serial.println("== [BUG1] Action 1 ==");

  Wheel.moveDirect(2,1);
  Wheel.rotateClockwise(2,1);
  Wheel.moveDirect(3,1);

  _currentState = _STATE_TWO;
}


// 任務
void Bug1StateMachine::_action_2(){
  Serial.println("== [BUG1] Action 2 == ");

  ESP_Servo.moveTo(90,45);
  
  _currentState = _STATE_THREE;
}


// 結束
void Bug1StateMachine::_action_3(){
  return;
}
