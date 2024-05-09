#ifndef _WHEEL_H_
#define _WHEEL_H_

#define MOTOR_L 5
#define MOTOR_R 16

class WHEEL{
public:
  void moveDirect(const float time);
  void moveDirectAvoid(const float time, const bool single_vl53);
  void rotateClockwise(const float time);
  void rotateCounterClockwise(const float time);

  void moveDirect2(const float time);
  void rotateClockwise2(const int steps);
  void rotateCounterClockwise2(const int steps);

  void moveDirectAvoid2_singleVL53(const float time);
  void moveDirectAvoid2_tripleVL53(const float time);

  void zero_cali();
  void force_zero_cali();
  
  void setup();

private:
  const bool _obstacle_avoidance = true;
};

extern WHEEL Wheel;

#endif
