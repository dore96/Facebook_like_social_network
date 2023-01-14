#include "Entity.h"

Entity::Entity(const string& name) noexcept(false)
{
	setName(name);
}
Entity::Entity(ifstream& in)
{
	in >> *this;
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
ostream& operator<<(ostream& os, const Entity& Entity) 
{
	os << Entity.name.size() << endl;
	os << Entity.name << endl;
	os << Entity.statusVect.size() << endl;

	vector<const Status*>::const_iterator itr = Entity.statusVect.begin();
	vector<const Status*>::const_iterator enditr = Entity.statusVect.end();
	for (; itr != enditr; ++itr)
	{
		os << *(*itr) << endl;
	}
	Entity.toOs(os);
	return os;
}
istream& operator>>(istream& in, Entity& Entity)
{
	char* name,*text,*url;
	int Len, numberOfStatuses, statusType;

	name = getString(in);
	Entity.name = name;
	delete[]name;

	in >> numberOfStatuses;
	for (int i = 0 ; i < numberOfStatuses; i++)
	{
		in >> statusType;
		switch(statusType)
		{
		case eStatusType::text:
			Entity.statusVect.push_back(new Status(in));
			break;
		case image:
			Entity.statusVect.push_back(new PictureStatus(in));
			break;
		case video:
			Entity.statusVect.push_back(new VideoStatus(in));
			break;
		}
	}

	return in;
}