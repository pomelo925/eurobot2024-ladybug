#include <Arduino.h>
#include <web.h>
#include <mission.h>
#include <wheel.h>
 
/******** USER DEFINED *********/
#define SSID "DIT_8C58" // mDNS Hostname
#define PWD "ditrobotics" // mDNS Hostname
#define HOSTNAME "ladybug-3" // mDNS Hostname
#define LADYBUG_ID 3// Mission ID
/*******************************/

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

/* 1. Initialization */
  WEBSERVER Webserver(SSID, PWD, HOSTNAME, server);
  Wheel.setup();
  Wheel.zero_cali();
  
/* 2. Wait for request */
  Serial.println("[MAIN] Wait For Request ...");
  while(!Webserver.readySignal) delay(500);


/* 3. Start Mission */
  Serial.println("[MAIN] Mission Start !");
  MISSION Mission(LADYBUG_ID, Webserver.color);
  Mission.run();
}

void loop(){

}


/***** 分隔線 *****/

// #include <Arduino.h>
// #include <web.h>
// #include <mission.h>
// #include <single_vl53.h>
// #include <triple_vl53.h>
// #include <wheel.h>
// #include <glv.h>
 
// /******** USER DEFINED *********/
// #define SSID "DIT_8C58" // mDNS Hostname
// #define PWD "ditrobotics" // mDNS Hostname
// #define HOSTNAME "ladybug-1" // mDNS Hostname
// #define LADYBUG_ID 1 // Mission ID

// #define HOMOLOGATION_MODE false
// /*******************************/

// AsyncWebServer server(80);

// void setup() {
//   Serial.begin(115200);

//   WEBSERVER Webserver(SSID, PWD, HOSTNAME, server);
  
//   Serial.println("[MAIN] Wait For Request ...");
//   while(!Webserver.readySignal) delay(500);

//   Triple_vl53.setup();
//   Wheel.setup();
// }


// void loop(){
//   Triple_vl53.checkObstacle(); 
  // digitalWrite(MOTOR_R, HIGH); digitalWrite(MOTOR_L, HIGH);
  // delay(5);
  // digitalWrite(MOTOR_R, LOW); digitalWrite(MOTOR_L, LOW);
  // delay(15);
// }

/***** 分隔線 *****/

// #include <Arduino.h>
// #include <web.h>
// #include <mission.h>
// #include <triple_vl53.h>
// #include <wheel.h>
 
// /******** USER DEFINED *********/
// #define SSID "DIT_8C58" // mDNS Hostname
// #define PWD "ditrobotics" // mDNS Hostname
// #define HOSTNAME "ladybug-1" // mDNS Hostname
// #define LADYBUG_ID 1 // Mission ID

// #define HOMOLOGATION_MODE false
// /*******************************/

// AsyncWebServer server(80);

// void setup() {
//   Serial.begin(115200);

//   WEBSERVER Webserver(SSID, PWD, HOSTNAME, server);
  
//   Serial.println("[MAIN] Wait For Request ...");
//   while(!Webserver.readySignal) delay(500);

//   Triple_vl53.setup();
//   Wheel.setup();
// }


// void loop(){
//   Serial.println(Triple_vl53.checkObstacle());
// }
