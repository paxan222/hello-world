#ifndef _REMOTE_SNAPSHOT_PARAM_H_
#define _REMOTE_SNAPSHOT_PARAM_H_

#include "SNPlatOS.h"

class SN_DLL_API RemoteSnapshotParam
{
public:
	enum
	{
		PHOTO_FORMAT_JPG	= 1,
		PHOTO_FORMAT_BMP	= 2
	};


	void setCameraID(int p_nCameraID);
	int getCameraID() const;

	void setQuality(int p_nQuality);
	int getQuality() const;

	void setPhotoFormat(int p_nPhotoFormat);
	int getPhotoFormat() const;


private:

	int m_nCameraID;
	int m_nQuality;
	int m_nPhotoFormat;

};





#endif	//_REMOTE_SNAPSHOT_PARAM_H_

