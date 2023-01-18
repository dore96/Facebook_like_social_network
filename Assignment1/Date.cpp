#include "Date.h"
Date::Date(int inputDay, int inputMonth, int inputYear) noexcept(false)//date ctor
{
	setDate(inputDay, inputMonth, inputYear);
}
Date::Date(istream& in)//date file ctor
{
	in >> *this;
}
void Date::setDate(int inputDay, int inputMonth, int inputYear) noexcept(false)
{
	setYear(inputYear);
	setMonth(inputMonth);
	setDay(inputDay);
}
int Date::getYear()					const
{
	return year;
}
int Date::getMonth()				const
{
	return month;
}
int Date::getDay()					const
{
	return day;
}
void Date::setYear(int year)
{
	this->year = year;
}
void Date::setMonth(int month)
{
	if (!(month < 13 && month > 0))//checks valid month
	{
		throw invalidMonthException();
	}
	this->month = month;
}
void Date::setDay(int day)
{
	if (day <= 0 || day > monthLen[month])//checks if in valid range of days in this month
	{
		throw invalidDayException();
	}
	this->day = day;
}
ostream& operator <<(ostream& os, const Date& date)
{
	os << date.day << "/" << date.month << "/" << date.year << endl;
	return os;
}

istream& operator >>(istream& in, Date& date)
{
	char ch;
	in >> date.day >> ch >> date.month >> ch >> date.year;
	return in;
}

void CleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}