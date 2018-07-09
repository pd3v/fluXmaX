//
//  sequencer.cpp
//  fluX
//
//  Created by pd3v on 01/07/18.
//
//

#include "sequencer.h"

maxiOsc Seq::_tick;
float Seq::_tempo;
int Seq::_pattern;
vector<int> Seq::_scale;
note_t Seq::_note;
function<vector<int>(void)> Seq::_f;
Gen Seq::_gen;

int Seq::counter = 0;
int& Seq::playHead = Seq::counter; // counter alias
int Seq::lastCount = -1;
Synth Seq::synth;
  
Seq& Seq::instance()  {
  static Seq s;
    
  return s;
};
  
Seq& Seq::start(float tempo, float pattern)  {
  _tempo = tempo;
  _pattern = pattern;
    
  return Seq::instance();
};
  
Seq& Seq::gen(vector<int> scale, std::function<vector<int>(void)> f)  {
  _gen = Gen::instance(scale, f);
  _scale = scale;
  _f = f;
    
  return Seq::instance();
};
  
Seq& Seq::synthOut()  {
  synth = Synth();
    
  return Seq::instance();
};

double Seq::output() {
  counter += (int)_tick.phasor(_tempo * _note.dur / 60);
  
  if (lastCount != counter) {
    _note = _gen.note();
    lastCount = counter;
  }
  
  return synth.output(_note.note);
}
