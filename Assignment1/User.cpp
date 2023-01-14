#include "User.h"
#include "Fanpage.h"

User::User(const string& inputName, const Date& inputDateOfBirth) noexcept(false) : Entity(inputName),dateOfBirth(inputDateOfBirth)
{
	time_t currentTime = time(NULL);
	const tm birthdayTime = *localtime(&currentTime);
	if ((inputDateOfBirth.getYear() < 1900 || inputDateOfBirth.getYear() > (birthdayTime.tm_year + 1900)))
	{
		throw invalidYearException();
	}
}
User::User(ifstream& in) : Entity(in)
{
	in >> *this;
}
const Date& User::getBirthDate()							const
{
	return dateOfBirth;
}
int User::getNumberOfFriends()								const
{
	return friendsList.size();
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

bool User::isFriendsWith(const User& isfriend)			const
{
	return find(friendsList.begin(), friendsList.end(), &isfriend) != friendsList.end();
}
bool User::isFanOf(const Fanpage& page)                  const
{
	return find(pageList.begin(), pageList.end(), &page) != pageList.end();
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
void User::unFriend(User& friendToRemove)
{
	list<const User*>::const_iterator itr = find(friendsList.begin(), friendsList.end(), &friendToRemove);
	if (itr == friendsList.end())
	{
		return;
	}
	friendsList.erase(itr);
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
	list<const Fanpage*>::const_iterator itr = find(pageList.begin(), pageList.end(), &page);
	if (itr == pageList.end())
	{
		return;
	}
	pageList.erase(itr);
	page.removeFan(*this); //remove user from list of fans in fanpage
}

void User::toOs(ostream& os) const
{
	os << dateOfBirth << endl;
	os << friendsList.size() << endl;
	os << pageList.size() << endl;

	list<const User*>::const_iterator itr = friendsList.begin();
	list<const User*>::const_iterator enditr = friendsList.end();
	for (; itr != enditr; ++itr)
	{
		os << (*itr)->getName().size() << endl;
		os << (*itr)->getName() << endl;
	}

	list<const Fanpage*>::const_iterator itr2 = pageList.begin();
	list<const Fanpage*>::const_iterator enditr2 = pageList.end();
	for (; itr2 != enditr2; ++itr2)
	{
		os << (*itr2)->getName().size() << endl;
		os << (*itr2)->getName() << endl;
	}
}
void User::fromOs(istream& in) : dateOfBirth(in)
{

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