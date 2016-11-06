//Lab 8 part 2
#include <iostream>

using namespace std;

// Global const values for intersect return value
const int OK = 0; // intersect
const int DIV_ZERO = 1; // parallell

// FIXME Add intersect function here

int intersect(double &xi, double &yi, double a1, double b1, double a2, double b2)
{

    if(a1 == a2) // parallell value of 1
    {
    
    return DIV_ZERO;
    }
    else //intersect value of 0
    {
    xi = (b2 - b1) / (a1 - a2);
    yi = a1 * xi + b1;
    
    return OK;
    }




}


int main()
{
    // line 1: y = a1*x + b1
    // line 2: y = a2*x + b2
    // lines intersect at xi, yi

    double a1 = 0.0;
    double b1 = 0.0;
    double a2 = 0.0;
    double b2 = 0.0;
    
    cout << "Enter coefficients for Line 1 (a1, b1): ";
    cin >> a1;
    cin >> b1;
    cout << endl;

    cout << "Enter coefficients for Line 2 (a2, b2): ";
    cin >> a2 >> b2;
    cout << endl;

    cout << "Line 1: Y = " << a1 << "X + " << b1 << endl;
    cout << "Line 2: Y = " << a2 << "X + " << b2 << endl;

    double xi = 0.0;
    double yi = 0.0;
    int flag;

    // FIXME: invoke intersect function here
    flag = intersect(xi, yi, a1, b1, a2, b2); // ?? xi && yi values??

    if (flag == DIV_ZERO)
    {
        cout << "Lines are parallel" << endl;
    }
    else
    {
        cout << "\nLines 1 & 2 intersect at {" << xi << ", " << yi << '}' << endl;

        cout << "Proof: yi on Line 1 at (xi = " << xi << ") is ";
        cout << a1 * xi + b1 << endl;
        cout << "       yi on Line 2 at (xi = " << xi << ") is ";
        cout << a2 * xi + b2 << endl;
    }

    return 0;
}