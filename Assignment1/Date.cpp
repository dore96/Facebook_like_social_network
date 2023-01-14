#include "Date.h"
Date::Date(int inputDay, int inputMonth, int inputYear) noexcept(false)
{
	setDate(inputDay, inputMonth, inputYear);
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
	if (!(month < 13 && month > 0))
	{
		throw invalidMonthException();
	}
	this->month = month;
}
void Date::setDay(int day)
{
	if (day <= 0 || day > monthLen[month])
	{
		throw invalidDayException();
	}
	this->day = day;
}
ostream& operator <<(ostream& os, const Date& date)
{
	os << date.day << "/" << date.month << "/" << date.year;
	return os;
}

char* getString(istream& in)
{
	char* res;
	int Len;
	in >> Len;
	res = new char[Len];
	in >> res;
	res[Len] = '\0';
	return res;
}

void CleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}