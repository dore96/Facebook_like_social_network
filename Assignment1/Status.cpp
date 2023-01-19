#include "Status.h"
Status::Status(const string& inputText) noexcept(false)
	: currentTime(time(NULL)), statusTime(*localtime(&currentTime)), dateOfStatus(statusTime.tm_mday, (statusTime.tm_mon) + 1, (statusTime.tm_year + 1900)),statusText(inputText)
{
}
Status::Status(istream& in, const string& inputText, const Date& dateOfStatus): dateOfStatus(dateOfStatus), statusText(inputText)
{
	in >> *this;
}
const tm& Status::getTime()			const
{
	return statusTime;
}
void Status::showTime()				const
{//prints formated time
	char time_string[TIME_FORMAT_LEN];
	strftime(time_string, TIME_FORMAT_LEN-1, "%T", &statusTime);
	cout << time_string << endl;
}
const string& Status::getText()	const
{
	return statusText;
}
void Status::showStatus()            const
{
	cout << statusText.data() << endl;
}
const Date& Status::getDate()		const
{
	return dateOfStatus;
}
bool Status::operator ==(const Status& other)		const
{
	return !(statusText.compare(other.statusText));
}
bool Status::operator !=(const Status& other)		const
{
	return !(*this == other);
}

ostream& operator <<(ostream& os, const Status& status)//print operator
{
	status.toOs(os);
	if(typeid(os) == typeid(ofstream))
	{
		os << status.getDate();
		os << status.statusText << endl;
		os << status.statusTime.tm_hour << ":"
		<< status.statusTime.tm_min << ":"
		<< status.statusTime.tm_sec;
	}
	else
	{
		status.showStatus();
	}
	return os;
}
istream& operator>>(istream& in, Status& status)//read opertaor
{
	char ch;
	in  >> status.statusTime.tm_hour >> ch
		>> status.statusTime.tm_min >> ch
		>> status.statusTime.tm_sec;
	return in;
}

void Status::toOs(ostream& os) const//to allow child classes to add for print
{
	if (typeid(os) == typeid(ofstream))
	{
		os << text << endl;
	}
}
