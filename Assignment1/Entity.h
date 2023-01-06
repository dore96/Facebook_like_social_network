#ifndef __Entity_H
#define __Entity_H

#include "Status.h" 
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
	//void showPagesStatus(int numberOfPrintStatus = INT_MAX)	 const;
	void showAllLinkedEntity(list<const Entity*> entityList) const;
	//void showAllLikedPages()								 const;

	//boolean funcs
	bool isLinkedTO(const Entity& isfriend, list<const Entity*> entityList)	const;
	//bool isFanOf(const Fanpage& page)                     const;

	//action funcs 
	void addEntity(Entity& entity, list<const Entity*> entityList);
	void addStatus(const string& status);		  //statusText is not able to change after creation - therefor const &
	void Unlink(Entity& entityToRemove, list<const Entity*> entityList);
	//void likeAPage(Fanpage& page);
	//void unlikeAPage(Fanpage& page);

	//Operators funcs
	virtual const Entity& operator+=(Entity& addEntity) = 0;
	virtual bool operator >(const Entity& other)  const = 0;
	//bool operator >(const Fanpage& page)					 const;
	virtual bool operator ==(const Entity& other) const = 0;
	//bool operator <(const User& other)						 const;
	virtual bool operator <(const Entity& page)	  const = 0;
	//bool operator ==(const Fanpage& page)					 const;
protected:
	//const Date dateOfBirth;
	string name;
	vector<Status> statusVect;
	list<const Entity*> UserList;
	//list<const Fanpage*> pageList;

	void setName(const string& tryName)  noexcept(false);
};

#endif

