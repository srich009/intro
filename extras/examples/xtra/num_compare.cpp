#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    cout << "Broken maybe??" << endl;
    
    vector<int> v;
    int index = 0;
    int val = 0;
    
    cout << "ENTER 5 VALS" << endl;
    for(unsigned int i = 0; i < 5; i++)
    {
     cin >> val;
     cout << endl;
     v.push_back(val);
    }
    
    
    index = v.at(0);
    for(unsigned int i = 0; i < v.size() - 1; i++) // size - 1 = num elements
    {
        if(v.at(i + 1) <= v.at(i)) // switch sign
        {
            index = v.at(i); //was .at(i + 1)
        }
    }
      
      cout << "Vals: " << endl;   
    for(unsigned int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << ", "; 
    }
    cout << endl << endl;
    
    cout << "largest:" << index << endl;
    
 return 0;   
}

