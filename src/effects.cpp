#include <effects.h>

void test() {
  static int y = 0;
  clearAll();
  for (int x = 0; x < MATRIX_WIDTH; x++) {
    setPixelXY(x, y, CRGB::Red);
  }

  if (++y > MATRIX_HEIGHT) y = 0;
  showScreen();
}

void pixelRainbow() {
  static float step = 255;
  static float rotationSin = 1;
  static float rotationCos = 1;
  static float scaleSin = 1;
  CHSV color;
  for (int x = 0; x < MATRIX_WIDTH; x++) {
    for (int y = 0; y < MATRIX_HEIGHT; y++) {
      int index = indexFromXY(x, y);
      if (index >= 0) {
        color = CHSV(
          int(
            step
            + (255 / MATRIX_WIDTH * x * rotationSin * scaleSin)
            + (255 / MATRIX_HEIGHT * y * rotationCos * scaleSin)
          ) % 255, 255, 255);
        setPixel(index, color);
      }
    }
  }
  showScreen();

  step += 1;
  rotationSin = sin(step / 100);
  rotationCos = cos(step / 100);
  scaleSin = abs(sin(step / 100)) * 2;
  // delay(30); // Adjust the delay based on the desired speed
}

void fire2021 (){
  int  a = millis();
  int  a1 = a/2;

  uint16_t yScale = a;
  for (byte y = 0; y < MATRIX_HEIGHT; y++) { 
    uint16_t xScale =  0;
    byte yHeight =  abs8(y - (MATRIX_HEIGHT-1)) * 255 / (MATRIX_HEIGHT+8);   //высота огня тут  - (NUM_ROWS+10) 
    for (byte x = 0; x < MATRIX_WIDTH; x++) {
      int index = indexFromXY(x, y);
      byte val = (index >= 0) ? qsub8 (min(inoise8 (xScale, yScale, a1), static_cast<uint8_t>(240)), yHeight) : 0;
      CRGB color = HeatColor(val);
      setPixel(index, color);
      xScale +=40;
    }
    yScale += 40;
  }
  showScreen();
  // delay(70); // Adjust the delay based on the desired speed
}