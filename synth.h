//
//  Synth.hpp
//  fluX
//
//  Created by pd3v on 01/07/18.
//
//

#ifndef synth_h
#define synth_h

#include <stdio.h>
#include "maximilian.h"

class Synth {
  maxiOsc _osc;
  
public:
  Synth() {}
  double output(double freq);
};

#endif /* synth_h */
