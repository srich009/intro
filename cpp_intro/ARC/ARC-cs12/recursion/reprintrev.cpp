//print backwards

#include <iostream>

using namespace std;

// prints a cstring
void printBackward(const char*);

int main()
{
    const char* c = "hello"; 
    
    printBackward(c);
    
    
    return 0;
}

// prints a cstring
void printBackward(const char* c)
{
    if(c == NULL || *c == '\0') 
    {
        // null || '\0'
        //checks if null pointer before dereference
        //to never get seg fault
        return;
    }
    
    
    // tail recursion
    printBackward(c + 1);
    cout << *c;

    
}