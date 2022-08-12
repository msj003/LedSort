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


void merge(int const left, int const mid,
           int const right)                                                                
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = stripAccess->getHue(left + i);
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = stripAccess->getHue(mid + 1 + j);
 
    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            stripAccess->setHue(indexOfMergedArray,leftArray[indexOfSubArrayOne]);
            indexOfSubArrayOne++;
        }
        else {
            stripAccess->setHue(indexOfMergedArray, rightArray[indexOfSubArrayTwo]);
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
       stripAccess->setHue(indexOfMergedArray, leftArray[indexOfSubArrayOne]);
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        stripAccess->setHue(indexOfMergedArray,rightArray[indexOfSubArrayTwo]);
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(begin, mid);
    mergeSort(mid + 1, end);
    merge(begin, mid, end);
}

void StripSortController::mergeSortControl() 
{ 
    Serial.println("Merge Sort Begin");
    stripAccess->printHueArray();
     mergeSort(0, NUM_LEDS - 1);
     Serial.println("Merge Sort End");
     stripAccess->printHueArray();
}

// ------------
// Quick Sort 
// ------------

void swap(int i, int j){
    // Swap
        int temp = stripAccess->getHue(i);
        stripAccess->setHue(i,stripAccess->getHue(j));
        stripAccess->setHue(j,temp);
}

int partition (int low, int high) 
{ 
    int pivot = stripAccess->getHue(high); // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (stripAccess->getHue(j) < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(i, j); 
        } 
    } 
    swap(i + 1, high); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(low, pi - 1); 
        quickSort(pi + 1, high); 
    } 
} 

void StripSortController::quickSortControl() 
{ 
    Serial.println("Quick Sort Begin");
     quickSort(0, NUM_LEDS - 1);
     Serial.println("Quick  Sort End");
}