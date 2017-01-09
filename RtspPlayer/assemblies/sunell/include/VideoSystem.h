#ifndef _VIDEOSYSTEM_H_
#define _VIDEOSYSTEM_H_

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

class SN_DLL_API VideoSystem
{
public:
	enum 
	{
		NTSC		= 0,	//NTFS��ʽ
		PAL			= 1,	//PAL��ʽ
		NA			= 2,	//
		BOUNDARY	= 5		//�߽���
	};

public:
	VideoSystem(void);
	~VideoSystem(void);

	VideoSystem(const VideoSystem& p_objVideoSystem);

public:
	
	/************************************************************************
	**������
	*		������Ƶ��ʽID
	**���룺
	*		p_nVideoSystemId ��Ҫ���õ���Ƶ��ʽID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setVideoSystemId(const int p_nVideoSystemId);

	/************************************************************************
	*������
	*		��ȡ��Ƶ��ʽid
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		��Ƶ��ʽId
	*���ܣ�       
	*************************************************************************/
	const int getVideoSystemId() const;


	/************************************************************************
	**������
	*		������Ƶ��ʽ����
	**���룺
	*		p_pszVideoSystemName��Ҫ���õ���Ƶ��ʽ����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	bool setVideoSystemName(const char* p_pszVideoSystemName);

	/************************************************************************
	*������
	*		��ȡ��Ƶ��ʽ����
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		��Ƶ��ʽ����
	*���ܣ�       
	*************************************************************************/
	const char* getVideoSystemName() const;

	/************************************************************************
	*������
	*		��ֵ����
	*���룺
	*		p_objVideoSystem��DDNS��Ϣ
	*�����
	*		��
	*����ֵ��
	*		DDNS��Ϣ
	*���ܣ�
	*************************************************************************/
	VideoSystem& operator =(const VideoSystem& p_objVideoSystem);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objVideoSystem��VideoSystem���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����VideoSystem��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const VideoSystem& p_objVideoSystem);


	//ͨ���߿��ȡ��ʽ
	static int getVideoSystem(int p_nVideoWidth, int p_nVideoHeight);

private:
	int			m_nVideoSystemId;											//��Ƶ��ʽid
	char		m_szVideoSystemName[CONST_MAXLENGTH_VIDEOSYSTEM_NAME + 1];	//��Ƶ��ʽ����
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_VIDEOSYSTEM_H_
