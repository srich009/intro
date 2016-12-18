//LAB2: Main test harness

#include <iostream>

#include "IntList.h"

using namespace std;

int main(){
    cout << "Hello" << endl;
    IntList myList;
    
    cout << "Test 2" << flush << endl;
    
    cout << "Pushing Front 10" << endl;
    myList.push_front(10);
    cout << "Pushing Front 20" << endl;
    myList.push_front(20);
    cout << "Pushing Front 30" << endl;
    myList.push_front(30);
    cout << "List: " << myList << endl;
    
    cout << "Popping Front" << endl;
    myList.pop_front();
    cout << myList << endl;
    cout << "Popping Front" << endl;
    myList.pop_front();
    cout << myList << endl;
    cout << "Popping Front" << endl;
    myList.pop_front();
    cout << myList << endl;
    
    cout << "Pushing Back 10" << endl;
    myList.push_back(10);
    cout << "Pushing Back 20" << endl;
    myList.push_back(20);
    cout << "Pushing Back 30" << endl;
    myList.push_back(30);
    cout << "List: " << myList << endl;
    
    cout << "Popping Back" << endl;
    myList.pop_back();
    cout << myList << endl;
    cout << "Popping Back" << endl;
    myList.pop_back();
    cout << myList << endl;
    cout << "Popping Back" << endl;
    myList.pop_back();
    cout << myList << endl;
    
    cout << "Testing if empty: " << endl;
    if(myList.empty()){
        cout << "Empty" << endl;
    }
    else {
        cout << "Not Empty" << endl;
    }
    
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);
    cout << "New List: " << myList << endl;
    
    cout << "Printing in Reverse: ";
    myList.printReverse();
    cout << endl;
    
    cout << "sz 1 test" << endl;
    IntList test;
    test.push_front(99);
    cout << test << 'x' << endl;
    
    return 0;
}