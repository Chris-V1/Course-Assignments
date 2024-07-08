// Cristian Molano - cmola002
// Section 20

#include "Wizard.h"
#include "Warrior.h"
#include "Elf.h"
#include <string>
#include "Character.h"
#include <iostream>
using namespace std;

Warrior::Warrior(string n, double h, double a, string fam):Character(WARRIOR,n,h,a)
{
    family = fam;
    w_name = n;
    w_health = h;
    w_attack = a;
    attackStrength = a;
    health = h;
    name = n;
}
string Warrior::GetFamily()
{
    return family;
}
void Warrior::attack(Character &opponent)
{   
    
    double dam = 0.0;
    if(opponent.getType() == WIZARD)
    {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        cout << "Warrior " << w_name << " attacks " << opp.getName() << " --- SLASH!!" << endl;
        opp.damage((health/MAX_HEALTH)*attackStrength);
        dam = (health/MAX_HEALTH)*attackStrength;
        cout << opp.getName() << " takes " << dam << " damage." << endl;
        return;
    }
    else if(opponent.getType() == WARRIOR)
    {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if(opp.GetFamily() == family)
        {
            cout << "Warrior "<< name << " does not attack Warrior " << opp.getName() << "."<<endl;
            cout << "They share an allegiance with " << family << "." << endl;
        }
        else
        {
            cout << "Warrior " << w_name << " attacks " << opp.getName() << " --- SLASH!!" << endl;
            opp.damage((health/MAX_HEALTH)*attackStrength);
            dam = (health/MAX_HEALTH)*attackStrength;
            cout << opp.getName() << " takes " << dam << " damage." << endl;
        }
        return;
    }
    else if(opponent.getType() == ELF)
    {
        
        Elf &opp = dynamic_cast<Elf &>(opponent);
        cout << "Warrior " << w_name << " attacks " << opp.getName() << " --- SLASH!!" << endl;
        opp.damage((health/MAX_HEALTH)*attackStrength);
        dam = (health/MAX_HEALTH)*attackStrength;
        cout << opp.getName() << " takes " << dam << " damage." << endl;
        return;
        
    }
}