#include <Arduino.h>
#include <web.h>
#include <mission.h>
#include <triple_vl53.h>
 
/******** USER DEFINED *********/
#define SSID "DIT_8C58" // mDNS Hostname
#define PWD "ditrobotics" // mDNS Hostname
#define HOSTNAME "ladybug-01" // mDNS Hostname
#define LADYBUG_ID 2  // Mission ID
/*******************************/

void setup() {
  Serial.begin(115200);
  vl53.setup();
  // WEBSERVER Webserver(SSID, PWD, HOSTNAME);
  MISSION Mission(LADYBUG_ID);

  // while(!Webserver.readySignal){};
  Mission.run();
}

void loop(){
  // baby baby baby ohhhhhhhh
}


/***** 分隔線 *****/

// #include <Arduino.h>

// void setup(){
//   // pinMode(5, OUTPUT);
//   pinMode(16, OUTPUT);
// }

// void loop(){
//   digitalWrite(5, HIGH);
//   digitalWrite(16, HIGH); 
//   delay(1000);
//   digitalWrite(5, LOW);
//   digitalWrite(16, LOW);
//   delay(1000);
// }