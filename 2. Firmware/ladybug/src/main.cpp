#include <Arduino.h>
#include <web.h>
#include <mission.h>
#include <triple_vl53.h>
 
/******** USER DEFINED *********/
#define SSID "DIT_8C58" // mDNS Hostname
#define PWD "ditrobotics" // mDNS Hostname
#define HOSTNAME "ladybug-01" // mDNS Hostname
#define LADYBUG_ID 1  // Mission ID
/*******************************/

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

  WEBSERVER Webserver(SSID, PWD, HOSTNAME, server);
  
  vl53.setup();
  MISSION Mission(LADYBUG_ID);


  while(!Webserver.readySignal) delay(100);
  Mission.run();
}

void loop(){
}


/***** 分隔線 *****/

