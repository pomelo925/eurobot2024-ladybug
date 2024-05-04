#include <Arduino.h>
#include <web.h>
#include <mission.h>
 
/******** USER DEFINED *********/
#define SSID "DIT_8C58" // mDNS Hostname
#define PWD "ditrobotics" // mDNS Hostname
#define HOSTNAME "ladybug-2" // mDNS Hostname
#define LADYBUG_ID 2 // Mission ID
/*******************************/

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

  WEBSERVER Webserver(SSID, PWD, HOSTNAME, server);
  
  Serial.println("[MAIN] Wait For Request ...");
  while(!Webserver.readySignal) delay(500);


  Serial.println("[MAIN] Mission Start !");
  MISSION Mission(LADYBUG_ID, Webserver.color);
  Mission.run();
}

void loop(){
}


/***** 分隔線 *****/
// #include <Arduino.h>
// #include <wheel.h>
// #include <actuator.h>
// #include <triple_vl53.h>

// void setup(){

//   Serial.begin(115200);
//   pinMode(MOTOR_L, OUTPUT);
//   pinMode(MOTOR_R, OUTPUT);
// }

// void loop(){
//     delay(500);
//   digitalWrite(MOTOR_L, HIGH);
//   digitalWrite(MOTOR_R, HIGH);
//   delay(500);
//   digitalWrite(MOTOR_L, LOW);
//   digitalWrite(MOTOR_R, LOW);      
// }