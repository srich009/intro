#include <iostream>

using namespace std;

// returns the length of the argument
unsigned int myStrlen(const char*);

int main()
{
    const char* g = "hello"; 
    unsigned f = 0;
    
    f = myStrlen(g);
    
    cout << f << endl;
    
    return 0;
}

// returns the length of the argument
unsigned int myStrlen(const char* g)
{
    unsigned int counter = 0;
    
    if(g == NULL || *g == '\0')
    {
        return counter;
    }
    
    counter = 1;
    
    counter += myStrlen(g + 1);
    return counter;
    
    
}