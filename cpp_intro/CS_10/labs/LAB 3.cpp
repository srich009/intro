/* 
Sean Richardson
CS 10 : ch 3.6 lab 3

text message decoder
*/

#include <iostream>
#include <string>

using namespace std;

int main ()
{
 
     string userText;
     string wordOne = "LOL";
     string wordTwo = "IDK";
     string wordThree = "BFF";
     string wordFour = "TMI";
     string wordFive = "IMHO";
     
     
     cout << "Input an abbreviation: " << endl;
     cin >> userText;
     
     if (userText == wordOne)
     {
         cout << "laughing out loud" << endl;
     }
     else if (userText == wordTwo)
     {
         cout << "I don't know" << endl;
     }
    else if (userText == wordThree)
     {
         cout << "best friends forever" << endl;
     }
      else if (userText == wordFour)
     {
         cout << "too much information" << endl;
     }
      else if (userText == wordFive)
     {
         cout << "in my humble opinion" << endl;
     }
      else 
     {
        cout << "Unknown" << endl; 
     }
 
 
 return 0;   
}
