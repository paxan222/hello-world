#ifndef _DEVICESERVICEPARAM_H_
#define _DEVICESERVICEPARAM_H_
/*
#ifdef __cplusplus
extern "C" {
#endif
*/ 

#include "DomainConst.h"
#include "SNPlatOS.h"

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

class DeviceServiceParam
{
public:

	DeviceServiceParam();
	DeviceServiceParam (const DeviceServiceParam &p_objDeviceServiceParam);
	~DeviceServiceParam();

public:
	
	//�����Ƿ����ñ�������
	void setAlarmCenterStartFlag(const bool p_bFlag);
	//��ȡ�Ƿ����ñ������ı�־
	const bool getAlarmCenterStartFlag() const;


	DeviceServiceParam& operator = (const DeviceServiceParam &p_objDeviceServiceParam);
	
private:
	bool			m_bAlarmCenterStartFlag;										//�Ƿ����ñ������ı�־,0�������ã�1������

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_DEVICESERVICEPARAM_H_
