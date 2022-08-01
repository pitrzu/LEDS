#pragma once
#ifndef STATE_H
#define STATE_H
#include <vector>

class State{
  protected:
    CRGB* leds;
    int h, s, v;
  public:
    State(){}
    State(CRGB leds[], int h, int s, int v){
      this->leds = leds;
      this->h = h;
      this->s = s;
      this->v = v;
    }
    virtual CRGB* changeLeds() = 0;
};
#endif