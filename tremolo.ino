#include <MozziGuts.h>
#include <Oscil.h> // oscillator template

//tables for oscillator
#include <tables/saw2048_int8.h>
Oscil <SAW2048_NUM_CELLS, AUDIO_RATE> aSaw(SAW2048_DATA);

#include <tables/triangle2048_int8.h>
Oscil <TRIANGLE2048_NUM_CELLS, AUDIO_RATE> aTri(TRIANGLE2048_DATA);

#include <tables/square_no_alias_2048_int8.h>
Oscil <SQUARE_NO_ALIAS_2048_NUM_CELLS, AUDIO_RATE> aSqrt(SQUARE_NO_ALIAS_2048_DATA);

#include <tables/sawRevers2048_int8.h>
Oscil <SAWREV2048_NUM_CELLS, AUDIO_RATE> aSawRev(SAWREV2048_DATA);


#define CONTROL_RATE 64 // Hz, powers of 2 are most reliable

uint8_t freq = 1;
uint8_t depth = 1;
uint8_t wave = 0;

void setup() {
  startMozzi(CONTROL_RATE);
  aTri.setFreq(freq);
  aSaw.setFreq(freq);
  aSqrt.setFreq(freq);
  aSawRev.setFreq(freq);
}

void loop() {
  audioHook(); // required here
}
