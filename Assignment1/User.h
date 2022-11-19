#ifndef __User_H
#define __User_H

#include "Status.h"
#include "Date.h" 

const int InitNumber = 10;

class User
{
public:
	User(char* tryName, int tryYear, int tryMonth, int tryDay);//constructor
	void AddFriend(User* addFriend);
	void AddStatus(Status* status);
	void ShowAllStatus()				const;
	void ShowAllFriends()				const;
	Date& GetBirthDate();
	void UnFriend(const char* friendToRemove);
	char* GetName()						const;
	void PrintName()                    const;
	int GetNumberOfStatus()		     	const;
	~User();								//Destructor
private:
	int numberOfFriends, numberOfStatus;
	int physicalNumberOfFriends, physicalNumberOfStatus;
	Date dateOfBirth;
	char* name;
	Status** statusPtrArr;
	User** friendsPtrArr;
	bool SetName(const char* tryName);
	void MakeDoubleFriendsSpace();
	void MakeDoubleStatusSpace();
};


#endif