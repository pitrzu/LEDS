#include "serverController.h"
#include "variables.h"
#include "env.h"
#include <ESPAsyncWebServer.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include "leds/states/fullColorState.h"
#include "leds/states/rainbowState.h"

AsyncWebServer server(80);

ServerController* ServerController::controller_ = nullptr;
ServerController::ServerController(){
  WiFi.mode(WIFI_STA);
  WiFi.config(IPAddress(192, 168, 1, 190), IPAddress(192, 168, 1, 100), IPAddress(255, 255, 255, 0));
  WiFi.begin(env::SSID, env::PASSWORD);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/plain", "Hello, world");  
  });
  server.on("/fill", HTTP_GET, [](AsyncWebServerRequest *request){
    ledController_->setState(new FullColorState(30));
    request->send(200, "text/plain", "Changed to color");  
  });
  server.on("/rainbow", HTTP_GET, [](AsyncWebServerRequest *request){
    ledController_->setState(new RainbowState());
    request->send(200, "text/plain", "Changed to rainbow"); 
  });

  server.begin();
}

ServerController *ServerController::getInstance() {
  if(controller_ == nullptr) controller_ = new ServerController();
  return controller_;
};