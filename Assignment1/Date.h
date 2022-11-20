#ifndef __Date_H
#define __Date_H
#define CURRENT_YEAR 2022
#include <iostream>
#include "Utilities.h"
using namespace std;
#pragma warning (disable: 4996)

class Date
{
public:
	Date(int inputDay, int inputMonth, int inputYear);
	int getYear() const;
	int getMonth() const;
	int getDay() const;
private:
	bool setDate(int inputDay, int inputMonth, int inputYear);
	int year, month, day;
	const int monthLen[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//how many days are in each month
};

#endif
