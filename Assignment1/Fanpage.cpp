#include "Fanpage.h"

Fanpage::Fanpage(const string& newName): Entity(newName)
{
}
Fanpage::Fanpage(istream& in, const string& newName) : Entity(in, newName)
{
}
int Fanpage::getNumberOfFans()									const
{
	return ListOfFans.size();
}

void Fanpage::showAllFans()										const
{//shows all fans
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

bool Fanpage::isAFan(const User& user)					    const
{//checks if a user is a fan of the page
	return find(ListOfFans.begin(), ListOfFans.end(), &user) != ListOfFans.end();
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
	list<const User*>::const_iterator itr = find(ListOfFans.begin(), ListOfFans.end(), &fan);
	if (itr == ListOfFans.end())
	{//if user do not fan page return
		return;
	}
	ListOfFans.erase(itr);
	fan.unlikeAPage(*this); // remove page from users fanpages
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