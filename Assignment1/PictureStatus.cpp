#include "PictureStatus.h"

PictureStatus::PictureStatus(const string& pictureString, const string& inputText) : Status(inputText), pictureString(pictureString)
{
}
void PictureStatus::showPicture()  const
{//check if valid
	system("start OOP-CPP");
}
void PictureStatus::showStatus()				const
{
	Status::showStatus();
	this->showPicture();
}
bool PictureStatus::operator ==(const Status& other)		const 
{
	if (!Status::operator==(other))
	{
		return false;
	}
	const PictureStatus* temp = dynamic_cast<const PictureStatus*>(&other);
	if (temp == NULL)
	{
		return false;
	}
	return pictureString == temp->pictureString;
}
bool PictureStatus::operator !=(const Status& other)		const
{
	return !(*this == other);
}
