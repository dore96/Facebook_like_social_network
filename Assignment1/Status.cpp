#include "Status.h"

Status::Status(char* inputText)
{

	statusTime = localtime(nullptr);
	textLen = strlen(inputText) + 1;
	text = new char[textLen];
	strcpy(text, inputText);
	dateOfStatus.setDate(statusTime->tm_mday, (statusTime->tm_mon) + 1, (statusTime->tm_year + 1900));//this is bullshit way of initializing constructor
}
Status::Status(const Status& other)  //copy ctor
{
	statusTime = other.statusTime;
	textLen = other.textLen;
	text = new char[textLen];
	strcpy(text, other.text);
	dateOfStatus.setDate(other.dateOfStatus.getDay(),other.dateOfStatus.getMonth(),other.dateOfStatus.getYear());//this is bullshit way of initializing constructor
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