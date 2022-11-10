#include "Date.h"

Date::Date(int mn, int dy, int yr)
{
    static int length[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    month = max(1, mn);         //check input
    month = min(month, 12);

    day = max(1, dy);
    day = min(day, length[month]);

    year = max(1, yr);
}

void Date::Display()
{
    cout << '\n' << name[month] << ' ' << day << "," << year << '\n';
    cout << "Days so far: " << DaysSoFar() << '\n';                   //need second or timespan so far.
}

Date::~Date()
{
    cout << "Thank You for using DateLine Services and have a nice date\n";
}

int Date::DaysSoFar()    //need time span so far not only days.
{
    int total = 0;
    static int length[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    for (int i = 1; i < month; i++) 
        total += length[i];
    total += day;
    return (total);
}

int Date::GetMonth()
{
    return month;
}

void Date::SetMonth(int mn)
{
    month = max(1, mn);
    month = min(month, 12);
}