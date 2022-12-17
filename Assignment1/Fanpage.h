#ifndef __FANPAGE_H
#define __FANPAGE_H
#include "User.h"

class Fanpage
{
public:
	Fanpage(const string& newName) noexcept(false);
	const string& getName()									const;
	int getNumberOfStatus()		     						const;
	int getNumberOfFans()									const;

	//show funcs
	void printName()										const;
	void showAllFans()										const;
	void showFansStatuses(int numberOfPrintStatus = INT_MAX)const;
	void showStatuses(int numberOfPrintStatus = INT_MAX)    const;
	bool isAFan(const string& name)							const;

	//action funcs
	void addFan(User& fan);
	void removeFan(User& fan);
	void addStatus(const Status& status);

	//operators funcs
	const Fanpage& operator+=(User& addfan);
	bool operator >(const Fanpage& other)					const;
	bool operator <(const Fanpage& other)					const;

	~Fanpage();
private:
	string name;
	list<const User*> ListOfFans;
	vector<const Status*> statusPtrArr;

	bool setName(const string& newName);
};


#endif
