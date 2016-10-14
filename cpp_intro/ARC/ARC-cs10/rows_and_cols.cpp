#include <iostream>
#include <string>

using namespace std;

int main ()
{
 
 int nrows;
 int ncols;
 
 cout << "enter num rows";
 cin >> nrows;
 cout << "enter cols";
 cin >> ncols;
 
 for(int j = 1; j <= nrows; ++j)
 {
     for (int i = 1; i <= ncols; ++i)
     {
         
      cout << "*";   
     }
     
 cout << endl;
 }
 
 
 return 0;   
}