#ifndef _VISS3XPARAM_H_
#define _VISS3XPARAM_H_

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

class SN_DLL_API Viss3XParam
{
public:
		Viss3XParam();
		~Viss3XParam();


		//�������캯��
		Viss3XParam(const Viss3XParam &p_objViss3XParam);

public:
		//���ó�ʼ��������IP��ַ
		bool setHttpServerIP(const char* p_pszHttpServerIP);
		const char* getHttpServerIP() const;

		//��ʼ���������˿�
		void setHttpServerPort(const int p_nHttpServerPort);
		const int getHttpServerPort() const;

		//ǰ���豸ID
		bool setPuID(const char* p_pszPuID);
		const char* getPuID() const;

		//SIP��Ȩ����
		bool setPuPW(const char* p_pszPuPW);
		const char* getPuPW() const;

		Viss3XParam& operator = (const Viss3XParam &p_objProtocolConfigParam);

private:

	char	m_szHttpServerIP[CONST_MAXLENGTH_PROTOCOL_PARAM];			//��ʼ��������IP��ַ

	int		m_nHttpServerPort;											//��ʼ���������˿�

	char	m_szPuID[CONST_MAXLENGTH_PROTOCOL_PARAM];					//ǰ���豸ID
	
	char	m_szPuPW[CONST_MAXLENGTH_PROTOCOL_PARAM];					//SIP��Ȩ����
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_VISS3XPARAM_H_
