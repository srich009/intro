#include <iostream>

using namespace std;

    //Wallet class uses int dollars, cents;   
    //public:
    
    //constructors
        Wallet::Wallet()
        {
           this -> cents = cents;
            this -> dollars = dollars;
        }
        
        Wallet::Wallet(int cents);
        
        Wallet::Wallet(int dollars, int cents);
        
    //member functions
        Wallet Wallet::operator+(Wallet); // add wallet
        Wallet Wallet::operator+(int);    // add cents
        Wallet Wallet::operator-(Wallet); // subtract wallet
        Wallet Wallet::operator-(int);    // subtract cents
    // other funtions
        Change Wallet::getMoney();
        friend ostream& operator<<(ostream& out, Wallet);

//stream insertion
ostream& operator<<(ostream& out, Wallet);