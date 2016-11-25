// 6.17 LAB 9: Vectors - Calculating Mean, Variance, and Standard Deviation

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void fillVector(vector<double> &userVector) //(1) FIXME - Add ParameterXXX
{
    double userDouble = 0.0;

    cout << "Enter numbers to populate the vector ";
    cout << "(enter any other character to end user input): "; 

    while (cin >> userDouble) 
    {
      //(1) FIXME - Add numbers to vectorXXX
      userVector.push_back(userDouble);
      
    }
    cout << endl;

    return;
}

double meanVector(const vector <double> &v) {

   //(2) FIXME - Calculate mean of vector numbersXXX
   double meanValue = 0.0;
   int counter = 0;
   
   for(unsigned int i = 0; i < v.size(); i++)
   {
    meanValue = meanValue + v.at(i);
    counter++;  
   }
   
   meanValue = meanValue / static_cast<double>(counter); 
   
   return meanValue;
}

double varianceVector(double vectorAvg, const vector <double> &v)
{
    int counter = 0;
    double vectorVar = 0.0;
    
   //(3) FIXME - Calculate variance of vector numbersXXX
   for(unsigned int i = 0; i < v.size(); i++)
   {
    vectorVar = vectorVar + pow( v.at(i) - vectorAvg , 2);  
    counter++;
   }
   
   vectorVar = vectorVar / static_cast<double>(counter);
   
   return vectorVar;
}

double standardDeviationForVariance(double vectorVariance) 
{
    double vectorSD = 0.0;
   //(4) FIXME - Calculate standard deviation
   vectorSD = sqrt(vectorVariance);
   
   return vectorSD; //FIX
}

int main() {
   //(1) FIXME - Declare vector of doublesXXX
   vector<double> userVector;
   double avg = 0.0;
   double var = 0.0;
   double stdDev = 0.0;
   unsigned int i = 0;

   //(1) FIXME - Call fillVector() functionXXX
   fillVector(userVector);

   cout << "You entered: ";
   //(1) FIXME - Print vector values (use i variable)XXX
   for(i = 0; i < userVector.size(); i++)
   {
    cout << userVector.at(i) << " ";   
   }
   cout << endl;
   
   
   //(2) FIXME - Call meanVector() functionXXX
   avg = meanVector(userVector);

   //(3) FIXME - Call varianceVector() functionXXX
   var = varianceVector(avg, userVector);

   //(4) FIXME - Call standardDeviationForVariance() function
   stdDev = standardDeviationForVariance(var);

   cout << "The mean is: " << avg << endl;
   cout << "The variance is: " << var << endl;
   cout << "The standard deviation is: " << stdDev << endl;

   return 0;
}

/*

Note: For this program, you will be working with populations, not samples.

(1) Declare a vector of doubles. Give the fillVector() function the correct parameter (pass by value or by reference?).
Then in the fillVector() function, add a line of code at the FIXME to store values from the user into the vector. Call the fillVector() function in main().

(2) In function meanVector(), calculate and return the mean (average) of vector's numbers. Call meanVector() from main().

(3) In varianceVector(), calculate and return the variance the vector's numbers, using the mean calculated above. 
Hint: Store the squared differences in a new vector and then use the mean function again to calculate the variance. Call varianceVector() in main().

(4) In standardDeviationVector(), calculate and return the standard deviation of the vector's numbers, using the variance calculated above. 
Call standardDeviationVector() in main().

DO NOT change any of the provided function headers other than adding the parameter to the fillVector (FIXME 3).
Each of your functions will be tested to insure they work correctly.

*/