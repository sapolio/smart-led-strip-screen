#define NUM_LEDS      300
#define MATRIX_WIDTH  20
#define MATRIX_HEIGHT 15
#define LED_TYPE      WS2812
#define COLOR_ORDER   GRB
#define LED_PIN       14
#define BRIGHTNESS    30

#include <FastLED.h>

bool pixelXYValid(int x, int y);
int indexFromXY(int x, int y);
void initScreen();
void showScreen();
void clearAll();
void setPixel(int index, CRGB color);
void setPixelXY(int x, int y, CRGB color);
CRGB getPixel(int index);
CRGB getPixelXY(int x, int y);
