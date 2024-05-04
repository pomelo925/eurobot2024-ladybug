#include <single_vl53.h>

SINGLE_VL53 Single_vl53;


/**
 * @brief Vl530X 初始化
 */
void SINGLE_VL53::setup(){
  if(!lox.begin()) Serial.println(F("[SINGLW_VL53][E] Failed to boot VL53L0X !"));
  else Serial.println(F("[SINGLW_VL53] VL53 set ID done."));
  
  lox.startRangeContinuous();
}


/**
 * @brief Vl530X 讀值
 * @return 距離，-1 表示無資訊
 */
int SINGLE_VL53::read(){
  if(lox.isRangeComplete()) return VL53_data=lox.readRange();
  else return -1;
}


/**
 * @brief  檢查是否有障礙物
 * @return true 表示有障礙物
 */
bool SINGLE_VL53::checkObstacle() {
  const int val = read();

  if(val>0 and val<=200) return true;
  return false;
}

