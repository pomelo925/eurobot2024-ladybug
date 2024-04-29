#include <web.h>

int WEBSERVER::readySignal = 0;

const char index_html[] PROGMEM = R"rawliteral(
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

// Replaces placeholder with button section in your web page
String WEBSERVER::processor(const String& var) {
  if (var == "BUTTONPLACEHOLDER") {
    String buttons = "";
    buttons += "<h4>ReadySignal</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"1\" " + outputState(1) + "><span class=\"slider\"></span></label>";
    return buttons;
  }
  return String();
}


String WEBSERVER::outputState(int output) {
  if (digitalRead(output)) return "checked";
  else return "";
}


void WEBSERVER::initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(_ssid, _password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  if (!MDNS.begin(_hostname)) {
    Serial.println("Error starting mDNS");
    return;
  }
  Serial.println(WiFi.localIP());
  /* Place Your WiFi Ready things here  */ 

  /*              END                    */
}


void WEBSERVER::setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  initWiFi();

  AsyncWebServer server(80);

  // Route for root / web page
  server.on("/", HTTP_GET, [this](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, [this](const String& var) { return this->processor(var); });
  });

  // Send a GET request to <ESP_IP>/updates?output=<inputMessage1>&state=<inputMessage2>
  server.on("/updates", HTTP_GET, [](AsyncWebServerRequest* request){
    String inputMessage1;
    if (request->hasParam("output")) {
      inputMessage1 = request->getParam("output")->value();
      if (inputMessage1.toInt() == 1) readySignal = inputMessage1.toInt();
      else inputMessage1 = "No message se nt";
    } // Add this closing brace
    request->send(200, "text/plain", "OK");
  });

  AsyncElegantOTA.begin(&server);  // Start ElegantOTA
  server.begin();
}