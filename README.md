# fluX_for_maximilian
A fluX version to work with Maximilian DSP library.

Example:

```cpp
maxiOsc panSine;
maxiFractionalDelay delay;
maxiMix mixOut;

double stereoOutput[2];
int mod, pan, dur = 0.0;

// maximilian's setup()
void setup(int args, char* argv[]) {
  int tempo = 90;
  vector<int> scale;
  scale = {0,2,4,5,7,9,11}; // C major scale

  // lambda expression with generative algorithm
  auto f = [scale](void)->vector<int> {
    static int inc = 1, oct = 2;

    if (Seq::playHead%scale.size() == 0) {
      int d = (int)rand(1,4); // rand() helper function
      oct += inc;
      pan = pow(2,d+1);
    }

    if (Seq::playHead%150 == 0) {
      inc *= -1;
    }

    if (oct > 4) {
      inc = -1;
    }

    if (oct < 2) {
      inc = 1;
    }

    // note generated is placed in a vector with the following format {midi note, velocity, duration, octave}
    return {inc == 1 ? scale[Seq::playHead%scale.size()] : scale[scale.size()-1-(Seq::playHead%scale.size())],127,(int)pow(2,rand(2,4)),oct};
  };
  // fluX's Sequencer plays with synthOut timbre, the Generator notes, generated based on "scale" out of algorithm "f" at "tempo".
  Seq::gen(scale, f).synthOut().start(tempo,4); //4 will be ignored, for now.
}

// maximilian's play()
void play(double *output) {
  double in = Seq::output(); // fluX Sequencer is outputting note's frequency and that's it...

  double in_delay = delay.dl(in, 0.0625, 0.33);
  mixOut.stereo(in_delay,stereoOutput,panSine.sinewave(pan));

  output[0] = in + in_delay;
  output[1] = in + in_delay;
}
```
