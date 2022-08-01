#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <FastLED.h>
#include "states/state.h"
#include "consts.h"

class LedController {
  protected:
    LedController(State*);
    static LedController* controller_;
    State *state_;
    CRGB leds[NUM_LEDS];

  public:
    static LedController *getInstance(State*);
    void operator=(const LedController &) = delete;
    LedController(LedController &other) = delete;
    State* getState();
    void setState(State* s);
    void changeLeds();
};
#endif