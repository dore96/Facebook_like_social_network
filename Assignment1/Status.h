#ifndef __Status_H
#define __Status_H
#define TIME_FORMAT_LEN 100
#include "Date.h"
enum eStatusType { text, image, video };//enum for status types
class Status
{
public:
	Status(const string& inputText) noexcept(false);//ctor
	Status(istream& in, const string& inputText, const Date& dateOfStatus);//file ctor

	const tm& getTime()						const;    //func returns the time ref , with no option to change it.
	const Date& getDate()					const;
	const string& getText()					const;
	void showTime()							const;
	virtual void showStatus()				const;

	//operators funcs
	virtual bool operator ==(const Status& other)		const;
	virtual bool operator !=(const Status& other)		const;

	//<< functions
	virtual void toOs(ostream& os) const;
	friend ostream& operator <<(ostream& os, const Status& status);
	friend istream& operator>>(istream& in, Status& status);

	//virtual void save(ofstream& out) const;
	virtual ~Status(){}
protected:
	time_t currentTime;
	tm statusTime;
	const Date dateOfStatus;
	const string statusText;
};

#endif