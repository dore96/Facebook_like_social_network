#ifndef __User_H
#define __User_H

#include "Entity.h"
class Fanpage;									  //avoiding the two way include problam. (user - fanpage , fanpage - user)

class User : public Entity
{
public:
	User(const string& inputName, const Date& inputDateOfBirth); //constructor
	//getters
	const Date& getBirthDate()					  const;
	int getNumberOfFanpages()					  const;

	void addEntity(Entity& entity);
	void Unlink(Entity& entityToRemove);

	//Operators funcs
	virtual const Entity& operator+=(Entity& addEntity);
	virtual bool operator >(const Entity& other)  const;
	virtual bool operator ==(const Entity& other) const;
	virtual bool operator <(const Entity& page)	  const;
private:
	const Date dateOfBirth;
	list<const Entity*> pageList;
};


#endif