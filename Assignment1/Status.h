#ifndef __Status_H
#define __Status_H
#define TIME_FORMAT_LEN 100
#include "Date.h"
enum eStatusType { text, image, video };
class Status
{
public:
	Status(const string& inputText) noexcept(false);
	//Status(ifstream& in);

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

	//virtual void save(ofstream& out) const;
	virtual ~Status(){}
protected:
	time_t currentTime;
	const tm statusTime;
	const Date dateOfStatus;
	const string statusText;
};

#endif