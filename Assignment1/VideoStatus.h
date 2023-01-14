#ifndef __videoStatus_H
#define __videoStatus_H
#include "Status.h"

class VideoStatus : public Status
{
public:
	VideoStatus(const string& videoString, const string& inputText) noexcept(false);
	virtual void showStatus()							const override;
	void showVideo()									const;
	//operators funcs
	virtual bool operator ==(const Status& other)		const override;
	virtual bool operator !=(const Status& other)		const override;
	virtual void toOs(ostream& os) const override;
	virtual ~VideoStatus(){}
protected:
	const string videoUrl;
};

#endif

