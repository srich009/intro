#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

///////////STAND_ALONE_FUNCTIONS//////////////////////////////////////

void bubble_sort(vector<int> &v);

void select_sort(vector<int> &v);

void insert_sort(vector<int> &v);

void shell_sort(vector<int> &v); // shell's sequence to find gap = floor(len/(2^k))

void merge_sort(vector<int> &v);
vector<int> merge(vector<int> &v1, vector<int> &v2);

// void quick_sort(); //uses midpoint 
// int q_partition();

// void quick3_sort(); //uses median of 3
// int q3_partition();

void count_sort(vector<int> &v, int largest_val); 

//void bucket_sort(vector<int> &v, int largest_val);

////////ALTERNATES//////////////////////////////////////////////////////////

template <typename TT>
void insertion_sort1(TT start, TT end, int jump=1);

void shell_sort1( vector<int>::iterator,  vector<int>::iterator);  // uses insertion sort && preset jumps

void bucket_sort1(vector<int> &v, int vals);  // uses insertion sort
 

/*

first section of algorithms implemented as void functions that take a single unsorted vector as input 

eventually templatize and have functions take iterator from begin() to end()

have a way to compare and time sorts... using different sizes of random numbers, then in order numbers, then reverse order numbers...

_bubble
_selection
_insertion
_shell
_merge
quick
quick3
_count
bucket

?heap
?radix


*/