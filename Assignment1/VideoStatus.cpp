#include "VideoStatus.h"

VideoStatus::VideoStatus(const string& videoString, const string& inputText) : Status(inputText) ,videoUrl(videoString)
{
}
void VideoStatus::showVideo()  const
{//check if valid
	system("start keren-video.mp4");      
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
		os << videoUrl << endl;
	}
	else
	{//to the screen
		this->showVideo();
	}
}
