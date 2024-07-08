// Cristian Molano - cmola002
// Section 20

#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int charCnt(string, char);


int main() {
   string filename;
   char ch;
   int chCnt = 0;
   ifstream file;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   file.open(filename);
   if(file.is_open())
   {
      file.close();
      chCnt = charCnt(filename, ch);  
      cout << "# of " << ch << "'s: " << chCnt << endl;
   }
   else
   {
      cout << "Error opening " << filename << endl;
      exit(1);
   }
   
   
   
   return 0;
}

int charCnt(string filename, char c)
{
  ifstream file;
  file.open(filename);
  string line;
  int counter = 0;
  
  while(getline(file,line))
  {
     int size = line.size();
     for(int i = 0; i < size; ++i)
     {
        if(c!=' ')
        {
           if(line.at(i) == c)
            {
               ++counter;
            }
        }
        else
        {
           if(line.at(i) == ' ') 
            {
               ++counter;
            }
        }
        
     }
  }
  file.close();
  return counter;
}
