#include "Fanpage.h"

Fanpage::Fanpage(char* newName)
{
	setName(newName);
	physicalNumberOfFans = InitNumber;
	PhysicalNumberOfStatus = InitNumber;
	numberOfFans = 0;
	numberOfStatus = 0;
	arrOfFans = new User * [physicalNumberOfFans];
	statusPtrArr = new Status * [PhysicalNumberOfStatus];
}
bool Fanpage::setName(char* newName)
{
	char* name = new char[strlen(newName) + 1];
	strcpy(name, newName);
	return true;
}
char* Fanpage::getName() const
{
	return name;
}
void Fanpage::printName() const
{
	cout << name << endl;
}
void Fanpage::addFan(User* fan)
{
	if (numberOfFans >= physicalNumberOfFans)
	{
		makeDoubleSpace((void**)arrOfFans, sizeof(User*), physicalNumberOfFans);
	}
	arrOfFans[numberOfFans] = fan;
	numberOfFans++;
}
void Fanpage::removeFan(User* fan)
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

void Fanpage::addStatus(Status* status)
{
	if(numberOfStatus >= PhysicalNumberOfStatus)
	{
		makeDoubleSpace((void**)statusPtrArr, sizeof(Status*), PhysicalNumberOfStatus);
	}
	statusPtrArr[numberOfStatus] = status;
	numberOfStatus++;
}
void Fanpage::showAllFans() const
{
	for(int i =0;i < numberOfFans;i++)
	{
		cout << "Fan number " << (i + 1) << " is: " << arrOfFans[i]->GetName() << endl;
	}
}
void Fanpage::showAllStatus() const
{
	for(int i = 0;i<numberOfStatus;i++)
	{
		cout << "Status number " << (i + 1) << ": ";
		statusPtrArr[i]->ShowText();
	}
}
int Fanpage::getNumberOfStatus() const
{
	return numberOfStatus;
}
int Fanpage::getNumberOfFans() const
{
	return numberOfFans;
}
Fanpage::~Fanpage()
{
	delete[]name;
	for(int i = 0;i< numberOfStatus;i++)
		delete statusPtrArr[i];
	delete arrOfFans;
	delete statusPtrArr;
}