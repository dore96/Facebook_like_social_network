#ifndef __User_H
#define __User_H

#include "Status.h"
#include "Date.h"
 

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
	bool SetDateOfBirth(int day, int month, int year);
	Date& getBirthDate();
	~User();									//Destructor
private:
	int numberOfFreinds, numberOfStatus;
	int PhisNumberOfFreinds, PhisnumberOfStatus;
	Date dateOfBirth;
	char* strTime, *name;
	Status** statusPtrArr;
	const User** friendsPtrArr;     //to linked list ?
};


#endif