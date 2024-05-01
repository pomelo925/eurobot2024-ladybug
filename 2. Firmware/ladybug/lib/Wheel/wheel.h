#ifndef _WHEEL_H_
#define _WHEEL_H_

#define DIGITAL_GPIO_05 5
#define DIGITAL_GPIO_16 16

#define WHEEL_PRINT true

class WHEEL{
public:
  void moveDirect(float time);
  void rotateClockwise(float time);
  void rotateCounterClockwise(float time);
  bool checkObstacle();

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
