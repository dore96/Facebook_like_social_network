#ifndef __Entity_H
#define __Entity_H

#include "Status.h"
class Fanpage;
class Entity
{
public:
	Entity(const string& tryName); 

	//getters
	int getNumberOfStatus()		     						 const;
	int getNumberOfLinkedUser()								 const;
	const string& getName()									 const;

	//printing funcs
	void printName()										 const;
	void showStatuses(int numberOfPrintStatus = INT_MAX)	 const;
	void showLinkedEntityStatus(list<const Entity*> entityList,int numberOfPrintStatus = INT_MAX) const;
	void showAllLinkedEntity(list<const Entity*> entityList) const;

	//boolean funcs
	bool isLinkedTO(const Entity& isfriend, list<const Entity*> entityList)	const;

	//action funcs 
	void addEntity(Entity& entity, list<const Entity*> entityList);
	void addStatus(const string& status);
	void Unlink(Entity& entityToRemove, list<const Entity*> entityList);

	//Operators funcs
	virtual const Entity& operator+=(Entity& addEntity) = 0;
	virtual bool operator >(const Entity& other)  const = 0;
	virtual bool operator ==(const Entity& other) const = 0;
	virtual bool operator <(const Entity& page)	  const = 0;
protected:
	string name;
	vector<Status> statusVect;
	list<const Entity*> UserList;
	void setName(const string& tryName)  noexcept(false);
};

#endif

