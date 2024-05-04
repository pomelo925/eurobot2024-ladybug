#ifndef _TRIPLE_VL53_H_
#define _TRIPLE_VL53_H_

#include <stdint.h>
#include <Adafruit_VL53L0X.h>

class TRIPLE_VL53 {
public:
    void setID();
    void setup();
    void read();
    void print();
    bool checkObstacle();

private:
    const int SHT_LOX[3] = {25, 27, 32};
    static const uint8_t LOX1_ADDRESS = 0x30;
    static const uint8_t LOX2_ADDRESS = 0x31;
    static const uint8_t LOX3_ADDRESS = 0x32;

    int VL53_data[3], VL53_flag[3] = {1}, is_out_of_range[3] = {0}, ReadBefore = 0, closest_num = 0, stop_flag = 0, go_flag = -2;
    int Is2ndMode, BugNum;

    Adafruit_VL53L0X lox1;
    Adafruit_VL53L0X lox2;
    Adafruit_VL53L0X lox3;
    VL53L0X_RangingMeasurementData_t measure1;
    VL53L0X_RangingMeasurementData_t measure2;
    VL53L0X_RangingMeasurementData_t measure3;
};

extern TRIPLE_VL53 Triple_vl53;

#endif