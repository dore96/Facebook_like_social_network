#include "Date.h"
Date::Date(int inputDay, int inputMonth, int inputYear)
{
	if (setDate(inputDay, inputMonth, inputYear) == false)
	{
		throw invalid_argument("Date given is not possible");
	}
}
bool Date::setDate(int inputDay, int inputMonth, int inputYear)
{
	return (setYear(inputYear) && setMonth(inputMonth) && setDay(inputDay));
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
bool Date::setYear(int year)
{
	this->year = year;
	return true;
}
bool Date::setMonth(int month)
{
	if (!(month < 13 && month > 0))
	{
		return false;
	}
	this->month = month;
	return true;
}
bool Date::setDay(int day)
{
	if (day <= 0 || day > monthLen[getMonth()])
	{
		return false;
	}
	this->day = day;
	return true;
}