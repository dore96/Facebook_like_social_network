#ifndef __Entity_H
#define __Entity_H

#include "Status.h"

class Entity
{
public:
	Entity(const string& name)								 noexcept(false); //constructor
	int getNumberOfStatus()		     						 const;
	const string& getName()									 const;
	void printName()										 const;
	void showStatuses(int numberOfPrintStatus = INT_MAX)	 const;
	void addStatus(const Status& status);
	virtual ~Entity() {};
protected:
	string name;
	vector<Status> statusVect;

	void setName(const string& name)  noexcept(false);
};

#endif
