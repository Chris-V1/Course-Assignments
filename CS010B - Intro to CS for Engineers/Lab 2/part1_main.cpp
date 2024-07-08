// Cristian Molano - cmola002
// Section 20

#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;


int fileSum(string filename);


int main() {

   string filename;
   ifstream file;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;

   file.open(filename);
   if(file.is_open())
   {
      file.close();
      sum = fileSum(filename);
      cout << "Sum: " << sum << endl;
      
   }
   else
   {
      cout << "Error opening " << filename << endl;
      return 1;
   }
   
   

   
   
   return 0;
}

int fileSum(string filename)
{
   ifstream file;
   file.open(filename);
   int num, sum = 0;
   
   while(file >> num)
   {
      sum = sum + num;
   }
   file.close();
   return sum;
}