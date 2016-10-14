// recursive collatz


#include <iostream>
#include <string>

using namespace std;

void collatz(unsigned int);


int main ()
{
    unsigned c =0;
    cout << "enter num" << endl;
    cin >> c;
    
    collatz(c);
    
    
    return 0;
}

void collatz(unsigned int c)
{
    if(c == 1){
        return;    
    }   
    else if(c % 2 == 0)
    {
        cout << c / 2 << endl;
        collatz(c/2);
    }
    else
    {
        cout << c*3 + 1 << endl;
        collatz(c*3 + 1);
    }
    
}