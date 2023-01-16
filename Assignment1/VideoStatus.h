#ifndef __videoStatus_H
#define __videoStatus_H
#include "Status.h"

class VideoStatus : public Status
{
public:
	VideoStatus(const string& videoString, const string& inputText) noexcept(false);
	VideoStatus(istream& in);

	virtual void showStatus()							const override;
	void showVideo()									const;

	virtual void fromOs(istream& in)						  override;
	virtual void toOs(ostream& os)						const override;
	//operators funcs
	virtual bool operator ==(const Status& other)		const override;
	virtual bool operator !=(const Status& other)		const override;
	virtual ~VideoStatus(){}
protected:
	string videoUrl;
};

#endif

