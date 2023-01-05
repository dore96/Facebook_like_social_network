#include "VideoStatus.h"

VideoStatus::VideoStatus(const string& videoString, const string& inputText) : Status(inputText) ,videoString(videoString)
{
}
void VideoStatus::showVideo()  const
{//check if valid
	system("start keren-video");      
}
void VideoStatus::showStatus()				const
{
	Status::showStatus();
	this->showVideo();
}
bool VideoStatus::operator ==(const Status& other)		const
{
	if(!Status::operator==(other))
	{
		return false;
	}
	const VideoStatus* temp = dynamic_cast<const VideoStatus*>(&other);
	if(temp == NULL)
	{
		return false;
	}
	return videoString == temp->videoString;
}
bool VideoStatus::operator !=(const Status& other)		const
{
	return !(*this == other);
}
