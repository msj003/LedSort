#include <FastLED.h>

class StripAccessSingleton
{
    public:
        static StripAccessSingleton* get(){
            if(! _instance){ _instance = new StripAccessSingleton;}
            return _instance;
        }
        void randomize();
        void setHue(int index, int hue);
        int getHue(int index);
        void printHueArray();
    private:
        static StripAccessSingleton* _instance;
        StripAccessSingleton();
        ~StripAccessSingleton();

};