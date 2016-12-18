//fill list with random numbers then remove evens

#include <list> // STL List
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    
    //list similar to vector STL Vector public interface
    
    list<int> test;
    
    for(unsigned i =0; i < 30; ++i)
    {
        test.push_back(rand() % 1000);
    }
    
    //iterator = encapsulated pointer to a node
    //begin() iterator to the firts node in the list
    //end() is an iterator to a dummy node 1 past the end of the list
    
    for(list<int>::iterator it = test.begin(); it != test.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl << endl;
    
    
    
    // list<int>::iterator it = test.begin();
    
    // it = test.erase(it);
    // //erase returns an iterator to the node after the one it removed
    
    // for( ; it != test.end(); ++it)
    // {
    //     cout << *it << ' ';
    // }
    // cout << endl << endl;
    
    
    
    //erase evens
    for(list<int>::iterator it = test.begin(); it != test.end(); it = it) 
    // at end dont need to set it = it; just for clarity
    //could be a while loop
    {
        if( (*it % 2)  == 0 )//delete evens 
        {
            it = test.erase(it);
        }
        else
        {
            it++;
        }
    }
    
    //display new list
    for(list<int>::iterator it = test.begin(); it != test.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;
    
return 0;   
}