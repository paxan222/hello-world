#ifndef _EXTERNCOMINFO_H_
#define _EXTERNCOMINFO_H_

#include <vector>
#include <string>
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
/*********************************************************************
�ⲿ������Ϣ
**********************************************************************/

class SN_DLL_API ExternComInfo
{
public:
	ExternComInfo(void);
	~ExternComInfo(void);
	
	/****************************************************************************
	**������
	*		�����ⲿ��������
	**���룺
	*		p_strExternComType���������������磺RS485��
	**�����
	*		��
	**����ֵ��
	*		�� 
	**���ܣ�
	*		
	*******************************************************************************/
	void setExternComType(const std::string& p_strExternComType);

	/****************************************************************************
	**������
	*		��ȡ�ⲿ��������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������������磺RS485�� 
	**���ܣ�
	*		
	*******************************************************************************/
	const std::string& getExternComType() const;

	/****************************************************************************
	**������
	*		�����ⲿ����ID�б�
	**���룺
	*		p_vecExternComIDList���ⲿ����ID�б�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*******************************************************************************/
	void setExternComIDList(const std::vector<int>& p_vecExternComIDList);

	/****************************************************************************
	**������
	*		��ȡ�ⲿ����ID�б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�ⲿ����ID�б�
	**���ܣ�
	*		
	*******************************************************************************/
	const std::vector<int>& getExternComIDList() const;

	ExternComInfo& operator =(const ExternComInfo& p_objExternComInfo);
private:
	std::string			m_strExternComType;
	std::vector<int>	m_vecExternComIDList;
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
	#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif 
