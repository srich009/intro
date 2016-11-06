#include <iostream>

using namespace std;

int main()
{
 
 //Variables
 int trunkHeight = 0;
 int trunkWidth = 0;
 int leafWidth = 0;
 int numRows =0;
 
    //user input
     cout << "Enter trunk height: ";
     cin >> trunkHeight;
     
     while( (trunkWidth % 2) == 0)
     {
         cout << "Enter trunk width: ";
         cin >> trunkWidth;
     }
     while( (leafWidth % 2) == 0)
     {
         cout << "Enter leaves width: ";
         cin >> leafWidth;
     }
     cout << endl;
 
    numRows = (leafWidth + 1) / 2;
    //for loop leaves
    for(int a = 1; a <= numRows; a++)
    {
        
        for (int b = 1; b <= numRows - a ; b++)
        {
            cout << " ";
        }
        
        for(int c = 1; c <= (2*a)-1; c++)
        {
            cout << "*";
        }
        cout << endl;
    }
 
 
 
    //for loop trunk
     for(int i = 1; i <= trunkHeight; i++)
     {
         for(int k = 1; k <= (leafWidth - trunkWidth)/2; k++ )
         {
             cout << " ";
         }
         for(int j = 1; j <= trunkWidth; j++)
         {
             cout << "*";
         }
      cout << endl;   
     }
 
 
 
 
 return 0;   
}