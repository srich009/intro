// main
// input stream object extraction

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string line;
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
        
    cout << "Enter 3 ints separated by spaces" << endl;
    getline(cin, line);
    
    stringstream box(line);
    
    box >> num1;
    if(!box.good())
    {
        cout << "ERR1" << endl;   
    }
    
    box >> num2;
    if(!box.good())
    {
        cout << "ERR2" << endl;   
    }   

    box >> num3;
    if(box.bad()) // if !box.good() then error
    {
        cout << "ERR3" << endl;   
    }

    cout << "NUMS: " << num1 << " " << num2 << " " << num3 << endl;
    
return 0;   
}