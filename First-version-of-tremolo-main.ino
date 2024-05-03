#include <MozziGuts.h>
#include <Oscil.h> // oscillator template

//tables for oscillator
#include <tables/saw2048_int8.h>
Oscil <SAW2048_NUM_CELLS, AUDIO_RATE> aSaw(SAW2048_DATA);

//up - down
#include <tables/triangle2048_int8.h>
Oscil <TRIANGLE2048_NUM_CELLS, AUDIO_RATE> aTri(TRIANGLE2048_DATA);

#include <tables/envelop2048_uint8.h>
Oscil <ENVELOP2048_NUM_CELLS, AUDIO_RATE> aSin(ENVELOP2048_DATA);

#include <tables/square_no_alias_2048_int8.h>
Oscil <SQUARE_NO_ALIAS_2048_NUM_CELLS, AUDIO_RATE> aSqrt(SQUARE_NO_ALIAS_2048_DATA);

//down - up
#include <tables/sawRevers2048_int8.h>
Oscil <SAWREV2048_NUM_CELLS, AUDIO_RATE> aSawRev(SAWREV2048_DATA);


#define CONTROL_RATE 64 // Hz, powers of 2 are most reliable

uint8_t freq = 1;
uint8_t depth = 0;
uint8_t wave = 0;

bool buttonWasUp = true;  // была ли кнопка отпущена?
bool tremEnabled = false;  // включено ли тремоло?
uint32_t btnTimer = 0; // таймер для заммены delay()

void setup() {
  pinMode(3, INPUT_PULLUP);

  startMozzi(CONTROL_RATE);
  freq = readAnalogInput(2, 127) + 20;
  wave = readAnalogInput(0, 3);

  aTri.setFreq(freq);
  aSaw.setFreq(freq);
  aSqrt.setFreq(freq);
  aSawRev.setFreq(freq);
}

void loop() {
  audioHook(); // required here
}
