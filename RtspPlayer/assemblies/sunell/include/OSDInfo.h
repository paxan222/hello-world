#ifndef _OSDINFO_H_
#define _OSDINFO_H_

#include "DomainConst.h"
#include "SNPlatOS.h"
#include "ImageFormat.h"

#ifndef byte
typedef unsigned char byte;
#endif

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

class SN_DLL_API OSDInfo
{

public:
	enum 
	{
		OSDTYPE_DEVICENAME		= 1,	//�豸��
		OSDTYPE_CAMERAID		= 2,	//�������
		OSDTYPE_CAMERANAME		= 3,	//�������
		OSDTYPE_TIME			= 4,	//ʱ��ˮӡ
		OSDTYPE_TEXT			= 5,	//����ˮӡ
		OSDTYPE_SCAN			= 6,	//ɨ��ˮӡ
		OSDTYPE_PTZ_POSITION	= 7,    //PTZλ�ò���ˮӡ
		OSDTYPE_PTZ_BEHAVIOUR	= 8		//PTZ��Ϊ����ˮӡ��������ʾ�����Ͻǣ�
	};

public:
	OSDInfo();
	~OSDInfo();

public:
	/****************************************************************************
	**������
	*		����ˮӡ����
    **���룺
	*		p_nOSDType:ˮӡ���ͣ�����ֵ����ʾOSD��Id��
	**�����
	*		��
	**����ֵ��
	*		�� 
	**���ܣ�
	*		
	*******************************************************************************/
	void setOSDType(const int p_nOSDType);

	/****************************************************************************
	**������
	*		���ˮӡ����
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ˮӡ���ͣ�����ֵ����ʾ�õ���OSD��Id�� 
	**���ܣ�
	*	
	*******************************************************************************/
	const int getOSDType() const;


	/****************************************************************************
	**������
	*		�����Ƿ���ʾˮӡ
    **���룺
	*		p_nEnableOSD���Ƿ�������ʾˮӡ��false������ʾ��true����ʾ��
	**�����
	*		��
	**����ֵ��
	*		�� 
	**���ܣ�
	*		
	*******************************************************************************/
	void setOSDEnableFlag(const bool p_nEnableOSD);

	/****************************************************************************
	**������
	*		����Ƿ�������ʾˮӡ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�Ƿ�������ʾˮӡ��ʶ��false������ʾ��true����ʾ��
	**���ܣ�
	*
	*******************************************************************************/
	const bool getOSDEnableFlag() const;


	/****************************************************************************
	**������
	*		����TopX
    **���룺
	*		p_nTopX:����ֵ����ʾˮӡ��Ϣ�ڹ��������Ͻ� x ������λ��
	**�����
	*		��
	**����ֵ��
	*		�� 
	**���ܣ�
	*		
	*******************************************************************************/
	void setTopX(const int p_nTopX);

	/****************************************************************************
	**������
	*		���TopX
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ˮӡ��Ϣ�ڹ��������Ͻ� x ������λ��
	**���ܣ�
	*	
	*******************************************************************************/
	const int getTopX() const;


	/****************************************************************************
	**������
	*		����TopY
    **���룺
	*		p_nTopY:����ֵ����ʾˮӡ��Ϣ�ڹ��������Ͻ� y ������λ��
	**�����
	*		��
	**����ֵ��
	*		�� 
	**���ܣ�
	*		
	*******************************************************************************/
	void setTopY(const int p_nTopY);

	/****************************************************************************
	**������
	*		���TopY
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ˮӡ��Ϣ�ڹ��������Ͻ� y ������λ��
	**���ܣ�
	*	
	*******************************************************************************/
	const int getTopY() const;


	/****************************************************************************
	**������
	*		����OSD��Ϣ
    **���룺
	*		p_pszInfo���ַ�������󳤶�ΪCONST_MAXLENGTH_OSDINFO�ֽ�,��β�ԡ�\0��������
	**�����
	*		��
	**����ֵ��
	*		true�� �ɹ�
	*		false��ʧ�� 
	**���ܣ�
	*		������p_pszInfo����<=CONST_MAXLENGTH_OSDINFO������true�������浽m_szInfo;
	*		������p_pszInfo����>CONST_MAXLENGTH_OSDINFO������false
	*****************************************************************************/
	bool setInfo(const char* p_pszInfo);

	/****************************************************************************
	**������
	*		���OSD��Ϣ
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���ر���OSD��Ϣ��m_szInfo�ַ���ָ�롣 
	**���ܣ�
	*	
	*******************************************************************************/
	const char* getInfo() const;


	/****************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		OSDInfo���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		OSD����������
	**���ܣ�
	*		������������������Ը�ֵ������һ�����󣬽�����һ����������÷��ء�
	*******************************************************************************/
	OSDInfo & operator =(const OSDInfo& p_objOSDInfo) ;

	/****************************************************************************
	**������
	*			���塰���ڡ�������
    **���룺
	*			OSD���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		������OSD��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const OSDInfo& p_objOSDInfo) const;

	bool operator < (const OSDInfo& p_objOSDInfo) const;

	
private:

	int		m_nOSDType;								//ˮӡ����
	bool	m_bOSDEnableFlag;						//�Ƿ���ʾˮӡ��false������ʾ��true����ʾ��
	int		m_nTopX;								//ˮӡ��Ϣ�ڹ��������Ͻ� x ������
	int		m_nTopY;								//ˮӡ��Ϣ�ڹ��������Ͻ� y ������
	char	m_szInfo[CONST_MAXLENGTH_OSDINFO + 1];	//ˮӡ��Ϣ

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_OSDINFO_H_

