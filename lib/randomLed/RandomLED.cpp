#include <FastLED.h>
#include <RandomLED.h>

CRGB RandomLED::randomLED()
{
    int r = rand() % 255 + 1;
    int g = rand() % 255 + 1;
    int b = rand() % 255 + 1;

    CRGB randomColor = CRGB(r,g,b);

    return randomColor;
}