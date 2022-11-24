#ifndef __Status_H
#define __Status_H

#include "Date.h"
#include <ctime>

class Status
{
public:
	Status(const char* inputText);

	const tm& getTime()			const;    //func returns the time ref , with no option to change it.
	const char* GetText()		const;
	int getTextLen()			const;
	const Date& getDate()		const;

	void showTime()				const;
	void ShowText()				const;
	~Status();

private:
	const tm* const statusTime;
	const Date dateOfStatus;
	char* text;
	time_t curr_time;
	int textLen;

	Status(const Status& other);  //disable the possibility of Status copy.	
};

#endif

