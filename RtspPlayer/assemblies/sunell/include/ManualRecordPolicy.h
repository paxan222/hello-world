#ifndef _MANUALRECORDPOLICY_
#define _MANUALRECORDPOLICY_
#include "SNPlatOS.h"
#include "RecordInfo.h"

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

class  SN_DLL_API ManualRecordPolicy
{
public:
	ManualRecordPolicy();
	~ManualRecordPolicy();

	const bool isFileLocked() const;
	void  setFileLocked(bool p_bIsFileLocked);
	
	void setPreRecordTime(int p_nPreRecordTime);
	const int  getPreRecordTime() const;
	
	void setRecordInfo(const RecordInfo &p_objRecordInfo);	

	const RecordInfo& getRecordInfo() const;
	
	void setDelayRecordTime(int p_nDelayRecordTime);

	const int  getDelayRecordTime() const;


	bool operator == (const ManualRecordPolicy& p_objManualRecordpolicy);
	

private:
	RecordInfo		m_objRecordInfo;			
	bool			m_bIsFileLocked;			//手动录像文件是否锁定
	int				m_nPreRecordTime;			//录像的预录时间
	int				m_nDelayRecordTime;			//录像的延录时间
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_MANUALRECORDPOLICY_
