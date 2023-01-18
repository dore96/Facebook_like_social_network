#include "Entity.h"
//father class for common needs of user and fanpage
Entity::Entity(const string& name) noexcept(false)//ctor
{
	setName(name);
}
Entity::Entity(istream& in, const string& name) : name(name)//file ctor
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
void Entity::showStatuses(int numberOfPrintStatus)				 const//shows entity statuses
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
ostream& operator<<(ostream& os, const Entity& Entity) //prints entity
{
	os << Entity.name << endl;
	Entity.toOs(os);
	os << Entity.statusVect.size() << endl;

	vector<const Status*>::const_iterator itr = Entity.statusVect.begin();
	vector<const Status*>::const_iterator enditr = Entity.statusVect.end();
	for (; itr != enditr; ++itr)
	{
		os << *(*itr) << endl;
	}
	return os;
}
istream& operator>>(istream& in, Entity& Entity)//reads entity
{
	string name,text,url;
	Date* date;
	int numberOfStatuses, statusType;
	in >> numberOfStatuses;

	for (int i = 0 ; i < numberOfStatuses; i++)
	{
		in >> statusType;
		switch(statusType)//checks which status we read and handles accordingly
		{
		case eStatusType::text:
			date = new Date(in);
			getline(in, text);
			getline(in, text);
			Entity.statusVect.push_back(new Status(in, text,*date));
			break;
		case image:
			getline(in, url);
			getline(in, url);
			date = new Date(in);
			getline(in, text);
			getline(in, text);
			Entity.statusVect.push_back(new PictureStatus(in, url, text, *date));
			break;
		case video:
			getline(in, url);
			getline(in, url);
			date = new Date(in);
			getline(in, text);
			getline(in, text);
			Entity.statusVect.push_back(new VideoStatus(in, url ,text, *date));
			break;
		}
	}

	return in;
}