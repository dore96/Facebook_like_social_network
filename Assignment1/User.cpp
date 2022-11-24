#include "User.h"

User::User(char* inputName, const Date& inputDateOfBirth) : dateOfBirth(inputDateOfBirth)      //constructor
{
	SetName(inputName);
	numberOfFriends = 0;
	numberOfStatus = 0;
	physicalNumberOfFriends = InitNumber;
	physicalNumberOfStatus = InitNumber;
	statusPtrArr = new const Status * [physicalNumberOfStatus];
	friendsPtrArr = new const User * [physicalNumberOfFriends];
}
void User::AddFriend(User& addFriend)
{
	if (IsFriendsWith(addFriend.GetName()))
	{
		return;
	}

	if (numberOfFriends >= physicalNumberOfFriends)
		MakeDoubleFriendsSpace();

	friendsPtrArr[numberOfFriends] = &addFriend;
	numberOfFriends++;
	addFriend.AddFriend(*this);
}
void User::AddStatus(const Status& status)
{
	if (numberOfStatus >= physicalNumberOfStatus)
		MakeDoubleStatusSpace();

	statusPtrArr[numberOfStatus] = &status;
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
void User::ShowAllFriends()									const
{
	for (int i = 0; i < numberOfFriends; i++)
		cout << "Friend number " << (i + 1) << " is: " << friendsPtrArr[i]->name << endl;
}
const char* User::GetName()									const
{
	return name;
}
void User::PrintName()										const
{
	cout << name << endl;
}
int User::GetNumberOfStatus()								const
{
	return numberOfStatus;
}
int User::GetNumberOfFriends()								const
{
	return numberOfFriends;
}
bool User::IsFriendsWith(const char* friendName)			const
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
bool User::SetName(char* inputName)
{
	name = new char[strlen(inputName) + 1];
	strcpy(name, inputName);
	return true;
}
void User::MakeDoubleFriendsSpace()//make generic double space function in utilities.
{
	physicalNumberOfFriends *= 2;
	const User** newFriendsPtrArr = new const User * [physicalNumberOfFriends];
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
	const Status** newStatusPtrArr = new const Status * [physicalNumberOfStatus];
	for (int i = 0; i < numberOfStatus; i++)
	{
		newStatusPtrArr[i] = statusPtrArr[i];
	}
	delete[]statusPtrArr;
	statusPtrArr = newStatusPtrArr;
}
const Date& User::GetBirthDate()							 const
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