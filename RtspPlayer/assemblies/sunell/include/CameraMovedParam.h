#ifndef _CAMERA_MOVED_PARAM_H
#define _CAMERA_MOVED_PARAM_H
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

class SN_DLL_API CameraMovedParam: public IntelligeBaseParam
{
public:
	CameraMovedParam();
	~CameraMovedParam();
	CameraMovedParam(const CameraMovedParam& p_objCameraMovedParam);
	CameraMovedParam& operator=(const CameraMovedParam& p_objCameraMovedParam);
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif
