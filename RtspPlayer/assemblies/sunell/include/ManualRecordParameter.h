#ifndef _MANUALRECORDPARAMETER_H_
#define _MANUALRECORDPARAMETER_H_
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

class SN_DLL_API ManualRecordParameter
{
public:
	ManualRecordParameter();

	~ManualRecordParameter();

public:
	void setCameraId(const int p_nCameraId);

	int getCameraId() const;

	void setRecordDuration(const unsigned long p_RecordEndTime);

	unsigned long getRecordDuration() const;
	
	void setStreamId(const int p_nStreamId);

	int getStreamId() const;

	

	/************************************************************************
	**概述：
	*		判等函数
	**输入：
	*		p_ManualRecordParameter	ManualRecordParameter对象
	**输出：
	*		无
	**返回值：
	*		true ：相等
	*		false：不相等
	************************************************************************/
	bool operator == (const ManualRecordParameter& p_ManualRecordParameter);
private:
	int					m_nCameraId;		
	int					m_nStreamId;
	unsigned long		m_nRecordDuration;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_MANUALRECORDPARAMETER_H_
