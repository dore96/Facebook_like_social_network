#include "Entity.h"


Entity::Entity(const string& inputName) noexcept(false) 
{
	setName(inputName);
}
void Entity::setName(const string& inputName) noexcept(false)
{
	if (!inputName.compare(""))
	{
		throw emptyNameException();
	}
	name = inputName;
}
int Entity::getNumberOfStatus()								const
{
	return statusVect.size();
}
int Entity::getNumberOfLinkedUser()								const
{
	return UserList.size();
}
const string& Entity::getName()								const
{
	return name;
}

void Entity::showStatuses(int numberOfPrintStatus)			const
{//Entity can limit how many statuses he wants to print - otherwise it will print all statuses.
	cout << name << " had posted " << statusVect.size() << " statuses." << endl;
	vector<Status>::const_iterator itr = statusVect.begin();
	vector<Status>::const_iterator enditr = statusVect.end();
	for (int i = 0; itr != enditr && i < numberOfPrintStatus; ++i, ++itr)
	{
		cout << "status number " << i + 1 << ": ";
		(*itr).showStatus();
		cout << "was posted on: " << (*itr).getDate() << " ";
		(*itr).showTime();
	}
}
void Entity::showLinkedEntityStatus(int numberOfPrintStatus)	    const
{//user can limit how many statuses he wants to print per user - otherwise it will prints all statuses.
	list<const Entity*>::const_iterator itr = UserList.begin();
	list<const Entity*>::const_iterator enditr = UserList.end();
	for (; itr != enditr; ++itr)
	{
		cout << "\n" << (*itr)->getName() << " statuses:" << endl;
		(*itr)->showStatuses(numberOfPrintStatus);
	}
}
void Entity::showAllLinkedEntity()									const
{
	list<const Entity*>::const_iterator itr = UserList.begin();
	list<const Entity*>::const_iterator enditr = UserList.end();
	for (int i = 0; itr != enditr; ++itr, ++i)
	{
		cout << "user Number " << (i + 1) << " is: " << (*itr)->name << endl;
	}
}

void Entity::printName()										const
{
	cout << name << endl;
}

bool Entity::isLinkedTO(const Entity& isfriend, list<const Entity*> entityList)					const
{
	list<const Entity*>::const_iterator itr = entityList.begin();
	list<const Entity*>::const_iterator enditr = entityList.end();
	for (; itr != enditr; ++itr)
	{
		if (isfriend == *(*itr))
		{//compare by name
			return true;
		}
	}
	return false;
}

void Entity::addEntity(Entity& entity, list<const Entity*> entityList)
{
	if (isLinkedTO(entity, entityList))
	{//if they are friends already - return
		return;
	}
	entityList.push_back(&entity);
}
void Entity::addStatus(const string& status)
{
	statusVect.push_back(status);
}
void Entity::Unlink(Entity& entityToRemove, list<const Entity*> entityList)
{
	list<const Entity*>::const_iterator itr = entityList.begin();
	list<const Entity*>::const_iterator enditr = entityList.end();
	if (!isLinkedTO(entityToRemove, entityList))
	{
		return;
	}
	for (; itr != enditr; ++itr)
	{
		if ((*itr) == &entityToRemove)
		{
			entityList.erase(itr);
			break;
		}
	}
}
