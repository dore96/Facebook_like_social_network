#include "Fanpage.h"

Fanpage::Fanpage(const string& newName) noexcept(false) : Entity(newName)
{
}
void Fanpage::addFan(User& user) noexcept(false)
{
	addEntity(user, UserList);
	user.addEntity(*this);
}
void Fanpage::removeFan(User& fan)
{
	Unlink(fan, UserList);
	fan.Unlink(fan); // remove page from users fanpages
}
const Fanpage& Fanpage::operator+=(User& addfan)
{//Multiple placement support
	addFan(addfan);
	return *this;
}
bool Fanpage::operator >(const Entity& other)						 const
{
	const User* user = dynamic_cast<const User*>(&other);
	if (user)
	{//if is user
		return UserList.size() > user->getNumberOfLinkedUser();
	}
	const Fanpage* fanpage = dynamic_cast<const Fanpage*>(&other);
	if (fanpage)
	{//if is fanpage
		return UserList.size() > fanpage->getNumberOfLinkedUser();
	}
}
bool Fanpage::operator <(const Entity& other)						 const
{
	const User* user = dynamic_cast<const User*>(&other);
	if (user)
	{//if is user
		return UserList.size() < user->getNumberOfLinkedUser();
	}
	const Fanpage* fanpage = dynamic_cast<const Fanpage*>(&other);
	if (fanpage)
	{//if is fanpage
		return UserList.size() < other.getNumberOfLinkedUser();
	}
}
bool Fanpage::operator ==(const Entity& entity)						     const
{
	const Fanpage* fanpage = dynamic_cast<const Fanpage*>(&entity);
	if (!fanpage)
	{
		return false;
	}
	return name == entity.getName();
}