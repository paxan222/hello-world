#ifndef _FISHEYE_DEWARP_MODE_PARAM_H_
#define _FISHEYE_DEWARP_MODE_PARAM_H_

#include "FisheyeConst.h"
#include "SNPlatOS.h"

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

/************************************************************************
**���������۽���ģʽ��Ϣ
*	��Ҫ����������Ϣ��
*		���û�ȡͨ���ţ����û�ȡ������Ƶģʽ�����û�ȡ��
************************************************************************/

class  SN_DLL_API FisheyeDewarpModeParam
{
public:
	FisheyeDewarpModeParam();
	~FisheyeDewarpModeParam();

public:

	/************************************************************************
	**����������ͨ����
	**���룺
	*		p_nCameraId ͨ����
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void setCameraId(const int p_nCameraId);
	
	/************************************************************************
	**��������ȡͨ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ͨ����
	*************************************************************************/
	int getCameraId()const;

	
	/************************************************************************
	**����������������Ƶģʽ
	**���룺
	*		p_nFisheyeVideoMode ������Ƶģʽ
	*		FISHEYE_SINGLE_STREAM ����ģʽ  FISHEYE_MULTIPLE_STREAM ����ģʽ
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void setFisheyeVideoMode(const int p_nFisheyeVideoMode);

	/************************************************************************
	**��������ȡ������Ƶģʽ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		������Ƶģʽֵ
	*************************************************************************/
	int getFisheyeVideoMode() const;

	/************************************************************************
	**���������ý���ģʽ
	**���룺
	*	p_nDewarpMode ���۽���ģʽ
	*	FISHEYE_DEWRAP_FISHEYE	= 0,	//����ģʽ
	*	FISHEYE_DEWRAP_PANORAMA	= 2,	//ȫ��ģʽ
	*	FISHEYE_DEWARP_1F_3P	= 4,	//1����+3PTZģʽ
	*	FISHEYE_DEWARP_1F_5P	= 5,	//1����+5PTZģʽ
	*	FISHEYE_DEWARP_1F_7P	= 6,	//1����+7PTZģʽ
	*	FISHEYE_DEWARP_1F_8P	= 7,	//1����+8PTZģʽ
	*	FISHEYE_DEWARP_4PTZ		= 8		//4PTZģʽ
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void setDewarpMode(const int p_nDewarpMode);
	
	/************************************************************************
	**��������ȡ���۽���ģʽ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���۽���ģʽֵ
	*************************************************************************/
	int getDewarpMode()const;
	
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
	bool operator == (const FisheyeDewarpModeParam& p_objRhs);
	FisheyeDewarpModeParam& operator = (const FisheyeDewarpModeParam& p_objRhs);
private:
	int m_nCameraId;		//ͨ����
	int m_nFisheyeVideoMode;	//������Ƶģʽ,���嶨��ɲ鿴FisheyeConst.h��FISHEYE_VIDEO_MODEö�ٶ���
	int m_nDewarpMode;	//����ģʽ,���嶨��ɲ鿴FisheyeConst.h��FISHEYE_DEWARP_MODEö�ٶ���
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif //_FISHEYE_DEWARP_MODE_PARAM_H_

