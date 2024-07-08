// Cristian Molano - cmola002
// Section 20

#include "Character.h"
#include <string>
#include <iostream>
using namespace std;

Character::Character(HeroType h, const string &s, double hea, double a)
{
    type = h;
    name = s;
    this->health = hea;
    attackStrength = a;
}
HeroType Character::getType() const
{
    return type;
}
const string& Character::getName() const
{
    return name;
}
int Character::getHealth() const
{
    return static_cast<int>(health);
}
void Character::damage(double d)
{
    health = health - d;
}
bool Character::isAlive() const
{
    if(health  > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Character::attack(Character &c)
{
    
}

