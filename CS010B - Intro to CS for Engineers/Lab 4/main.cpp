// Cristian Molano - cmola002
// Section 20

#include <iostream>
#include "IntVector.h"
using namespace std;

int main()
{
    IntVector s = IntVector(2,10);

    /*
    cout << s.size() << endl;

    s.~IntVector();

    s = IntVector(10,10);

    cout << s.size() << endl;

    if(s.empty())
    {
        cout << "empty" << endl;
    }
    else
    {
        cout << "not empty" << endl;
    }

    cout << "vector at 1 is: " << s.at(1) << endl;
    
    cout << "vector at 0 is: " <<s.front() << endl;

    cout << "vector at end is: " <<s.back() << endl;

    //test insert
    s.insert(5,5);
    cout << endl;
    for(unsigned int i = 0; i < s.size(); ++i)
    {
        cout << s.at(i) << endl;
    }
    cout << endl;

    //test erase
    s.erase(5);
    for(unsigned int i = 0; i < s.size(); ++i)
    {
        cout << s.at(i) << endl;
    }

    //test push back
    s.push_back(20);
    cout << endl;
    for(unsigned int i = 0; i < s.size(); ++i)
    {
        cout << s.at(i) << endl;
    }
    cout << endl;

    //test pop back
    s.pop_back();
    cout << endl;
    for(unsigned int i = 0; i < s.size(); ++i)
    {
        cout << s.at(i) << endl;
    }
    cout << endl;

    //test clear
    s.clear();
    cout << s.size() << endl;

    //test resize
    s.~IntVector();
    s = IntVector(10,10);
    s.resize(15,30);
    cout << endl;
    for(unsigned int i = 0; i < s.size(); ++i)
    {
        cout << s.at(i) << endl;
    }
    cout << endl;

    //test reserve
    s.reserve(12);

    //test assign
    s.assign(5,13);
    cout << endl;
    for(unsigned int i = 0; i < s.size(); ++i)
    {
        cout << s.at(i) << endl;
    }
    cout << endl;
    */
   /*
   cout << "old array:" << endl;
    for(unsigned int i = 0; i < s.size(); ++i)
    {
        cout << s.at(i) << endl;
    }
    cout << endl << "newer array: " << endl;
    s.push_back(1);
   //cout << s.at(1) << endl;
   for(unsigned int i = 0; i < s.size(); ++i)
    {
        cout << s.at(i) << endl;
    }
    cout << endl;
    */
    /////////////////////////////////////////////////////////
    s.~IntVector();
    s = IntVector(0,10);
    s.resize(20,30);
    cout << endl;
    for(unsigned int i = 0; i < s.size(); ++i)
    {
        cout << s.at(i) << endl;
    }
    cout << endl;

    return 0;
}