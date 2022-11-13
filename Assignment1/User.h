#ifndef __User_H
#define __User_H

#include "Status.h"
#include "Date.h"
#include <ctime> 

class User
{
public:
	User(char* tryName, tm tryDate);         //constructor
	void AddFriend(const User& addFriend);
	void AddStatus(Status& status)		 const;
	void ShowAllStatus()				 const;
	void ShowAllFriend()				 const;
	void Unfriend(User& freind)			 const;

	bool SetName(const char* tryName);
	bool SetDateOfBirth(tm& tryDate) const;


	~User();									//Destructor
private:
	int numberOfFreinds, numberOfStatus;
	int PhisNumberOfFreinds, PhisnumberOfStatus;
	time_t time, dateOfBirth;
	char* strTime, *name;
	Status** statusPtrArr;
	const User** friendsPtrArr;     //to linked list ?
};


#endif