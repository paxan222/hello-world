#ifndef _AUDIO_PROCESS_PARAM_
#define _AUDIO_PROCESS_PARAM_

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

class SN_DLL_API AudioProcessParam
{
public:


public:
	AudioProcessParam();
	~AudioProcessParam();

	//拷贝构造函数
	AudioProcessParam(const AudioProcessParam &p_objProcessParam);

public:
	void setProcessType(const int& p_nProcessType);
	const int  getProcessType(void) const;

	void setEnable(const bool & p_bEnable );
	const bool getEnable(void)const;
	
	AudioProcessParam& operator = (const AudioProcessParam& p_objProcessParam);

	bool operator == (const AudioProcessParam& p_objProcessParam) const;
private:
	int m_nProcessType;
	bool m_bEnable;
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_LOUDHAILERPARAM_H_