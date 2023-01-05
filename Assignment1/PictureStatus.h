#ifndef __pictureStatus_H
#define __pictureStatus_H
#include "Status.h"

class PictureStatus : public Status
{
public:
	PictureStatus(const string& pictureString, const string& inputText) noexcept(false);
	virtual void showStatus()							const override;
	void showPicture()									const;
	//operators funcs
	virtual bool operator ==(const Status& other)		const override;
	virtual bool operator !=(const Status& other)		const override;
	virtual ~PictureStatus() {}
protected:
	const string pictureString;
};

#endif
