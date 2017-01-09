#ifndef _DDNS_INFO_H_
#define _DDNS_INFO_H_

#include <string>

#include "SNPlatOS.h"

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

class SN_DLL_API DDNSInfo 
{
public:
	DDNSInfo();
	~DDNSInfo();
	
	DDNSInfo& operator =(const DDNSInfo& p_objDDNSInfo);
	DDNSInfo(const DDNSInfo& p_objDDNSInfo);
	bool operator == (const DDNSInfo& p_objDDNSInfo) const;
public:

	/************************************************************************
	** ������
	*		�����ṩ��ID
	**���룺
	*		p_nDDNSProviderId���ṩ��ID
	**�����
	*	  ��
	**����ֵ��
	*	  ��
	************************************************************************/
	void setDDNSProviderId(const int p_nDDNSProviderId);
	
	/************************************************************************
	**������
	*		��ȡ�ṩ��ID
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�ṩ��ID
	************************************************************************/
	const int getDDNSProviderId(void) const;
	
	/************************************************************************
	** ������
	*		���÷���������
	**���룺
	*		p_strDDNSHostName������������
	**�����
	*	  ��
	**����ֵ��
	*	  ��
	************************************************************************/
	void setDDNSHostName(const std::string& p_strDDNSHostName);
	
/************************************************************************
	**������
	*		��ȡ����������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����������
	************************************************************************/
	const std::string& getDDNSHostName(void) const;
	
	/************************************************************************
	** ������
	*		���÷�������
	**���룺
	*		p_strDDNSCommand����������
	**�����
	*	  ��
	**����ֵ��
	*	  ��
	************************************************************************/
	void setDDNSCommand(const std::string& p_strDDNSCommand);
	
/************************************************************************
	**������
	*		��ȡ��������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��������
	************************************************************************/
	const std::string& getDDNSCommand(void) const;
	
private:

	int						m_nDDNSProviderId;	//�ṩ��ID
	std::string				m_strDDNSHostName;	//����������
	std::string				m_strDDNSCommand;	//��������

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif	//_DDNS_INFO_H_
