#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    
    /*
    
    char title[80] = "The Force Awakens"; //array of cstrings ends in null
    // char title[80] = {'T', 'h', 'e', ' ', 'F', 'o', 'r', 'c', 'e'}
    
    cout << title << endl;
    
    //title[6] = '\0'; //now array will end at element 6
    
    cout << "enter a title" << endl;
    //cin >> title;
    cin.getline(title, 79); //getline for cstrings  (array, max_size)
    
    cout << title << endl;
    
    cout << strlen(title) << endl; // tell length of cstrings
    
    strcpy(title, "braveheart"); // copy into cstring (destination, new_info)
    cout << title << endl;
    
    strcat(title, ": my favorite movie"); // add to end of cstring, (destination, cstring_to_add)
    cout << title << endl;
    */
    
    
    /*
    ///SWAP CSTRINGS??? not done
    
    char s1[80];
    char s2[80];
    
    cout << "enter 2 words" << endl;
    cin >> s1 >> s2;
    
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl; 
    
    //swap if o is bigger... etc
    if(strcmp(s1, s2) > 0)
    {
        char temp[80];
        strcpy(temp, s1);
        strcpy(s1, s2);
        strcpy(s2, temp);
    }
    
    cout << s1;
    cout << endl;
    cout << s2;
    */
    
    
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    cout << arr << endl; // address of first element in the array
        
    int n = 10;
    int m = 20;
    
    int *iptr = arr; // pointer to the first element of an array
    
    cout << iptr << endl;
    cout << *iptr << endl;
    cout << *arr << endl;
    cout << *iptr + 1 << endl;
    cout << *(iptr + 1) << endl;
    cout << *(arr + 1) << endl;
    cout << arr[1] << endl;
    cout << iptr[1] << endl;
    
    //  ++arr;  // not legal; arr is const
    ++iptr; // OK now iptr ponts to second element in arr
    cout << arr << endl;
    cout << iptr << endl;
    cout << *iptr << endl;
    cout << iptr[0] << endl;  // first thing iptr now points to arr[1]
    cout << iptr[1] << endl; // second thing iptr points to arr[2]
    
    
    /*
    int *iptr2 = new int;  // using new opperator to assign local variable iptr2 a mem location in HEAP to iptr2 returns address in HEAP
    cout << iptr2 << endl;
    cout << *iptr2 << endl;
    *iptr2 = 3;
    cout << *iptr2 << endl;
    int *iptr3 = new int(999);
    cout << *iptr3 << endl;
    
    delete iptr2; // deallocate iptr2 and give back mem to heap
    delete iptr3;
    
    iptr4 = new int[100];
    delete[] iptr4; // delete for using arrays
    
    */
    
    
return 0;    
}