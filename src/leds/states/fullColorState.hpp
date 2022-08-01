#include "consts.hpp"
#include "state.hpp"
#include "FastLED.h"

class FullColorState: public State{
  public:
    changeLeds(CRGB *leds, int h = 0, int s = 0, int v = 0){
      for(let i = 0; i < NUM_LEDS; i++){
        leds[i] = CHSV(h, s, v);
      }
    }
};