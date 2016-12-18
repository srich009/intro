// STL LIST iteration exercises

// compile with the c++11 std
//g++ -std=c++11 XXX.cpp


#include <iostream>
#include <vector>
#include <list>
#include <iterator> // special type of encapsulated list pointer

using namespace std;


//fancy stuff
typedef list<int>::iterator Iter; // now just use "Iter" instead

//DEFINITIONS
int LLength(Iter beg, Iter end);

int LSum(Iter beg, Iter end);

void LPrint(Iter beg, Iter end);

void LRPrint(Iter start, Iter fin);

Iter LFindMid(Iter beg, Iter end);



int RLength(Iter beg, Iter end);

int RSum(Iter beg, Iter end);

void RPrint(Iter beg, Iter end);

void RrevPrint(Iter beg, Iter end);

Iter RFindMid(Iter beg, Iter end);

Iter RMin(Iter be, Iter end);



int main()
{
    list<int> test = {1,2,3,4,5}; // c++ 11 std list fill....
    
    cout << "L print test: " << endl;
    LPrint(test.begin(), test.end());
    
    cout << "L Rprint: " << endl;
    LRPrint(test.begin(), test.end());
    
    cout << "L length test: " << endl;
    cout << LLength(test.begin(), test.end()) << endl;
    
    cout << "L sum test: " << endl;
    cout << LSum(test.begin(), test.end()) << endl;
    
    cout << "L find mid: " << endl;
    cout << *(LFindMid(test.begin(), test.end())) << endl;
    
    cout << endl << "RECURSE" << endl << endl;
    
    cout << "R print test: " << endl;
    RPrint(test.begin(), test.end());
    cout << endl;
    
    cout << "R Revprint: " << endl;
    RrevPrint(test.begin(), test.end());
    cout << endl;
    
    cout << "R length test: " << endl;
    cout << RLength(test.begin(), test.end()) << endl;
    
    cout << "R sum test: " << endl;
    cout << RSum(test.begin(), test.end()) << endl;  
    
    cout << "R find mid: " << endl;
    cout << *(RFindMid(test.begin(), test.end())) << endl;
    
    return 0;    
}
//=============================================================

//IMPLEMENTATIONS
int LLength(Iter beg, Iter end)
{
    int len = 0;
    
    for(Iter it = beg; it != end; ++it)
    {
        len++;   
    }
    return len;
}
//-----------------------------------------------------------

int LSum(Iter beg, Iter end)
{
    int sums = 0;
    
    for(Iter it = beg; it != end; it++)
    {
        sums += (*it);
    }
    
    return sums;
}
//---------------------------------------------------------------

void LPrint(Iter beg, Iter end)
{
    for(Iter it = beg; it != end; ++it)
    {
        cout << *it << ", ";
    }
    cout << endl;
}
//-----------------------------------------------------------

void LRPrint(Iter start, Iter fin)
{
    if(start == fin)
    {
        return;
    }
    
    Iter it = fin;
    for(it-- ; it != start; it--)
    {
        //--it;
        cout << *it << ", ";
    }
    cout << *start << endl;   
}
//--------------------------------------------------------------

Iter LFindMid(Iter beg, Iter end)
{
    if(beg == end)
    {
        Iter ehalf = end;
        return ehalf;
    }

    int sz = LLength(beg, end);
    sz /= 2;
    
    Iter half = beg;
    
    for(int i = 0; i < sz; i++)
    {
        half++;   
    }
   
   //advance(half, sz);
   
   return half;
}
//-----------------------------------

int RLength(Iter beg, Iter end)
{
    if(beg == end)
    {
        return 0;
    }
    
    return 1 + RLength(++beg, end);
}
//-----------------------------

int RSum(Iter beg, Iter end)
{
    if(beg == end)
    {
        return 0;
    }
    
    return *beg + RSum(++beg, end);
}
//---------------------------------------

void RPrint(Iter beg, Iter end)
{
    if(beg == end) return;
    Iter it = beg;
    cout << *it << ", ";
    RPrint(++beg, end);
}
//------------------------------

void RrevPrint(Iter beg, Iter end)
{
    if(beg == end) return;
    RrevPrint(next(beg, 1), end);
    cout << *beg << ", ";
}
//------------------------------------

Iter RFindMid(Iter beg, Iter end)
{    
    if(beg == end)// sz 0
    {
        return beg;
    }
    
    end--;
    
    if(beg == end)// sz 0
    {
        return beg;
    }
    
    beg++;
    
    if(beg == end)// sz 0
    {
        return beg;
    }

    
    return RFindMid(beg, end);
}
//-------------------------------------------

Iter RMin(Iter beg, Iter end)
{   
    if(beg == end)// base case sz 0
    {
        return beg;
    } 
    else if(next(beg, 1) == end) //sz 1
    {
        return beg;
    }
    
    Iter m = RMin(next(beg, 1), end);
    if(*beg < *m) return beg;
    return m;
    
}