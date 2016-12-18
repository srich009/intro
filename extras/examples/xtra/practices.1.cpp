//BROKEN??????? or nah?

#include <iostream>
#include <algorithm>

using namespace std;

//const int *arr
int* min(int *arr, int size)
{
	//Base cases
	if(size == 0)
	{
		int* ip = 0;
		return ip;
	}
	else if(size == 1)
	{
		return arr;
	}
	
	//broken
	
	int* ip = min(arr, size-1);

	if(ip < arr)
	{
		return ip;
	}
	else
	{
		return ip;
	}

}

int* reverse(int* arr, int size)  // recursive array reversal
{
	if(size <= 1)
	{
		return arr;
	}
	
	swap(arr[0], arr[size-1]);
	
	int* ip = arr + 1;
	
	size -= 1;
	
	reverse(ip, size-1);
}


int main()
{
	int arr[5]  = {5,2,1,3,4};

    
    int* point = 0;
    point = min(arr, 5);
    
    cout << "min: ";
    cout << *point << endl;
    
    cout << "reverse" << endl;
    for(int i = 0; i < 5; i++)
    {
    	cout << arr[i] << ' ';
    }
    cout << endl;
    
    reverse(arr,5);
    
    for(int i = 0; i < 5; i++)
    {
    	cout << arr[i] << ' ';
    }
    cout << endl;
    
return 0;
}