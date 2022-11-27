#ifndef __Status_H
#define __Status_H
#define TIME_FORMAT_LEN 100
#include "Date.h"
#include <ctime>

class Status
{
public:
	Status(const char* inputText);

	const tm& getTime()			const;    //func returns the time ref , with no option to change it.
	const char* getText()		const;
	int getTextLen()			const;
	const Date& getDate()		const;

	void showTime()				const;
	void showText()				const;
	~Status();

private:
	time_t currentTime;
	const tm statusTime;
	const Date dateOfStatus;
	char* text;
	int textLen;

	Status(const Status& other);  //disable the possibility of Status copy.	
};

#endif

