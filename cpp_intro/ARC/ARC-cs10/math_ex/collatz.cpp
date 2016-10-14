// collatz conjecture program

#include <iostream>
#include <string>

using namespace std;

int main ()
{
 
 int userNum = 0;
 int numType;
 
 cout << "enter a number greater than 1" << endl;
 cout << "Start Number: ";
 cin >> userNum;
 
 while (userNum > 1)
 {
  numType = userNum % 2;
  
  if (numType == 0)
  {
      userNum = userNum / 2;
  }
  else
  {
      userNum = ((3 * userNum) + 1 );
  }
  
  cout << userNum << ", ";
     
 }
    
   cout << endl; 
    
    
 return 0;   
}