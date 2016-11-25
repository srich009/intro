#include <iostream>
#include <string>

using namespace std;

int main ()
{
 string userText;
 int i = 0;
 
 cout << "Enter text: ";
 getline(cin, userText);

 
 cout << endl << "You entered: ";
 cout << userText << endl;
 
 for (i = 1; i < 2; ++i)
 {
     if(userText.find("BFF") != string::npos)
      {
         cout << "BFF: best friend forever" << endl;
      }
    if(userText.find("IDK") != string::npos)
      {
         cout << "IDK: I don't know" << endl;
      }
    if(userText.find("JK") != string::npos)
      {
         cout << "JK: just kidding" << endl;
      }
    if(userText.find("TMI") != string::npos)
      {
         cout << "TMI: too much information" << endl;
      }
    if(userText.find("TTYL") != string::npos)
      {
         cout << "TTYL: talk to you later" << endl;
      }
     
 }
 
    
    
    
 return 0;   
}