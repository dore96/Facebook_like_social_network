#include "User.h"
#include "Fanpage.h"

User::User(const string& inputName, const Date& inputDateOfBirth) noexcept(false) : dateOfBirth(inputDateOfBirth)//constructor
{
	time_t currentTime = time(NULL);
	const tm birthdayTime = *localtime(&currentTime);
	if ((inputDateOfBirth.getYear() < 1900 || inputDateOfBirth.getYear() > (birthdayTime.tm_year + 1900)))
	{
		throw invalidYearException();
	}
	setName(inputName);
}

void User::setName(const string& inputName) noexcept(false)
{
	if (!inputName.compare(""))
	{
		throw emptyNameException();
	}
	name = inputName;
}
const Date& User::getBirthDate()							const
{
	return dateOfBirth;
}
int User::getNumberOfStatus()								const
{
	return statusVect.size();
}
int User::getNumberOfFriends()								const
{
	return friendsList.size();
}
const string& User::getName()								const
{
	return name;
}

void User::showStatuses(int numberOfPrintStatus)			const 
{//user can limit how many statuses he wants to print - otherwise it will print all statuses.
	cout << name << " had posted " << statusVect.size() << " statuses." << endl;
	vector<Status>::const_iterator itr = statusVect.begin();
	vector<Status>::const_iterator enditr = statusVect.end();
	for (int i = 0; itr != enditr && i < numberOfPrintStatus; ++i, ++itr)
	{
		cout << "status number " << i + 1 << ": ";
		(*itr).showText();
		cout << "was posted on: " << (*itr).getDate() << " ";
		(*itr).showTime();
	}
}
void User::showFriendsStatus(int numberOfPrintStatus)	    const
{//user can limit how many statuses he wants to print per user - otherwise it will prints all statuses.
	list<const User*>::const_iterator itr = friendsList.begin();
	list<const User*>::const_iterator enditr = friendsList.end();
	for (; itr != enditr; ++itr)
	{
		cout << "\n" << (*itr)->getName() << " statuses:" << endl;
		(*itr)->showStatuses(numberOfPrintStatus);
	}
}
void User::showPagesStatus(int numberOfPrintStatus)			const
{//user can limit how many statuses he wants to print per page - otherwise it will prints all statuses.
	list<const Fanpage*>::const_iterator itr = pageList.begin();
	list<const Fanpage*>::const_iterator enditr = pageList.end();
	for (; itr != enditr; ++itr)
	{
		cout << "\n" << (*itr)->getName() << " statuses:" << endl;
		(*itr)->showStatuses(numberOfPrintStatus);
	}
}
void User::showAllFriends()									const
{
	list<const User*>::const_iterator itr = friendsList.begin();
	list<const User*>::const_iterator enditr = friendsList.end();
	for (int i = 0; itr != enditr; ++itr, ++i)
	{
		cout << "Friend number " << (i + 1) << " is: " << (*itr)->name << endl;
	}
}
void User::showAllLikedPages()								const
{
	list<const Fanpage*>::const_iterator itr = pageList.begin();
	list<const Fanpage*>::const_iterator enditr = pageList.end();
	for (int i = 0; itr != enditr; ++itr, ++i)
	{
		cout << "Page number " << (i + 1) << " is: " << (*itr)->getName() << endl;
	}
}
void User::printName()										const
{
	cout << name << endl;
}

bool User::isFriendsWith(const User& isfriend)			const
{
	list<const User*>::const_iterator itr = friendsList.begin();
	list<const User*>::const_iterator enditr = friendsList.end();
	for (; itr != enditr; ++itr)
	{
		if (isfriend == *(*itr))
		{//compare by name of users (uniq)
			return true;
		}
	}
	return false;
}
bool User::isFanOf(const Fanpage& page)                  const
{
	list<const Fanpage*>::const_iterator itr = pageList.begin();
	list<const Fanpage*>::const_iterator enditr = pageList.end();
	for (; itr != enditr; ++itr)
	{
		if (page == **itr)
		{//compare by name of users (uniq)
			return true;
		}
	}
	return  false;
}

void User::addFriend(User& addFriend)
{
	if (isFriendsWith(addFriend))
	{//if they are friends already - return
		return;
	}
	friendsList.push_back(&addFriend);
	addFriend.addFriend(*this);  //add myself to friend list.
}
void User::addStatus(const string& status)
{
	statusVect.push_back(status);
}
void User::unFriend(User& friendToRemove)
{
	list<const User*>::const_iterator itr = friendsList.begin();
	list<const User*>::const_iterator enditr = friendsList.end();
	if (!isFriendsWith(friendToRemove))
	{
		return;
	}
	for (; itr != enditr; ++itr)
	{
		if((*itr) == &friendToRemove)
		{
			friendsList.erase(itr);
			break;
		}
	}
	friendToRemove.unFriend(*this);
}
void User::likeAPage(Fanpage& page)
{
	if (isFanOf(page))
	{//if user is a fan of the page , return.
		return;
	}
	pageList.push_back(& page);
	page.addFan(*this);  //add user to fans of fanpage.
}
void User::unlikeAPage(Fanpage& page)
{
	list<const Fanpage*>::const_iterator itr = pageList.begin();
	list<const Fanpage*>::const_iterator enditr = pageList.end();
	if (!isFanOf(page))
	{
		return;
	}
	for (; itr != enditr; ++itr)
	{
		if ((*itr) == &page)
		{
			pageList.erase(itr);
			break;
		}
	}
	page.removeFan(*this); //remove user from list of fans in fanpage
}

const User& User::operator+=(User& addfriend)  
{//Multiple placement support
	addFriend(addfriend);
	return *this;
}
bool User::operator >(const User& other)					const
{
	return friendsList.size() > other.friendsList.size();
}
bool User::operator <(const User& other)					const
{
	return friendsList.size() < other.friendsList.size();
}
bool User::operator >(const Fanpage& page)					const
{
	return friendsList.size() > page.getNumberOfFans();
}
bool User::operator <(const Fanpage& page)					const
{
	return friendsList.size() < page.getNumberOfFans();
}
bool User::operator == (const Fanpage& page)				const
{
	return friendsList.size() == page.getNumberOfFans();
}
bool User::operator ==(const User& other)					const
{
	return !name.compare(other.getName());
}
