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
  WEBSERVER(String ssid, String password, String hostname, AsyncWebServer &server): \
   _ssid(ssid), _password(password), _hostname(hostname){
    startup(server);
  };

private:
  String _ssid = "DIT_8C58";          // WiFi SSID
  String _password = "ditrobotics";   // WiFi PWD
  String _hostname = "ladybug-01";    // mDNS Hostname

const char* index_html PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
  <title>DIT-Ladybug</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    html {
      font-family: Arial;
      text-align: center;
    }
    body {
      max-width: 600px;
      margin: 0 auto;
      padding-bottom: 25px;
    }
    h2 {
      font-size: 3.0rem;
    }
    p {
      font-size: 3.0rem;
    }
    .button {
      background-color: #DE272C;
      color: white;
      padding: 15px 32px;
      font-size: 28px;
      margin: 4px 2px;
      cursor: pointer;
      border: none;
      border-radius: 6px;
      text-decoration: none;
      display: inline-block;
      text-align: center;
    }
    .switch {
      position: relative;
      display: inline-block;
      width: 120px;
      height: 68px;
    }
    .slider {
      position: absolute;
      top: 0;
      left: 0;
      right: 0;
      bottom: 0;
      background-color: blue;
      border-radius: 6px;
      transition: .4s;
    }
    .slider:before {
      position: absolute;
      content: "";
      height: 52px;
      width: 52px;
      left: 8px;
      bottom: 8px;
      background-color: white;
      border-radius: 3px;
    }
    input:checked + .slider {
      background-color: yellow;
    }
    input:checked + .slider:before {
      transform: translateX(52px);
    }
  </style>
</head>
<body>
  <h2>Eurobot 2024</h2>
  <label class="switch">
    <input type="checkbox" id="colorToggle" onchange="toggleColor(this)">
    <span class="slider"></span>
  </label>
  <div> </div>
  <button class="button" onclick="sendState(0)">RESET</button>
  <button class="button" onclick="sendState(1)">READY</button>
<script>

function toggleColor(element) {
  var xhr = new XMLHttpRequest();
  var colorValue = element.checked ? 1 : 0;
  xhr.open("GET", "/updates?color=" + colorValue + "&state=" + state, true);
  xhr.send();
}

function sendState(state) {
  var xhr = new XMLHttpRequest();
  var color = document.getElementById('colorToggle').checked ? 1 : 0;
  xhr.open("GET", "/updates?color=" + color + "&state=" + state, true);
  xhr.send();
}
</script>
</body>
</html>
)rawliteral";

  const char* PARAM_INPUT_1 = "color";
  const char* PARAM_INPUT_2 = "state";

  String processor(const String& var);
  
  void startup(AsyncWebServer &server);
  void initWiFi();
  
};

// extern WEBSERVER Webserver;
#endif