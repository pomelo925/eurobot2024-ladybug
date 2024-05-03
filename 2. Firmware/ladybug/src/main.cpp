// #include <Arduino.h>
// #include <web.h>
// #include <mission.h>
 
// /******** USER DEFINED *********/
// #define SSID "DIT_8C58" // mDNS Hostname
// #define PWD "ditrobotics" // mDNS Hostname
// #define HOSTNAME "ladybug-4" // mDNS Hostname
// #define LADYBUG_ID 4 // Mission ID
// /*******************************/

// AsyncWebServer server(80);

// void setup() {
//   Serial.begin(115200);

//   WEBSERVER Webserver(SSID, PWD, HOSTNAME, server);
//   while(!Webserver.readySignal) delay(500);

//   Serial.println("[MAIN] Ready to run Mission.");
//   int color;
//   MISSION Mission(LADYBUG_ID, color);
//   Mission.run();
// }

// void loop(){
// }



/***** 分隔線 *****/
/* 電路測試版 */

#include <Arduino.h>
#include <actuator.h>
#include <web.h>
#include <wheel.h>
#include <mission.h>
#include <triple_vl53.h>
 
// /******** USER DEFINED *********/
#define SSID "DIT_8C58" // mDNS Hostname
#define PWD "ditrobotics" // mDNS Hostname
#define HOSTNAME "ladybug7" // mDNS Hostname
#define LADYBUG_ID 7  // Mission ID
// /*******************************/

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

  WEBSERVER Webserver(SSID, PWD, HOSTNAME, server);
  
  Triple_vl53.setup();
  // Triple_vl53.singleSetup();
  // Serial.println("Ready to run Mission.");
  ESP_Servo.moveTo(180);
  Wheel.moveDirect(4);
  Wheel.rotateClockwise(1);
  Wheel.rotateCounterClockwise(2);
  ESP_Servo.moveTo(0);
}

void loop(){
  // Triple_vl53.singleread();
}



/***** 分隔線 *****/
// #include <Arduino.h>
// #include <wheel.h>
// #include <actuator.h>

// void setup(){
//   Serial.begin(115200);
//   ESP_Servo.moveTo(170);
//   Wheel.zero_cali();
//   Wheel.moveDirect2(200);
// }

// void loop(){
// }