#ifndef __Status_H
#define __Status_H

#include "Date.h"
#include <ctime>

class Status
{
public:
	Status(const char* inputText);
	char* GetText() const;
	void ShowText() const;
	~Status();

private:
	tm* statusTime;
	time_t curr_time;
	char* text;
	int textLen;
	Date dateOfStatus;
	Status(const Status& other);  //disable the possibility of Status copy.	
};

#endif

