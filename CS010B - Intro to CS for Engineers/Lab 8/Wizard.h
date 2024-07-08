#include <string>
#include "Character.h"
using namespace std;

#ifndef WIZARD_H
#define WIZARD_H
class Wizard : public Character
{
    protected:
    string wiz_name = name;
    double wiz_health = health;
    double wiz_attack = attackStrength;
    int wiz_rank;

    public:
    Wizard(string, double, double, int);
    void attack(Character &opponent);
};
#endif