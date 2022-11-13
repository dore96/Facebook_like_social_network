#include "User.h"

User::User(char* tryName, tm tryDate)         //constructor
{
	SetName(tryName);
	//set time , *strTime
	numberOfFreinds = 0;
	numberOfStatus = 0;		
	PhisNumberOfFreinds = 10;
	PhisnumberOfStatus = 10;
	statusPtrArr = new Status*[PhisnumberOfStatus];
	friendsPtrArr = new User*[PhisNumberOfFreinds];
}
void User::AddFriend(const User& addFriend)
{
	if (numberOfFreinds >= PhisNumberOfFreinds)
	{
		PhisNumberOfFreinds *= 2;
		const User** newFriendsPtrArr = new User *[PhisNumberOfFreinds];
		for (int i = 0;  i < numberOfFreinds;  i++)
		{
			newFriendsPtrArr[i] = friendsPtrArr[i];
		}
		delete []friendsPtrArr;
		friendsPtrArr = newFriendsPtrArr;
	}
	friendsPtrArr[numberOfFreinds] = &addFriend;
	numberOfFreinds++;
}
void User::AddStatus(Status& status)    const
{

}
void User::ShowAllStatus()			  const
{

}
void User::ShowAllFriend()			  const
{

}
void User::Unfriend(User& freind)	      const
{

}

bool User::SetName(const char* tryName)
{
	name = new char[strlen(tryName) + 1];
	strcpy(name, tryName);
	return true;
}

bool User::SetDateOfBirth(tm& tryDate) const
{

}

User::~User()		//Destructor
{

}