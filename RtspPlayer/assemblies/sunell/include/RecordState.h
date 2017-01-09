#ifndef _RECORD_STATE_H_
#define	_RECORD_STATE_H_

#include "DomainConst.h"
#include "const.h"
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

class SN_DLL_API RecordState
{
public:
	RecordState();
	~RecordState();
public:
	bool setDeviceId(const char *p_pszDeviceId);
	const char* getDeviceId() const;

	void setCameraId(const int p_nCameraId);
	const int getCameraId() const;

	void setState(const int p_nState);
	const int getState() const;

	const RecordState& operator=(const RecordState &p_objRecordState);
	bool operator==(const RecordState &p_objRecordState);

private:
	char m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];			//�豸ID
	int m_nCameraId;											//�����ID
	int m_nState;												//¼��״̬
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif	//_RECORD_STATE_H_
