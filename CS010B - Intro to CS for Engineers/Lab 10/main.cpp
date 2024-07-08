// Cristian Molano - cmola002
// Section 20

#include <iostream>

using namespace std;



#include "IntList.h"

int main() {

   int testNum;
   
   cout << "Enter test number: ";
   cin >> testNum;
   cout << endl;
   
   // Test removeOdds function when first, middle, and last values odd
   if (testNum == 1) {
      IntList test1;
      test1.push_front(-3);
      test1.push_front(8);
      test1.push_front(0);
      test1.push_front(3);
      test1.push_front(4);
      test1.push_front(2);
      test1.push_front(71);
      cout << "Before: " << test1 << endl;
      test1.removeOdds();
      cout << "After : " << test1 << endl;    
   }
   
   // Test removeOdds function when most values odd
   if (testNum == 2) {
      IntList test2;
      test2.push_front(-3);
      test2.push_front(-81);
      test2.push_front(1);
      test2.push_front(59);
      test2.push_front(4);
      test2.push_front(11);
      test2.push_front(43);
      test2.push_front(-3);
      test2.push_front(581);
      cout << "Before: " << test2 << endl;
      test2.removeOdds();
      cout << "After : " << test2 << endl;  
   }
   
   return 0;
}