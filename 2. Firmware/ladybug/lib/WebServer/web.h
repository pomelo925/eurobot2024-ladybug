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
  static int color;
  WEBSERVER(String ssid, String password, String hostname, AsyncWebServer &server): _ssid(ssid), _password(password), _hostname(hostname){
    startup(server);
  };

private:
  String _ssid = "DIT_8C58";          // WiFi SSID
  String _password = "ditrobotics";   // WiFi PWD
  String _hostname = "ladybug-01";    // mDNS Hostname

  const char* index_html = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>DIT-Ladybug</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
  <style>
    html {font-family: Arial; display: inline-block; text-align: center;}
    h2 {font-size: 3.0rem;}
    p {font-size: 3.0rem;}
    body {max-width: 600px; margin:0px auto; padding-bottom: 25px;}
    .switch {position: relative; display: inline-block; width: 120px; height: 68px} 
    .switch input {display: none}
    .slider {position: absolute; top: 0; left: 0; right: 0; bottom: 0; background-color: #ccc; border-radius: 6px}
    .slider:before {position: absolute; content: ""; height: 52px; width: 52px; left: 8px; bottom: 8px; background-color: #fff; -webkit-transition: .4s; transition: .4s; border-radius: 3px}
    input:checked+.slider {background-color: #DE272C}
    input:checked+.slider:before {-webkit-transform: translateX(52px); -ms-transform: translateX(52px); transform: translateX(52px)}
  </style>
</head>
<body>
  <h2>Eurobot 2024</h2>
  %BUTTONPLACEHOLDER%
<script>function toggleCheckbox(element) {
  var xhr = new XMLHttpRequest();
  if(element.checked){ xhr.open("GET", "/updates?output="+element.id+"&state=1", true); }
  else { xhr.open("GET", "/updates?output="+element.id+"&state=0", true); }
  xhr.send();
}
</script>
</body>
</html>
)rawliteral";

  String processor(const String& var);
  String outputState(int output);
  
  void startup(AsyncWebServer &server);
  void initWiFi();
  
};

// extern WEBSERVER Webserver;
#endif