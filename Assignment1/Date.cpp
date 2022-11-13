#include "Date.h"


Date::Date(int inputDay, int inputMonth, int inputYear)
{
	while (!setDate(inputDay, inputMonth, inputYear))
	{
		cout << "Date is not legit, please enter new date" << endl;
		cout << "Please enter the user's bDay (dd/mm/yy): ";
		cin >> inputDay;
		getchar();
		cin >> inputMonth;
		getchar();
		cin >> inputYear;
		cout << endl;
	}
}
bool Date::setDate(int inputDay, int inputMonth, int inputYear)
{
	tm* yearNow;
	yearNow = localtime(nullptr);
	if (!(inputMonth < 13 && inputMonth > 0))
	{
		return false;
	}
	else if (inputDay <= 0 || inputDay > monthLen[inputMonth])
	{
		return false;
	}
	else if (inputYear < 1900 || inputYear > yearNow->tm_year + 1900)
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