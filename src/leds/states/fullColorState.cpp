#include "consts.h"
#include "state.h"
#include "FastLED.h"

class FullColorState: public State{
  public:
    FullColorState(){}
    FullColorState(CRGB leds[], int h, int s, int v) : State(leds, h, s, v){}
    CRGB* changeLeds(){
      for(int i = 0; i < NUM_LEDS; i++){
        this->leds[i] = CHSV(this->h, this->s, this->v);
      }
      return leds;
    }
};