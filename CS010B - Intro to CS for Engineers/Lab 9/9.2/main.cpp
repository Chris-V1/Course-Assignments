// Cristian Molano - cmola002
// Section 20

#include <iostream>

using namespace std;

#include "minFunc.h"

int main() {
   const int arrSize = 5;
  // cin >> arrSize;
   if (arrSize > 0) {
      int arr[arrSize] = {5, 4, 1, 2, 3};
      
      /*

      for (int i = 0; i < arrSize; ++i) {
         cin >> arr[i];
      }
      */
      const int *minLoc = min(arr, arrSize);
      cout << *minLoc << endl;
   }   
   return 0;
}
