//-std=c++11
#include "sort_repo.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;


int main()
{
   srand(time(0));
   
   vector<int> v1;
   int key_large = 100; // for count && bucket
   int val = 0;
   
   for(unsigned i = 0; i < 10; i++)
   {
      v1.push_back(rand() % 100);
   }   

   cout << "Choose sort algorithm" << endl;
   cout << "1 = bubble, 2 = select, 3 = insert, 4 = shell," << endl;
   cout << "5= merge, 6 = quick, 7 = quick3, 8 = count, 9 = bucket" << endl;
   cin >> val;
   
   cout << "Vector before:" << endl;
   for(unsigned i = 0; i < v1.size(); i++)
   {
      cout << v1.at(i) << ", ";
   }
   cout << endl;
   
   switch(val)
   {

      case 1:
         bubble_sort(v1);
         break;      
      case 2:
         select_sort(v1);
         break;
      case 3:
         insert_sort(v1);
         break;
      case 4:
         shell_sort(v1);
         break;
      case 5:
         merge_sort(v1);
         break;      
      case 6:
          cout << "no" << endl;
         break;      
      case 7:
          cout << "no" << endl;
         break;   
      case 8:
         count_sort(v1, key_large);
         break;   
      case 9:
         bucket_sort1(v1, key_large);
         break;
                  
      default:
         cout << "invalid choice" << endl;
         break;
   }
   
   cout << "Vector after:" << endl;
   for(unsigned i = 0; i < v1.size(); i++)
   {
      cout << v1.at(i) << ", ";
   }
   cout << endl;
   
   
return 0;
}
//---------------------------------




////////////////////////////////////////////////////////
/*

broken?

template <typename T>
void insertion_sort1(vector<T> &v, typename vector<T>::iterator start, typename vector<T>::iterator end) 
{
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