#include "Status.h"

Status::Status(char* text)
{
								//בדיקת קלט
	textLen = strlen(text) + 1;
	text = new char[textLen];
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