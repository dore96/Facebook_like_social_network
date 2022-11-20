#ifndef __Status_H
#define __Status_H

#include "Date.h"
#include <ctime>

class Status
{
public:
	Status(char* inputText);
	char* GetText() const;
	void ShowText() const;
	~Status();

private:
	tm* statusTime;
	char* text;
	int textLen;
	Date dateOfStatus;
	Status(const Status& other);  //disable the possibility of Status copy.	
};

#endif

