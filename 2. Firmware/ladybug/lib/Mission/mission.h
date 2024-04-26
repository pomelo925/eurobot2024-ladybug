#ifndef _MISSION_H_
#define _MISSION_H_

#include <Arduino.h>
#include <bug1.h>

class MISSION{
public:
  MISSION(int id): _id(id) {
    if(id==1) Bug1.update();
    else Serial.println("[MISSION][E] No such BugID");
  }

  void run();

private:
  int _id;
};

extern MISSION Mission;

#endif