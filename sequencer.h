//
//  sequencer.hpp
//  fluX
//
//  Created by pd3v on 01/07/18.
//
//

#ifndef sequencer_h
#define sequencer_h

class maxiOsc;
class note_t;
class Gen;
class Synth;

class Seq {
  static maxiOsc _tick;
  static float _tempo;
  static int _pattern;
  static std::vector<int> _scale;
  static note_t _note;
  static std::function<std::vector<int>(void)> _f;
  static Gen _gen;
  
public:
  static note_t note();
  static int counter;
  static int& playHead;
  static int lastCount;
  
  static Seq& instance();
  static Seq& start(float tempo, float pattern);
  static Seq& gen(std::vector<int> scale, std::function<std::vector<int>(void)> f);
  static Seq& synthOut();
  static double output();
  
  static Synth synth;
};


#endif /* sequencer_h */
