// Lab 8: recursion strnig backward

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//global function declaration
void flipString(string &s);


int main()
{
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

return 0;
}


//global function implementation
void flipString(string &s)
{   
   
    ///BASE CASE 
    //empty string && size 1
    if(s.size() <= 1) 
    {
        return;
    }
    
     string temp; 
    
    
    swap(s.at(0), s.at(s.size() - 1)); // swap outsides
 
    temp = s.substr(1, s.size() - 2); //temp shorten    
     
    flipString(temp);
   
    s= s.at(0)+temp+s.at(s.size()-1); //  add s front with middle and s back
   
    
    
     return;
     
}     



    

/*
    //only displays backwards BUT BROKEN
    //destroys original string passed in...
    //------------------
    string temp;
    
    temp.push_back(s.at(s.size()-1));
    
    s.erase(s.end()-1, s.end());
    
    cout << temp;
    
    flipString(s);
    //-------------------------
*/
   


