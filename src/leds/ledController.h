#pragma once
#ifndef L_CONTROLLER_H
#define L_CONTROLLER_H
#include <FastLED.h>
#include "states/state.h"
#include "consts.h"

class LedController {
  private:
    CRGB leds[NUM_LEDS];
    State *state_;
    long updateMillis;
    int offset;

  protected:
    LedController(State*);
    static LedController* controller_;

  public:
    static LedController *getInstance(State*);
    void operator=(const LedController &) = delete;
    LedController(LedController &other) = delete;
    State* getState();
    void setState(State*);
    void run();
    void update();
    void setValue(int);
};
#endif