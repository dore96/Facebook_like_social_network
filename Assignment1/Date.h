#ifndef __Date_H
#define __Date_H

#pragma warning (disable: 4996)
#include <iostream>
#include <string.h>
using namespace std;
#include <math.h>

static const char* name[] = { "nothing", "January", "February", "March", "April",
         "May", "June", "July", "August", "September", "October",
         "November", "December" };

int max(int a, int b)
{
    if (a > b) return(a); else return (b);
}

int min(int a, int b)
{
    if (a > b) return(b); else return (a);
}

class Date
{
public:
    Date(int mn, int day, int yr);  // constructor
    void Display();                   // function to display date
    int GetMonth();
    void SetMonth(int mn);
    ~Date();
private:
    int month, day, year;
    int DaysSoFar();
};

#endif