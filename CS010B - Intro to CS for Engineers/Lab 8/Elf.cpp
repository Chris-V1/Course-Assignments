// Cristian Molano - cmola002
// Section 20

#include "Wizard.h"
#include "Warrior.h"
#include "Elf.h"
#include <string>
#include "Character.h"
#include <iostream>
using namespace std;

Elf::Elf(string n, double h, double a, string fam):Character(ELF,n,h,a)
{
    family = fam;
    e_name = n;
    name = n;
    e_health = h;
    health = h;
    e_attack = a;
    attackStrength = a;
    
}
string Elf::GetFam()
{
    return family;
}
void Elf::attack(Character &opponent)
{
    double dam = 0.0;
    if(opponent.getType() == WIZARD)
    {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        cout << "Elf " << e_name << " shoots an arrow at " << opp.getName() << " --- TWANG!!" << endl;
        opp.damage((health/MAX_HEALTH)*attackStrength);
        dam = (health/MAX_HEALTH)*attackStrength;
        cout << opp.getName() << " takes " << dam << " damage." << endl;
        return;
    }
    else if(opponent.getType() == ELF)
    {
        Elf &opp = dynamic_cast<Elf &>(opponent);

        if(opp.GetFam() == family)
        {
            cout << "Elf "<< name << " does not attack Elf " << opp.getName() << "."<<endl;
            cout << "They are both members of the " << family << " family." << endl;
        }
        else
        {
            cout << "Elf " << e_name << " shoots an arrow at " << opp.getName() << " --- TWANG!!" << endl;
            opp.damage((health/MAX_HEALTH)*attackStrength);
            dam = (health/MAX_HEALTH)*attackStrength;
            cout << opp.getName() << " takes " << dam << " damage." << endl;
        }
        return;
    }
    else if(opponent.getType() == WARRIOR)
    {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        cout << "Elf " << e_name << " shoots an arrow at " << opp.getName() << " --- TWANG!!" << endl;
        opp.damage((health/MAX_HEALTH)*attackStrength);
        dam = (health/MAX_HEALTH)*attackStrength;
        cout << opp.getName() << " takes " << dam << " damage." << endl;
        return;
    }
}