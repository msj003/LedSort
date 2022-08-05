#include<StripSortController.h>
#include<StripAccessSingleton.h>

#define NUM_LEDS 240

StripAccessSingleton* StripAccessSingleton::_instance = 0;
StripAccessSingleton*  stripAccess = StripAccessSingleton::get();

StripSortController::StripSortController()
{}

void StripSortController::intialize()
{
    stripAccess->randomize();
}

void StripSortController::testColor()
{
    Serial.println(stripAccess->getHue(1));
    Serial.println(stripAccess->getHue(2));
    Serial.println(stripAccess->getHue(3));
    Serial.println(stripAccess->getHue(4));
    Serial.println(stripAccess->getHue(5));
    Serial.println(stripAccess->getHue(6));
    stripAccess->setHue(1,100);
    stripAccess->setHue(2,112);
    stripAccess->setHue(3,32);
    stripAccess->setHue(4,222);
    stripAccess->setHue(5,0);
    stripAccess->setHue(6,149);


    Serial.println("-----------------After--------------------");
    Serial.println(stripAccess->getHue(1));
    Serial.println(stripAccess->getHue(2));
    Serial.println(stripAccess->getHue(3));
    Serial.println(stripAccess->getHue(4));
    Serial.println(stripAccess->getHue(5));
    Serial.println(stripAccess->getHue(6));
}


void StripSortController::runningDot()
{
    for (int dot = 1; dot < NUM_LEDS; dot++)
    {   
       int hueIdx = stripAccess->getHue(dot);
       stripAccess->setHue(dot,hueIdx);
    }
}




void StripSortController::insertionSort()
{    
    int i, key, j; 
    for (i = 1; i < NUM_LEDS; i++)
    { 
        key = stripAccess->getHue(i); 
        j = i - 1; 
  
        // Move elements of arr[0..i-1],  
        // that are greater than key, to one 
        // position ahead of their 
        // current position
        while (j >= 0 && stripAccess->getHue(j) > key)
        { 
            stripAccess->setHue((j + 1),stripAccess->getHue(j)); 
            j = j - 1; 
        } 
        stripAccess->setHue((j + 1),key); 
    }
}

void StripSortController::selectionSort() 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of 
    // unsorted subarray 
    for (i = 0; i < NUM_LEDS-1; i++) 
    { 
        
        // Find the minimum element in 
        // unsorted array 
        min_idx = i; 
        for (j = i+1; j < NUM_LEDS; j++) 
        if (stripAccess->getHue(j) < stripAccess->getHue(min_idx)) 
            min_idx = j; 
  
        // Swap the found minimum element 
        // with the first element 
        int temp = stripAccess->getHue(min_idx);
        stripAccess->setHue(min_idx,stripAccess->getHue(i));
        stripAccess->setHue(i,temp);
    } 
} 


