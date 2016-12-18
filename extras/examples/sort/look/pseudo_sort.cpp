//Figure 13.3.2: Runtime complexities for various code examples.

//Notation	Name	Example pseudocode


//===================================================================


//O(N log N)	Log-linear	
MergeSort(numbers, i, k) {
   j = 0
   if (i < k) {
      j = (i + k) / 2              // Find midpoint 
      
      MergeSort(numbers, i, j)     // Sort left part
      MergeSort(numbers, j + 1, k) // Sort right part
      Merge(numbers, i, j, k)      // Merge parts
   }
}
//-----------------------------------------------------

//O(N2)	Quadratic	
SelectionSort(int numbers, N) 
{ 
   for (i = 0; i < numbersSize; ++i) 
   {
      // Find index of smallest remaining element
      indexSmallest = i
      for (j = i + 1; j < numbersSize; ++j) 
      {
         if (numbers[j] < numbers[indexSmallest]) 
         {
            indexSmallest = j
         }
      }
      
      // Swap numbers[i] and numbers[indexSmallest]
      temp = numbers[i]
      numbers[i] = numbers[indexSmallest]
      numbers[indexSmallest] = temp
   }
}

//selection sort goes through list, swap after the inner loop
//bubble sort swaps inside inner loop

//-------------------------------------------------


//=========================================
//=========================================


//EXTRAS

/*------------------------------------------------

#include <algorithm> // for std::swap, use <utility> instead if C++11
 
void SelectionSort(int *array, int size)
{
    // Step through each element of the array
    for (int startIndex = 0; startIndex < size; ++startIndex)
    {
        // smallestIndex is the index of the smallest element we've encountered so far.
        int smallestIndex = startIndex;
 
        // Look for smallest element remaining in the array (starting at startIndex+1)
        for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
        {
            // If the current element is smaller than our previously found smallest
            if (array[smallestIndex] > array[currentIndex]) // COMPARISON DONE HERE
                // This is the new smallest number for this iteration
                smallestIndex = currentIndex;
        }
 
        // Swap our start element with our smallest element
        std::swap(array[startIndex], array[smallestIndex]);
    }
}


*///-----------------------------------------------------------

