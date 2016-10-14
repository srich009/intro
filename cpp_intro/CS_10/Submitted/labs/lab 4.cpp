/*
lab 4 

text substitution scramble
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string theWord;
    int i = 0;
    
    cout << "Enter a word:" << endl;
    cin >> theWord;
    
    i = theWord.size();
    for(; i >=0; --i)
    {
        
      if(theWord.find('a') != string::npos)
      {
         theWord.replace(theWord.find('a'), 1, "@");
      }
     if(theWord.find('e') != string::npos)
      {
          theWord.replace(theWord.find('e'), 1, "3");
      }
    if(theWord.find('i') != string::npos)
      {
          theWord.replace(theWord.find('i'), 1, "!");
      }
    if(theWord.find('g') != string::npos)
      {
          theWord.replace(theWord.find('g'), 1, "9");
      }
    if(theWord.find('s') != string::npos)
      {
          theWord.replace(theWord.find('s'), 1, "$");
      }
     if(theWord.find('x') != string::npos)
      {
          theWord.replace(theWord.find('x'), 1, "*");
      }
      
    }
    
   cout <<theWord << endl;
   
   return 0;
}