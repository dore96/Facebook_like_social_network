#include "User.h"
/*
Maor:
- User* addFriend ?? or const User* addFriend?? or const User* const addFriend
*/
User::User(char* tryName, int inputYear, int inputMonth, int inputDay) :  dateOfBirth(inputDay, inputMonth, inputYear)//constructor
{
	SetName(tryName);                         
	numberOfFriends = 0;
	numberOfStatus = 0;		
	physicalNumberOfFriends = InitNumber;
	physicalNumberOfStatus = InitNumber;
	statusPtrArr = new Status*[physicalNumberOfStatus];
	friendsPtrArr = new User*[physicalNumberOfFriends];
}
void User::AddFriend(User* addFriend)
{
	if (numberOfFriends >= physicalNumberOfFriends)
		MakeDoubleFriendsSpace();

	friendsPtrArr[numberOfFriends] = addFriend;
	numberOfFriends++;
}
void User::AddStatus(Status* status)
{
	if (numberOfStatus >= physicalNumberOfStatus)
		MakeDoubleStatusSpace();

	statusPtrArr[numberOfStatus] = status;
	numberOfStatus++;
}
void User::ShowAllStatus()			  const
{
	for (int i = 0; i < numberOfStatus; i++)
		statusPtrArr[i]->ShowText();
}
void User::ShowAllFriends()			  const
{
	for (int i = 0; i < numberOfFriends; i++)
		cout << "Friend number " << (i + 1) << " is: " << friendsPtrArr[i]->name << endl;
}
char* User::GetName()				  const
{
	return name;
}
void User::PrintName()                const
{
	cout << name << endl;
}
int User::GetNumberOfStatus()		  const
{
	return numberOfStatus;
}
void User::UnFriend(const char* friendToRemove)
{
	for (int i = 0; i < numberOfFriends; i++)
	{
		if (friendsPtrArr[i] != nullptr && !strcmp(friendsPtrArr[i]->name, friendToRemove))
		{
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
void User::MakeDoubleFriendsSpace()//make generic double space function in utilities.
{
	physicalNumberOfFriends *= 2;
	User** newFriendsPtrArr = new User * [physicalNumberOfFriends];
	for (int i = 0; i < numberOfFriends; i++)
	{
		newFriendsPtrArr[i] = friendsPtrArr[i];
	}
	delete[]friendsPtrArr;
	friendsPtrArr = newFriendsPtrArr;
}
void User::MakeDoubleStatusSpace()
{
	physicalNumberOfStatus *= 2;
	Status** newStatusPtrArr = new Status * [physicalNumberOfStatus];
	for (int i = 0; i < numberOfStatus; i++)
	{
		newStatusPtrArr[i] = statusPtrArr[i];
	}
	delete[]statusPtrArr;
	statusPtrArr = newStatusPtrArr;
}
Date& User::GetBirthDate()
{
	return dateOfBirth;
}
User::~User()		//Destructor
{
	delete[]name;
	for (int i = 0; i < numberOfStatus; i++)
	{
		delete statusPtrArr[i];
	}
	delete []friendsPtrArr;                
	delete []statusPtrArr;
}