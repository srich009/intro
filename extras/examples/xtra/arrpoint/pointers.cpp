#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string s;
    
    string* sp;
    sp = 0;
    
    const char* cp; // has to be const ?? later when cp = s.c_str
                    // const char* x || char x[] = "...";
    cp = 0;
    
    /*
    cout << "before" << endl;
    cout << "str " << s << endl;
    cout << "&s " << &s << endl;
    cout << "str* " << sp << endl;
    cout << endl;
    */
    
    
    cout << "enter string" << endl;
    cin >> s;
    cout << endl;
    
    sp = &s;
    
    cout  << "str : " << s << flush << endl;
    cout << "&s  : " << &s << flush << endl;
    cout << "sp  : " << sp << flush << endl;
    cout << "*sp : " << *sp << flush <<  endl;
    cout << endl;
    
    cout << "cp test" << endl;

    cp = "abcdefgTEST123";
    cout << "cp: " << cp << endl;
    cout  << "*cp: " << *cp << endl;
    
    cout << "cp reassign str" << endl;
    cout << endl;
    
    cp = s.c_str();
    cout << cp << endl; //out string as char array
    cout << *cp << endl;
        
    cout << cp + 1 << endl; // out string starting from second element
    cout << *(cp + 1) << endl;
        
    cout << (*sp).at(0) << endl;
    cout << (*sp).at(1) << endl;
    cout << endl;
    
    cout << *cp + 1 << endl; // ?? number
    
    cout << (*sp).at(0)+1 << endl;
    cout << (*sp).at(0)-1 << endl;
    cout << (*sp).at(0)+2 << endl;
    cout << (*sp).at(0)-2 << endl;
    cout << endl;
    
    cout << sp << endl;
    cout << sp+1 << endl;
    //cout << *(sp+1) << endl; // corrupt
   
    
    
return 0;
}


