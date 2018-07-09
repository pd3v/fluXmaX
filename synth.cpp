//
//  Synth.cpp
//  fluX
//
//  Created by pd3v on 01/07/18.
//
//

#include "synth.h"
#include "maximilian.h"

maxiOsc _osc;
  
double Synth::output(double freq) {
  return _osc.triangle(freq);
}
