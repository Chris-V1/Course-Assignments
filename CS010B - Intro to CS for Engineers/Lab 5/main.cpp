// Cristian Molano - cmola002
// Section 20

#include<iostream> 
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   
   // verify file name provided on command line
   string inputfile;
   inputfile = argv[1];
   // open file and verify it opened
   ifstream file; 
   file.open(inputfile);
   if(!file.is_open())
   {
      cout << "Error opening " << inputfile;
      exit(1);
   }
   // Declare an array of doubles of size ARR_CAP.
   double a[ARR_CAP]; 
    
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
   //string str;
   //size_t offset = 0;
   double d;
   int i = 0;
   while(file >> d)
   {
      //d = stod(str, offset);
      a[i] = d;
      ++i;
   }
    
   // Call the mean function passing it this array and output the 
   // value returned.
   double m;
   m = mean(a, i);
   cout << "Mean: " << m << endl;
    
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
   cout << "Enter index of value to be removed (0 to " << i - 1 << "):" << endl;
   int remove_index;
   cin >> remove_index;
	
   // Call the display function to output the array.
   cout <<"Before removing value: " << endl;
   display(a, i);
   
   // Call the remove function to remove the value at the index
   // provided by the user.
   
   remove(a,i,remove_index);
    
   // Call the display function again to output the array
   // with the value removed.
   cout <<"After removing value: " << endl;
   display(a, i);
   
   // Call the mean function again to get the new mean
m = mean(a, i);
   cout << "Mean: " << m << endl;
   
	return 0;
}
double mean (const double array[], int arraySize)
{
   double sum = 0.0;
   for(int i = 0; i < arraySize; ++i)
   {
      sum = sum + array[i];
   }
   return sum/arraySize;
}
void remove(double array[], int &arraySize, int index)
{
   //  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
   //  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
   //  - Reduces arraySize by 1.
   for(int i = index; i < arraySize; ++i)
   {
      if(i != arraySize - 1)
      {
         array[i] = array[i + 1];
      }
   }
   arraySize = arraySize - 1;
}
void display(const double array[], int arraySize)
{
   for(int i = 0; i < arraySize - 1; ++i)
   {
      cout << array[i] <<", ";
   }
   cout << array[arraySize - 1] << endl;
}