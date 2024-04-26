#include <actuator.h>


void SERVO::attach_check(){
  if (!esp_servo.attached()) {
		esp_servo.setPeriodHertz(50);
		esp_servo.attach(pin, 1000, 2000);
	}
}


void SERVO::vel_update(){
  unsigned long currentTime = millis();
  float timeDifference = (currentTime - lastUpdateTime) / 1000.0; // convert to seconds

  if (timeDifference > 0) {
    float angleToMove = speed * timeDifference;
    
    if (currentAngle + angleToMove >= targetAngle) currentAngle = targetAngle;
    else currentAngle += angleToMove;
    
    esp_servo.write(currentAngle);
    lastUpdateTime = currentTime;
  }
}


/**
 * @brief 設定 SERVO 角度
 * @param angle 目標角度 (degree)
 * @param speed 旋轉速度 (deg/sec)
 */
void SERVO::moveTo(float angle, float speed){
  attach_check();

  this->targetAngle = angle;
  this->speed = speed;

  vel_update();
}

SERVO ESP_Servo(GPIO4);