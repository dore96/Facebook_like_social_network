#ifndef __FANPAGE_H
#define __FANPAGE_H
#include "User.h"

class Fanpage :public Entity
{
public:
	Fanpage(const string& newName) noexcept(false);

	//action funcs
	void addFan(User& user);
	void removeFan(User& fan);

	//operators funcs
	const Fanpage& operator+=(User& addfan);
	bool operator >(const Entity& other)					const;
	bool operator <(const Entity& other)					const;
	bool operator ==(const Entity& other)					const;
};


#endif
