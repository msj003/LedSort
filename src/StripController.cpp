#include<StripController.h>
#include<StripAccess.h>


void StripController::intialize()
{
    StripAccess::init();
}

void StripController::testColor()
{
    
    for (int dot = 40; dot < 200; dot++)
    {
        StripAccess::setHue(dot,0);
    }

}


void StripController::runningDot()
{
// for (int dot = 1; dot < NUM_LEDS; dot++)
//   {
//     CHSV ledOld = CHSV(_hueLeds[dot],255,255);
//     CHSV ledOld30 = CHSV(_hueLeds[dot+30],255,255);
//     _leds[dot] = CHSV(0,0,0);
//     FastLED.show();
//     _leds[dot+30] = CHSV(0,0,0);
//     FastLED.show();
//     delay(10);
//     _leds[dot] = ledOld;
//     _leds[dot+30] = ledOld30;
//     FastLED.show();
//     delay(10);
//   }
}




void StripController::sort()
{
    // _hueLeds[50] = 0;
    // _hueLeds[100] = 255;
    // for (int dot = 1; dot < NUM_LEDS; dot++)
    // {
    //     _leds[dot] = CHSV(_hueLeds[dot],255,255);
    //     StripController::refresh();
    //     delay(10);
    // }
}



