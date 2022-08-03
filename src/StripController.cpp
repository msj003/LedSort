#include<StripController.h>
#include<StripAccessSingleton.h>


StripAccessSingleton* StripAccessSingleton::_instance = 0;
StripAccessSingleton*  stripAccess = StripAccessSingleton::get();

StripController::StripController()
{}

void StripController::testColor()
{
    for (int dot = 40; dot < 200; dot++)
    {
        stripAccess->setHue(dot,0);
    }
}


void StripController::runningDot()
{
    for (int dot = 1; dot < 240; dot++)
    {   
       int hueIdx = stripAccess->getHue(dot);
       stripAccess->setHue(dot,hueIdx);
    }
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



