
/* Name: Andrew Stade
Date: 2/7/2020
Section: 2 */

#include <iostream>
#include <iomanip>
#include <string>
#include "date.h"

using namespace std; 

Date::Date()                       
// default constructor
{
    month = 1;
    day = 1;
    year = 2000;
    format = 'D';
}

Date::Date(int m, int d, int y)      
// constructor w/ parameters
{
    if (y >= 0)
    {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)   // months with 31 days
        {
            if (d <= 31 && d > 0)
            {
                month = m;
                day = d;
                year = y;
                format = 'D';
            }
            else
            {
                month = 1;
                day = 1;
                year = 2000;
                format = 'D';
            }
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11)     // months with 30 days
        {
            if (d <= 30 && d > 0)
            {
                month = m;
                day = d;
                year = y;
                format = 'D';
            }
            else
            {
                month = 1;
                day = 1;
                year = 2000;
                format = 'D';
            }
        }
        else if (m == 2)    // month with 28 days
        {
            if (d <= 28 && d > 0)
            {
                month = m;
                day = d;
                year = y;
                format = 'D';
            }
            else
            {
                month = 1;
                day = 1;
                year = 2000;
                format = 'D';
            }
        }
        else
        {
            month = 1;
            day = 1;
            year = 2000;
            format = 'D';
        }
    }        
    else
    {
        month = 1;
        day = 1;
        year = 2000;
        format = 'D';
    }
}    
    
void Date::Show()
// outputs the date object
{
    string S;
    int DDyear;
    
    if (format == 'D')
    {
        cout << month << "/" << day << "/" << year;
    }
    else if (format == 'T')
    {
        DDyear = year % 100;
        
        if (DDyear < 10)
        {
            if (month < 10)
            {
                if (day < 10)
                {
                    cout << "0" << month << "/" << "0" << day << "/" << "0" << DDyear;
                }
                else
                {
                    cout << "0" << month << "/" << day << "/" << "0" << DDyear;
                }
            }
            else
            {
                if (day < 10)
                {
                    cout << month << "/" << "0" << day << "/" << "0" << DDyear;
                }
                else
                {
                    cout << month << "/" << day << "/" << "0" << DDyear;
                }
            }
        }
        else
        {
            if (month < 10)
            {
                if (day < 10)
                {
                    cout << "0" << month << "/" << "0" << day << "/" << DDyear;
                }
                else
                {
                    cout << "0" << month << "/" << day << "/" << DDyear;
                }
            }
            else
            {
                if (day < 10)
                {
                    cout << month << "/" << "0" << day << "/" << DDyear;
                }
                else
                {
                    cout << month << "/" << day << "/" << DDyear;
                }
            }
        }
    }
    else if (format == 'L')
    {
        if (month == 1)
        {
            S = "Jan ";
            cout << S << day << ", " << year; 
        }
        else if (month == 2)
        {
            S = "Feb ";
            cout << S << day << ", " << year; 
        }
        else if (month == 3)
        {
            S = "Mar ";
            cout << S << day << ", " << year; 
        }
        else if (month == 4)
        {
            S = "Apr ";
            cout << S << day << ", " << year; 
        }
        else if (month == 5)
        {
            S = "May ";
            cout << S << day << ", " << year; 
        }
        else if (month == 6)
        {
            S = "June ";
            cout << S << day << ", " << year; 
        }
        else if (month == 7)
        {
            S = "July ";
            cout << S << day << ", " << year; 
        }
        else if (month == 8)
        {
            S = "Aug ";
            cout << S << day << ", " << year; 
        }
        else if (month == 9)
        {
            S = "Sept ";
            cout << S << day << ", " << year; 
        }
        else if (month == 10)
        {
            S = "Oct ";
            cout << S << day << ", " << year; 
        }
        else if (month == 11)
        {
            S = "Nov ";
            cout << S << day << ", " << year; 
        }
        else if (month == 12)
        {
            S = "Dec ";
            cout << S << day << ", " << year; 
        }
        else
        {
            cout << "Error. char 'month' not being read" << endl;
        }
    }
    else
    {
        cout << "\nError. char 'format' not being read" << endl;
    }
}
    
int Date::GetMonth()
{
    return month;
}
    
int Date::GetDay()
{
    return day;
}

int Date::GetYear()
{
    return year;
}

int Date::Compare(const Date& d)
{
    Date answer = d;
    
    if (year == answer.year)
    {
        if (month == answer.month)
        {
            if (day == answer.day)
            {
                return 0;
            }
            else if (day > answer.day)
            {
                return 1;
            }
            else if (day < answer.day)
            {
                return -1;
            }
        }
        else if (month > answer.month)
        {
            return 1;
        }
        else if (month < answer.month)
        {
            return -1;
        }
    }    
    else if (year > answer.year)
    {
        return 1;
    }
    else if (year < answer.year)
    {
        return -1;
    }
}    

void Date::Input()
// allows the user to enter a date
{
    int usrMonth;
    int usrDay;
    int usrYear;
    char slash;
    
    
    cout << "\nEnter a month/day/year: " << endl;
    cin >> usrMonth >> slash >> usrDay >> slash >> usrYear;        // test for slashes
    Set(usrMonth, usrDay, usrYear);
    
    if (Set(usrMonth,usrDay,usrYear) == false)
    {
        while (Set(usrMonth,usrDay,usrYear) == false)
        {
            cout << "Invalid date. Try again: " << endl;
            cin >> usrMonth >> slash >> usrDay >> slash >> usrYear;
            Set(usrMonth, usrDay, usrYear);
        }
    } 
}

bool Date::Set(int m, int d, int y)
{
    if (y >= 0)
    {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)   // months with 31 days
        {
            if (d <= 31 && d > 0)
            {
                month = m;
                day = d;
                year = y;
                format = 'D';
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11)     // months with 30 days
        {
            if (d <= 30 && d > 0)
            {
                month = m;
                day = d;
                year = y;
                format = 'D';
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (m == 2)    // month with 28 days
        {
            if (d <= 28 && d > 0)
            {
                month = m;
                day = d;
                year = y;
                format = 'D';
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }        
    else
    {
        return false;
    }    
}    

bool Date::SetFormat(char f)
{
    if (f == 'D')
    {
        format = 'D';
        return true;
    }
    else if (f == 'T')
    {
        format = 'T';
        return true;
    }
    else if (f == 'L')
    {
        format = 'L';
        return true;
    }
    else 
    {
        return false;
    }
}

void Date::Increment(int numDays)
// increase the date by numDays (default = 1)
{   
    day = day + numDays;
    
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)
    {
        if (day > 31)
        {
            month++;
            day = day % 31;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
        {
            month++;
            day = day % 30;
        }           
    }                   
    else if (month == 12)
    {
        if (day > 31)
        {
            year++;
            month = 1;
            day = day % 31;
        }
    }        
    else if (month == 2)
    {
        if (day > 28)
        {
            month++;
            day = day % 28;
        }
    }
}