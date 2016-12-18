//g++ with std=c++11

//trows and templates

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

template<typename T>
void get(string prompt, T& val);


int main()
{
/*
    vector<int> v = {5,6,8,4,2,3,9,7,1,0,};
    
    int index;
    
    while(1)
    {
        cout << "you enter index now" << endl;
        cin >> index;
                
        try
        {
            cout << v.at(index) << endl;
        }
        catch(out_of_range &err)
        {
            cout << err.what() << endl;
            cout << "you picked a index not in the vector" << endl;
        }
    }
*/


    int roo = 0;
    double doo = 0.0;
    char coo = 'a';
    string soo;
    
    
    get("enter a something int", roo);
    
    get("enter a something dub", doo);
        
    get("enter a something char", coo);
        
    get("enter a something string", soo);


    cout << endl;

    cout << roo << endl;
    cout << doo << endl;
    cout << coo << endl;
    cout << soo << endl;


return 0;
}
//--------------------------------------

template<typename T>
void get(string prompt, T& val)
{
    cout << prompt << endl;
    cin >> val;
    return;   
}