#ifndef __User_H
#define __User_H

#include "Status.h"
#include <ctime> 

const int initNumberOfFriendsStatus = 10;

class User
{
public:
	User(char* tryName, tm tryDate);         //constructor
	void AddFriend(const User& addFriend);
	void AddStatus(const Status& status);
	void ShowAllStatus()						const;
	void ShowAllFriend()					    const;
	void Unfriend(const User& friendToRemove);
	~User();								//Destructor
private:
	int numberOfFriends, numberOfStatus;
	int PhisNumberOfFreinds, PhisnumberOfStatus;
	time_t time, dateOfBirth;
	char* strTime, *name;
	const Status** statusPtrArr;
	const User** friendsPtrArr;     //to linked list ?

	bool SetName(const char* tryName);
	bool SetDateOfBirth(const tm& tryDate);

	void MakeDoubleFriendsSpace();
	void MakeDoubleStatusSpace();
};


#endif