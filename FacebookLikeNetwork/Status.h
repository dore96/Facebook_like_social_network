#ifndef __Status_H
#define __Status_H
#define TIME_FORMAT_LEN 100
#include "Date.h"

class Status
{
public:
	Status(const string& inputText) noexcept(false);

	const tm& getTime()			const;    //func returns the time ref , with no option to change it.
	const string& getString()	const;
	const Date& getDate()		const;
	void showTime()				const;
	void showText()				const;
	//operators funcs
	bool operator ==(const Status& other)		const;
	bool operator !=(const Status& other)		const;
private:
	time_t currentTime;
	const tm statusTime;
	const Date dateOfStatus;
	const string statusText;
};
#endif
