// Chapter 8 lab 2

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> //needed for exit function

using namespace std;

// prototype (declaration) here
int charCnt(string, char );

int main()
{
   string filename;
   char ch;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << "Enter a character: ";
   cin >> ch;
   
   cout << "# of " << ch << "'s: " << charCnt(filename, ch) << endl;

return 0;
}

// implementation here

int charCnt(string filename, char ch)
{
    ifstream inFile;
    inFile.open(filename.c_str()); 
    
    if(!inFile.is_open())
    {
        cout << "Error opening " << filename << endl;
        exit (EXIT_FAILURE);
        return 1;
    }
    
   int counter = 0;
   char temp;
   while(inFile.get(temp))
   {
      if(temp == ch)
      {
         counter++;
      }
   }
    


return counter;
}

/*


Implement the function charCnt.
charCnt is passed in a name of a file and a single character (type char).
This function should open the file, count the number of times
the character is found within the file, close the file, and then return the count.

If the file does not exist,
this function should output an error message
and then call the exit function to exit the program with an error value of 1.

*/


