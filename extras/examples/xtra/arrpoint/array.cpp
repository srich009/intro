#include <iostream>

using namespace std;


///GLOBAL CONSTANT
const int ARR_CAP = 5; // array capacity


///GLOBAL FUNCTIONS
void display(const double arr[], int arrSize) // arrays are passed in by reference auto. so set to const if displaying...
{
    for(int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << ", ";
    }
}




///MAIN
int main()
{
    double arrX[ARR_CAP] = {1, 2, 3, 4, 5}; //  sets elements equal to the initilization list in braces. 
                                            //if list size != ARR_CAP elements past list set to 0
                                            
    int b = 2;
    int *ptr = &b; // pointer to an integer variable, stores an address.  single & means address of
    
    cout << ptr << endl;  // display address
    cout << *ptr << endl; // display value at address, uses dereference *ptr
    
    
    /*
    cout << "Enter " << ARR_CAP << " values" << endl;
    for(int i = 0; i < ARR_CAP; i++)
    {
        cin >> arrX[i];
    }
    */
    
    
    
    /*    
    for(int i = 0; i < ARR_CAP; i++)
    {
        cout << arrX[i] << ", " << flush;  // flushes the cout buffer, each time flush encountered dumps content of buffer to screen, no newline.
    }
    
    cout << arrX[10000] << endl; // seg fault access past the arrays capacity ;;  UNDEFINED BEHAVIOR
    */
    
    
    
    display(arrX, ARR_CAP);
    cout << endl;
    display(arrX, ARR_CAP);
    cout << endl;
    
return 0;
}

