#ifndef _VIDEOOSDINFOEX_H_
#define _VIDEOOSDINFOEX_H_

#include "OSDInfoEx.h"
#include <vector>
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

class SN_DLL_API VideoOSDInfoEx
{
public:
	VideoOSDInfoEx();
	~VideoOSDInfoEx();

	//�������캯��
	VideoOSDInfoEx(const VideoOSDInfoEx &p_objVideoOSDInfoEx);
public:
	
	/************************************************************************
	**������
	*		������������
	**���룺
	*		p_nCameraId ����������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**������
	*		��ȡ��������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��������
	**���ܣ�
	*
	**************************************************************************/
	const int getCameraId() const;

	/************************************************************************
	**������
	*		����ˮӡ��Ϣ
	**���룺
	*		p_objOSDInfoList ��ˮӡ��Ϣ�б�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	void setOSDInfoList(const std::vector<OSDInfoEx>& p_objOSDInfoList);

	/************************************************************************
	**������
	*		��ȡˮӡ��Ϣ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ˮӡ��Ϣ
	**���ܣ�
	*
	**************************************************************************/
	const std::vector<OSDInfoEx>& getOSDInfoList() const;

	bool findOSDInfo(int p_nOSDType, OSDInfoEx& p_objOSDInfo) const;

	/****************************************************************************
	**������
	*		��ֵ����
    **���룺
	*		OSD���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		OSD����������
	**���ܣ�
	*	������������������Ը�ֵ������һ�����󣬽�����һ����������÷��ء�
	*****************************************************************************/
	VideoOSDInfoEx & operator =(const VideoOSDInfoEx &p_objVideoOSDInfoEx) ;
	
private:
	int					m_nCameraId;				//�����ID

	std::vector<OSDInfoEx>		m_objOSDInfoList;			//ˮӡ�б�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_OSDINFO_H_


