int updateAudio() {
  int result;
  aTri.setFreq(freq >> 4);
  aSaw.setFreq(freq >> 4);
  aSqrt.setFreq(freq >> 4);
  aSawRev.setFreq(freq >> 4);

  if (wave < 64)
    result = (int)aTri.next();
  else if (wave < 128)
    result = (int)aSaw.next();
  else if (wave < 192)
    result = (int)aSqrt.next();
  else
    result = (int)aSawRev.next();

  return (result * depth) >> 8;
}
