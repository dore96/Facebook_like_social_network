#include "User.h"

#include "Fanpage.h"
//add like a fanpage for user
User::User(char* inputName, const Date& inputDateOfBirth) : dateOfBirth(inputDateOfBirth)      //constructor
{
	SetName(inputName);
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
bool User::SetName(char* inputName)
{
	name = new char[strlen(inputName) + 1];
	strcpy(name, inputName);
	return true;
}
const Date& User::GetBirthDate()							const
{
	return dateOfBirth;
}
int User::GetNumberOfStatus()								const
{
	return numberOfStatus;
}
int User::GetNumberOfFriends()								const
{
	return numberOfFriends;
}
const char* User::GetName()									const
{
	return name;
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
void User::PrintName()										const
{
	cout << name << endl;
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
bool User::isFanOf(const char* pageName)                   const
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
void User::UnFriend(const char* friendToRemove)
{
	if (!IsFriendsWith(friendToRemove))
	{
		return;
	}
	for (int i = 0; i < numberOfFriends; i++)
	{
		if (friendsPtrArr[i] != nullptr && !strcmp(friendsPtrArr[i]->name, friendToRemove))
		{
			friendsPtrArr[i] = friendsPtrArr[numberOfFriends - 1];
			numberOfFriends--;
			break;
		}
	}
	//remove from othre friend
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
void User::unlikeAPage(Fanpage& page)//dor please complete
{
	if (!isFanOf(page.getName()))
	{
		return;
	}

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