#ifndef _OSDFORMATABILITY_H_
#define _OSDFORMATABILITY_H_

#include <vector>
#include "OSDTimeFormatType.h"
#include "SNPlatOS.h"

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
/**********************************************************************/

class SN_DLL_API OSDFormatAbility
{
public:
	OSDFormatAbility();
	~OSDFormatAbility();

	void setOSDTimeFormatTypeList(const std::vector<OSDTimeFormatType>  &p_OSDFormatTypeList);
	const std::vector<OSDTimeFormatType> &getOSDTimeFormatTypeList() const;

private:
	std::vector<OSDTimeFormatType> m_OSDFormatTypeList;


}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif

