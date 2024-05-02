#include <web.h>

int WEBSERVER::readySignal = 0;
IPAddress local_IP(192, 168, 8, 51);
IPAddress gateway(192, 168, 8, 1);
IPAddress subnet(255, 255, 255, 0);

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
  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("STA Failed to configure");
  }
  WiFi.begin(_ssid, _password);

  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.'); delay(1000);
  }

  if (!MDNS.begin(_hostname)) {
    Serial.println("Error starting mDNS");
    return;
  }
  Serial.println(WiFi.localIP());
  
  /* Place Your WiFi Ready things here  */ 

  /*              END                    */
}


void WEBSERVER::startup(AsyncWebServer &server) {
  pinMode(2, OUTPUT);
  initWiFi();

  // Route for root / web page
  server.on("/", HTTP_GET, [this](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, [this](const String& var) { return this->processor(var); });
  });

  // Send a GET request to <ESP_IP>/updates?output=<inputMessage1>&state=<inputMessage2>
  server.on("/updates", HTTP_GET, [](AsyncWebServerRequest* request){
    String inputMessage1;
    if (request->hasParam("output")) {
      inputMessage1 = request->getParam("state")->value();
      readySignal = inputMessage1.toInt();
      // Serial.print("ReadySignal: ");
      // Serial.println(readySignal);
    } // Add this closing brace
    request->send(200, "text/plain", "OK");
  });

  AsyncElegantOTA.begin(&server);  
  server.begin();
}