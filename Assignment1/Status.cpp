#include "Status.h"

Status::Status(const char* inputText)//ctor
	: statusTime(localtime(nullptr)), dateOfStatus(statusTime->tm_mday, (statusTime->tm_mon) + 1, (statusTime->tm_year + 1900))
{
	textLen = strlen(inputText) + 1;
	text = new char[textLen];
	strcpy(text, inputText);
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
	delete[]text;
}