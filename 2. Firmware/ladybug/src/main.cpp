#include <Arduino.h>

#include <web.h>
#include <mission.h>

/******** USER DEFINED *********/
#define SSID "DIT_8C58" // mDNS Hostname
#define PWD "ditrobotics" // mDNS Hostname
#define HOSTNAME "ladybug-01" // mDNS Hostname
#define LADYBUG_ID 1  // Mission ID
/*******************************/

WEBSERVER Webserver(SSID, PWD, HOSTNAME);
MISSION Mission(LADYBUG_ID);

void setup() {
  Serial.begin(115200);
  while(!Webserver.readySignal){};
  Mission.run();
}

void loop(){
  // baby baby baby ohhhhhhhh
}


/***** 分隔線 *****/

//#include <Arduino.h>
//
//void setup() {
//  Serial.begin(115200);
//  pinMode(0, OUTPUT);
//  pinMode(16, OUTPUT);
//}
//
//void loop(){ 
//  analogWrite(0,255);
//  delay(500);
//  digitalWrite(16, HIGH);
//  delay(500);
//  digitalWrite(16, LOW); 
//}