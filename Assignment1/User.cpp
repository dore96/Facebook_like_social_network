#include "User.h"

User::User(char* tryName, tm tryDate)         //constructor
{
	SetName(tryName);
	//set time , *strTime
	numberOfFriends = 0;
	numberOfStatus = 0;		
	PhisNumberOfFreinds = initNumberOfFriendsStatus;
	PhisnumberOfStatus = initNumberOfFriendsStatus;
	statusPtrArr = new const Status*[PhisnumberOfStatus];
	friendsPtrArr = new const User*[PhisNumberOfFreinds];
}
void User::AddFriend(const User& addFriend)
{
	if (numberOfFriends >= PhisNumberOfFreinds)
		MakeDoubleFriendsSpace();

	friendsPtrArr[numberOfFriends] = &addFriend;
	numberOfFriends++;
}
void User::AddStatus(const Status& status)
{
	if (numberOfStatus >= PhisnumberOfStatus)
		MakeDoubleStatusSpace();

	statusPtrArr[numberOfStatus] = &status;
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
void User::Unfriend(const User& friendToRemove)
{
	for (int i = 0; i < numberOfFriends; i++)
	{
		if (friendsPtrArr[i] != nullptr && !strcmp(friendsPtrArr[i]->name, friendToRemove.name))
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

bool User::SetDateOfBirth(int day, int month,int year)
{
	dateOfBirth.setDate(day, month, year);
}
bool User::SetDateOfBirth(const tm& tryDate)
{
	return true;              //implementation needed.
}

void User::MakeDoubleFriendsSpace()
{
	PhisNumberOfFreinds *= 2;
	const User** newFriendsPtrArr = new const User * [PhisNumberOfFreinds];
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
	const Status** newStatusPtrArr = new const Status * [PhisnumberOfStatus];
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
	delete []friendsPtrArr;                   //dont delete friends address ?
	delete []statusPtrArr;
}