//
//  helpers.cpp
//  fluXo
//
//  Created by pd3v on 14/06/18.
//
//

#include "helpers.h"
#include <random>
#include "sequencer.h"

namespace hlp {
  float rand(float min=0.0, float max=1.0) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> distribution(min, max);
    
    return distribution(rng);
  }

  float midi_to_amp(int value) {
    return value / 127.;
  }
  
  float scale_to (float min, float max, float minTo, float maxTo, float value) {
    return std::abs(((value - min) / (max - min)) * (maxTo - minTo) + minTo);
  }

}