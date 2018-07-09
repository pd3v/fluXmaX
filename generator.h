//
//  generator.hpp
//  fluX
//
//  Created by pd3v on 01/07/18.
//
//

#ifndef generator_h
#define generator_h

#include <stdio.h>
#include <vector>
#include <functional>

using namespace std;

struct note_t {
  double note;
  int dur;
  int vel;
  int oct;
};

class Gen {
  static vector<int>_scale;
  static function<vector<int>(void)> _f;
  
public:
  static Gen& instance(vector<int> scale, function<vector<int>(void)> f);
  static double midi_to_freq(double midiNote);
  static note_t note();
};


#endif /* generator_h */
