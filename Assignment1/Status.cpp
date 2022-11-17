#include "Status.h"


/*
maor:
move c'tor
*/
Status::Status(char* inputText) 
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
	delete []text;
}