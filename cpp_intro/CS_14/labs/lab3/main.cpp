//Sean Richardson
//Michael KreegerJohnston

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept> // try && catch
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;


//part 1
template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index)
{
    unsigned min = index;
    for(unsigned i = index + 1; i <vals.size(); i++)
    {
        if(vals.at(i) < vals.at(min))
        {
            min = i;
        }
    }
    
    return min;
    
}
/* Passes in an index of type int and a vector of type T (T could be string, double or int).
The function returns the index of the min value starting from "index" to the end of the "vector". */

template<typename T>
void selection_sort(vector<T> &vals)
{
    for(unsigned i = 0; i + 1 < vals.size(); i++)
    {
        unsigned minval = min_index(vals, i) ;
    
        swap(vals.at(i), vals.at(minval));
    }
    
    return;
}
/*
Passes in a vector of type T and sorts them based on the selection sort method. 
This function should utilize the min_index function to find the index of the min value in the unsorted portion of the vector.
*/

//=============================================================================

//part2

char getChar(vector<char> vals, unsigned int index) // changed to unsigned...
{
    try
    {
        if(index >= vals.size() || index < 0)
        {
            throw runtime_error("out of range exception occured");
        }
        else
        {
            return vals.at(index);
        }
    }
    catch(runtime_error &err)
    {
        cout << err.what();
        return '\0';
    }
    
}
/*
 Passes in a vector of characters and an index of type int. The function returns the char located at the index of the vals. 
 You should write up a try catch block so that when the index is out of the range of the vector,
 the "std::outofrange" exception will be caught by the catch (const std::outofrange& excpt). 
 Once the exception is caught, it should output "out of range exception occured".
*/

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main()
{
    //test for min_index && sel sort()
    
    
    std::vector<int> v;
    
    for(unsigned i = 5; i > 0; i--)
    {
        v.push_back(i);
    }

    for(unsigned i = 0; i < v.size(); i++)
    {
        cout << v.at(i) <<' ';
    }
   
    cout << "sel sort test" << endl;
    selection_sort(v);
    
    for(unsigned i = 0; i < v.size(); i++)
    {
        cout << v.at(i) <<' ';
    }
    cout << endl;
    
    
         //Part B
     srand(time(0));
     vector<char> vals = createVector();
     char curChar = 'a';
     int index;
     int numOfRuns = 5;
     while(--numOfRuns >= 0){
         cout << "Enter a number: " << endl;
         cin >> index;
         curChar = getChar(vals,index);
         cout << curChar << endl;
     }
    
    
  return 0; 
}