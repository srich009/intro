//recursive multiply

#include <iostream>

using namespace std;

// returns the product of the two arguments
int mul(int, int);

int main()
{
    int x = 0;
    int y = 0;
    
    int z = 0;
    
    cout << "enter 2 nums:" << endl;
    cin >> x >> y;
    
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    
    z = mul(x,y);
    
    cout << "x*y = " << z << endl;
    
    
    return 0;
}

// returns the product of the two arguments
int mul(int x, int y)
{
    if(x == 0 || y == 0)
    {
        return 0;   
    }
    
    return x + mul(x, y - 1);
    
}