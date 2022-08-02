#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <FastLED.h>
#include "states/state.h"
#include "consts.h"

class LedController {
  private:
    CRGB leds[NUM_LEDS];
    State *state_;
    long updateMillis;

  protected:
    LedController(State*);
    static LedController* controller_;

  public:
    static LedController *getInstance(State*);
    void operator=(const LedController &) = delete;
    LedController(LedController &other) = delete;
    State* getState();
    void setState(State* s);
    void run();
    void update();
};
#endif