#ifndef __Date_H
#define __Date_H
#include "exception"
#include "vector"
#include "list"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

#include <iostream>
using namespace std;
#pragma warning (disable: 4996)
#pragma warning (disable: 4267)

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

void CleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

#endif
