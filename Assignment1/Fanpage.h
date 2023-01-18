#ifndef __FANPAGE_H
#define __FANPAGE_H
#include "User.h"

class Fanpage : public Entity
{
public:
	Fanpage(const string& newName) noexcept(false);
	Fanpage(istream& in,const string& newName);
	int getNumberOfFans()									const;

	//show funcs
	void showAllFans()										const;
	void showFansStatuses(int numberOfPrintStatus = INT_MAX)const;
	bool isAFan(const User& user)							const;

	//action funcs
	void addFan(User& fan);
	void removeFan(User& fan);

	//operators funcs
	const Fanpage& operator+=(User& addfan);
	bool operator >(const Fanpage& other)					const;
	bool operator >(const User& user)					    const;
	bool operator <(const Fanpage& other)					const;
	bool operator <(const User& user)					    const;
	bool operator ==(const User& user)					    const;
	bool operator ==(const Fanpage& other)					const;
private:
	list<const User*> ListOfFans;
};


#endif
