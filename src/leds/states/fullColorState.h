#include "consts.h"
#include "state.h"
#include "FastLED.h"

class FullColorState: public State{
  public:
    FullColorState(int h = 160, int s = 255, long millis = 1) : State(h, s, millis){}
    void changeLeds(CRGB* leds){
      for(int i = 0; i < NUM_LEDS; i++){
        leds[i] = CHSV(this->h, this->s, this->v);
      }
      this->State::show();
    }
};