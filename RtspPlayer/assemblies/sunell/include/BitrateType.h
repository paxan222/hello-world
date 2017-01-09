#ifndef _BITRATETYPE_H_
#define _BITRATETYPE_H_

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

class SN_DLL_API BitrateType
{
public:
	enum BITRATE_TYPE
	{
		CBR_TYPE = 1,//�̶�����

		VBR_TYPE = 2 //���̶�����
	};

public:
	BitrateType(void);
	~BitrateType(void);
	BitrateType(const BitrateType& p_objBitrateType);

public:

	/************************************************************************
	**������
	*		���ñ���������ID
	**���룺
	*		p_nBitrateTypeId ��Ҫ���õı���������ID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setBitrateTypeId(const int p_nBitrateTypeId);

	/************************************************************************
	*������
	*		��ȡ����������id
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		����������Id
	*���ܣ�       
	*************************************************************************/
	const int getBitrateTypeId() const;


	/************************************************************************
	**������
	*		���ñ���������ID
	**���룺
	*		p_pszBitrateTypeName��Ҫ���õı�������������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	bool setBitrateTypeName(const char* p_pszBitrateTypeName);

	/************************************************************************
	*������
	*		��ȡ��������������
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		��������������
	*���ܣ�       
	*************************************************************************/
	const char* getBitrateTypeName() const;

	/************************************************************************
	*������
	*		��ֵ����
	*���룺
	*		p_objBitrateType��DDNS��Ϣ
	*�����
	*		��
	*����ֵ��
	*		DDNS��Ϣ
	*���ܣ�
	*************************************************************************/
	BitrateType& operator =(const BitrateType& p_objBitrateType);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objBitrateType��BitrateType���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����BitrateType��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const BitrateType& p_objBitrateType);


private:
	int			m_nBitrateTypeId;										//����������id
	char		m_szBitrateTypeName[CONST_MAXLENGTH_BITRATETYPE_NAME + 1];	//��������������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_BITRATETYPE_H_
