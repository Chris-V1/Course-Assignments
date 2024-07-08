// Cristian Molano - cmola002
// Section 20

#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

void flipString(string &s)
{
   if(s.size() == 0)
   {
      return;
   }
   
          
          string temp = s.substr(1,s.size());
          flipString(temp);
          s = temp + s.at(0);
        

            
   
   
}


