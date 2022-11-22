#ifndef __User_H
#define __User_H

#include "Status.h" 
class Fanpage;					//avoiding the two way include problam. (user - fanpage , fanpage - user)
const int InitNumber = 10;

class User
{
public:
	User(const char* tryName, int tryYear, int tryMonth, int tryDay);//constructor
	void AddFriend(User* addFriend);
	void AddStatus(Status* status);
	void ShowAllStatus()				const;
	void ShowAllFriends()				const;
	Date& GetBirthDate();
	void UnFriend(const char* friendToRemove);
	char* GetName()						const;
	void PrintName()                    const;
	int GetNumberOfStatus()		     	const;
	void ShowAllStatus(int numberOfPrintStatus)			const;   //overload - showing wanted number of status or all status.
	void ShowFriendsStatus(int numberOfPrintStatus)	    const;
	int GetNumberOfFriends()							const;
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