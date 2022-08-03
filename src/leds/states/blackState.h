#include "state.h"

class BlackState: public State{
  public:
    BlackState() : State(0, 0, 0, 1){}
    void changeLeds(CRGB* leds){
      for(int i = 0; i < NUM_LEDS; i++){
        leds[i] = CRGB::Black;
      }
      this->State::update();
    }
};