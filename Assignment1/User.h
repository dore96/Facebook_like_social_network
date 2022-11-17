#ifndef __User_H
#define __User_H

#include "Status.h"
#include "Date.h"
 
#include <ctime> 

const int InitNumber = 10;

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
	void AddStatus(const Status& status);
	void ShowAllStatus()						const;
	void ShowAllFriend()					    const;
	char* GetName()								const;
	int GetNumberOfStatus()		     			const;
	void Unfriend(const User& friendToRemove);
	~User();								//Destructor
private:
	int numberOfFriends, numberOfStatus;
	int PhisNumberOfFreinds, PhisnumberOfStatus;
	Date dateOfBirth;
	char* strTime, *name;
	const Status** statusPtrArr;
	const User** friendsPtrArr;     //to linked list ?

	bool SetName(const char* tryName);
	bool SetDateOfBirth(const tm& tryDate);

	void MakeDoubleFriendsSpace();
	void MakeDoubleStatusSpace();
};


#endif