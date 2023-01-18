#include "VideoStatus.h"

VideoStatus::VideoStatus(const string& videoString, const string& inputText) : Status(inputText) ,videoUrl(videoString)
{
}

VideoStatus::VideoStatus(istream& in, const string& videoString, const string& inputText, const Date& dateOfStatus) :
Status(in, inputText, dateOfStatus), videoUrl(videoString)
{
}
void VideoStatus::showVideo()  const
{//plays the video from the file we provided
	system("start keren-video.mp4");      
}
void VideoStatus::showStatus()				const
{//shows status
	Status::showStatus();
	this->showVideo();
}
bool VideoStatus::operator ==(const Status& other)		const
{
	if(!Status::operator==(other))
	{
		return false;
	}
	const VideoStatus* temp = dynamic_cast<const VideoStatus*>(&other);//checks type is equal
	if(temp == NULL)
	{
		return false;
	}
	return videoUrl == temp->videoUrl;
}
bool VideoStatus::operator !=(const Status& other)		const
{
	return !(*this == other);
}

void VideoStatus::toOs(ostream& os) const
{
	if (typeid(os) == typeid(ofstream))
	{//if we are writing to file
		os << video << endl;
		os << videoUrl << endl;
	}
	else
	{//to the screen
		this->showVideo();
	}
}


