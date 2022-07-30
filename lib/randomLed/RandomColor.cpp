#include <FastLED.h>
#include <RandomColor.h>

int hue;
int sat;
int val;

RandomColor::RandomColor()
{
    hue = rand() % 255 + 1;
    sat = 255;
    val = 255;
}

CHSV RandomColor::getCHSV()
{
    CHSV randomColor = CHSV(hue,sat,val);
    return randomColor;
}

int RandomColor::getHue()
{
    return hue;
}