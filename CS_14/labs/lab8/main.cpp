// Brad Cai
// Sean Richardson
//LAB8

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;

//USE FOR THE LAB
const int NUMBERS_SIZE = 50000;
const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds

void InsertionSort(int numbers[], int numbersSize); 
//: this function sorts the given array using InsertionSort method. 
//(implementation of this method is provided in section 21.3).

int Partition_midpoint(int numbers[], int i, int k);
void Quicksort_midpoint(int numbers[], int i, int k); 
//: this function sorts the given array in the range from i to k using quicksort method. 
//In this function, pivot is the midpoint element (numbers[(i+k)/2]). (implementation of this function is given in section 21.5)

int Partition_medianOfThree(int numbers[], int i, int k);
void Quicksort_medianOfThree(int numbers[], int i, int k); 
//: this function utilizes different pivot selection technique in quicksort algorithm. 
//The pivot is the median of the following three values: leftmost (numbers[i]), midpoint (numbers[(i+k)/2]) and rightmost (numbers[k]). 
// You should modify the partition function given in section 21.5 to select the pivot using median-of-three technique.

int genRandInt(int low, int high) 
{
   return low + rand() % (high - low + 1);
}

void fillArrays(int arr1[], int arr2[],int arr3[])
{
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}
////--------------------------------------------------------------------

void InsertionSort(int numbers[], int numbersSize) 
{
   int i = 0;
   int j = 0;
   int temp = 0;  // Temporary variable for swap
   
   for (i = 1; i < numbersSize; ++i) {
      j = i;
      // Insert numbers[i] into sorted part
      // stopping once numbers[i] in correct position
      while (j > 0 && numbers[j] < numbers[j - 1]) {
         
         // Swap numbers[j] and numbers[j - 1]
         temp = numbers[j];
         numbers[j] = numbers[j - 1];
         numbers[j - 1] = temp;
         --j;
      }
   }
   
   return;
}
//---------------------------------------------------------------

int Partition_midpoint(int numbers[], int i, int k) {
   int l = 0;
   int h = 0;
   int midpoint = 0;
   int pivot = 0;
   int temp = 0;
   bool done = false;
   
   /* Pick middle element as pivot */
   midpoint = i + (k - i) / 2;
   pivot = numbers[midpoint];
   
   l = i;
   h = k;
   
   while (!done) {
      
      /* Increment l while numbers[l] < pivot */
      while (numbers[l] < pivot) {
         ++l;
      }
      
      /* Decrement h while pivot < numbers[h] */
      while (pivot < numbers[h]) {
         --h;
      }
      
      /* If there are zero or one elements remaining,
       all numbers are partitioned. Return h */
      if (l >= h) {
         done = true;
      }
      else {
         /* Swap numbers[l] and numbers[h],
          update l and h */
         temp = numbers[l];
         numbers[l] = numbers[h];
         numbers[h] = temp;
         
         ++l;
         --h;
      }
   }
   
   return h;
}

void Quicksort_midpoint(int numbers[], int i, int k) {
   int j = 0;
   
   /* Base case: If there are 1 or zero elements to sort,
    partition is already sorted */
   if (i >= k) {
      return;
   }
   
   /* Partition the data within the array. Value j returned
    from partitioning is location of last element in low partition. */
   j = Partition_midpoint(numbers, i, k);
   
   /* Recursively sort low partition (i to j) and
    high partition (j + 1 to k) */
   Quicksort_midpoint(numbers, i, j);
   Quicksort_midpoint(numbers, j + 1, k);
   
   return;
}
//-------------------------------------------------------------------------



int Partition_medianOfThree(int numbers[], int i, int k) {
   int l = 0;
   int h = 0;
   int midpoint = 0;
   int pivot = 0;
   int temp = 0;
   bool done = false;
   
   // /* Pick middle element as pivot */  ORIGINAL
   // midpoint = i + (k - i) / 2;
   // pivot = numbers[midpoint];
   
/*
    int center = (left + right) / 2;
    // order left & center
    if (data[left] > data[center])
      swap(left, center);
    // order left & right
    if (data[left] > data[right])
      swap(left, right);
    // order center & right
    if (data[center] > data[right])
      swap(center, right);

    swap(center, right - 1); // put pivot on right
    return data[right - 1]; // return median value
*/

   midpoint= (i + k) / 2;
   
   if(numbers[i] > numbers[midpoint])
   {
      swap(numbers[i], numbers[midpoint]);
   }
   if(numbers[i] > numbers[k])
   {
      swap(numbers[i], numbers[k]);
   }
   if(numbers[midpoint] > numbers[k])
   {
      swap(numbers[midpoint], numbers[k]);
   }
   
   swap(numbers[midpoint], numbers[k-1]);
   pivot = numbers[midpoint];
   
   l = i;
   h = k;
   
   while (!done) {
      
      /* Increment l while numbers[l] < pivot */
      while (numbers[l] < pivot) {
         ++l;
      }
      
      /* Decrement h while pivot < numbers[h] */
      while (pivot < numbers[h]) {
         --h;
      }
      
      /* If there are zero or one elements remaining,
       all numbers are partitioned. Return h */
      if (l >= h) {
         done = true;
      }
      else {
         /* Swap numbers[l] and numbers[h],
          update l and h */
         temp = numbers[l];
         numbers[l] = numbers[h];
         numbers[h] = temp;
         
         ++l;
         --h;
      }
   }
   
   return h;
}

void Quicksort_medianOfThree(int numbers[], int i, int k) {
   // int size = right - left + 1;
   //  if (size <= 3) // manual sort if small
   //    manualSort(left, right);
   //  else // quicksort if large
   //  {
   //    long median = medianOf3(left, right);
   //    int partition = partitionIt(left, right, median);
   //    recQuickSort(left, partition - 1);
   //    recQuickSort(partition + 1, right);
   //  }

   int j = 0;
   
   /* Base case: If there are 1 or zero elements to sort,
    partition is already sorted */
   if (i >= k) {
      return;
   }
   
   /* Partition the data within the array. Value j returned
    from partitioning is location of last element in low partition. */
   j = Partition_medianOfThree(numbers, i, k);
   
   /* Recursively sort low partition (i to j) and
    high partition (j + 1 to k) */
   Quicksort_medianOfThree(numbers, i, j);
   Quicksort_medianOfThree(numbers, j + 1, k);
   
   return;
}
//--------------------------------------------------------------------------

int main()
{
   // clock_t Start = clock();
   // //call sort function here
   // clock_t End = clock();
   // int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
   int arr1[NUMBERS_SIZE];
   int arr2[NUMBERS_SIZE];
   int arr3[NUMBERS_SIZE];
   int elapsedTime = 0;
   clock_t Start = 0;
   clock_t End = 0;
   
   fillArrays(arr1, arr2, arr3);
   
   Start = clock();
   Quicksort_medianOfThree(arr1, 0, NUMBERS_SIZE - 1);
   End = clock();
   elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.  
   cout << "Quicksort median of three took: " << elapsedTime << " milliseconds" << endl;
   
   Start = clock();
   Quicksort_midpoint(arr2, 0, NUMBERS_SIZE - 1);
   End = clock();
   elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.  
   cout << "Quicksort midpoint took: " << elapsedTime << " miliseconds" << endl;
   
   Start = clock();
   InsertionSort(arr3, NUMBERS_SIZE);
   End = clock();
   elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.  
   cout << "Insertion Sort took: " << elapsedTime << " miliseconds" << endl;
   
   return 0;
}