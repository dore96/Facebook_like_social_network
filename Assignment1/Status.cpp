#include "Status.h"

Status::Status(char* text)
{
								//בדיקת קלט
	textLen = strlen(text) + 1;
	text = new char[textLen];
}

Status::Status(const Status& other)//copy ctor
{
	textLen = other.textLen;
	text = new char[textLen];
	strcpy(text, other.text);
}
char* Status::GetText() const
{
	return text;
}

void Status::ShowText() const
{
	cout << text << endl;
}

Status::~Status()
{
	delete text;
}