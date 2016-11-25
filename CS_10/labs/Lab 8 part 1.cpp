#include <iostream>
using namespace std;

// FIXME (3) multiply function
void multiply(double multVal1, double multVal2, double& multResult )
{
    multResult = multVal1 * multVal2;
    
return;   
}

// FIXME (5) divide function
void divide(double divVal1, double divVal2, double& divResult)
{
    divResult = divVal1 / divVal2;
    
return;
}

int main() {
   double num1 = 0.0;
   double num2 = 0.0;
   double prod = 0.0; //product of numbers
   double quot = 0.0; //quotient of numbers

   //Prompt user for floating point numbers (type double) and print them
   cout << "Enter the first floating point number: "; 
   cin >> num1;
   cout << endl;
   cout << "Enter the second floating point number: ";
   cin >> num2;
   cout << endl << endl;
   
   cout << "First floating point number: " << num1 << endl;
   cout << "Second floating point number: " << num2 << endl;
   cout << endl;
   

   //Call multiply function
   multiply(num1, num2, prod);

   // FIXME (2) Call divide function
   divide(num1, num2, quot);

   // FIXME (4) Output result of num1 * num2
   cout << num1 << " * " << num2 << " = " << prod << endl;


   // FIXME (6) Output result of num1 / num2
   cout << num1 << " / " << num2 << " = " << quot << endl;

   return 0;
}