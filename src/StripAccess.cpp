#include<StripAccess.h>
#include<RandomColor.h>
#include<FastLED.h>

#define DATA_PIN D2
#define NUM_LEDS 240

CRGB _leds[NUM_LEDS];
int _hueLeds[NUM_LEDS];

void StripAccess::init()
{
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(_leds, NUM_LEDS);
    for (int dot = 0; dot < NUM_LEDS; dot++)
    {
        RandomColor randomColor;
        _leds[dot] = randomColor.getCHSV();
        _hueLeds[dot] = randomColor.getHue(); 
        FastLED.show();
        delay(5);
    }
}

int * StripAccess::getStripArray()
{
    return  _hueLeds;
}


void StripAccess::setHue(int index, int hue)
{
    _hueLeds[index] = hue;
    _leds[index] = CHSV(255,255,255);
    FastLED.show();
    delay(30);
    _leds[index] = CHSV(hue,255,255);
    FastLED.show();
    delay(5);
}