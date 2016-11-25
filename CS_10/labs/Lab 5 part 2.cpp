#include <iostream>
#include <string>

using namespace std;

int main ()
{
 
 int numRows;
 char userChar = 'x';
 
 cout << "Enter a character: ";
 cin >> userChar;
 cout << "Enter number of rows: " << endl;
 cin >> numRows;
 
 for(int i = 1; i <= numRows; i++)
 {
 for(int j = numRows; j >= i; --j)
 {
  cout << userChar << " ";
 }
  cout << endl;
 }
 
 
 return 0;   
}