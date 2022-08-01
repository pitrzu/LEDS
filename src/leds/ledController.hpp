#include <FastLED.h>
#include "state.hpp"
#include "consts.hpp"

class LedController {
  protected:
    LedController();
    static LedController* controller_;
    State state_;
    CRGB leds[NUM_LEDS];

  public:
    static LedController *getInstance();
    void operator=(const LedController &) = delete;
    LedController(LedController &other) = delete;
    state getState();
    void setState(state s);
    void changeLeds(CRGB *leds, int h, int s, int v);
};

LedController LedController::LedContoller(){
  FastLED.addLeds<WS2813, DATA_PIN, GRB>(leds, NUM_LEDS);
}

LedController* LedController::controller_ = nullptr;
LedController *LedController::getInstance {
  if(controller_ == nullptr) controller_ = new LedController();
  return controller_;
};

void LedController::setState(state s){
  this->state_ = s;
}

state LedController::getState(){
  return this->state_;
}

void LedController::changeLeds(CRGB *leds, int h, int s, int v){
  this->state_->changeLeds(CRGN *leds, int h, int s, int v);
}