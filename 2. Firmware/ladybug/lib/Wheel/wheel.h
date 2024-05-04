#ifndef _WHEEL_H_
#define _WHEEL_H_

#define MOTOR_L 5
#define MOTOR_R 16

class WHEEL{
public:
  void moveDirect(float time, bool single_vl53);
  void rotateClockwise(float time, bool single_vl53);
  void rotateCounterClockwise(float time, bool single_vl53);


  void moveDirect2(float dist);
  void rotateClockwise2(int steps);
  void rotateCounterClockwise2(int steps);

  void zero_cali();
  bool checkObstacle();
  
  void setup();

private:
  const bool _obstacle_avoidance = true;
  static constexpr float _wheel_radius = 0.021; // meter
  static constexpr float _wheel_perimeter = 2 * 3.14159 * _wheel_radius;
};

extern WHEEL Wheel;

#endif
