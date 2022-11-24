#ifndef __Status_H
#define __Status_H

#include "Date.h"
#include <ctime>

class Status
{
public:
	Status(const char* inputText);
	const tm& getTime()			const;    //func returns the time ref , with no option to change it.
	void showTime()				const;
	char* GetText()				const;
	int getTextLen()			const;
	void ShowText()				const;
	const Date& getDate()		const;
	~Status();

private:
	const tm* const statusTime;
	time_t curr_time;
	char* text;
	int textLen;
	const Date dateOfStatus;
	Status(const Status& other);  //disable the possibility of Status copy.	
};

#endif

