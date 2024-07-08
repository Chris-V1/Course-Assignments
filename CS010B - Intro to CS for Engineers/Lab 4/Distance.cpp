// Cristian Molano - cmola002
// Section 20

#include <iostream>
#include "Distance.h"
using namespace std;

Distance::Distance()
{
    feet = 0;
    inches = 0.0;
}
Distance::Distance(unsigned ft, double in)
{
    int f = (short) ft;
    inches = in;
    if(f < 0)
    {
        f = f * -1;
    }
    if( inches < 0)
    {
        inches = inches * -1;
    }
    
    feet = f;
    
    while(inches >= 12)
    {
        feet = feet + 1;
        inches = inches - 12;
    }
    
    
}
Distance::Distance(double in)
{
    feet = 0; 
    inches = in;
    if(inches < 0)
    {
        inches = inches * -1;
    }
    
    while(inches >= 12)
    {
        feet = feet + 1;
        inches = inches - 12;
    }
}
unsigned Distance::getFeet() const
{
    return feet;
}
double Distance::getInches() const
{
    return inches;
}
double Distance::distanceInInches() const
{
    double f = feet * 12;
    return f + inches;
}
double Distance::distanceInFeet() const
{
    double i = inches / 12;
    return i + feet;
}
double Distance::distanceInMeters() const
{
   double m1 = inches * 0.0254;
   double m2 = (feet * 12) * 0.0254;
   return m1 + m2;
}
Distance Distance::operator+(const Distance &rhs) const
{
    Distance d(this->feet + rhs.getFeet(),this->inches + rhs.getInches());
    return d;

}
Distance Distance::operator-(const Distance &rhs) const
{   
    int f = this->feet - rhs.getFeet();
    double i = this->inches - rhs.getInches();
    if(f < 0)
    {
        f = f + 1;
        i = rhs.getInches() + 12 - this->inches;
    }
    if(i < 0)
    {
        f = f - 1;
        i = this->inches+12-rhs.getInches();
    }
    Distance d(f, i);
    return d;
}
ostream & operator<<(ostream &out, const Distance &rhs)
{
    out << rhs.getFeet() << "' " << rhs.getInches() << "\"";
    return out;
}
void Distance::init()
{
    if(feet < 0)
    {
        feet = feet * -1;
    }
    if(inches < 0.0)
    {
        inches = inches * -1.0;
    }
}