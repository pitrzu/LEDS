#pragma once
#ifndef STATE_H
#define STATE_H
#include <vector>
#include <FastLED.h>
#include "consts.h"

class State{
  protected:
    int h, s, v;
    long showDelay, showMillis, fpsDelay, fpsMillis;
  public:
    State(){}
    State(int h, int s, long showDelay){
      this->h = h;
      this->s = s;
      this->v = floor(analogRead(34)/16);
      this->showDelay = showDelay;
      this->fpsMillis = millis();
      this->fpsDelay = 100/6;
    }
    virtual void changeLeds(CRGB* leds){}
    void show(){
      if(millis() - this->fpsMillis < this->fpsDelay) return;
      this->fpsMillis = millis();
      if(abs8(floor(analogRead(34)/16) - v) > 4 ) v = floor(analogRead(34)/16);
      FastLED.show();
    }
    bool canUpdateLed(){
      if(millis() - this->showMillis < this->showDelay) return false;
      this->showMillis = millis();
      return true;
    }
};
#endif