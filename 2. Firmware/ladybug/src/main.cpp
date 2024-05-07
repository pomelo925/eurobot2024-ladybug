#include <Arduino.h>
#include <web.h>
#include <mission.h>
#include <wheel.h>
 
#define LADYBUG_ID 4
#define PWD "ditrobotics"

/******** ID: 1~6 @ Differential *********/
#if LADYBUG_ID >= 1 && LADYBUG_ID <= 6
  #define SSID "DIT_376E"
/******** ID: 7~12 @ Ominversal *********/
#elif LADYBUG_ID >= 7 && LADYBUG_ID <= 12
  #define SSID "DIT_8C58"
#endif


AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

/* 1. Initialization */
  WEBSERVER Webserver(SSID, PWD, LADYBUG_ID, server);
  Wheel.setup();

/******** ID: 1~4 & 7~10 @ ONLY *********/
#if (LADYBUG_ID >= 1 && LADYBUG_ID <= 4) || (LADYBUG_ID >= 7 && LADYBUG_ID <= 10)
  Wheel.zero_cali();
#endif
/*******************************/


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