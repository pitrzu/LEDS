#include <Arduino.h>
#include <FS.h>
#include <WiFi.h>
#include <Wire.h>
#include "leds/ledController.h"
#include "leds/states/blackState.h"
#include "server/serverController.h"

LedController* ledController_;

void setup() {
  ledController_ = LedController::getInstance(new BlackState());
  ServerController* serverController_ = ServerController::getInstance();
}

void loop() {
  ledController_->run();
}