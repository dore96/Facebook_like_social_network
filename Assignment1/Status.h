#ifndef __Status_H
#define __Status_H
#include <iostream>
#include <string.h>
using namespace std;

class Status
{
public:
	Status(char* text);
	char* GetText() const;   //האם צריך 2 ? פונקציות שעושות אותו הדבר בערך
	void ShowText() const;
	~Status();
private:
	char* text;
	int textLen;
};

#endif // !1

