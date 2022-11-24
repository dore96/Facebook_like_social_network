#ifndef __FANPAGE_H
#define __FANPAGE_H
#include "User.h"

class Fanpage
{
public:
	Fanpage(const char* newName);
	const char* getName()     const;
	int   getNumberOfStatus() const;
	int   getNumberOfFans()   const;

	void printName()          const;
	void showAllFans()        const;
	void showAllStatus()      const;

	void addFan(User& fan);
	void removeFan(User& fan);
	void addStatus(const Status& status);

	bool hasAFan(const User& userName);

	void makeDoubleStatusSpace();
	void makeDoubleFansSpace();

	~Fanpage();
private:
	char* name;
	int numberOfFans,numberOfStatus,physicalNumberOfFans,physicalNumberOfStatus;
	bool setName(const char* newName);
	const User** arrOfFans;
	const Status** statusPtrArr;
	Fanpage(const Fanpage&);
};


#endif
