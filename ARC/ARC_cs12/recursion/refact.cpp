// factirial

#include <iostream>

using namespace std;

unsigned int fact(unsigned int x);

int main()
{
    unsigned int p = 0;
    unsigned int r = 0;
    
    cout << "enter factorial num!" << endl;
    cin >> p;
    
    r = fact(p);
    cout << "Ans: " << endl;
    cout << r << endl;
    
    
 return 0;   
}

unsigned int fact(unsigned int x)
{
    unsigned int temp = x;
    
    if(x == 0)
    {
        return 1;
    }
    else if(x == 1)
    {
        return 1;
    }
    else
    {
        return temp * fact(x-1);
    }
    
    
}