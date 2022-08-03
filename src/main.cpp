#include <Arduino.h>
#include <FastLED.h>
#include <RandomColor.h>
#include <StripController.h>


StripController stripController;

void setup()
{
  // put your setup code here, to run onc
  Serial.begin(9600);

  Serial.println("LED Initiated");
}

void loop()
{
  stripController.runningDot();

  //StripController::testColor();

  
}