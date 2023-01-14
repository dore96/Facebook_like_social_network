#include "PictureStatus.h"

PictureStatus::PictureStatus(const string& pictureString, const string& inputText) : Status(inputText), pictureUrl(pictureString)
{
}
/*PictureStatus::PictureStatus(ifstream& in) : Status(in)
{
	in.read((char*)this, sizeof(*this));
}*/
void PictureStatus::showPicture()						  const
{//check if valid
	system("start OOP-CPP.jpg");
}
void PictureStatus::showStatus()						  const
{
	Status::showStatus();
	this->showPicture();
}
bool PictureStatus::operator ==(const Status& other)	  const 
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
	return pictureUrl == temp->pictureUrl;
}
bool PictureStatus::operator !=(const Status& other)	  const
{
	return !(*this == other);
}
void PictureStatus::toOs(ostream& os)					  const
{
	if (typeid(os) == typeid(ofstream))
	{//if we are writing to file
		os << image << endl;
		os << pictureUrl.size() << endl;
		os << pictureUrl << endl;
	}
	else
	{//to the screen
		this->showPicture();
	}
}