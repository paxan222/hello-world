#ifndef _ALCATELSIPPARAM_H_
#define _ALCATELSIPPARAM_H_

#include "SNPlatOS.h"
#include "DomainConst.h"

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

class SN_DLL_API AlcatelSIPParam
{
public:
		AlcatelSIPParam();
		~AlcatelSIPParam();


		//�������캯��
		AlcatelSIPParam(const AlcatelSIPParam &p_objAlcatelSIPParam);

public:
		//����ҵ��ƽ̨������IP��ַ
		bool setServIpAddress(const char* p_pszServIpAddress);
		const char* getServIpAddress() const;

		//����ҵ��ƽ̨�������˿�
		void setServPort(const int p_nServPort);
		const int getServPort() const;

		//����ҵ��ƽ̨����������
		bool setServDomainName(const char* p_pszServDomainName);
		const char* getServDomainName() const;
	
		//����ҵ��ƽ̨�ʺ�
		bool setPuID(const char* p_pszPuID);
		const char* getPuID() const;

		//����ҵ��ƽ̨����
		bool setPuPW(const char* p_pszPuPW);
		const char* getPuPW() const;

		AlcatelSIPParam& operator = (const AlcatelSIPParam &p_objProtocolConfigParam);

private:

	char	m_szServIpAddress[CONST_MAXLENGTH_PROTOCOL_PARAM];			//ҵ��ƽ̨������IP

	int		m_nServPort;												//ҵ��ƽ̨�������˿�

	char	m_szServDomainName[CONST_MAXLENGTH_PROTOCOL_PARAM];			//ҵ��ƽ̨����������

	char	m_szPuID[CONST_MAXLENGTH_PROTOCOL_PARAM];					//ҵ��ƽ̨�������˻���
	
	char	m_szPuPW[CONST_MAXLENGTH_PROTOCOL_PARAM];					//ҵ��ƽ̨����������
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_ALCATELSIPPARAM_H_
