#ifndef _SPECIALCUSTOM_H_
#define _SPECIALCUSTOM_H_
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

class SN_DLL_API SpecialCustom
{
public:
	SpecialCustom(void);
	~SpecialCustom(void);

	void setDispalyInfoShowFlag(const bool p_bEnableFlag);
	//获取是否显示信息
	bool getDispalyInfoShowFlag() const;

	//设置是否显示流名称
	void  setStreamNameShowFlag(const bool p_bEnableFlag);
	//获取是否显示流名称
	bool getStreamNameShowFlag() const;

	//设置是否显示编码类型
	void setEncodeTypeShowFlag(const bool p_bEnableFlag);
	//获取是否显示编码类型
	bool getEncodeTypeShowFlag() const;

	//设置是否显示分辨率
	void setResolutionNameShowFlag(const bool p_bEnableFlag);
	//获取是否显示分辨率
	bool getResolutionNameShowFlag() const;

	//设置是否显示帧率
	void setFrameRateShowFlag(const bool p_bEnableFlag);
	//获取是否显示帧率
	bool getFrameRateShowFlag() const;

	//设置是否显示比特率
	void setBitRateShowFlag(const bool p_bEnableFlag);
	//获取是否显示比特率
	bool getBitRateShowFlag() const;


	bool operator == (const SpecialCustom &p_objSpecialCustom);
private:
	bool		m_bDispalyInfoShowFlag;
	bool		m_bStreamNameShowFlag;
	bool		m_bEncodeTypeShowFlag;
	bool		m_bResolutionNameShowFlag;
	bool		m_bFrameRateShowFlag;
	bool		m_bBitRateShowFlag;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif
