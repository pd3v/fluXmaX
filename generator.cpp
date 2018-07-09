//
//  generator.cpp
//  fluX
//
//  Created by pd3v on 01/07/18.
//
//

#include "generator.h"
#include <vector>
#include <math.h>

using namespace std;

vector<int>Gen::_scale;
function<vector<int>(void)> Gen::_f;

Gen& Gen::instance(vector<int> scale, function<vector<int>(void)> f)  {
   static Gen g;
 
   _scale = scale;
   _f = f;
 
   return g;
}
 
double Gen::midi_to_freq(double midiNote) {
   return (pow(2, ((midiNote - 69.0) / 12)) * 440.0);
}
 
note_t Gen::note()  {
  vector<int> n = Gen::_f();
  note_t note;
 
  note.note = midi_to_freq(n[0] + 12 * n[3]);
  note.vel = n[1];
  note.dur = n[2];
 
  return note;
}