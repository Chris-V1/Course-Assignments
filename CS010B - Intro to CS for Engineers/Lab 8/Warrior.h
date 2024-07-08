#include <string>
#include "Character.h"
using namespace std;

#ifndef WARRIOR_H
#define WARRIOR_H
class Warrior : public Character
{
    protected:
    string family;
    string w_name = name;
    double w_health = health;
    double w_attack = attackStrength;

    public:
    Warrior(string, double, double, string);
    void attack(Character &opponent);
    string GetFamily();
};
#endif