#include <FastLED.h>

class StripAccess
{
    public:
        static void init();
        static int * getStripArray();
        static void setHue(int index, int hue);
};