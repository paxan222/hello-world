#ifndef _VIDEORESOLUTION_H_
#define _VIDEORESOLUTION_H_

#include "DomainConst.h"
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

class SN_DLL_API VideoResolution
{
public:
	VideoResolution(void);
	~VideoResolution(void);

	VideoResolution (const VideoResolution &p_objVideoResolution);

public:
	/************************************************************************
	**���������ø߶�
	**���룺
	*		p_nHeight���߶�
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void setVideoHeight(int p_nHeight);

	/************************************************************************
	**��������ȡ�߶�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�߶�
	*************************************************************************/
	int getVideoHeight() const;


	/************************************************************************
	**���������ÿ��
	**���룺
	*		p_nWidth�����
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void setVideoWidth(int p_nWidth);

	/************************************************************************
	**��������ȡ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���
	*************************************************************************/
	int getVideoWidth() const;


	/************************************************************************
	**���������÷ֱ��ʱ���
	**���룺
	*		p_pszResolutionName���ֱ��ʱ���
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	bool setResolutionName(const char* p_pszResolutionName);

	/************************************************************************
	**��������ȡ�ֱ��ʱ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�ֱ��ʱ���
	*************************************************************************/
	const char* getResolutionName() const;


	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objVideoResolution ����Ƶ�ֱ��ʶ���
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	VideoResolution& operator = (const VideoResolution &p_objVideoResolution);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objVideoResolution��VideoResolution���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����VideoResolution��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const VideoResolution& p_objVideoResolution);

private:
	int		m_nVideoHeight;												//�߶�
	int		m_nVideoWidth;												//���
	char	m_szResolutionName[CONST_MAXLENTH_RESOLUTION_NAME + 1];		//�ֱ��ʱ���
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_VideoResolution_H_
