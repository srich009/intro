// Chapter 8 lab 1

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string );

int main()
{
   string filename;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << "Sum: " << fileSum(filename) << endl;
   
   return 0;
}

// Place fileSum implementation here

int fileSum(string filename)
{
    ifstream inFile;
    inFile.open(filename.c_str()); 
    
    if(!inFile.is_open())
    {
        cout << "Error opening " << filename << endl;
        exit (EXIT_FAILURE);
        return 1;
    }
    
    int n = 0;
    int q = 0;
    while( inFile >> n )
    {  
        q = q + n;
    }
    


return q;
}





/*
Implement the function fileSum.
fileSum is passed in a name of a file.
This function should open the file,
sum all of the integers within this file,
close the file, and then return the sum.

If the file does not exist,
this function should output an error message
and then call the exit function to exit
the program with an error value of 1.
*/