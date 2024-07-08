// Cristian Molano - cmola002
// Section 20

#include <iostream>
#include "IntVector.h"
using namespace std;

int main()
{
    IntVector s = IntVector(0,10);

    cout << s.size() << endl;

    s.~IntVector();

    s = IntVector(1,10);

    cout << s.size() << endl;

    if(s.empty())
    {
        cout << "empty" << endl;
    }
    else
    {
        cout << "not empty" << endl;
    }

    cout << s.at(1) << endl;
    
    cout << s.front() << endl;

    cout << s.back() << endl;
    return 0;
}