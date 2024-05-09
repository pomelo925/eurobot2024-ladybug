#ifndef _WHEEL_H_
#define _WHEEL_H_

#define MOTOR_L 5
#define MOTOR_R 16

class WHEEL{
public:
  void moveDirect_time(const float time);
  void moveDirectAvoid_time(const float time, const bool single_vl53);
  void rotateClockwiseAvoid_tripleVL53_time(const float time);
  void rotateCounterClockwiseAvoid_tripleVL53_time(const float time);

  void moveDirect_glv_time(const float time);
  void rotateClockwiseAvoid_tripleVL53_glv_steps(const int steps);
  void rotateCounterClockwiseAvoid_tripleVL53_glv_steps(const int steps);

  void moveDirectAvoid_singleVL53_glv_time(const float time);
  void moveDirectAvoid_tripleVL53_glv_time(const float time);

  void zero_cali();
  void force_zero_cali();
  
  void setup();

private:
  const bool _obstacle_avoidance = true;
};

extern WHEEL Wheel;

#endif
