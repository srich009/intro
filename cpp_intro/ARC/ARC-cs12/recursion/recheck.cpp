// palindrome check

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string);

int main()
{
    string s;
    cin >> s;
    
    if(isPalindrome(s))
    {
        cout << "true" << endl;
    }
    else{ cout << "false" << endl;}
    
    
    // .begin() && .end() are iterators
    
return 0;   
}

bool isPalindrome(string s)
{
    //base cases
    if(s.size() <= 1)
    {
        return true;
    }
    if( s.at(0) != s.at(s.size() - 1) )
    {
        return false;   
    }
    
    return isPalindrome(s.substr(1, s.size() - 2));
    

}


///xxxxxxxxxxxxxxxxxxxxxxxxxxx

