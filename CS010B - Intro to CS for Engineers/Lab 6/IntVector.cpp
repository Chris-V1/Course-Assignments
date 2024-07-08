// Cristian Molano - cmola002
// Section 20

#include <iostream>
#include "IntVector.h"
#include <stdexcept>
using namespace std;

IntVector::IntVector(unsigned c, int v)
{
    _capacity = c;
    _size = c;
    if(_capacity != 0)
    {
        _data = new int[_capacity];
        for(unsigned i = 0; i < _capacity; ++i)
        {
            _data[i] = v;
            //cout << _data[i] << endl;
        }
        //cout << _data << endl;
    }
    else
    {
        _data = nullptr;
    }
}
IntVector::~IntVector()
{
    delete _data;
}
unsigned IntVector::size() const
{
    return _size;
}
unsigned IntVector::capacity() const
{
    return _capacity;
}
bool IntVector::empty() const
{
    if(_size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
const int& IntVector::at(unsigned index) const
{
    if(index < _size)
    {
        return _data[index];
    }
    else
    {
        throw out_of_range("IntVector::at_range_check");
    }
    
}
 const int& IntVector::front() const
 {
     return _data[0];
 }
 const int& IntVector::back() const
 {
     return _data[_capacity - 1];
 }