#ifndef _WHEEL_H_
#define _WHEEL_H_

#define MOTOR_L 5
#define MOTOR_R 16

#define WHEEL_PRINT true

class WHEEL{
public:
  void moveDirect(float time);
  void rotateClockwise(float time);
  void rotateCounterClockwise(float time);

  void moveDirect2(float dist);
  void rotateClockwise2(float angle);
  void rotateCounterClockwise2(float angle);

  void zero_cali();
  bool checkObstacle();

  WHEEL(){ 
    setup();
  };

private:
  static constexpr float _wheel_radius = 0.21; // meter
  static constexpr float _wheel_perimeter = 2 * 3.14159 * _wheel_radius;

  static constexpr int _checkpoint_steps = 12; // calib every 4 steps

  void setup();
  void stepsCheckpoint(int _checkpoint_steps);
};

extern WHEEL Wheel;

#endif
