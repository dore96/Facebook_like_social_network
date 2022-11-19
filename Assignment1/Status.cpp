#include "Status.h"

Status::Status(char* inputText)//ctor
	: statusTime(localtime(nullptr)), dateOfStatus(statusTime->tm_mday, (statusTime->tm_mon) + 1, (statusTime->tm_year + 1900))
{
	textLen = strlen(inputText) + 1;
	text = new char[textLen];
	strcpy(text, inputText);
}
Status::Status(const Status& other)
	: dateOfStatus(other.dateOfStatus.getDay(), other.dateOfStatus.getMonth(), other.dateOfStatus.getYear())    //copy ctor
{
	statusTime = other.statusTime;
	textLen = other.textLen;
	text = new char[textLen];
	strcpy(text, other.text);
}
Status::Status(Status&& other)
	: dateOfStatus(other.dateOfStatus.getDay(), other.dateOfStatus.getMonth(), other.dateOfStatus.getYear())//move ctor
{
	statusTime = other.statusTime;
	textLen = other.textLen;
	text = other.text;
	other.text = nullptr;
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