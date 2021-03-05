/////////////////////////////////////////////////////////
// Bob Myers
//
// sample.cpp -- sample test program starter for Date class
/////////////////////////////////////////////////////////

#include <iostream>
#include "date.h"

using namespace std;

int main()
{
   Date d1;		// should default to 1/1/2000
   Date d2(10,31,1992);  // should init to 10/31/1992
   Date d3(-2,30,1990); // invalid month, initializes to Jan 1, 2000 instead. 
   Date d4(1,-10,1990); // invalid day, initializes to Jan 1, 2000 instead. 
   Date d5(12,30,500); // should init to 1/18/500 
   

   // display dates to the screen
   cout << "\nDate d1 is: ";
   d1.Show();			
   cout << "\nDate d2 is: ";
   d2.Show();
   cout << "\nDate d3 is: ";
   d3.Show();
   cout << "\nDate d4 is: ";
   d4.Show();
   cout << "\nDate d5 is: ";
   d5.Show();
   cout << "\n";

   d3.Set(2,11,1964);   // demonstrate the Set function
   cout << "\nDate d3 is set to: "; 
   d3.Show();
   cout << "\n";
   
   d1.Input();			// Allow user to enter a date for d1
   cout << "\nDate d1 is: ";
   d1.Show();			
   
   d1.SetFormat('T');		// change format of d1 to "Two-Digit" format
   cout << "\nDate d1 is: ";
   d1.Show();			// print d1 -- should show now in two digit format
   
   d1.SetFormat('L');		// change format of d1 to "Long" format
   cout << "\nDate d1 is: ";
   d1.Show();			// print d1 -- should show now in long format
   cout << "\n";
   
   d2.Increment();      // demonstrate the Increment function
   cout << "\nDate d2 is incremented to: ";
   d2.Show();           // should output 11/1/1992
   
   d5.Increment(5);     // demonstrate the Increment function
   cout << "\nDate d5 is incremented to: ";
   d5.Show();           // should output 1/4/501
   cout << "\n\n";
   
   cout << "Comparing the functions d1(input) and d2(11/1/1992):";
   cout << "\n" <<  d1.Compare(d2);
   cout << "\n" << d2.Compare(d1);
   cout << "\n";
   

   // and so on.  Add your own tests to fully test the class' 
   //   functionality.
}