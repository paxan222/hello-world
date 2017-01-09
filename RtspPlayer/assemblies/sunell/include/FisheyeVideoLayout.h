#ifndef _FISHEYE_VIDEO_LAYOUT_H_
#define _FISHEYE_VIDEO_LAYOUT_H_

#include "SNPlatOS.h"
#include "VideoRect.h"
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

class SN_DLL_API FisheyeVideoLayout
{
public:
	FisheyeVideoLayout();
	~FisheyeVideoLayout();

public:
	//��װģʽ
	void setCameraId(const int p_nCameraId);
	const int getCameraId()const;

	//��װģʽ
	void setVideoRectList(const std::vector<VideoRect> &p_objVideoRectList);
	void getVideoRectList(std::vector<VideoRect> &p_objVideoRectList)const;

	/************************************************************************
	**���������������еȲ���
	*
	**���룺
	*		p_objRhs���еȲ����Ҳ�����
	**�����
	*		��
	**����ֵ��
	*		��ȷ���true�� ���ȷ���false
	*************************************************************************/
	bool operator == (const FisheyeVideoLayout& p_objRhs);

	/************************************************************************
	**��������ֵ����
	*
	**���룺
	*		p_objRhs����ֵ�����Ҳ�����
	**�����
	*		��
	**����ֵ��
	*		����FisheyeVideoLayout���������
	*************************************************************************/
	FisheyeVideoLayout& operator =(const FisheyeVideoLayout& objRhs);
private:
	int m_nCameraId;						//ͨ����

	std::vector<VideoRect> m_nVideoRectList; //���ۡ�ȫ����PTZ��ʾ����
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
	#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif //_FISHEYE_VIDEO_LAYOUT_H_