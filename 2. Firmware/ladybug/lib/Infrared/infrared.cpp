#include <stdint.h>
#include <infrared.h>
#include "Adafruit_VL53L0X.h"

#define stop_dst 50
#define final_dst 100

// address we will assign if dual sensor is present
#define LOX1_ADDRESS 0x30
#define LOX2_ADDRESS 0x31
#define LOX3_ADDRESS 0x32

// objects for the vl53l0x
Adafruit_VL53L0X lox1 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox2 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox3 = Adafruit_VL53L0X();
// this holds the measurement
VL53L0X_RangingMeasurementData_t measure1;
VL53L0X_RangingMeasurementData_t measure2;
VL53L0X_RangingMeasurementData_t measure3;

const int SHT_LOX[3] = {27, 25, 32}; // 0是右邊
int VL53_data[3], VL53_flag[3] = {1}, out_of_range[3] = {0}, ReadBefore = 0, closest_num = 0, stop_flag = 0, go_flag = -2;
extern int Is2ndMode, BugNum;


void setID() {
  int i;

  // all reset
  Serial.println(F("VL53 set ID test 1."));
  for ( i = 0; i < 3; i++) digitalWrite(SHT_LOX[i], LOW);    
  delay(10);
  // all unreset
  Serial.println(F("VL53 set ID test 2."));
  for ( i = 0; i < 3; i++) digitalWrite(SHT_LOX[i], HIGH);    
  delay(10);
  // activating LOX1 and reseting LOX2
  Serial.println(F("VL53 set ID test 3."));

  digitalWrite(SHT_LOX[0], HIGH);
  for ( i = 1; i < 3; i++) digitalWrite(SHT_LOX[i], LOW); 
  delay(10);   
  // initing LOX1
  Serial.println(F("VL53 set ID test 4."));
  if(!lox1.begin(LOX1_ADDRESS)) {
    Serial.println(F("Failed to boot first VL53L0X"));
    while(1);
  }
  ///************************* sensor 2 activation 
  // activating LOX2
  Serial.println(F("VL53 set ID test 5."));
  digitalWrite(SHT_LOX[1], HIGH);
  delay(10);
  //initing LOX2
  Serial.println(F("VL53 set ID test 6."));
  if(!lox2.begin(LOX2_ADDRESS)) {
    Serial.println(F("Failed to boot second VL53L0X"));
    while(1);
  }
  // activating LOX3
  Serial.println(F("VL53 set ID test 7."));
  digitalWrite(SHT_LOX[2], HIGH);
  delay(10);
  //initing LOX3
  Serial.println(F("VL53 set ID test 8."));
  if(!lox3.begin(LOX3_ADDRESS)) {
    Serial.println(F("Failed to boot third VL53L0X"));
    while(1);
  }  
  Serial.println(F("VL53 set ID done."));
}

void VL53_setup() {
  int i;
  for ( i = 0; i < 3; i++)  pinMode(SHT_LOX[i], OUTPUT);
  Serial.println("Shutdown pins inited...");
  for ( i = 0; i < 3; i++)  digitalWrite(SHT_LOX[i], LOW);
  Serial.println("All in reset mode...(pins are low)");
  Serial.println(F("VL53 set ID start."));
  setID();
  /*Ranging Profile:
    VL53L0X_SENSE_DEFAULT
    VL53L0X_SENSE_LONG_RANGE
    VL53L0X_SENSE_HIGH_SPEED
    VL53L0X_SENSE_HIGH_ACCURACY
  */
  // lox1.configSensor(Adafruit_VL53L0X::VL53L0X_SENSE_HIGH_SPEED);
  // lox2.configSensor(Adafruit_VL53L0X::VL53L0X_SENSE_HIGH_SPEED);
  // lox3.configSensor(Adafruit_VL53L0X::VL53L0X_SENSE_HIGH_SPEED);
}

