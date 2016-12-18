//test harness

#include <iostream>

#include "IntList.h"
#include "SortedSet.h"

using namespace std;

int main()
{

    cout << "empty harness for int lists && sorted sets" << endl;  
    
    cout << "consider stream to output into a file?" << endl;

    cout << "resize list function???" << endl;
    
    
    IntList i;
    i.push_back(1);
    i.push_back(2);
    i.push_back(3);
    i.push_back(4);
    i.push_back(5);
    i.push_back(5);
    
    cout << i.sum() << endl;
return 0;
}