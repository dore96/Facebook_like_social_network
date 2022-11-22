#ifndef __User_H
#define __User_H

#include "Status.h"
#include "Date.h" 

#include "Status.h" 
class Fanpage;				//avoiding the two way include problam. (user - fanpage , fanpage - user)
const int InitNumber = 10;

class User
{
public:
	User(char* tryName, int tryYear, int tryMonth, int tryDay);
	//constructor
	void AddFriend(User* addFriend);
	void AddStatus(Status* status);
	void AddStatus(Status& status)		 const;
	void ShowAllStatus()				 const;
	void ShowAllFriend()				 const;
	void Unfriend(User& freind)			 const;

	Date& getBirthDate();

	void Unfriend(const char* friendToRemove);

	char* GetName()						const;
	int GetNumberOfStatus()		     	const;

	~User();								//Destructor
private:
	int numberOfFriends, numberOfStatus;
	int PhisNumberOfFriends, PhisnumberOfStatus;
	Date dateOfBirth;
	char *name;
	Status** statusPtrArr;
	User** friendsPtrArr;
	Fanpage** fanpagePtrArr;
	bool SetName(const char* tryName);

	void MakeDoubleFriendsSpace();
	void MakeDoubleStatusSpace();
};


#endif