#ifndef _0_STATEMACHINE_H_
#define _0_STATEMACHINE_H_

#include <map>
#include <functional>

class StateMachine {
public:
  void update(){
    _stateMap[_currentState]();
  }

protected:
  enum State {
    _STATE_ONE,
    _STATE_TWO,
    _STATE_THREE
  };

  State _currentState=_STATE_ONE;
  std::map<State, std::function<void()>> _stateMap;

  virtual void _action_1(){}
  virtual void _action_2(){}
  virtual void _action_3(){}

  void setStateMap(State state, std::function<void()> func){
    _stateMap[state] = func;
  }

};

#endif