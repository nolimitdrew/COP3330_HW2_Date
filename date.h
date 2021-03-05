
/* Name: Andrew Stade
Date: 2/7/2020
Section: 2 */

class Date
{
public:
    Date();                         // default constructor
    Date(int m, int d, int y);      // constructor w/ parameters
    
    // accessors
    void Show();
    int GetMonth();
    int GetDay();
    int GetYear();
    int Compare(const Date& d);
    
    // mutators 
    void Input();
    bool Set(int m, int d, int y);
    bool SetFormat(char f);
    void Increment(int numDays = 1);

private:
    int month;
    int day;
    int year;
    char format;
};