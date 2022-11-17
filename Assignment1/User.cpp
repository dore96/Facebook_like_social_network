#include "User.h"


/*
Maor:
- User* addFriend ?? or const User* addFriend?? or const User* const addFriend
- add show name func printing
*/
User::User(char* tryName, int tryYear, int tryMonth, int tryDay) :  dateOfBirth(tryDay, tryMonth, tryYear)        //constructor
{
	SetName(tryName);                         
	numberOfFriends = 0;
	numberOfStatus = 0;		
	PhisNumberOfFriends = InitNumber;
	PhisnumberOfStatus = InitNumber;
	statusPtrArr = new Status*[PhisnumberOfStatus];
	friendsPtrArr = new User*[PhisNumberOfFriends];
}
void User::AddFriend(User* addFriend)
{
	if (numberOfFriends >= PhisNumberOfFriends)
		MakeDoubleFriendsSpace();

	friendsPtrArr[numberOfFriends] = addFriend;
	numberOfFriends++;
}
void User::AddStatus(Status* status)
{
	if (numberOfStatus >= PhisnumberOfStatus)
		MakeDoubleStatusSpace();

	statusPtrArr[numberOfStatus] = status;
	numberOfStatus++;
}
void User::ShowAllStatus()			  const
{
	for (int i = 0; i < numberOfStatus; i++)
		statusPtrArr[i]->ShowText();
}
void User::ShowAllFriend()			  const
{
	for (int i = 0; i < numberOfFriends; i++)
		cout << "Friend number " << (i + 1) << " is: " << friendsPtrArr[i]->name << endl;
}
char* User::GetName()				  const
{
	return name;
}
int User::GetNumberOfStatus()		  const
{
	return numberOfStatus;
}
void User::Unfriend(const char* friendToRemove)
{
	for (int i = 0; i < numberOfFriends; i++)
	{
		if (friendsPtrArr[i] != nullptr && !strcmp(friendsPtrArr[i]->name, friendToRemove))
		{
			delete friendsPtrArr[i];
			friendsPtrArr[i] = friendsPtrArr[numberOfFriends - 1];
			numberOfFriends--;
			break;
		}
	}
}

bool User::SetName(const char* tryName)
{
	name = new char[strlen(tryName) + 1];
	strcpy(name, tryName);
	return true;
}

void User::MakeDoubleFriendsSpace()
{
	PhisNumberOfFriends *= 2;
	User** newFriendsPtrArr = new User * [PhisNumberOfFriends];
	for (int i = 0; i < numberOfFriends; i++)
	{
		newFriendsPtrArr[i] = friendsPtrArr[i];
	}
	delete[]friendsPtrArr;
	friendsPtrArr = newFriendsPtrArr;
}
void User::MakeDoubleStatusSpace()
{
	PhisnumberOfStatus *= 2;
	Status** newStatusPtrArr = new Status * [PhisnumberOfStatus];
	for (int i = 0; i < numberOfStatus; i++)
	{
		newStatusPtrArr[i] = statusPtrArr[i];
	}
	delete[]statusPtrArr;
	statusPtrArr = newStatusPtrArr;
}
Date& User::getBirthDate()
{
	return dateOfBirth;
}

User::~User()		//Destructor
{
	for (int i = 0; i < numberOfStatus; i++)
	{
		delete statusPtrArr[i];
	}
	delete []friendsPtrArr;                
	delete []statusPtrArr;
}