#include <Arduino.h>
#include <FastLED.h>
#include <RandomLED.h>

#define NUM_LEDS 240
#define DATA_PIN D2

CRGB _leds[NUM_LEDS];
int _hueLeds[NUM_LEDS];

void setup()
{
  // put your setup code here, to run onc
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(_leds, NUM_LEDS);
  for (int dot = 0; dot < NUM_LEDS; dot++)
  {
    RandomLED randomLed;
    _leds[dot] = randomLed.getCHSV();
    _hueLeds[dot] = randomLed.getHue();
    FastLED.show();
  }
  Serial.println("LED Initiated");
}

void loop()
{
  for (int dot = 1; dot < NUM_LEDS; dot++)
  {
    CHSV ledOld = CHSV(_hueLeds[dot],255,255);
    _leds[dot] = CHSV(0,0,0);
    FastLED.show();
    delay(5);
    _leds[dot] = ledOld;
    FastLED.show();
    delay(5);
  }
}