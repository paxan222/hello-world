#ifndef _SYSTEMSERVICEINFO_H_
#define _SYSTEMSERVICEINFO_H_
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

class SN_DLL_API SystemServiceInfo
{
public:
	SystemServiceInfo(void);
	~SystemServiceInfo(void);

	void setFTPEnableFlag(bool p_bFlag) ;
	bool getFTPEnableFlag() const;

	void setTelnetEnableFlag(bool p_bFlag);
	bool getTelnetEnableFlag() const;

	void  setWebLanguageID(const int& p_nWebLanguageID);
	int   getWebLanguageID()const;



private:
	bool			m_bFTPEnableFlag;
	bool			m_bTelnetEnableFlag;

	int				m_nWebLanguageID;//webĬ����ʾ���ԣ�2������  1��Ӣ��
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
#endif
