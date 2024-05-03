#ifndef _MISSION_H_
#define _MISSION_H_

#include <Arduino.h>
#include <bugs.h>

class MISSION{
public:
  MISSION(int id, int color): _id(id), _color(color) {};

  void run();

private:
  int _id;
  int _color;
};

extern MISSION Mission;

#endif