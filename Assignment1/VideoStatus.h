#ifndef __videoStatus_H
#define __videoStatus_H
#include "Status.h"

class VideoStatus : public Status
{
public:
	VideoStatus(const string& videoString, const string& inputText) noexcept(false);//ctor
	VideoStatus(istream& in, const string& videoString, const string& inputText, const Date& dateOfStatus);//file ctor

	virtual void showStatus()							const override;
	void showVideo()									const;

	virtual void toOs(ostream& os)						const override;
	//operators funcs
	virtual bool operator ==(const Status& other)		const override;
	virtual bool operator !=(const Status& other)		const override;
	virtual ~VideoStatus(){}
protected:
	const string videoUrl;
};

#endif

