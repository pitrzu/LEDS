#pragma once
#ifndef STATE_H
#define STATE_H
#include <vector>
#include <FastLED.h>
#include "consts.h"

class State{
  protected:
    std::array<CRGB, NUM_LEDS> leds;
    int h, s, v;
    long millis;
  public:
    State(){}
    State(int h, int s, int v, long millis){
      this->h = h;
      this->s = s;
      this->v = v;
      this->millis = millis;
    }
    virtual std::array<CRGB, NUM_LEDS> changeLeds() = 0;
    virtual long getMillis() = 0;
};
#endif