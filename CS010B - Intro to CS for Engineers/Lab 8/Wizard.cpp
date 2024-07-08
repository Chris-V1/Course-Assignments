// Cristian Molano - cmola002
// Section 20

#include "Wizard.h"
#include "Warrior.h"
#include "Elf.h"
#include <string>
#include "Character.h"
#include <iostream>
using namespace std;

Wizard::Wizard(string n, double h, double a, int r):Character(WIZARD,n,h,a)
{
    wiz_rank = r;
    wiz_name = n;
    wiz_health = h;
    wiz_attack = a;
    attackStrength = a;
    health = h;
    name = n;
}
void Wizard::attack(Character &opponent)
{
    
    double dam = 0.0;
    if(opponent.getType() == WIZARD)
    {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        cout << "Wizard " << wiz_name << " attacks " << opp.wiz_name << " --- POOF!!" << endl;
        dam = static_cast<double>(wiz_attack) * (static_cast<double>(wiz_rank)/static_cast<double>(opp.wiz_rank));
        opp.damage(dam);
        cout << opp.wiz_name << " takes " << dam << " damage." << endl;
        return;
    }
    else if(opponent.getType() == WARRIOR)
    {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        cout << "Wizard " << name << " attacks " << opp.getName() << " --- POOF!!" << endl;
        //damage(static_cast<double>(attackStrength)); 
        dam = static_cast<double>(attackStrength);
        opp.damage(attackStrength);
        cout << opp.getName() << " takes " << dam << " damage." << endl;
        return;
    }
    else if(opponent.getType() == ELF)
    {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        cout << "Wizard " << name << " attacks " << opp.getName() << " --- POOF!!" << endl;
        opp.damage(static_cast<double>(attackStrength)); 
        dam = static_cast<double>(attackStrength);
        cout << opp.getName() << " takes " << dam << " damage." << endl;
        return;
    }
   
}