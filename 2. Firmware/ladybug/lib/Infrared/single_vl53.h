#ifndef _SINGLE_VL53_H_
#define _SINGLE_VL53_H_

#include <stdint.h>
#include <Adafruit_VL53L0X.h>

class SINGLE_VL53 {
public:
  void setup();
  uint16_t read();
  bool checkObstacle();

private:
  int VL53_data;
  Adafruit_VL53L0X lox;
};

extern SINGLE_VL53 Single_vl53;


#endif