//Lab 5 array stuff

#include <iostream>

using namespace std;

///Global Functions

double mean(const double array[], int arraySize);

void remove(double array[], int arraySize, int index);

void display(const double array[], int arraySize);



int main()
{
      
       int testSize = 10;
       int remVal = 0;
       int i = 0;
       double meanVal = 0;
       
    // Declare an array of doubles of size 10.
    double testArray[10];
    
    // Fill the array with 10 doubles entered by the user.
    cout << "Enter 10 values:" << endl;
    
    for(i = 0; i < testSize; i++)
    {
        cin >> testArray[i];
    }
    cout << endl;
    
    // Call the mean function passing it this array and output the value returned.
    cout << "Mean: ";
     meanVal = mean(testArray, testSize);
    cout << meanVal;
    cout << endl;
    cout << endl;
    
    // Ask the user for the index (0 to 9) of the value they want to remove.
    cout << "Enter index of value to be removed: ";
    cin >> remVal;
    cout << endl;
    
    
    // Call the display function to output the array.
    cout << "Before removing value: ";
    display(testArray, testSize);
    cout << endl;
    
    // Call the remove function to remove the value at the index provided by the user.
    remove(testArray, testSize, remVal);
    
    // Call the display function again to output the array with the value removed.
    cout << "After removing value: " ;
    display( testArray, (testSize - 1) );   
    cout << endl;
        
return 0;
}
//==================================================

//Passes in an array along with the size of the array
//returns the mean of all values stored in the array.
double mean(const double array[], int arraySize)
{
    double sum = 0;
    
    for(int i = 0; i < arraySize; i++)
    {
        sum += array[i];
    }
    
    return (sum / static_cast<double>(arraySize));
}

//Passes in an array, the size of the array, and the index of a value to be removed from the array.
//The function should remove the value at this index by shifting all of the values after this value left,
//keeping the same relative order of all values not removed.
void remove(double array[], int arraySize, int index)
{
    if(index == 0)
    {
        for(int i = 0; i < arraySize; i++)
        {
            array[i] = array[i + 1];
        }
    }
    else if(index == arraySize - 1)
    {
        cout << "";
    }
    else
    {
        for(int i = index; i < arraySize; i++)
        {
            array[i] = array[i + 1];
        }
    }
    
    
    return;
}

//Passes in an array and the size of the array,
//and then outputs each value in the array
//separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize)
{
    for(int i = 0; i < arraySize - 1; i++)
    {
        cout << array[i] << ", ";
    }
    cout << array[arraySize - 1];
    
    return;
}