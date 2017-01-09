#ifndef _CAMERA_TAMPER_PARAM_H
#define _CAMERA_TAMPER_PARAM_H
#include "IntelligeBaseParam.h"
#include "DomainConst.h"
#include "PolygonArea.h"

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

class SN_DLL_API CameraTamperParam: public IntelligeBaseParam
{
public:
	CameraTamperParam();
	~CameraTamperParam();

	CameraTamperParam(const CameraTamperParam& p_objCameraTamperParam);
	CameraTamperParam& operator=(const CameraTamperParam& p_objCameraTamperParam);
public:
	void setMinTime(const int p_nMinTime);
	const int  getMinTime()const;

private:
	int 						m_nMinTime;  //	�ڵ���Сʱ��
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif
