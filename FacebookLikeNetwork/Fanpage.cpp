#include "Fanpage.h"

Fanpage::Fanpage(const string& newName) noexcept(false)
{
	setName(newName);
}

bool Fanpage::setName(const string& newName) noexcept(false)
{
	if (!newName.compare(""))
	{
		throw emptyNameException();
	}
	name = newName;
	return true;
}
const string& Fanpage::getName()								const
{
	return name;
}
int Fanpage::getNumberOfStatus()								const
{
	return statusPtrArr.size();
}
int Fanpage::getNumberOfFans()									const
{
	return ListOfFans.size();
}

void Fanpage::showAllFans()										const
{
	list<const User*>::const_iterator itr = ListOfFans.begin();
	list<const User*>::const_iterator enditr = ListOfFans.end();
	for (int i = 0; itr != enditr; ++itr, ++i)
	{
		cout << "Fan number " << (i + 1) << " is: " << (*itr)->getName() << endl;
	}
}
void Fanpage::showFansStatuses(int numberOfPrintStatus)			const
{
	list<const User*>::const_iterator itr = ListOfFans.begin();
	list<const User*>::const_iterator enditr = ListOfFans.end();
	for (; itr != enditr; ++itr)
	{
		cout << "\n" << (*itr)->getName() << " statuses:" << endl;
		(*itr)->showStatuses(numberOfPrintStatus);
	}
}
void Fanpage::showStatuses(int numberOfPrintStatus)             const
{
	cout << name << " had posted " << statusPtrArr.size() << " statuses." << endl;
	vector<Status>::const_iterator itr = statusPtrArr.begin();
	vector<Status>::const_iterator enditr = statusPtrArr.end();
	for (int i = 0; itr != enditr && i < numberOfPrintStatus; ++i, ++itr)
	{
		cout << "status number " << i + 1 << ": ";
		(*itr).showText();
		cout << "was posted on: ";
		(*itr).showTime();
	}
}
void Fanpage::printName()										const
{
	cout << name << endl;
}

bool Fanpage::isAFan(const User& user)					    const
{
	list<const User*>::const_iterator itr = ListOfFans.begin();
	list<const User*>::const_iterator enditr = ListOfFans.end();
	for (; itr != enditr; ++itr)
	{
		if (user == **itr)
		{//compere fans by == operator (uniq names)
			return true;
		}
	}
	return false;
}
void Fanpage::addFan(User& fan)
{
	if (isAFan(fan))
	{//if user is a fan already return
		return;
	}
	ListOfFans.push_back(&fan);
	fan.likeAPage(*this); //add page to user fanpages
}
void Fanpage::removeFan(User& fan)
{
	list<const User*>::const_iterator itr = ListOfFans.begin();
	list<const User*>::const_iterator enditr = ListOfFans.end();
	if (!isAFan(fan))
	{//if user do not fan page return
		return;
	}
	for (; itr != enditr; ++enditr)
	{
		if ((*itr) == &fan)
		{
			ListOfFans.erase(itr);
			break;
		}
	}
	fan.unlikeAPage(*this); // remove page from users fanpages
}
void Fanpage::addStatus(const string& status)
{
	statusPtrArr.push_back(status);
}

const Fanpage& Fanpage::operator+=(User& addfan)
{//Multiple placement support
	addFan(addfan);
	return *this;
}
bool Fanpage::operator >(const Fanpage& other)						 const
{
	return ListOfFans.size() > other.ListOfFans.size();
}
bool Fanpage::operator <(const Fanpage& other)						 const
{
	return ListOfFans.size() < other.ListOfFans.size();
}
bool Fanpage::operator >(const User& user)						     const
{
	return ListOfFans.size() > user.getNumberOfFriends();
}
bool Fanpage::operator <(const User& user)						     const
{
	return ListOfFans.size() < user.getNumberOfFriends();
}
bool Fanpage::operator ==(const User& user)						     const
{
	return user == *this;
}
bool Fanpage::operator ==(const Fanpage& other)					     const
{
	return !name.compare(other.getName());
}
