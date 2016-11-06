// Lab 7 part 1

#include <iostream>
using namespace std;

//definition of the add function

int add(int val1, int val2)
{
    int sumTotal = 0;
    
    sumTotal = val1 + val2;
    
    return sumTotal;
}


//definition of the sub function
int subtract( int valA1, int valA2)
{
    int diffTotal = 0;
    
    diffTotal = valA1 - valA2;
    
    return diffTotal;
}


int main() 
{
   int num1 = 0;
   int num2 = 0;
   int sum = 0; //sum of numbers
   int diff = 0; //difference of numbers

   //Prompt user for ints and print them
   cout << "Enter the first integer: ";
   cin >> num1;
   cout << "Enter the second integer: ";
   cin >> num2;
   cout << endl;
   cout << endl;
   
   cout << "First Integer: " << num1 << endl;
   cout << "Second Integer: " << num2 << endl;
   cout << endl;

   //Call add function
   sum = add(num1, num2);

   //Call subtract function
   diff = subtract(num1, num2);

   //Output sum of num1 + num2 
   cout << num1 << " + " << num2 << " = " << sum;
   cout << endl;


   // FIXME (8) Output result of num1 - num2
   cout << num1 << " - " << num2 << " = " << diff;
   cout << endl;


   return 0;
}