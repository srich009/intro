// main program 6
//LINEAR DIOPHANTINE EQUATIONS

#include <iostream>

using namespace std;

/* Returns true if a solution was found and false if there is no solution.
   x and y will contain a solution if a solution was found. 
   This function will NOT output anything.
*/
bool diophantine(int a, int b, int c, int &x, int &y);
int GCD(int num1, int num2) ;

int main() 
{

    int a, b, c, x, y;

    cout << "Enter a b c" << endl;
    cin >> a >> b >> c;
    cout << endl;

    cout << "Result: ";
    if (diophantine(a, b, c, x, y)) 
    {
        cout << x << " " << y << endl;
    } 
    else 
    {
        cout << "No solution!" << endl;
    }

    return 0;
}

/* Returns true if a solution was found and false if there is no solution.
   x and y will contain a solution if a solution was found. 
   This function will NOT output anything.
*/
bool diophantine(int a, int b, int c, int &x, int &y)
{
    //uses gcd inside
    //ax + by = c
    //ax + by = gcd(a,b)
    
// If gcd(a,b) does not divide c, then there is no solution.

//If b divides a (the remainder of a / b is 0), then you can just divide by b to get the solution: x = 0, y = c / b.

//Otherwise (b does not divide a), through a substitution method, we can come up with a simpler version of the original problem and solve the simpler problem using recursion.
  
  if( c % GCD(a,b) != 0)
  {
      return false;
  }
  
  if((a%b) == 0)
  {
      x = 0;
      y = (c/b);
      return true;
  }
  
  //RECURSE
  int u;
  int v;
  int q = a/b;
  int r = a%b;
  
  
  
  if( diophantine(b, r, c, u, v ) )
  {
      x = v;
      y = u - (q*x);
      return true;
  }
  return false;
}


//gcd function
int GCD(int num1, int num2) 
{
   int gcdVal = 0; // Holds GCD results
   
   if(num1 < 0)
   {
       num1 *= -1;
   }
   
   if(num2 < 0)
   {
       num2 *= -1;
   }
   
   
   if(num1 == num2) {    // Base case: Numbers are equal
      gcdVal = num1;       // Return value
   }
   else {                    // Recursive case: subtract smaller from larger
      if (num1 > num2) { // Call function with new values
         gcdVal = GCD(num1 - num2, num2);
      }
      else {
         gcdVal= GCD(num1, num2 - num1);
      }
   }
   
   return gcdVal;
}

/*
ax + by = c
Now, we can define a as:

a = bq + r
where q is (a / b) (using integer division) and r is the remainder (a % b).

Substituting (bq + r) in as a now:

(bq + r)x + by = c
which is the same as

b(qx + y) + rx = c
and now we have the equation in the same style, only with smaller coefficients:

bu + rv = c
with u = qx + y and v = x.

Finally, you recursively call your function on this simpler version of the original problem.
remember that this recursive call will actually solve  u and v in this case, so you still have to solve  x and y to get the solution to the original problem:

x = v 
y = u - qx
*/