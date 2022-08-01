#include <Arduino.h>
#include <FS.h>
#include <WiFi.h>
#include <Wire.h>
#include "leds/ledController.h"
#include "leds/states/fullColorState.cpp"

void setup() {
  LedController* controller = LedController::getInstance(new FullColorState());
}

void loop() {
  // put your main code here, to run repeatedly:
}