#ifndef __Exceptions_H
#define __Exceptions_H
#include "exception"
#include "vector"
#include "list"
#include "string"
#include <ctime>
#include <iostream>
using namespace std;
#pragma warning (disable: 4996)
#pragma warning (disable: 4267)

//date exceptions
class dateException : public exception
{
public:
	const char* what() const { return "Failed while constructing a date\n"; }
};

class invalidMonthException : public dateException
{
public:
	const char* what() const { return "Date of month given is not possible\n"; }
};

class invalidDayException : public dateException
{
public:
	const char* what() const { return "Date of day given is not possible\n"; }
};

//user exceptions
class userException : public exception
{
public:
	const char* what() const { return "Failed while constructing a user\n"; }
};

class invalidYearException : public userException
{
public:
	const char* what() const { return "Year of Birth given is not possible\n"; }
};

class emptyUserNameException : public userException
{
public:
	const char* what() const { return "Name can not be empty\n"; }
};

//fanpage exceptions
class fanpageException : public exception
{
public:
	const char* what() const { return "Failed while constructing a fanpage\n"; }
};

class emptyFanpageNameException : public fanpageException
{
public:
	const char* what() const { return "Name can not be empty\n"; }
};

#endif