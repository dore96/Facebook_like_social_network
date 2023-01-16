#ifndef __pictureStatus_H
#define __pictureStatus_H
#include "Status.h"

class PictureStatus : public Status
{
public:
	PictureStatus(const string& pictureString, const string& inputText) noexcept(false);
	PictureStatus(istream& in);

	virtual void showStatus()							const override;
	void showPicture()									const;

	virtual void fromOs(istream& in)						  override;
	virtual void toOs(ostream& os)						const override;

	//operators funcs
	virtual bool operator ==(const Status& other)		const override;
	virtual bool operator !=(const Status& other)		const override;
	virtual ~PictureStatus() {}
protected:
	string pictureUrl;
};

#endif
