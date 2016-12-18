//Figure 13.3.2: Runtime complexities for various code examples.

//Notation	Name	Example pseudocode

//===================================================

//O(log N)	Logarithmic	
BinarySearch(numbers, N, key) {
  mid = 0;
   low = 0;
   high = 0;
   
   high = N - 1;
   
   while (high >= low) {
      mid = (high + low) / 2
      if (numbers[mid] < key) {
         low = mid + 1
      }
      else if (numbers[mid] > key) {
         high = mid - 1
      }
      else {
         return mid
      }
   }
   
   return -1   // not found
}
//------------------------------------------------------

//O(N)	Linear	
LinearSearch(numbers, N, key) {
  for (i = 0; i < N; ++i) {
      if (numbers[i] == key) {
         return i
      }
   }
   
   return -1 // not found
}
//------------------------------------------------------


