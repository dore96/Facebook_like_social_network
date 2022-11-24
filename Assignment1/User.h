#ifndef __User_H
#define __User_H

#include "Status.h" 
class Fanpage;														 //avoiding the two way include problam. (user - fanpage , fanpage - user)
const int InitNumber = 10;

class User
{
public:
	User(char* tryName, const Date &dateOfBirth);							//constructor 
	const Date& GetBirthDate()								const;
	int GetNumberOfStatus()		     						const;
	int GetNumberOfFriends()								const;
	const char* GetName()									const;

	void PrintName()										const;
	void ShowAllStatus(int numberOfPrintStatus = INT_MAX)	const;
	void ShowFriendsStatus(int numberOfPrintStatus)			const;
	void ShowAllFriends()									const;

	bool IsFriendsWith(const char* friendName)				const;

	void AddFriend(User& addFriend);								 //recive by refrence
	void AddStatus(const Status& status);
	void UnFriend(const char* friendToRemove);
	
	~User();														//Destructor
private:
	int numberOfFriends, numberOfStatus;
	int physicalNumberOfFriends, physicalNumberOfStatus;
	const Date dateOfBirth;
	char* name;
	const Status** statusPtrArr;
	const User** friendsPtrArr;
	const Fanpage** fanpagePtrArr;

	bool SetName(char* tryName);                               
	void MakeDoubleFriendsSpace();
	void MakeDoubleStatusSpace();
	User(const User&);												 //disable the possibility of user copy.
};


#endif