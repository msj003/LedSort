#include <Arduino.h>
#include <FastLED.h>
#include <RandomLED.h>

#define NUM_LEDS 240
#define DATA_PIN D2

CRGB leds[NUM_LEDS];

void setup()
{
  // put your setup code here, to run onc
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  // for (int dot = 0; dot < NUM_LEDS; dot++)
  // {
  //   RandomLED random;
  //   leds[dot] = random.randomLED();
  //   FastLED.show();
  //   // clear this led for the next time around the loop
  //   // leds[dot] = CRGB::Black;
  //   // delay(70);
  // }
  Serial.println("LED Initiated");
}

void loop()
{
  // put your main code here, to run repeatedly:
  // Serial.readBytes((char *)&leds[1], 3);

  // Serial.println("LED LED");
  // CRGB led1 = Serial.readBytes((char *)&leds[2], 3);
  // Serial.println(led1.r);

  for (int dot = 0; dot < NUM_LEDS; dot++)
  {
    RandomLED random;
    leds[dot] = random.randomLED();
    FastLED.show();
    // clear this led for the next time around the loop
    // leds[dot] = CRGB::Black;
    // delay(70);
  }

  for (int dot = 1; dot < NUM_LEDS; dot++)
  {
    CRGB ledOld = leds[dot];
    leds[dot] = CRGB::Blue;
    FastLED.show();
    delay(10);
    leds[dot] = ledOld;
    // clear this led for the next time around the loop
    delay(10);
  }
}