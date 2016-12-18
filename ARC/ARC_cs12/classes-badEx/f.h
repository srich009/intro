#include <iostream>

using namespace std;

#define debug(A) std::cout << #A << ": '" << A << '\'' << std::endl

struct Change {
    unsigned int pennies,
                 nickels,
                 dimes,
                 quarters,
                 dollars,
                 fives,
                 tens,
                 twenties,
                 fifties,
                 hundreds;
};

class Wallet {
    private:
        // You do it!
        int cents;
        int dollars;
        
    public:
        // do what makes cents ;)
        Wallet();
        Wallet(int cents);
        Wallet(int dollars, int cents);

        Wallet operator+(Wallet); // add wallet
        Wallet operator+(int);    // add cents
        Wallet operator-(Wallet); // subtract wallet
        Wallet operator-(int);    // subtract cents

        Change getMoney();
        friend ostream& operator<<(ostream& out, Wallet);
};

ostream& operator<<(ostream& out, Wallet);