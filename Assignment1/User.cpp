#include "User.h"
#include "Fanpage.h"

User::User(const string& inputName, const Date& inputDateOfBirth) noexcept(false) : Entity(inputName), dateOfBirth(inputDateOfBirth)//constructor
{
	time_t currentTime = time(NULL);
	const tm birthdayTime = *localtime(&currentTime);
	if ((inputDateOfBirth.getYear() < 1900 || inputDateOfBirth.getYear() > (birthdayTime.tm_year + 1900)))
	{
		throw invalidYearException();
	}
}
const Date& User::getBirthDate()							const
{
	return dateOfBirth;
}
int User::getNumberOfFanpages()								const
{
	return pageList.size();
}

void User::addEntity(Entity& entity)
{
	User* temp = dynamic_cast<User*>(&entity);
	if (temp != NULL)
	{//if is user
		Entity::addEntity(entity, pageList);
		temp->addEntity(*this);
	}

	Fanpage* temp2 = dynamic_cast<Fanpage*>(&entity);
	if (temp2 != NULL)
	{//if is fanpage
		Entity::addEntity(entity, UserList);
		temp2->addEntity(*this);
	}
}
void User::Unlink(Entity& entityToRemove)
{
	User* temp = dynamic_cast<User*>(&entityToRemove);
	if (temp != NULL)
	{//if is user
		Entity::Unlink(entityToRemove, UserList);
		temp->Unlink(*this);
	}

	Fanpage* temp2 = dynamic_cast<Fanpage*>(&entityToRemove);
	if (temp2 != NULL)
	{//if is user
		Entity::Unlink(entityToRemove, pageList);
		temp2->Unlink(*this);
	}

}

const Entity& User::operator+=(Entity& EntityToAdd)
{//Multiple placement support
	addEntity(EntityToAdd);
	return *this;
}
bool User::operator >(const Entity& other)					const
{
	const User* temp = dynamic_cast<const User*>(&other);
	if (temp != NULL)
	{//if is user
		return UserList.size() > temp->UserList.size();
	}
	const Fanpage* temp2 = dynamic_cast<const Fanpage*>(&other);
	if (temp2 != NULL)
	{//if is user
		return UserList.size() > temp2->getNumberOfFans();
	}
	else
	{
		//handle error
	}
}
bool User::operator <(const Entity& other)					const
{
	const User* temp = dynamic_cast<const User*>(&other);
	if (temp != NULL)
	{//if is user
		return UserList.size() < temp->UserList.size();
	}
	const Fanpage* temp2 = dynamic_cast<const Fanpage*>(&other);
	if (temp2 != NULL)
	{//if is user
		return UserList.size() < temp2->getNumberOfFans();
	}
	else
	{
		//handle error
	}
}
bool User::operator == (const Entity& other)				const
{
	const User* temp = dynamic_cast<const User*>(&other);
	if (temp != NULL)
	{//if is user
		return UserList.size() == temp->UserList.size();
	}
	const Fanpage* temp2 = dynamic_cast<const Fanpage*>(&other);
	if (temp2 != NULL)
	{//if is user
		return UserList.size() == temp2->getNumberOfFans();
	}
	else
	{
		//handle error
	}
}