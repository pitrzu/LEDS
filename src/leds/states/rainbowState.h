#include "consts.h"
#include "state.h"
#include "FastLED.h"

class RainbowState: public State{
  public:
    RainbowState(long millis = 1000/60) : State(0, 255, 255, millis){}
    void changeLeds(CRGB* leds){
      for (int j = 0; j < 255; j++) {
        for (int i = 0; i < NUM_LEDS; i++) {
          leds[i] = CHSV(i - (j * 2), s, v); /* The higher the value 4 the less fade there is and vice versa */ 
        }
        this->State::update();
      }
    }
};