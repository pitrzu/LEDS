#include "ledController.h"

LedController* LedController::controller_ = nullptr;

LedController::LedController(State* s){
  FastLED.addLeds<WS2813, DATA_PIN, GRB>(leds, NUM_LEDS); 
  this->setState(s);
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

void LedController::changeLeds(){
  this->state_->changeLeds();
}