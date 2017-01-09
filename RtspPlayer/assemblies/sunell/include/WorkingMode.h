#ifndef _WORKING_MODE_
#define _WORKING_MODE_


#include "SNPlatOS.h"
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
/**********************************************************************/

class SN_DLL_API WorkingMode
{
public:
	WorkingMode(void);
	~WorkingMode(void);

public:
	void setModeID(int p_nModeID);
	const int getModeID() const;

	
	bool setModeName(const char* p_pszModeName);
	const char* getModeName() const;

	WorkingMode& operator = (const WorkingMode &p_objLanguageType);

private:
	
	int m_nModeID;										//工作模式ID

	char m_szModeName[CONST_WORKMODE_NAME + 1];			//工作模式名称

};

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif	//_WORKING_MODE_
