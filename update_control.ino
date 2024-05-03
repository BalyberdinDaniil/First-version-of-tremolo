byte readButton () {
  // У меня кнопка без фиксации. Заменяем эту возможность кодом
  bool buttonIsUp = digitalRead(3);
  if (buttonWasUp && !buttonIsUp) {
    if (millis() - btnTimer > 10) {
      btnTimer = millis();
      buttonIsUp = digitalRead(3);
      if (!buttonIsUp) {
        tremEnabled = !tremEnabled;
      }
    }
  }
  buttonWasUp = buttonIsUp;
}

int readAnalogInput(uint8_t input, uint8_t maxValue) {
  int sensor_value = mozziAnalogRead(input); // value is 0-1023
  sensor_value = sensor_value;

  return  map(sensor_value, 0, 1023, 0, maxValue);
}

void updateControl() {

  byte status = readButton ();

  freq = 127 - readAnalogInput(2, 127) + 20;
  depth = 63 - readAnalogInput(0, 63);
  wave = readAnalogInput(1, 255);


  if (tremEnabled) {
    aTri.setFreq(freq >> 4);
    aSaw.setFreq(freq >> 4);
    aSqrt.setFreq(freq >> 4);
    aSawRev.setFreq(freq >> 4);
    aSin.setFreq(freq >> 4);
  }
  else {
    depth = 0;
  }
}

