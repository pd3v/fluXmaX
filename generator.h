//
//  generator.hpp
//  fluX
//
//  Created by pd3v on 01/07/18.
//
//

#ifndef generator_h
#define generator_h

#include <vector>
#include <functional>

class note_t;

class Gen {
  static std::vector<int>_scale;
  static std::function<std::vector<int>(void)> _f;
  
public:
  static Gen& instance(std::vector<int> scale, std::function<std::vector<int>(void)> f);
  static double midi_to_freq(double midiNote);
  static double midi_to_amp(double midiNote);
  static note_t note();
};

#endif /* generator_h */
