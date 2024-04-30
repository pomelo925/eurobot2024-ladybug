#include <Adafruit_VL53L0X.h>
#include <single_vl53.h>

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

SINGLEVL53 SingleVL53;

void SINGLEVL53::setup() {
  Serial.begin(115200);

  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
}

void get_range(){
  VL53L0X_RangingMeasurementData_t measure;
   
  lox.rangingTest(&measure, false);

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance (mm): "); 
    Serial.println(measure.RangeMilliMeter);
  } else Serial.println(" out of range ");
   
  delay(100);
}
