#include <iostream>
#include <string>

#include "Character.h"
#include "Wizard.h"

using namespace std;

    // private:
    // int rank;
    
    //public:
    
    Wizard::Wizard( const string &name, double health, double attackStrength,  int level )
         :Character(WIZARD, name, health, attackStrength), rank(level)
    {}
    
    void Wizard::attack(Character &cname)
    {
        double damage = 0;
        
        if(cname.getType() == WIZARD)
        {
            Wizard& opp = dynamic_cast<Wizard&>(cname);
            damage = (this->attackStrength) * (static_cast<double>(this->rank)) / (static_cast<double>(opp.rank));
            
            cout << "Wizard " << this->name << " attacks " << cname.getName() << " --- POOF!!" << endl;
            cout << cname.getName() << " takes " << damage << " damage."  << endl;
            
            cname.setHealth(cname.getHealth() - damage);
            return;
        }
        
        damage = attackStrength;
        cname.setHealth(cname.getHealth() - damage);
        
            cout << "Wizard " << this->name << " attacks " << cname.getName() << " --- POOF!!" << endl;
            cout << cname.getName() << " takes " << damage << " damage."  << endl;
        
        return;
    }
    
    // Stores the wizard's rank as an int.

// When a wizard attacks another wizard, the damage done is the wizard's attack strength multiplied by the ratio of the attacking wizard's rank over the defending wizard's rank.

// The damage done to non-wizards is just the attack strength. The wizard's health is not taken into consideration.
