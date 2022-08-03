#include <Arduino.h>
#include <FS.h>
#include <WiFi.h>
#include <Wire.h>
#include "leds/ledController.h"
#include "leds/states/fullColorState.h"
#include "leds/states/rainbowState.h"
#include "server/serverController.h"

LedController* ledController_;

void setup() {
  ledController_ = LedController::getInstance(new FullColorState(0, 0, 0));
  ServerController* serverController_ = ServerController::getInstance();
}

void loop() {
  ledController_->run();
}