#include "Fanpage.h"

Fanpage::Fanpage(const string& newName)
{
	if (!newName.compare(""))
	{
		throw invalid_argument("Cannot be an empty name");
	}
	setName(newName);
}
bool Fanpage::setName(const string& newName)
{
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
	return arrOfFans.size();
}

void Fanpage::showAllFans()										const
{
	vector<const User*>::const_iterator itr = arrOfFans.begin();
	vector<const User*>::const_iterator enditr = arrOfFans.end();
	for (int i = 0; itr != enditr; ++itr, ++i)
	{
		cout << "Fan number " << (i + 1) << " is: " << (*itr)->getName() << endl;
	}
}
void Fanpage::showFansStatuses(int numberOfPrintStatus)			const
{
	vector<const User*>::const_iterator itr = arrOfFans.begin();
	vector<const User*>::const_iterator enditr = arrOfFans.end();
	for (; itr != enditr; ++itr)
	{
		cout << "\n" << (*itr)->getName() << " statuses:" << endl;
		(*itr)->showStatuses(numberOfPrintStatus);
	}
}
void Fanpage::showStatuses(int numberOfPrintStatus)             const
{
	cout << name << " had posted " << statusPtrArr.size() << " statuses." << endl;
	vector<const Status*>::const_iterator itr = statusPtrArr.begin();
	vector<const Status*>::const_iterator enditr = statusPtrArr.end();
	for (int i = 0; itr != enditr && i < numberOfPrintStatus; ++i, ++itr)
	{
		cout << "statusText number " << i + 1 << ": ";
		(*itr)->showText();
		cout << "was posted on: ";
		(*itr)->showTime();
	}
}
void Fanpage::printName()										const
{
	cout << name << endl;
}

bool Fanpage::isAFan(const string& name)					    const
{
	vector<const User*>::const_iterator itr = arrOfFans.begin();
	vector<const User*>::const_iterator enditr = arrOfFans.end();
	for (; itr != enditr; ++itr)
	{
		if (!(name.compare((*itr)->getName())))
		{//compere fans by name (uniq)
			return true;
		}
	}
	return false;
}
void Fanpage::addFan(User& fan)
{
	if (isAFan(fan.getName()))
	{//if user is a fan already return
		return;
	}
	arrOfFans.push_back(&fan);
	fan.likeAPage(*this); //add page to user fanpages
}
void Fanpage::removeFan(User& fan)
{
	vector<const User*>::const_iterator itr = arrOfFans.begin();
	vector<const User*>::const_iterator enditr = arrOfFans.end();
	if (!isAFan(fan.getName()))
	{//if user do not fan page return
		return;
	}
	for (; itr != enditr; ++enditr)
	{
		if ((*itr) == &fan)
		{
			vector<const User*>::const_iterator tmp = --enditr;
			swap(itr, tmp);
			arrOfFans.pop_back();
			return;
		}
	}
	fan.unlikeAPage(*this); // remove page from users fanpages
}
void Fanpage::addStatus(const Status& status)
{
	statusPtrArr.push_back(&status);
}

const Fanpage& Fanpage::operator+=(User& addfan)
{//Multiple placement support
	addFan(addfan);
	return *this;
}
bool Fanpage::operator >(const Fanpage& other)						 const
{
	return arrOfFans.size() > other.arrOfFans.size();
}
bool Fanpage::operator <(const Fanpage& other)						 const//check with dor regarding ==
{
	return !(*this > other);
}

Fanpage::~Fanpage()
{
	vector<const Status*>::const_iterator itr = statusPtrArr.begin();
	vector<const Status*>::const_iterator enditr = statusPtrArr.end();
	for (; itr != enditr; ++itr)
		delete (*itr);
}