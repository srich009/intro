//recursive pow

#include <iostream>

using namespace std;

double pow(double base, unsigned int exponent);

int main()
{
    double b = 0;
    unsigned e = 0;
    double k = 0;
    
    cout << "base then expon" << endl;
    cin >> b >> e;
    
   k=  pow(b,e);
   
   cout << "ans" << endl;
   cout << k << endl;
    
    
    return 0;
}

double pow(double base, unsigned int exponent)
{
    if(exponent == 0)
    {
        return 1;
    }
    return base * pow(base, exponent - 1);
    
}