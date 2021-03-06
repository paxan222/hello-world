#ifndef _SIGNAL_BAD_PARAM_H
#define _SIGNAL_BAD_PARAM_H
#include "IntelligeBaseParam.h"
#include "DomainConst.h"

/**********************************************************************/
//此处用于控制文件编译字节对齐，拷贝时两行注释间内容需一起拷贝，
//结束处的“#ifdef PRAGMA_PACK”部分也要一起拷贝，否则pragma pack入栈出栈不匹配
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

class SN_DLL_API SignalBadParam: public IntelligeBaseParam
{
public:
	SignalBadParam();
	~SignalBadParam();

	SignalBadParam(const SignalBadParam& p_objSignalBadParam);
	SignalBadParam& operator=(const SignalBadParam& p_objSignalBadParam);
public:
	void setIsGetDetail(const bool p_bIsGetDetail);
	const bool getIsGetDetail()const;

private:
	bool				m_bIsGetDetail;//是否显示详细信息
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif
