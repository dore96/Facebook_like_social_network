#ifndef __Date_H
#define __Date_H
#include "Exceptions.h"

const int monthLen[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };  //how many days are in each month
void CleanBuffer();													 //utilitie func

class Date
{
public:
	Date(int inputDay, int inputMonth, int inputYear) noexcept(false);
	//getters
	int getYear()  const;
	int getMonth() const;
	int getDay()   const;
	//setters
	void setDate(int inputDay, int inputMonth, int inputYear) noexcept(false);
	void setYear(int year);
	void setMonth(int month) noexcept(false);
	void setDay(int day) noexcept(false);
	friend ostream& operator <<(ostream& os, const Date& date);
private:
	int year, month, day;
};



#endif
