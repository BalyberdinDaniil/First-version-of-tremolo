int readAnalogInput(uint8_t input, uint8_t to) {
  int sensor_value = mozziAnalogRead(input); // value is 0-1023
  return  map(sensor_value, 0, 1023, 0, to);
}


void updateControl() {
  freq = readAnalogInput(2, 254) + 1;
  depth = readAnalogInput(1, 32);
  wave = readAnalogInput(0, 255);
}
