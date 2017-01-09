#ifndef _REMOTEZXWPROTOCOLCONFIGURE_H_
#define _REMOTEZXWPROTOCOLCONFIGURE_H_

#include "DeviceInfoEx.h"
#include "SNPlatOS.h"

#include "CWMPParam.h"
#include "AlcatelSIPParam.h"
#include "Viss3XParam.h"
#include "Viss2XParam.h"

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

class SN_DLL_API RemoteZXWProtocolConfigure
{
public:
	RemoteZXWProtocolConfigure(void);
	~RemoteZXWProtocolConfigure(void);

	int open(const DeviceInfoEx &p_DeviceInfo);

	//��������Э��
	int setCWMPParam(const CWMPParam& p_objCWMPParam);
	int getCWMPParam(CWMPParam& p_objCWMPParam);

	//����SIPЭ��
	int setAlcatelSIPParam(const AlcatelSIPParam& p_objAlcatelSIPParam);
	int getAlcatelSIPParam(AlcatelSIPParam& p_objAlcatelSIPParam);

	//Viss3xЭ��
	int setViss3XParam(const Viss3XParam& p_objViss3XParam);
	int getViss3XParam(Viss3XParam& p_objViss3XParam);

	//Viss2xЭ��
	int setViss2XParam(const Viss2XParam& p_objViss2XParam);
	int getViss2XParam(Viss2XParam& p_objViss2XParam);


	void close();

private:
	DeviceInfoEx m_objDeviceInfo;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTEZXWPROTOCOLCONFIGURE_H_
