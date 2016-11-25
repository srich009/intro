// main

#include <iostream>
#include <vector>

using namespace std;

unsigned int posMax( const vector<int> &val) 
{
    unsigned int place = 0;
    
    for(unsigned int i = 0; i < val.size(); i++)
    {
        if(val.size() > place)
        {
            place = i;
        }
    }
    
    return place;
}


void display(const vector<int> &v )
{
    for(unsigned int i = 0; i < v.size(); i++)
    {
     cout << "Hour " << i << ": " << v.at(i) << endl;   
    }

}

void getInputs(vector<int> &traffic)
{
    for(unsigned int i = 0; i < traffic.size(); i++)
    {
        cout << "cars per hr: " << i << ": ";
        cin >> traffic.at(i);
        cout << endl;
    }

}

const int NUM_HOURS = 24;

int main()
{
    
    vector<int> traffic(NUM_HOURS);
    unsigned int posMaxTraffic = 0;
    
    getInputs(traffic);
    display(traffic);
    posMaxTraffic = posMax(traffic);
    cout << "Max traffic: Hour: " 
    << posMaxTraffic << ": " << traffic.at(posMaxTraffic);
    cout << endl;

return 0;    
}
