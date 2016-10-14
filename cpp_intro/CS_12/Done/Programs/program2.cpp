#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date
{
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:

   Date();
   // creates the date January 1st, 2000.


   Date(unsigned m, unsigned d, unsigned y);
   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */


   Date(const string &mn, unsigned d, unsigned y);
   /* parameterized constructor: month name, day, year
       - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000 
       (with a newline at the end).

       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */


   void printNumeric() const;
   /* Outputs to the console (cout) a Date exactly in the format "3/1/2012". 
      Does not output a newline at the end.
   */


   void printAlpha() const;
   /* Outputs to the console (cout) a Date exactly in the format "March 1, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   

   //************************************************************
   // Only uncomment the following function (addDays) declaration
   // if you are trying for the extra credit
   // Date addDays(int d) const;
      /* Add a number of days to one date to get another: 
      this number may be positive or negative.
      Obviously, the new date will be a valid date, 
      accounting for the correct number of days in each month, 
      and for leap years. Gregorian calendar leap year rules
      used no matter how many negative days passed in.
   */ //**********************************************************

 private:

   bool isLeap(unsigned y) const;
   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */

   unsigned daysPerMonth(unsigned m, unsigned y) const;
   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */

   string name(unsigned m) const;
   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */

   unsigned number(const string &mn) const;
   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   
};
//====================================================================


//Constructor definitions
Date::Date()
{
   monthName = "January";
   month = 1;
   day = 1;
   year = 2000;   
return;
}
//----------------------------
Date::Date(unsigned m, unsigned d, unsigned y)  // month num
{
   bool hasErr = false;
   
   //month 
   if(m < 1) // if 0 or less
   {
      month = 1;
      hasErr = true;
      
   }
   else if( m > 12)// if 13 or greater
   {
      month = 12;
     hasErr = true;
   }
   else
   {
      month = m;
   }
   
   year = y;
   
   //days
   if(d < 1) // if 0 or less
   {
      day = 1;
      hasErr = true;
   }
   else if(d > daysPerMonth(month, year))
   {
    day = daysPerMonth(month, year) ;
    hasErr = true;
   }
   else
   {
      day = d;
   }
   
   monthName = name(month); //Test

   //err check
   if(hasErr)
   {
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }
   
         
return;
}
//--------------------------
Date::Date(const string &mn, unsigned d, unsigned y)  // month string
{
   bool hasErrDate = false;
   bool hasErrName = false;
   
   
   if(number(mn) == 0)
   {
      hasErrName = true;
   }
   else
   {
       monthName = mn;
       
   //}
   
      year = y; 
      
      month = number(mn); // TEST
      
      //days
      if(d < 1) // if 0 or less
      {
         day = 1;
         hasErrDate = true;
      }
      else if(d > daysPerMonth(month, year))
      {
       day = daysPerMonth(month,year) ;
       hasErrDate = true;
      }
      else
      {
         day = d;
      }
      
          for(unsigned k = 0; k < 2; k++)
         {
            monthName.at(0) = toupper(monthName.at(0)); // TEST
         }
      
   } 
   

   
   //err check
   if(hasErrDate)
   {
      cout << "Invalid date values: Date corrected to "  << number(mn) << "/" << day << "/" << year << "." <<endl;
   }
   
   if(hasErrName)
   {
      cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
      monthName = "January";
      month = 1;
      day = 1;
      year = 2000;
      
   }
   
return;
}
//--------------------------------

//function definitions

//public
void Date::printNumeric() const
{
   cout << month;
   
   cout << "/" << day << "/" << year;
   return;
}
//-----------------------
void Date::printAlpha() const
{
   
   
   cout << monthName;
   
   cout << " " << day << ", " << year;
   return; 
}
//----------------------

//private
bool Date::isLeap(unsigned y) const
{
   if(y % 4 == 0)
   {
      if(y % 400 == 0)
      {
         return true;
      }
      if(y % 100 == 0)
      {
         return false;
      }
      return true;
   }
   else
   {
      return false;
   }
   
return false; // just to compile?
  
}
//-----------------------
unsigned Date::daysPerMonth(unsigned m, unsigned y) const
{

   if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
   {
      return 31;
   }
   else if(m == 4 || m == 6 || m == 9 || m == 11)
   {
      return 30;
   }
   
   if(m == 2 && isLeap(y))
   {
      return 29;
   }
   else if(m == 2 && !isLeap(y))
   {
      return 28;
   }
   else
   {
      return 0;
   }
   
}
//-----------------------------
string Date::name(unsigned m) const
{
   switch (m)
   {
      case 1:
         return "January";
      case 2:
         return "February";      
      case 3:
         return "March";
      case 4:
         return "April";
      case 5:
         return "May";      
      case 6:
         return "June";
      case 7:
         return "July";     
      case 8:
         return "August";
      case 9:
         return "September";
      case 10:
         return "October";   
      case 11:
         return "November";   
      case 12:
         return "December";
      default:
         return "Err";
   }
   
   
}
//-------------------------------
unsigned Date::number(const string &mn) const
{
   string h = mn;
   for(unsigned int i = 0; i < h.size(); i++)
   {
     h.at(i) = toupper(h.at(i));
   }
   
      if( h == "JANUARY")
         {
            return 1;
         }
      else if( h == "FEBRUARY") 
         {
            return 2;
         }
      else if( h == "MARCH")
         {
            return 3;
         }
      else if( h == "APRIL")
         {
            return 4;
         }
      else if( h == "MAY")
         {
            return 5;
         }
      else if( h == "JUNE")
         {
            return 6;
         }
      else if( h == "JULY")
         {
            return 7;
         }
      else if( h == "AUGUST")
         {
            return 8;
         }
      else if( h == "SEPTEMBER")
         {
            return 9;
         }
      else if( h == "OCTOBER")
         {
            return 10;
         }
      else if( h == "NOVEMBER")
         {
            return 11;
         }
      else if( h == "DECEMBER")
         {
            return 12;
         }
      else
         {
            return 0;
         }

}

//====================================================================

//global
Date getDate();

int main() 
{

   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;

   return 0;
}

Date getDate() 
{
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) 
   {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } 
   else if (choice == 2) 
   {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } 
   else 
   {
      return Date();
   }
   
}