#include <web.h>

int WEBSERVER::readySignal = 0;
int WEBSERVER::color = -1;

IPAddress local_IP(192, 168, 8, 52);
IPAddress gateway(192, 168, 8, 1);
IPAddress subnet(255, 255, 255, 0);

// Replaces placeholder with button section in your web page
String WEBSERVER::processor(const String& var) {
  return String();
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

  server.on("/updates", HTTP_GET, [this](AsyncWebServerRequest* request) { // Capture 'this' pointer
    String inputMessage1, inputMessage2;
    if (request->hasParam(PARAM_INPUT_1)) {
      inputMessage1 = request->getParam(PARAM_INPUT_1)->value();
      inputMessage2 = request->getParam(PARAM_INPUT_2)->value();
      color = inputMessage1.toInt();
      readySignal = inputMessage2.toInt();
    } else {
      inputMessage1 = "No message sent";
    }
    request->send(200, "text/plain", "DIT Robotics");
  });

  AsyncElegantOTA.begin(&server);  
  server.begin();
}