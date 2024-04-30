#include <stdint.h>
#include <Adafruit_VL53L0X.h>
#include <triple_vl53.h>

#define stop_dst 50
#define final_dst 100

VL53 vl53;

void VL53::setID(){
  // all reset
  for (int i = 0; i < 3; i++) digitalWrite(SHT_LOX[i], LOW);    
  delay(10);

  // all unreset
  for (int i = 0; i < 3; i++) digitalWrite(SHT_LOX[i], HIGH);    
  delay(10);

  // activating LOX1 and reseting LOX2
  digitalWrite(SHT_LOX[0], HIGH);
  for (int i = 1; i < 3; i++) digitalWrite(SHT_LOX[i], LOW); 
  delay(10);   

  // initing LOX1
  if(!lox1.begin(LOX1_ADDRESS)) {
    Serial.println(F("Failed to boot first VL53L0X"));
    // while(1);
  }

  // activating LOX2
  digitalWrite(SHT_LOX[1], HIGH);
  delay(10);

  //initing LOX2
  if(!lox2.begin(LOX2_ADDRESS)) {
    Serial.println(F("Failed to boot second VL53L0X"));
    // while(1);
  }

  // activating LOX3
  digitalWrite(SHT_LOX[2], HIGH);
  delay(10);

  //initing LOX3
  if(!lox3.begin(LOX3_ADDRESS)) {
    Serial.println(F("Failed to boot third VL53L0X"));
    // while(1);
  }  
  Serial.println(F("VL53 set ID done."));
}

void VL53::setup() {
  for (int i = 0; i < 3; i++)  pinMode(SHT_LOX[i], OUTPUT);
  Serial.println("Shutdown pins inited...");

  for (int i = 0; i < 3; i++)  digitalWrite(SHT_LOX[i], LOW);
  Serial.println(F("VL53 set ID start. "));
  
  setID();
}

void VL53::read() {
  for (int i = 0; i < 3; i++) is_out_of_range[i] = 0;
  lox1.rangingTest(&measure1, false); // pass in 'true' to get debug data printout!
  lox2.rangingTest(&measure2, false); // pass in 'true' to get debug data printout!
  lox3.rangingTest(&measure3, false); // pass in 'true' to get debug data printout!
  
  // print sensor one reading
  if(measure1.RangeStatus != 4) {     // if not out of range
    if ((measure1.RangeMilliMeter -= 0) > 0) VL53_data[0] = measure1.RangeMilliMeter;
    else is_out_of_range[0] = 1;
  } else is_out_of_range[0] = 1;
  // print sensor two reading
  if(measure2.RangeStatus != 4) {     // if not out of range
    if ((measure2.RangeMilliMeter -= 0) > 0) VL53_data[1] = measure2.RangeMilliMeter;
    else is_out_of_range[1] = 1;
  } else is_out_of_range[1] = 1;
  // print sensor three reading
  if(measure3.RangeStatus != 4) {     // if not out of range
    if ((measure3.RangeMilliMeter -= 0) > 0) VL53_data[2] = measure3.RangeMilliMeter;
    else is_out_of_range[2] = 1; 
  } else is_out_of_range[2] = 1;
  ReadBefore = 1;
}

void VL53::print() {
  if (ReadBefore){
    for (int i=2; i>=0; i--) {   
      Serial.print(VL53_data[i]);
      if(i) Serial.print(F(":"));
    }
    Serial.print("\r"); 
  }
}

void VL53::avoid(int flag[3]){
  for(int i = 0; i < 3 && flag[i]; i++) {
    if (!Is2ndMode) {
      if (VL53_data[0] < stop_dst && !is_out_of_range[0]) stop_flag = 1;
      else if (VL53_data[1] < stop_dst && !is_out_of_range[1]) stop_flag = 1;
      else if ((VL53_data[2]-20) < stop_dst && !is_out_of_range[2]) stop_flag = 1;
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