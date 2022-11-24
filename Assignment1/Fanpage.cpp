#include "Fanpage.h"

Fanpage::Fanpage(const char* newName)
{
	setName(newName);
	physicalNumberOfFans = InitNumber;
	physicalNumberOfStatus = InitNumber;
	numberOfFans = 0;
	numberOfStatus = 0;
	arrOfFans = new const User * [physicalNumberOfFans];
	statusPtrArr = new const Status * [physicalNumberOfStatus];
}
bool Fanpage::setName(const char* newName)
{
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
	return true;
}
const char* Fanpage::getName() const
{
	return name;
}
int Fanpage::getNumberOfStatus() const
{
	return numberOfStatus;
}
int Fanpage::getNumberOfFans() const
{
	return numberOfFans;
}

void Fanpage::showAllFans() const
{
	for (int i = 0; i < numberOfFans; i++)
	{
		cout << "Fan number " << (i + 1) << " is: " << arrOfFans[i]->GetName() << endl;
	}
}
void Fanpage::showAllStatus() const
{
	for (int i = 0; i < numberOfStatus; i++)
	{
		cout << "Status number " << (i + 1) << ": ";
		statusPtrArr[i]->ShowText();
	}
}
void Fanpage::printName() const
{
	cout << name << endl;
}

void Fanpage::addFan(User& fan)
{
	if (numberOfFans >= physicalNumberOfFans)
	{
		makeDoubleFansSpace();
	}
	arrOfFans[numberOfFans] = fan;
	numberOfFans++;
}
void Fanpage::removeFan(User& fan)
{
	for(int i = 0;i < numberOfFans;i++)
	{
		if (arrOfFans[i] == fan)
		{
			arrOfFans[i] = arrOfFans[numberOfFans - 1];
			numberOfFans--;
		}
	}
}
void Fanpage::addStatus(Status& status)
{
	if(numberOfStatus >= physicalNumberOfStatus)
	{
		makeDoubleStatusSpace();
	}
	statusPtrArr[numberOfStatus] = status;
	numberOfStatus++;
}

bool Fanpage::hasAFan(const User& userName)
{
	for (int i = 0; i < numberOfFans; i++)
	{
		if((arrOfFans[i]) == &userName)
		{
			return true;
		}
	}
	return false;
}
void Fanpage::makeDoubleStatusSpace()
{
	physicalNumberOfStatus *= 2;
	const Status** newStatusPtrArr = new const Status * [physicalNumberOfStatus];
	for (int i = 0; i < numberOfStatus; i++)
	{
		newStatusPtrArr[i] = statusPtrArr[i];
	}
	delete[]statusPtrArr;
	statusPtrArr = newStatusPtrArr;
}
void Fanpage::makeDoubleFansSpace()
{
	physicalNumberOfFans *= 2;
	const User** newFansPtrArr = new const User * [physicalNumberOfFans];
	for (int i = 0; i < numberOfFans; i++)
	{
		newFansPtrArr[i] = arrOfFans[i];
	}
	delete[]arrOfFans;
	arrOfFans = newFansPtrArr;
}


Fanpage::~Fanpage()
{
	delete[]name;
	for(int i = 0;i< numberOfStatus;i++)
		delete statusPtrArr[i];
	delete arrOfFans;
	delete statusPtrArr;
}