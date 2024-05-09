#include <actuator.h>

SERVO ESP_Servo(GPIO4);

/**
 * @brief 檢查 SERVO 連接狀態
 */
void SERVO::attach_check(){
  if (!esp_servo.attached()) {
		esp_servo.setPeriodHertz(50);
		esp_servo.attach(pin, 1000, 2000);
	}
}


/**
 * @brief 設定 SERVO 角度
 * @param angle 目標角度 (degree)
 */
void SERVO::moveTo(const float angle){
  esp_servo.write(angle);
  attach_check();
} 


/**
 * @brief 初始化為 0 度
 */
void SERVO::setup(){
  esp_servo.write(90);
  return;
}