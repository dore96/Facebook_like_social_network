#include "User.h"
#include "Fanpage.h"

User::User(char* inputName, const Date& inputDateOfBirth) : dateOfBirth(inputDateOfBirth)      //constructor
{
	setName(inputName);
	numberOfFriends = 0;
	numberOfStatus = 0;
	numberOfLikedPages = 0;
	physicalNumberOfLikedPages = InitNumber;
	physicalNumberOfFriends = InitNumber;
	physicalNumberOfStatus = InitNumber;
	statusPtrArr = new const Status * [physicalNumberOfStatus];
	friendsPtrArr = new const User * [physicalNumberOfFriends];
	fanpagePtrArr = new const Fanpage * [physicalNumberOfLikedPages];
}
bool User::setName(char* inputName)
{
	name = new char[strlen(inputName) + 1];
	strcpy(name, inputName);
	return true;
}
const Date& User::getBirthDate()							const
{
	return dateOfBirth;
}
int User::getNumberOfStatus()								const
{
	return numberOfStatus;
}
int User::getNumberOfFriends()								const
{
	return numberOfFriends;
}
const char* User::getName()									const
{
	return name;
}

void User::showStatuses(int numberOfPrintStatus)			const //user can limit how many statuses he wants to print
{
	int i;
	for (i = 0; i < numberOfStatus && i < numberOfPrintStatus; i++)
	{
		cout << "status number " << i + 1 << ": ";
		statusPtrArr[i]->showText();
		cout << "was posted on: ";
		statusPtrArr[i]->showTime();
	}
	if (i < numberOfPrintStatus)
	{
		cout << name << " had posted " << i << " statuses." << endl;
	}
}
void User::showFriendsStatus(int numberOfPrintStatus)	    const
{
	for (int i = 0; i < numberOfFriends; i++)
	{
		friendsPtrArr[i]->showStatuses(numberOfPrintStatus);
	}
}
void User::showAllFriends()									const
{
	for (int i = 0; i < numberOfFriends; i++)
		cout << "Friend number " << (i + 1) << " is: " << friendsPtrArr[i]->name << endl;
}
void User::printName()										const
{
	cout << name << endl;
}

bool User::isFriendsWith(const char* friendName)			const
{
	for (int i = 0; i < numberOfFriends; i++)
	{
		if (!strcmp(friendsPtrArr[i]->getName(), friendName))
		{
			return true;
		}
	}
	return false;
}
bool User::isFanOf(const char* pageName)                    const
{
	for (int i = 0; i < numberOfLikedPages; i++)
	{
		if (!strcmp(fanpagePtrArr[i]->getName(), pageName))
		{
			return true;
		}
	}
	return  false;
}

void User::addFriend(User& addFriend)
{
	if (isFriendsWith(addFriend.getName()))
	{
		return;
	}

	if (numberOfFriends >= physicalNumberOfFriends)
		makeDoubleFriendsSpace();

	friendsPtrArr[numberOfFriends] = &addFriend;
	numberOfFriends++;
	addFriend.addFriend(*this);
}
void User::addStatus(const Status& status)
{
	if (numberOfStatus >= physicalNumberOfStatus)
		makeDoubleStatusSpace();

	statusPtrArr[numberOfStatus] = &status;
	numberOfStatus++;
}
void User::unFriend(User& friendToRemove)
{
	if (!isFriendsWith(friendToRemove.getName()))
	{
		return;
	}
	for (int i = 0; i < numberOfFriends; i++)
	{
		if (friendsPtrArr[i] == &friendToRemove)
		{
			friendsPtrArr[i] = friendsPtrArr[numberOfFriends - 1];
			numberOfFriends--;
		}
	}
	friendToRemove.unFriend(*this);
}
void User::likeAPage(Fanpage& page)
{
	if (isFanOf(page.getName()))
	{
		return;
	}
	if (numberOfLikedPages >= physicalNumberOfLikedPages)
		makeDoublePageSpace();
	fanpagePtrArr[numberOfLikedPages] = &page;
	numberOfLikedPages++;
	page.addFan(*this);
}
void User::unlikeAPage(Fanpage& page)
{
	if (!isFanOf(page.getName()))
	{
		return;
	}
	for (int i = 0; i < numberOfLikedPages; i++)
	{
		if (fanpagePtrArr[i] == &page)
		{
			fanpagePtrArr[i] = fanpagePtrArr[numberOfLikedPages - 1];
			numberOfLikedPages--;
		}
	}
	page.removeFan(*this);
}

void User::makeDoubleFriendsSpace()
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
void User::makeDoubleStatusSpace()
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
void User::makeDoublePageSpace()
{
	physicalNumberOfLikedPages *= 2;
	const Fanpage** newFanpagePtrArr = new const Fanpage * [physicalNumberOfLikedPages];
	for (int i = 0; i < numberOfLikedPages; i++)
	{
		newFanpagePtrArr[i] = fanpagePtrArr[i];
	}
	delete[] fanpagePtrArr;
	fanpagePtrArr = newFanpagePtrArr;
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