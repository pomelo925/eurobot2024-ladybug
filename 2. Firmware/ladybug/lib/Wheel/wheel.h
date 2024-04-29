#ifndef _WHEEL_H_
#define _WHEEL_H_

#define ANALOG_GPIO_0 0
#define DIGITAL_GPIO_16 16

class WHEEL{
public:
  void moveDirect(float time);
  void rotateClockwise(float time);
  void rotateCounterClockwise(float time);

  WHEEL(){
    setup();
  };

private:
// 速度控制內部參數 
  const int _DIGITAL_HALF_SEC_MS=30;
  
  void setup();
};

extern WHEEL Wheel;

#endif
