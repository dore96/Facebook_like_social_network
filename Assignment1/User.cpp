#include "User.h"
/*
Maor:
- User* addFriend ?? or const User* addFriend?? or const User* const addFriend
*/
User::User(const char* tryName, int inputYear, int inputMonth, int inputDay) : dateOfBirth(inputDay, inputMonth, inputYear)//constructor
{
	SetName(tryName);
	numberOfFriends = 0;
	numberOfStatus = 0;
	physicalNumberOfFriends = InitNumber;
	physicalNumberOfStatus = InitNumber;
	statusPtrArr = new Status * [physicalNumberOfStatus];
	friendsPtrArr = new User * [physicalNumberOfFriends];
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
void User::ShowAllStatus(int numberOfPrintStatus)			const //user can limit how many statuses he wants to print
{
	int i;
	for (i = 0; i < numberOfStatus && i < numberOfPrintStatus; i++)
	{
		statusPtrArr[i]->ShowText();
	}
	if (i < numberOfPrintStatus)
	{
		cout << name << "had only " << i << " statuses posted." << endl;
	}
}
void User::ShowFriendsStatus(int numberOfPrintStatus)	    const
{
	for (int i = 0; i < numberOfFriends; i++)
	{
		friendsPtrArr[i]->ShowAllStatus(numberOfPrintStatus);
	}
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
int User::GetNumberOfFriends()		  const
{
	return numberOfFriends;
}
bool User::IsFriendsWith(const char* friendName)
{
	for (int i = 0; i < numberOfFriends; i++)
	{
		if (!strcmp(friendsPtrArr[i]->GetName(), friendName))
		{
			return true;
		}
	}
	return false;
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
const Date& User::GetBirthDate()      const
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
	delete[]friendsPtrArr;
	delete[]statusPtrArr;
}