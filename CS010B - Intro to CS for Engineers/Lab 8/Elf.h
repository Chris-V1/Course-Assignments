#include <string>
#include "Character.h"
using namespace std;

#ifndef ELF_H
#define ELF_H
class Elf : public Character
{
    protected:
    string family;
    string e_name;
    double e_health;
    double e_attack;

    public:
    Elf(string, double, double, string);
    void attack(Character &opponent);
    string GetFam();
};
#endif