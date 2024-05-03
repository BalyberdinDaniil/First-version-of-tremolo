int updateAudio() {

  int result;

  if (wave <= 255 && wave > 237)
    result = (int)aSaw.next();
  if (wave <= 237 && wave > 223)
    result = (int)aSqrt.next();
  if (wave <= 223 && wave > 159)
    result = (int)aSawRev.next();
  if (wave <= 150 && wave >= 0)
    result = (int)aTri.next();

  return (result * depth) >> 8;
}
/*
Интерполяция потенциометра
  255
  237
  223
  150
  0
*/
