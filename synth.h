//
//  Synth.hpp
//  fluX
//
//  Created by pd3v on 01/07/18.
//
//

#ifndef synth_h
#define synth_h

#include "maximilian.h"

class note_t;

class Synth {
  maxiOsc _osc;
  
public:
  Synth() {
    _osc.triangle(0);
  }
  double output(double freq);
  double output(note_t note);
};

#endif /* synth_h */
