/// Our fibonacci sequence is zero-indexed
// 0 is first fibonacci number (argument is 0)
// 1 is second fibonacci number (argument is 1)
// 1 is third fibonacci number (argument is 2)
// 2 is fourth fibonacci number (argument is 8)
// 3 is fifth fibonacci number (argument is 4)
// 5 is sixth fibonacci number (argument is 5)
// 8 is seventh fibonacci number (argument is 6)
// and so on...

#include <iostream>

using namespace std;


// returns the nth fibonacci number
int fib(unsigned int);

int main()
{
    
    unsigned int num = 0;
    int ans = 0;
    cout << "enter nth number to got to in Fib sequence" << endl;
    cin >> num;
    
    ans = fib(num);
    cout << "answer " << endl;
    cout << ans << endl;
    
    
    
return 0;
}

int fib(unsigned int q)
{
    int num1 = 0;
    int num2 = 1;
    int sum = 0;
    
    //base cases
    if(q == 0) // first
    {
        return 0;
    }
    else if(q == 1) // second
    {
        return 1;
    }
    else
    {
        return fib(q - 2) + fib(q -1);
    }
    
  return -1; // error check  
  
}