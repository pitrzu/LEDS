#include "consts.h"
#include "state.h"
#include "FastLED.h"

class PulseState: public State{
  public:
    PulseState(long millis = 1000/60) : State(0, 255, millis){}
    void changeLeds(CRGB* leds){
      for (int j = 0; j < 255; j++) {
        if(!this->State::canUpdateLed()) {
          j--;
          continue;
        }
        for (int i = 0; i < NUM_LEDS; i++) {
          leds[i] = CHSV(j, s, v);
        }
        this->State::show();
      }
    }
};