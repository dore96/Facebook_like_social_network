#include "Status.h"
Status::Status(const string& inputText) noexcept(false)
	: currentTime(time(NULL)), statusTime(*localtime(&currentTime)), dateOfStatus(statusTime.tm_mday, (statusTime.tm_mon) + 1, (statusTime.tm_year + 1900)),statusText(inputText)
{
}
const tm& Status::getTime()			const
{
	return statusTime;
}
void Status::showTime()				const
{
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
ostream& operator <<(ostream& os, const Status& status)
{
	status.showStatus();
	status.toOs(os);
	return os;
}
