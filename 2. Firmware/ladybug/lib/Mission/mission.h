#ifndef _MISSION_H_
#define _MISSION_H_

#include <Arduino.h>
#include <bugs.h>

class MISSION{
public:
  MISSION(int id): _id(id) {};

  void run();

private:
  int _id;
};

extern MISSION Mission;

#endif