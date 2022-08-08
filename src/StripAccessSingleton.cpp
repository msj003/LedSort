#include<StripAccessSingleton.h>
#include<RandomColor.h>
#include<FastLED.h>

#define DATA_PIN D2
#define NUM_LEDS 240

CRGB _leds[NUM_LEDS];
int _hueLeds[NUM_LEDS];

StripAccessSingleton::StripAccessSingleton()
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

void StripAccessSingleton::randomize()
{
    for (int dot = 0; dot < NUM_LEDS; dot++)
    {
        RandomColor randomColor;
        _leds[dot] = randomColor.getCHSV();
        _hueLeds[dot] = randomColor.getHue(); 
        FastLED.show();
        delay(5);
    }
}

void StripAccessSingleton::setHue(int index, int hue)
{
    _hueLeds[index] = hue;
    _leds[index] = CRGB(255,255,255);
    FastLED.show();
    delay(0.1);
    _leds[index] = CHSV(hue,255,255);
    FastLED.show();
    delay(0.1);
}

int StripAccessSingleton::getHue(int index)
{
    return  _hueLeds[index];
}

void StripAccessSingleton::printHueArray()
{
    for (int dot = 0; dot < NUM_LEDS; dot++)
    {
        Serial.println(_hueLeds[dot]);
    }
}