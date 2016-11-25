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
     while(userText.find("BFF") != string::npos)
      {
         userText.replace(userText.find("BFF"), 3, "best friend forever");
      }
      
    while(userText.find("IDK") != string::npos)
      {
         userText.replace(userText.find("IDK"), 3, "I don't know");
      }
      
    while(userText.find("JK") != string::npos)
      {
        userText.replace(userText.find("JK"), 2, "just kidding");
      }
      
    while(userText.find("TMI") != string::npos)
      {
         userText.replace(userText.find("TMI"), 3, "too much information");
      }
      
    while(userText.find("TTYL") != string::npos)
      {
         userText.replace(userText.find("TTYL"), 4, "talk to you later");
      }
     
 }
 
    cout << "Expanded: " << userText << endl;
    
    
 return 0;   
}