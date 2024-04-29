#include <stdint.h>
#include <infrared.h>
#include "Adafruit_VL53L0X.h"

#define stop_dst 50
#define final_dst 100

VL53 vl53;

void VL53::setID(){
  // all reset
  // Serial.println(F("VL53 set ID test 1."));
  for (int i = 0; i < 3; i++) digitalWrite(SHT_LOX[i], LOW);    
  delay(10);

  // all unreset
  // Serial.println(F("VL53 set ID test 2."));
  for (int i = 0; i < 3; i++) digitalWrite(SHT_LOX[i], HIGH);    
  delay(10);

  // activating LOX1 and reseting LOX2
  // Serial.println(F("VL53 set ID test 3."));
  digitalWrite(SHT_LOX[0], HIGH);
  for (int i = 1; i < 3; i++) digitalWrite(SHT_LOX[i], LOW); 
  delay(10);   

  // initing LOX1
  // Serial.println(F("VL53 set ID test 4."));
  if(!lox1.begin(LOX1_ADDRESS)) {
    Serial.println(F("Failed to boot first VL53L0X"));
    while(1);
  }

  // activating LOX2
  // Serial.println(F("VL53 set ID test 5."));
  digitalWrite(SHT_LOX[1], HIGH);
  delay(10);

  //initing LOX2
  // Serial.println(F("VL53 set ID test 6."));
  if(!lox2.begin(LOX2_ADDRESS)) {
    Serial.println(F("Failed to boot second VL53L0X"));
    while(1);
  }

  // activating LOX3
  // Serial.println(F("VL53 set ID test 7."));
  digitalWrite(SHT_LOX[2], HIGH);
  delay(10);

  //initing LOX3
  // Serial.println(F("VL53 set ID test 8."));
  if(!lox3.begin(LOX3_ADDRESS)) {
    Serial.println(F("Failed to boot third VL53L0X"));
    while(1);
  }  
  Serial.println(F("VL53 set ID done."));
}

void VL53::setup() {
  for (int i = 0; i < 3; i++)  pinMode(SHT_LOX[i], OUTPUT);
  Serial.println("Shutdown pins inited...");
  for (int i = 0; i < 3; i++)  digitalWrite(SHT_LOX[i], LOW);
  // Serial.println("All in reset mode...(pins are low)");
  Serial.println(F("VL53 set ID start. "));
  setID();
}

void VL53::read() {
  for (int i = 0; i < 3; i++) out_of_range[i] = 0;
  lox1.rangingTest(&measure1, false); // pass in 'true' to get debug data printout!
  lox2.rangingTest(&measure2, false); // pass in 'true' to get debug data printout!
  lox3.rangingTest(&measure3, false); // pass in 'true' to get debug data printout!
  
  // print sensor one reading
  if(measure1.RangeStatus != 4) {     // if not out of range
    if ((measure1.RangeMilliMeter -= 0) > 0) VL53_data[0] = measure1.RangeMilliMeter;
    else out_of_range[0] = 1;
  } else out_of_range[0] = 1;
  // print sensor two reading
  if(measure2.RangeStatus != 4) {     // if not out of range
    if ((measure2.RangeMilliMeter -= 0) > 0) VL53_data[1] = measure2.RangeMilliMeter;
    else out_of_range[1] = 1;
  } else out_of_range[1] = 1;
  // print sensor three reading
  if(measure3.RangeStatus != 4) {     // if not out of range
    if ((measure3.RangeMilliMeter -= 0) > 0) VL53_data[2] = measure3.RangeMilliMeter;
    else out_of_range[2] = 1; 
  } else out_of_range[2] = 1;
  ReadBefore = 1;
}

void VL53::print() {
  // need to read before print
  if (ReadBefore){
    for (int i = 0; i < 3; i++) {
      Serial.print(i+1);
      Serial.print(F(": "));

      if(VL53_data[i] > 0 && VL53_data[i] < 8191 && !out_of_range[i]) {     // if not out of range   
        Serial.print(VL53_data[i]);
        Serial.print(F("mm\t"));    
        if(VL53_data[i] < 100) Serial.print(F("\t"));
        else  Serial.print(F("Out of range\t"));
      if(i == 2) Serial.println();
      }
    }
  }
}

void VL53::avoid(int flag[3]){
  for(int i = 0; i < 3 && flag[i]; i++) {
    if (!Is2ndMode) {
      if (VL53_data[0] < stop_dst && !out_of_range[0]) stop_flag = 1;
      else if (VL53_data[1] < stop_dst && !out_of_range[1]) stop_flag = 1;
      else if ((VL53_data[2]-20) < stop_dst && !out_of_range[2]) stop_flag = 1;
      else stop_flag = 0;
    }
    else {
      if (VL53_data[i] < final_dst) stop_flag = 1;
    }
  }
}

void VL53::closest() {
  int MinDst = 9999;
  for(int i = 0; i < 3; i++) {
    if (VL53_data[i] < MinDst) {
      MinDst = VL53_data[i];
      closest_num = i;
    } 
  }
}

void VL53::control (){
  read();
  avoid(VL53_flag);
  while(Serial.available() > 0) Serial.read();
  print();
}