#ifndef _WEB_H_
#define _WEB_H_

#include <WiFi.h>
#include <AsyncTCP.h>
#include <AsyncElegantOTA.h>
#include <ESPmDNS.h>
#include <ESPAsyncWebServer.h>

class WEBSERVER{
public:
  static int readySignal;
  WEBSERVER(String ssid, String password, String hostname): _ssid(ssid), _password(password), _hostname(hostname){
    setup();
  };

private:
  String _ssid = "DIT_8C58";          // WiFi SSID
  String _password = "ditrobotics";   // WiFi PWD
  String _hostname = "ladybug-01";    // mDNS Hostname

  String processor(const String& var);
  String outputState(int output);
  
  void setup();
  void initWiFi();
  
};

extern WEBSERVER Webserver;
#endif