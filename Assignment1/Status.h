#ifndef __Status_H
#define __Status_H
#include <string.h>
#include "Date.h"


class Status
{
public:
	Status(char* inputText);
	Status(const Status& other);
	char* GetText() const;   //האם צריך 2 ? פונקציות שעושות אותו הדבר בערך
	void ShowText() const;
	~Status();
	
private:
	tm* statusTime;
	char* text;
	int textLen;
	Date dateOfStatus;
};

#endif // !1

