//print forward

#include <iostream>

using namespace std;

// prints a cstring
void printForward(const char*);

int main()
{
    char c[] = "hello"; // can be const char* x || char x[]
    
    printForward(c);
    
    
    return 0;
}

// prints a cstring
void printForward(const char* c)
{
    if(c == NULL || *c == '\0') 
    {
        // null || '\0'
        //checks if null pointer before dereference
        //to never get seg fault
        return;
    }
    
    
    // head recursion
    cout << *c;
    printForward(c + 1);
    
}