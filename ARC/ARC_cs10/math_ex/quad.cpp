/*
quadratic equation solver
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main ()
{
    // variables
    double userA = 0.0;
    double userB = 0.0;
    double userC = 0.0;
    
    double theDiscrim = 0.0;
    double rootX1 = 0.0;
    double rootX2 = 0.0;
    
    // user imput
    cout << "Enter a value for A: ";
    cin >> userA;
    cout << "Enter a value for B: ";
    cin >> userB;
    cout << "Enter a value for C: ";
    cin >> userC;
    
    theDiscrim = sqrt((pow(userB, 2.0)) - (4 * userA *userC));
    
    rootX1 = ((-userB) + theDiscrim) / (2 * userA);
    cout << rootX1;
    
    rootX2 = ((-userB) - theDiscrim) / (2 * userA);
    cout << ", " << rootX2;
    cout << endl;
    
 return 0;   
}