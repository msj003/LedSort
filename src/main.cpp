#include <Arduino.h>
#include <FastLED.h>
#include <RandomColor.h>
#include <StripController.h>


void setup()
{
  // put your setup code here, to run onc
  Serial.begin(9600);

  StripController::intialize();
  //FastLED.show();
  Serial.println("LED Initiated");
}

void loop()
{
  //StripController::runningDot();

  StripController::testColor();

  
}