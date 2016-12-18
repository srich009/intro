#include <iostream>
#include <queue>

using namespace std;

int qfib(int x)
{
    int sum = 0;
    
    queue<int> bbb;
    
    bbb.push(1);
    bbb.push(1);
    
    for(unsigned i = 0; i < x; i++)
    {
        sum = bbb.front();
        bbb.pop();
        sum += bbb.front();
        bbb.push(sum);
    }
    
    return sum;
}


int main()
{
    int num = 6;
    
    cout << qfib(num) << endl;
    
return 0;
}