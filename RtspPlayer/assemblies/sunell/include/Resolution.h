#ifndef _RESOLUTION_H_
#define _RESOLUTION_H_

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

class SN_DLL_API Resolution
{
public:
	Resolution(void);
	~Resolution(void);

	Resolution(const Resolution& p_objResolution);

public:
	
	/************************************************************************
	**������
	*		���÷ֱ���ID
	**���룺
	*		p_nResolutionId ��Ҫ���õķֱ���ID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setResolutionId(const int p_nResolutionId);

	/************************************************************************
	*������
	*		��ȡ�ֱ���id
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		�ֱ���Id
	*���ܣ�       
	*************************************************************************/
	const int getResolutionId() const;


	/************************************************************************
	**������
	*		���÷ֱ�������
	**���룺
	*		p_pszResolutionName��Ҫ���õķֱ�������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	bool setResolutionName(const char* p_pszResolutionName);

	/************************************************************************
	*������
	*		��ȡ�ֱ�������
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		�ֱ�������
	*���ܣ�       
	*************************************************************************/
	const char* getResolutionName() const;

	/************************************************************************
	*������
	*		��ֵ����
	*���룺
	*		p_objResolution��DDNS��Ϣ
	*�����
	*		��
	*����ֵ��
	*		DDNS��Ϣ
	*���ܣ�
	*************************************************************************/
	Resolution& operator =(const Resolution& p_objResolution);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objResolution��Resolution���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����Resolution��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const Resolution& p_objResolution);


private:
	int			m_nResolutionId;											//�ֱ���id
	char		m_szResolutionName[CONST_MAXLENGTH_RESOLUTION_NAME + 1];	//�ֱ�������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_RESOLUTION_H_
