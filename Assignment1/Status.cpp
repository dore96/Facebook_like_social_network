#include "Status.h"

Status::Status(const char* inputText)
	: curr_time(time(NULL)), statusTime(localtime(&curr_time)), dateOfStatus(statusTime->tm_mday, (statusTime->tm_mon) + 1, (statusTime->tm_year + 1900))//ctor
{
	textLen = strlen(inputText) + 1;
	text = new char[textLen];
	strcpy(text, inputText);
}
const tm& Status::getTime()   const
{
	return *statusTime;
}
void Status::showTime()				const
{
	cout << statusTime->tm_hour << ":" << statusTime->tm_min << ":" << statusTime->tm_sec << endl;
}
const char* Status::GetText() const
{
	return text;
}
void  Status::ShowText() const
{
	cout << text << endl;
}
int   Status::getTextLen()      const
{
	return  strlen(text);
}
const Date& Status::getDate() const
{
	return dateOfStatus;
}
Status::~Status()
{
	delete[]text;
}