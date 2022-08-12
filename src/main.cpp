#include <Arduino.h>
#include <StripSortController.h>


StripSortController stripSortController;

void setup()
{
  // put your setup code here, to run onc
  Serial.begin(9600);

  Serial.println("LED Initiated");
  //stripSortController.testColor();
}

void loop()
{
  stripSortController.runningDot();
  stripSortController.intialize();
  stripSortController.insertionSort();
  delay(1000);
  stripSortController.runningDot();
  stripSortController.intialize();
  stripSortController.mergeSortControl();
  delay(1000);
  stripSortController.runningDot();
  stripSortController.intialize();
  stripSortController.selectionSort();
  delay(1000);
  stripSortController.runningDot();
  stripSortController.intialize();
  stripSortController.quickSortControl();
  delay(1000);
}