void read_VL53s() {
  int i;
  for (i = 0; i < 3; i++) out_of_range[i] = 0;
  lox1.rangingTest(&measure1, false); // pass in 'true' to get debug data printout!
  lox2.rangingTest(&measure2, false); // pass in 'true' to get debug data printout!
  lox3.rangingTest(&measure3, false); // pass in 'true' to get debug data printout!
  // print sensor one reading
  if(measure1.RangeStatus != 4) {     // if not out of range
    if ((measure1.RangeMilliMeter -= 0) > 0) VL53_data[0] = measure1.RangeMilliMeter;
    else out_of_range[0] = 1;
    // VL53_data[0] = 0;
    // for (i = 0 ; i < 10; i++) {
    //   if ((measure1.RangeMilliMeter -= 0) > 0) VL53_data[0] += measure1.RangeMilliMeter;
    //   else {
    //     out_of_range[0] = 1;
    //     break;
    //   }
    // }    
    // VL53_data[0] /= 10;    
  } else out_of_range[0] = 1;
  // print sensor two reading
  if(measure2.RangeStatus != 4) {     // if not out of range
    if ((measure2.RangeMilliMeter -= 0) > 0) VL53_data[1] = measure2.RangeMilliMeter;
    else out_of_range[1] = 1;
    // VL53_data[1] = 0;
    // for (i = 0 ; i < 10; i++) {
    //   if ((measure2.RangeMilliMeter -= 0) > 0) VL53_data[1] += measure2.RangeMilliMeter;
    //   else {
    //     out_of_range[1] = 1;
    //     break;
    //   }
    // }    
    // VL53_data[1] /= 10;    
  } else out_of_range[1] = 1;
  // print sensor three reading
  if(measure3.RangeStatus != 4) {     // if not out of range
    if ((measure3.RangeMilliMeter -= 0) > 0) VL53_data[2] = measure3.RangeMilliMeter;
    else out_of_range[2] = 1;
    // VL53_data[2] = 0;
    // for (i = 0 ; i < 10; i++) {
    //   if ((measure3.RangeMilliMeter -= 0) > 0) VL53_data[2] += measure3.RangeMilliMeter;
    //   else {
    //     out_of_range[2] = 1;
    //     break;
    //   }
    // }    
    // VL53_data[2] /= 10;    
  } else out_of_range[2] = 1;
  ReadBefore = 1;
}

void print_VL53s() {
  // need to read before print
  if (ReadBefore) 
    for (int i = 0; i < 3; i++) {
      Serial.print(i+1);
      Serial.print(F(": "));
      if(VL53_data[i] > 0 && VL53_data[i] < 8191 && !out_of_range[i]) {     // if not out of range   
        Serial.print(VL53_data[i]);
        Serial.print(F("mm\t"));    
        if(VL53_data[i] < 100) Serial.print(F("\t"));
      } else {
        Serial.print(F("Out of range\t"));
      }
      if(i == 2) Serial.println();
    }
}

void VL53_avoid (int flag[3]){
  for(int i = 0; i < 3 && flag[i]; i++) {
    if (!Is2ndMode) {
      if (VL53_data[0] < stop_dst && !out_of_range[0]) {
        stop_flag = 1;
      } else if (VL53_data[1] < stop_dst && !out_of_range[1]) {
        stop_flag = 1;
      } else if ((VL53_data[2]-20) < stop_dst && !out_of_range[2]) {
        stop_flag = 1;
      } else {
        stop_flag = 0;
      }
    } else {
      if (VL53_data[i] < final_dst) {
        stop_flag = 1;
      }
    }
  }
}

void VL53_closest() {
  int MinDst = 9999;
  for(int i = 0; i < 3; i++) {
    if (VL53_data[i] < MinDst) {
      MinDst = VL53_data[i];
      closest_num = i;
    } 
    // else if (VL53_data[i] == MinDst) (如果要再加兩個方向)
  }
}

void VL53_control (){
  // Serial.println("VL53_control start");
  read_VL53s();
  VL53_avoid(VL53_flag);
  while(Serial.available() > 0) Serial.read();
  print_VL53s();
  // Serial.println("VL53_control end");
}