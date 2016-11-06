// program 1
// calculating lift coefficient

#include<iostream> 
#include<fstream> 
#include<sstream>
#include<cstdlib>
#include <vector>
#include <algorithm> 
#include<cmath>
#include <iomanip>

using namespace std;

//function prototypes
void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

int main()
{
    string fileName;
    double pathAngle;
    vector<double> flightAngle;
    vector<double> liftCoefficient;
    
    cout << "Enter name of input data file:" << endl;
    cin >> fileName;
    cout << endl;
    
    readData(fileName, flightAngle, liftCoefficient);
    
    if(!isOrdered(flightAngle))
    {        
       reorder(flightAngle, liftCoefficient);
                
    }
    
    char again = 'x';
    do
    {
    cout << "Enter a flight-path angle:" << endl;
    cin >> pathAngle;
    
    cout << "matching coefficient of lift: "; // set size 3 decimal "<< setprecision(3) <<"
    cout  << interpolation(pathAngle, flightAngle, liftCoefficient) << endl;
    cout << endl;
    
    cout << "enter another flight path angle? y/n" << endl;
    cin >> again;
    cout << endl;
    
    }
    while(again != 'n');
     
return 0;   
}
//======================================================================================================


//completed functions
void readData(const string &fileName, vector<double> &flightAngle, vector<double> &liftCoefficient)
{
    ifstream inData;
    inData.open(fileName.c_str()); 
    
    if(!inData.is_open()) 
    {
        cout << "Error opening " << fileName << endl;
        exit (EXIT_FAILURE);
        return;
    }
 
    double f;
    int counter = 0;
    
    while(inData >> f)
    {
        if(counter % 2 == 0)
        {
            flightAngle.push_back(f);
        }
        else
        {
            liftCoefficient.push_back(f);   
        }
        counter++;
    }
    
 
return;   
}
//-----------------------------------------------------------------------------------------------------------------------

double interpolation(double pathAngle, const vector<double> &flightAngle, const vector<double> &liftCoefficient)
{
    if(flightAngle.empty()) // size 0
    {
        return -1;
    }
    else if(flightAngle.size() == 1 && pathAngle != flightAngle.at(0))
    {
        return -1;
    }
    
    
    for(unsigned int i = 0; i < flightAngle.size(); i++) // size > 1 && found pathAngle in vector
    {
        if(pathAngle == flightAngle.at(i))
        {
            return liftCoefficient.at(i); 
        }
    }
    
    
    double a = 0; 
    double b = pathAngle;
    double c = 0;
    
    unsigned int i;
    
    for(i=0; i < flightAngle.size(); i++)
    {
        if(flightAngle.at(0) > pathAngle) // catch for too small
        {
            return -1;
        }
        
        if( flightAngle.at(flightAngle.size() - 1) < pathAngle) // catch for too big
        {
            return -2;
        }    
        
        if(flightAngle.at(i) > pathAngle) // catch for in between
        {
            c = flightAngle.at(i);
            a = flightAngle.at(i-1);
            break;
        }
        
    }
    
    double fB = 0;
    double fA = liftCoefficient.at(i - 1);
    double fC = liftCoefficient.at(i);
    fB = ( ((b-a) * (fC-fA)) / (c - a) ) + fA ;
    
    //original formula
    // f(b) = f(a) + (b - a)/(c - a)(f(c) - f(a))
 
 
 
return fB; //Fixme return corresponding lift coefficient in percent ?? fB/10
}
//------------------------------------------------------------------


bool isOrdered(const vector<double> &flightAngle)
{
    if(flightAngle.empty() || flightAngle.size() == 1) // size 0 || 1
    {
        return true;
    }
    
    for(unsigned int i = 1; i < flightAngle.size() ; i++) // size >= 2
    {
        if(flightAngle.at(i - 1) > flightAngle.at(i))
        {
            return false;
        }
            
    }
    return true;
 
}
//-----------------------------------------------------------


void reorder(vector<double> &flightAngle, vector<double> &liftCoefficient)
{
    if(flightAngle.empty() || flightAngle.size() == 1) // size 0 || 1
    {
        return;
    }
        
    for(unsigned int i = 0; i < flightAngle.size() - 1 ; i++) // size >= 2
    {
        for(unsigned int k = (i +1); k < flightAngle.size(); k++)
        {
            if(flightAngle.at(i) > flightAngle.at(k))
            {
                swap(flightAngle.at(i), flightAngle.at(k));
                swap(liftCoefficient.at(i), liftCoefficient.at(k));
            }
        }
    }
    
    
 
return;    
}

/*

vector display test...

    for(unsigned int i = 0; i < flightAngle.size(); i++)
    {
        cout << flightAngle.at(i) << " ";
        cout << liftCoefficient.at(i) << endl;
        
    }
    cout << endl;

*/