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
void IntVector::expand()
{
    
    _capacity = _capacity * 2;
    if(_capacity == 0)
    {
        _capacity = 1;
    }
    int a[100];
    for(unsigned int i = 0; i < _size; ++i)
    {
        a[i] = _data[i];
    }
    _data = new int[_capacity];
   // _size = _capacity;
    for(unsigned int j = 0; j < _size; ++j)
    {
        _data[j] = a[j];
    }
}
void IntVector::expand(unsigned amount)
{
    /*int *d = _data;
    //delete _data;
    _capacity = amount; 
    _data = new int[amount];
    _data = d;
    */
    //////////
    int a[500];
    for(unsigned int i = 0; i < _size; ++i)
    {
        a[i] = _data[i];
    }
    _data = new int[_capacity + amount];
    _capacity = _capacity + amount;
    for(unsigned int j = 0; j < _size; ++j)
    {
        _data[j] = a[j];
    }

}
void IntVector::insert(unsigned index, int value)
{
    if(index > _size)
    {
        throw out_of_range("IntVector::insert_range_check");
    }
    if(_size + 1 > _capacity)
    {
        expand();
    }
    _size = _size + 1;
    

    for(unsigned int i = index; i < _size - index; ++i)
    {
        _data[i + 1] = _data[i];
    }
    _data[index] = value;
}
void IntVector::erase(unsigned index)
{ 
    if(index >= _size)
    {
        throw out_of_range("IntVector::erase_range_check");
    }
    _size = _size - 1;
    for(unsigned int i = index; i < (_size + 1) - index; ++i)
    {
        _data[i] = _data[i + 1];
    }
}
void IntVector::push_back(int value)
{
    
    if(_size + 1 > _capacity)
    {
       expand();
       
    }
    
    unsigned int s = _size;
    _data[s] = value;
    _size = _size + 1;
    
}
void IntVector::pop_back()
{
   _size = _size - 1;
}
void IntVector::clear()
{
    _size = 0;
}
void IntVector::resize(unsigned size, int value)
{   
    //cout << "old capacity is " << _capacity << endl;
    if(size > _capacity)
    {
        if(size > _capacity * 2)
        {
            expand(size - _capacity);
        }
        else
        {
            expand();
        }
        
    }
    //cout << "new capacity is " << _capacity << endl;
    if(size < _size)
    {
        _size = size;
    }
    else if(size > _size)
    {
        for(unsigned int i = _size; i < size; ++i)
        {
           // cout << "doin stuff" << endl;
            _data[i] = value;
        }
        _size = size;
        //cout << "capacity is " << _capacity << endl;
    }
}
void IntVector::reserve(unsigned n)
{
    if(_capacity < n)
    {
        expand(n - _capacity);
    }
}
void IntVector::assign(unsigned n, int value)
{
    delete _data;
     if(n>_capacity)
     {
        if(n  > _capacity * 2)
            {
                expand(n - _capacity);
            }
            else
            {
                expand();
            }
     }
    _size = n;
    for(unsigned i = 0; i < _capacity; ++i)
    {
            _data[i] = value;
            
    }
}
int & IntVector::at(unsigned index)
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
int & IntVector::front()
{
    return _data[0];
}
int& IntVector::back()
{
    return _data[_size - 1];
}
