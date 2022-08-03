#include "ledController.h"

LedController* LedController::controller_ = nullptr;

LedController::LedController(State* s){
  FastLED.addLeds<LED_CONTROLLER, LED_PIN, LED_ORDER>(this->leds, NUM_LEDS).setTemperature(HighNoonSun).setCorrection(Typical8mmPixel);
  this->setState(s);
  this->offset = 0;
}

LedController *LedController::getInstance(State* s) {
  if(controller_ == nullptr) controller_ = new LedController(s);
  return controller_;
};

void LedController::setState(State* s){
  this->state_ = s;
}

State *LedController::getState(){
  return this->state_;
}

void LedController::run(){
  this->state_->changeLeds(this->leds);
}

