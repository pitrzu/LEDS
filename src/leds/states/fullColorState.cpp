#include "consts.h"
#include "state.h"
#include "FastLED.h"

class FullColorState: public State{
  public:
    FullColorState(int h = 160, int s = 255, int v = 255, long millis = 1000) : State(h, s, v, millis){}
    std::array<CRGB, NUM_LEDS> changeLeds(){
      for(int i = 0; i < NUM_LEDS; i++){
        this->leds[i] = CHSV(this->h, this->s, this->v);
      }
      return leds;
    }
    long getMillis(){
      return this->millis;
    }
};