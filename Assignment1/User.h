#ifndef __User_H
#define __User_H

#include "Status.h" 
class Fanpage;					//avoiding the two way include problam. (user - fanpage , fanpage - user)
const int InitNumber = 10;

class User
{
public:
	User(const char* tryName, int tryYear, int tryMonth, int tryDay);//constructor // change to recive date!
	void AddFriend(User* addFriend);//recive by refrence
	void AddStatus(Status* status);
	void ShowAllFriends()				const;
	const Date& GetBirthDate()          const;
	void UnFriend(const char* friendToRemove);
	char* GetName()						const;
	void PrintName()                    const;
	int GetNumberOfStatus()		     	const;
	void ShowAllStatus(int numberOfPrintStatus = INT_MAX)const;
	void ShowFriendsStatus(int numberOfPrintStatus)	     const;
	bool IsFriendsWith(const char* friendName);
	int GetNumberOfFriends()			const;
	~User();								//Destructor
private:
	int numberOfFriends, numberOfStatus;
	int physicalNumberOfFriends, physicalNumberOfStatus;
	Date dateOfBirth;
	char* name;
	Status** statusPtrArr;
	User** friendsPtrArr;
	Fanpage** fanpagePtrArr;
	bool SetName(const char* tryName);
	void MakeDoubleFriendsSpace();
	void MakeDoubleStatusSpace();
	User(const User&);           //disable the possibility of user copy.
};


#endif