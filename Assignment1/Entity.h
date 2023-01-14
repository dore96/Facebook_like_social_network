#ifndef __Entity_H
#define __Entity_H

#include "Status.h"
#include "VideoStatus.h"
#include "PictureStatus.h"

class Entity
{
public:
	Entity(const string& name)								 noexcept(false); //constructor
	Entity(ifstream& in);
	int getNumberOfStatus()		     						 const;
	const string& getName()									 const;
	void printName()										 const;
	void showStatuses(int numberOfPrintStatus = INT_MAX)	 const;
	void addStatus(const Status* status);

	virtual void toOs(ostream& os)const {} ;
	virtual void fromOs(istream& in) {};
	friend ostream& operator<<(ostream& os, const Entity& Entity);
	friend istream& operator>>(istream& in, Entity& Entity);
	virtual ~Entity(){};
protected:
	string name;
	vector<const Status*> statusVect;

	void setName(const string& name)  noexcept(false);
};

#endif
