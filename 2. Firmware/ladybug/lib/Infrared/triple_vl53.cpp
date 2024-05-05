#include <stdint.h>
#include <Adafruit_VL53L0X.h>
#include <triple_vl53.h>

TRIPLE_VL53 Triple_vl53;


/**
 * @brief 分配 VL53L0X 的 ID/address
 */
void TRIPLE_VL53::setID(){
  for (int i = 0; i < 3; i++) digitalWrite(SHT_LOX[i], LOW);    
  delay(10);
  for (int i = 0; i < 3; i++) digitalWrite(SHT_LOX[i], HIGH);    
  delay(10);

  // activating LOX1 and reseting LOX2
  digitalWrite(SHT_LOX[0], HIGH);
  for (int i = 1; i < 3; i++) digitalWrite(SHT_LOX[i], LOW); 
  delay(10); 
  if(!lox1.begin(LOX1_ADDRESS)) Serial.println(F("[TRIPLE_VL53] Failed to boot VL53L0X [0]"));
  else Serial.println(F("[TRIPLE_VL53] VL53_0 set ID done."));

  // activating LOX2
  digitalWrite(SHT_LOX[1], HIGH);
  delay(10);
  if(!lox2.begin(LOX2_ADDRESS)) Serial.println(F("[TRIPLE_VL53] Failed to boot VL53L0X [1]"));
  else Serial.println(F("[TRIPLE_VL53] VL53_1 set ID done."));  

  // activating LOX3
  digitalWrite(SHT_LOX[2], HIGH);
  delay(10);
  if(!lox3.begin(LOX3_ADDRESS)) Serial.println(F("[TRIPLE_VL53] Failed to boot VL53L0X [2]"));
  else Serial.println(F("[TRIPLE_VL53] VL53_2 set ID done."));

}


/**
 * @brief Vl530X 初始化
 */
void TRIPLE_VL53::setup() {
  for (int i = 0; i < 3; i++)  pinMode(SHT_LOX[i], OUTPUT);
  for (int i = 0; i < 3; i++)  digitalWrite(SHT_LOX[i], LOW);
  
  setID();
}


/**
 * @brief Vl530X 讀取距離
 */
void TRIPLE_VL53::read() {
  for (int i = 0; i < 3; i++) is_out_of_range[i] = 0;
  lox1.rangingTest(&measure1, false); // pass in 'true' to get debug data printout!
  lox2.rangingTest(&measure2, false); // pass in 'true' to get debug data printout!
  lox3.rangingTest(&measure3, false); // pass in 'true' to get debug data printout!
  
  // print sensor one reading
  if(measure1.RangeStatus != 4) {     // if not out of range
    if (measure1.RangeMilliMeter > 0) VL53_data[0] = measure1.RangeMilliMeter;
    else is_out_of_range[0] = 1;
  } else is_out_of_range[0] = 1;
  
  // print sensor two reading
  if(measure2.RangeStatus != 4) {     // if not out of range
    if (measure2.RangeMilliMeter > 0) VL53_data[1] = measure2.RangeMilliMeter;
    else is_out_of_range[1] = 1;
  } else is_out_of_range[1] = 1;

  // print sensor three reading
  if(measure3.RangeStatus != 4) {     // if not out of range
    if (measure3.RangeMilliMeter > 0) VL53_data[2] = measure3.RangeMilliMeter;
    else is_out_of_range[2] = 1; 
  } else is_out_of_range[2] = 1;
}


/**
 * @brief 列印三個 VL53L0X 的距離
 */
  void TRIPLE_VL53::print() {
  for (int i=2; i>=0; i--) {   
      Serial.print(VL53_data[i]);
      if(i) Serial.print(F(":"));
  }
  Serial.println();
}


/**
 * @brief  檢查是否有障礙物
 * @return true 表示有障礙物
 */
bool TRIPLE_VL53::checkObstacle() {
  Triple_vl53.read();
  // Triple_vl53.print();

  if(is_out_of_range[0] and is_out_of_range[1] and is_out_of_range[2]) return false;
  
  for (auto &value : Triple_vl53.VL53_data) {
    if (value >= 0 && value <= 200) return true;
  }

  return false;
}

