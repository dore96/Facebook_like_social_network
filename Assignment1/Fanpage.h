#ifndef __FANPAGE_H
#define __FANPAGE_H
#include "User.h"

class Fanpage
{
public:
	Fanpage(const char* newName);
	const char* getName()									const;
	int getNumberOfStatus()		     						const;
	int getNumberOfFans()									const;

	//show funcs
	void printName()										const;
	void showAllFans()										const;
	void showStatuses(int numberOfPrintStatus = INT_MAX)	const;

	bool isAFan(const User& userName)						const;

	//action funcs
	void addFan(User& fan);
	void removeFan(User& fan);
	void addStatus(const Status& status);

	void makeDoubleStatusSpace();
	void makeDoubleFansSpace();

	~Fanpage();
private:
	char* name;
	int numberOfFans,numberOfStatus,physicalNumberOfFans,physicalNumberOfStatus;
	const User** arrOfFans;
	const Status** statusPtrArr;

	bool setName(const char* newName);
	Fanpage(const Fanpage&);													//disable the possibility of Fanpage copy.
};


#endif
