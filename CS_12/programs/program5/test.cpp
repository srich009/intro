//my test harness

#include <iostream>

using namespace std;

#include "IntList.h"


int main() {
   
IntList w1;
IntList w2;


//cout << "w1 empty: " << flush;
// cout << w1 << endl;

cout << "w1: ";
w1.push_back(2);
cout << w1 << endl;

for(int i = 0; i < 5; i++)
{
w2.push_back(5);
w2.push_back(6);
w2.push_back(7);
}
cout << "w2:";
cout << w2 << endl;


cout << "Make w3 new copy of w1" << flush;
cout << endl;
IntList w3(w1);
cout << w3 << endl;


cout << "self assign" << endl;
cout << "w1 = w1" << endl;
w1 = w1;
cout << "w1 " << w1 << endl;


cout << "assign" << endl;
cout << "w1 = w2" << endl;
w1 = w2;
cout << "w1: ";
cout << w1 << endl;
cout << "w2:";
cout << w2 << endl;

cout << "w1 = w3" << endl;
w1 = w3;
cout << "w1: ";
cout << w1 << endl;
cout << "w3: ";
cout << w3 << endl;

return 0;
}