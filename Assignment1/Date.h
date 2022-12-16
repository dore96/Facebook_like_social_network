#ifndef __Date_H
#define __Date_H
#include "Utilities.h"
#include "exception"
#include "vector"
#include "list"
const int monthLen[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };  //how many days are in each month

class Date
{
public:
	Date(int inputDay, int inputMonth, int inputYear) noexcept(false);
	//getters
	int getYear()  const;
	int getMonth() const;
	int getDay()   const;
	//setters
	bool setDate(int inputDay, int inputMonth, int inputYear);
	bool setYear(int year);
	bool setMonth(int month);
	bool setDay(int day);
private:
	int year, month, day;
};

#endif
