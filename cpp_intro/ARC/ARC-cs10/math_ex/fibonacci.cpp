// eh

#include <iostream>

using namespace std;

int main ()
{

    int userValue = 0;
    int fibNum1 = 1;
    int fibNum2 = 1; 
    int nextNum = 0;
    
    cout << "Prints n Numbers of Fibonacci sequence " << endl;
    cout << "Enter a value for n,  0 < n < 46" << endl;
    cout << ">>: ";
    cin >> userValue;
    
    cout << fibNum1 << ", ";
     
    if(userValue >= 2)
    {
    cout << fibNum2 << ", ";
    }
   
    
    for(int i = 2; i < userValue; i++)
    {
        
        nextNum = fibNum1 + fibNum2;
        cout << nextNum << ", ";
        fibNum1 = fibNum2;
        fibNum2 = nextNum;
        
        
    }

    cout << endl; 
return 0;    
}
