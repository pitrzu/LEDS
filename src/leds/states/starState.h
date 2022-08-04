#include "consts.h"
#include "state.h"
#include "FastLED.h"

class StarState: public State{
  private:
    int p;
  public:
    StarState(int s, int p, long millis = 1000/60) : State(0, s, millis){
      this->p = p;
    }
    void changeLeds(CRGB* leds){
      int partitionLength = NUM_LEDS/this->p;
      for(int i = 0; i < this->p; i++){
        for(int j = (partitionLength * i); j < (partitionLength * (i+1)); j++){
          if(j > 0) leds[j-1] = CHSV(h, s, v);
          leds[j] = CHSV(h, s, 255);
          this->State::show();
        }
        h += (255 / p) * i;
      }
    }
};