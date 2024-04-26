#ifndef _BUG1_H_
#define _BUG1_H_

#include "0_stateMachine.h"

class Bug1StateMachine : public StateMachine {
public:
  Bug1StateMachine(){
    setup();
  };

protected:
  void setup();
  void _action_1() override;
  void _action_2() override;
  void _action_3() override;
};

extern Bug1StateMachine Bug1;

#endif