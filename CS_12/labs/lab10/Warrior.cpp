#include <iostream>
#include <string>

#include "Character.h"
#include "Warrior.h"

using namespace std;

    // private:
    // string allegiance;
    
    //public:
 
    Warrior::Warrior( const string &name, double health, double attackStrength, const string &tribe)
       :Character(WARRIOR, name, health, attackStrength), allegiance(tribe)
    {}
    
    void Warrior::attack(Character &cname)
    {
        if(cname.getType() == WARRIOR)
        {
           Warrior &opp = dynamic_cast<Warrior &>(cname);
            if(opp.allegiance == this->allegiance)
            {
                cout << "Warrior " << this->name << " does not attack Warrior " << cname.getName() << "." << endl;
                cout << "They share an allegiance with " << opp.allegiance << "." << endl;
                
                return;
            }
        }
        
       double damage = 0;
       damage = (this->health / MAX_HEALTH) * (this->attackStrength) ;
       
       cname.setHealth(cname.getHealth() - damage);
        
        cout << "Warrior " << this->name << " attacks " << cname.getName() << " --- SLASH!!" << endl;
        cout << cname.getName() << " takes " << damage << " damage."  << endl;
    
        return;


    }
    
    // Warrior

// Stores the warrior's allegiance as a string.

// The warrior does not attack warriors that have the same allegiance.

//The damage done by the warrior is the percentage of the warrior's health remaining (health / MAX_HEALTH) multiplied by the warrior's attack strength.
    //Warrior &opp = dynamic_cast<Warrior &>(opponent);