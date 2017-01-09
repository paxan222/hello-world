#ifndef _DEVICE_VIDEO_ENCODE_QUALITY_H_
#define _DEVICE_VIDEO_ENCODE_QUALITY_H_

#include "DomainConst.h"
#include "SNPlatOS.h"
#include "VideoEncodeQuality.h"
#include <vector>
using namespace std;

/**********************************************************************/
//�˴����ڿ����ļ������ֽڶ��룬����ʱ����ע�ͼ�������һ�𿽱���
//�������ġ�#ifdef PRAGMA_PACK������ҲҪһ�𿽱�������pragma pack��ջ��ջ��ƥ��
#if(PRAGMA_PACK_DEFINE != 10000)
	# error Not included "SNPlatOS.h".
#endif
 
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(push, PRAGMA_PACK_CHAR)
	#endif

	#ifndef WIN32  
		#ifndef _PACKED_1_  
		  
		#define _PACKED_1_ __attribute__((packed, aligned(PRAGMA_PACK_CHAR)))	// for gcc   
		#endif  
	#else  
		#ifndef _PACKED_1_  
		#define _PACKED_1_  
		#endif  
	#endif  
#else  
	#ifndef _PACKED_1_  
	#define _PACKED_1_  
	#endif  
#endif
/**********************************************************************/

class SN_DLL_API DeviceVideoEncodeQuality
{
public:
	DeviceVideoEncodeQuality();

	~DeviceVideoEncodeQuality();
	
	DeviceVideoEncodeQuality(const DeviceVideoEncodeQuality &p_objDeviceVideoEncodeQuality);

public:

	void setCameraID(const int p_nCameraID);
	const int getCameraID() const ;

	void setVideoEncodeQualityList(const vector<VideoEncodeQuality>& p_objVideoEncodeQualityList);

	void addVideoEncodeQuality(const VideoEncodeQuality &p_objVideoEncodeQuality);
	const vector<VideoEncodeQuality>& getVideoEncodeQualityList() const;

	
	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*****************************************************************************/
	DeviceVideoEncodeQuality &operator =(const DeviceVideoEncodeQuality &p_objDeviceVideoEncodeQuality);

private:
	int									m_nCameraID;
	vector<VideoEncodeQuality>			m_objVideoEncodeQualityList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_DEVICE_VIDEO_ENCODE_QUALITY_H_
