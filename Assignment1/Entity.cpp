#include "Entity.h"

Entity::Entity(const string& name) noexcept(false)
{
	setName(name);
}
int Entity::getNumberOfStatus()		     						 const
{
	return statusVect.size();
}
const string& Entity::getName()									 const
{
	return name;
}
void Entity::printName()										 const
{
	cout << name << endl;
}
void Entity::showStatuses(int numberOfPrintStatus)				 const
{
	cout << name << " had posted " << statusVect.size() << " statuses." << endl;
	vector<const Status*>::const_iterator itr = statusVect.begin();
	vector<const Status*>::const_iterator enditr = statusVect.end();
	for (int i = 0; itr != enditr && i < numberOfPrintStatus; ++i, ++itr)
	{
		cout << "status number " << i + 1 << ": ";
		(*itr)->showStatus();
		cout << "was posted on: ";
		(*itr)->showTime();
	}
}
void Entity::addStatus(const Status* status)		  //statusText is not able to change after creation - therefor const &
{
	statusVect.push_back(status);
}
void Entity::setName(const string& name)  noexcept(false)
{
	if (!name.compare(""))
	{
		throw emptyNameException();
	}
	this->name = name;
}