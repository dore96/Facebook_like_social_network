#include "Status.h"

Status::Status(const char* inputText)
	: currentTime(time(NULL)), statusTime(localtime(&currentTime)), dateOfStatus(statusTime->tm_mday, (statusTime->tm_mon) + 1, (statusTime->tm_year + 1900))
{//ctor how initiate the time and date of a status.
	textLen = strlen(inputText) + 1;
	text = new char[textLen];
	strcpy(text, inputText);
}
const tm& Status::getTime()			const
{
	return *statusTime;
}
void Status::showTime()				const
{
	char time_string[TIME_FORMAT_LEN];
	strftime(time_string, TIME_FORMAT_LEN-1, "Current time is %T", statusTime);
	cout << time_string << endl;
}
const char* Status::getText()		const
{
	return text;
}
void  Status::showText() const
{
	cout << text << endl;
}
int   Status::getTextLen()			const
{
	return  strlen(text);
}
const Date& Status::getDate()		const
{
	return dateOfStatus;
}
Status::~Status()  //d'tor - deletes the text char*.
{
	delete[]text;
}