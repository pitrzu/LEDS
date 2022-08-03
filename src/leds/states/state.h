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
    long waitMillis, updateMillis;
  public:
    State(){}
    State(int h, int s, int v, long waitMillis){
      this->h = h;
      this->s = s;
      this->v = v;
      this->waitMillis = waitMillis;
      this->updateMillis = millis();
    }
    virtual void changeLeds(CRGB* leds){}
    void update(){
      if(millis() - this->updateMillis < this->waitMillis) return;
      this->updateMillis = millis();
      if(abs8(floor(analogRead(34)/16) - v) > 4 ) v = floor(analogRead(34)/16);
      FastLED.show();
    }
};
#endif