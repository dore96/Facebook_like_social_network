#include "Date.h"
#include "Utilities.h"

Date::Date(int inputDay, int inputMonth, int inputYear)
{
	setDate(inputDay, inputMonth, inputYear);
}
bool Date::setDate(int inputDay, int inputMonth, int inputYear)
{
	if (!(inputMonth < 13 && inputMonth > 0))
	{
		return false;
	}
	else if (inputDay <= 0 || inputDay > monthLen[inputMonth])
	{
		return false;
	}
	else if (inputYear > CURRENT_YEAR)
	{
		return false;
	}
	year = inputYear;
	month = inputMonth;
	day = inputDay;
	return true;
}
int Date::getYear() const
{
	return year;
}
int Date::getMonth() const
{
	return month;
}
int Date::getDay() const
{
	return day;
}