//
//  helpers.hpp
//  fluXo
//
//  Created by pd3v on 14/06/18.
//
//

#ifndef helpers_hpp
#define helpers_hpp

#include <stdio.h>

namespace hlp {
  float rand(float min, float max);
  float midi_to_amp(int value);
  float scale_to(float min, float max, float minTo, float maxTo, float value);
}
#endif /* helpers_hpp */
