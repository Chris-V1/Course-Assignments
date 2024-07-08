// Cristian Molano - cmola002
// Section 20

#include "minFunc.h"
#include <iostream>
using namespace std;
const int * min(const int arr[], int arrSize) {
    
    const int *checker = &arr[arrSize - 2];
    const int *mini;
    /*
        5, 2, 13, 4, 7

       4 > 7

       13 > 4

       2 > 4

       5 > 2

       2
    */
    if(arrSize == 1)
    {
        mini = &arr[0];
        return mini;
    }
    if(arrSize == 0)
    {
        return nullptr;
    }
   else
   { 
     if(*checker > arr[arrSize - 1])
     {
        mini = &arr[arrSize - 1];
     }
     else
     {
        mini = &arr[arrSize - 2];
     }
     checker = min(arr, arrSize - 1);
     if(*checker < *mini)
     {
        mini = checker;
     }
   }
   return mini;
}