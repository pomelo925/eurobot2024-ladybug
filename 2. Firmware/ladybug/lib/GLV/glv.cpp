#include <glv.h>
#include <Arduino.h>

GLV Glv;


/**
 * @brief 取得左邊光閘
 * @return true 代表光閘被遮蔽，false 則沒有
 */
bool GLV::get_glv_l(){
  return digitalRead(_GLV_PIN_L);
}


/**
 * @brief 取得右邊光閘
 * @return true 代表光閘被遮蔽，false 則沒有
 */
bool GLV::get_glv_r(){
  return digitalRead(_GLV_PIN_R);
}


/**
 * @brief  初始化 GLV
 */
void GLV::setup() {
  pinMode(_GLV_PIN_R, INPUT);
  pinMode(_GLV_PIN_L, INPUT);
}


/**
 * @brief  列印 GLV 資訊
 */
void GLV::read() {
  Serial.print("Right: ");
  Serial.print(digitalRead(_GLV_PIN_R));
  Serial.print(" Left: ");
  Serial.println(digitalRead(_GLV_PIN_L));
}
