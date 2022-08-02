#include "ledController.h"

LedController* LedController::controller_ = nullptr;

LedController::LedController(State* s){
  FastLED.addLeds<LED_CONTROLLER, LED_PIN, LED_ORDER>(this->leds, NUM_LEDS); 
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

void LedController::run(){
  std::array<CRGB, NUM_LEDS> returnedLeds = this->state_->changeLeds();
  for(int i = 0; i < NUM_LEDS; i++){
    this->leds[i] = returnedLeds[i];
  }
  this->update();
}

void LedController::update(){
  if(millis() - this->updateMillis < this->state_->getMillis()) return;
  this->updateMillis = millis();
  FastLED.show();
}