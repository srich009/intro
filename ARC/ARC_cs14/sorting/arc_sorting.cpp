//-std=c++11

#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;


template <class TT>
void insertion_sort(TT start, TT end, int jump=1) 
{
   for(TT i = start; i != end; i++)
   {
      TT j = i;
      while(j >= start + jump && *(j - jump) > *j)
      {
         swap(*(j - jump), *j);
         j -= jump;
      }
   }
}
//-----------------------------------------------------------------------------------------------------------------------

template <class T>
void shell_sort(typename vector<T>::iterator start, typename vector<T>::iterator end)
{
   // outer loop goes by 1
   // inner loop jumps happen
   // comparison ,swaps are during jump
   //jumps go backwards through the vector
   //cant go out of range but check if under the range
   vector<int> jumps =  {1750, 701, 301, 132, 57, 23, 10, 4, 1};  // there is an eqn for fig jumps...
   
   for(int i = 0; i < jumps.size(); i++)
   {
      insertion_sort(start, end, jumps.at(i));
   }
}
//-----------------------------------------------------------------------------------------------------------------------

void count_sort(vector<int> &v, int numz_of) // only int...
{
   vector<int> county(numz_of);
   
   for(unsigned i = 0; i < v.size(); i++) // count
   {
      county.at(v.at(i))++;
   }
   
   int x = 0;
   for(unsigned i = 0; i < county.size(); i++) // go through each index
   {
      for(unsigned j = 0; j < county.at(i); j++) // take vals from index j times
      {
         v.at(x++) = i;
      }
   }
}
//-----------------------------------------------------------------------------------------------------------------------

void bucket_sort(vector<int> &v, int vals)// only ints... situation determines num buckets
{
   vector< vector<int> > box(vals/10); // vector of empty buckets, each holds certain values from [a,b]

   for(unsigned i = 0; i < v.size(); i++) // filling buckets in their range
   {
     box.at(v.at(i)/10).push_back(v.at(i));
   }

   for(unsigned i = 0; i < box.size(); i++) // sort buckets
   {
     insertion_sort(box.at(i).begin(), box.at(i).end());
   }

   int x = 0;
   for(unsigned i = 0; i < box.size(); i++) // go through each index
   {
      for(unsigned j = 0; j < box.at(i).size(); j++) // take vals
      {
          v.at(x++) = box.at(i).at(j);
      }
   }
}

//------------------------------------------------------------------------------------------------------------------------


int main()
{
   srand(time(0));
   
   vector<int> v1;
   vector<int> v2;
   vector<int> v3;
   
   for(unsigned i = 0; i < 25; i++)
   {
      v1.push_back(rand() % 100);
   }   
   v2 = v1;
   v3 = v1;
   
   // //INSERT
   // for(unsigned i = 0; i < v1.size(); i++)
   // {
   //    cout << v1.at(i) << ", ";
   // }
   // cout << endl;
   
   // insertion_sort(v1.begin(), v1.end());
   
   // for(unsigned i = 0; i < v1.size(); i++)
   // {
   //    cout << v1.at(i) << ", ";
   // }
   // cout << endl;
   //////////////////////////////////////////////////////
   
   // //SHELL
   // for(unsigned i = 0; i < v2.size(); i++)
   // {
   //    cout << v2.at(i) << ", ";
   // }
   // cout << endl;
   
   // shell_sort(v2.begin(), v2.end());
   
   // for(unsigned i = 0; i < v2.size(); i++)
   // {
   //    cout << v2.at(i) << ", ";
   // }
   // cout << endl;
   ///////////////////////////////////////////////////////////
   
   //COUNTING
   for(unsigned i = 0; i < v3.size(); i++)
   {
      cout << v3.at(i) << ", ";
   }
   cout << endl;
   
   int set_sz = 100;
   bucket_sort(v3, set_sz);
   
   for(unsigned i = 0; i < v3.size(); i++)
   {
      cout << v3.at(i) << ", ";
   }
   cout << endl;
   
   
return 0;
}
//---------------------------------




////////////////////////////////////////////////////////
/*
template <class T>
void insertion_sort1(vector<T> &v, typename vector<T>::iterator start, typename vector<T>::iterator end) 
{
   cout << "INSERT" << endl;
   typedef typename vector<T>::iterator iter;
   for(iter i = start; i != end; i++)
   {
      iter j = i;
      //stop when j == start || *prev(j) < *j
      //loop while j != start && *prev(j) >= *j
      while(j != start && *prev(j) > *j)
      {
            swap(*prev(j), *j);
            j--;
      }
   }
}
*/