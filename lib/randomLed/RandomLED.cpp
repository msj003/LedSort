#include <FastLED.h>
#include <RandomLED.h>

int hue;
int sat;
int val;

RandomLED::RandomLED()
{
    hue = rand() % 255 + 1;
    sat = 255;
    val = 255;
}

CHSV RandomLED::getCHSV()
{
    CHSV randomColor = CHSV(hue,sat,val);
    return randomColor;
}

int RandomLED::getHue()
{
    return hue;
}