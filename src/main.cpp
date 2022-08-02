#include <Arduino.h>
#include <FS.h>
#include <WiFi.h>
#include <Wire.h>
#include "leds/ledController.h"
#include "leds/states/fullColorState.cpp"
#include "leds/states/rainbowState.cpp"
LedController* ledController_;

void setup() {
  ledController_ = LedController::getInstance(new RainbowState());
}

void loop() {
  ledController_->run();
}