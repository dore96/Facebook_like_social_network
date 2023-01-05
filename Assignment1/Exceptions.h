#ifndef __Exceptions_H
#define __Exceptions_H
#include "exception"
#include "vector"
#include "list"
#include "string"
#include <ctime>
#include <iostream>
#include <fstream>
using namespace std;
#pragma warning (disable: 4996)
#pragma warning (disable: 4267)

//general facebook exception
class generalFacebookException : public exception
{
public:
	virtual const char* what() const { return "An error has occurred"; }
};
class emptyNameException : public generalFacebookException
{
public:
	virtual const char* what() const override { return "Name can not be empty"; }
};
class notFoundException : public generalFacebookException
{
public:
	virtual const char* what() const override { return "No entity/s with the given name/s was found"; }
};
class duplicateConnactionException : public generalFacebookException
{
public:
	virtual const char* what() const override { return "Entities are already linked"; }
};

//date exceptions
class dateException : public generalFacebookException
{
public:
	virtual const char* what() const override { return "Failed while constructing a date"; }
};
class invalidMonthException : public dateException
{
public:
	virtual const char* what() const override { return "Date of month given is not possible"; }
};
class invalidDayException : public dateException
{
public:
	virtual const char* what() const override { return "Date of day given is not possible"; }
};
class invalidYearException : public dateException
{
public:
	virtual const char* what() const override { return "Year of Birth given is not possible"; }
};

//user exceptions
class userException : public generalFacebookException
{
public:
	virtual const char* what() const override { return "An error occurred related to user"; }
};
class constructUserException : public userException
{
public:
	virtual const char* what() const override { return "Failed while constructing a user"; }
};
class duplicateUserException : public userException
{
public:
	virtual const char* what() const override { return "User already exist"; }
};

//fanpage exceptions
class fanpageException : public generalFacebookException
{
public:
	virtual const char* what() const override { return "An error occurred related to fanpage"; }
};
class constructFanpageException : public fanpageException
{
public:
	virtual const char* what() const override { return "Failed while constructing a fanpage"; }
};
class duplicateFanpageException : public fanpageException
{
public:
	virtual const char* what() const override { return "Fanpage already exist"; }
};


#endif