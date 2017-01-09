#ifndef _EXTERNCOMINFO_H_
#define _EXTERNCOMINFO_H_

#include <vector>
#include <string>
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
/*********************************************************************
外部串口信息
**********************************************************************/

class SN_DLL_API ExternComInfo
{
public:
	ExternComInfo(void);
	~ExternComInfo(void);
	
	/****************************************************************************
	**概述：
	*		设置外部串口类型
	**输入：
	*		p_strExternComType：串口类型名（如：RS485）
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setExternComType(const std::string& p_strExternComType);

	/****************************************************************************
	**概述：
	*		获取外部串口类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		串口类型名（如：RS485） 
	**功能：
	*		
	*******************************************************************************/
	const std::string& getExternComType() const;

	/****************************************************************************
	**概述：
	*		设置外部串口ID列表
	**输入：
	*		p_vecExternComIDList：外部串口ID列表
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*******************************************************************************/
	void setExternComIDList(const std::vector<int>& p_vecExternComIDList);

	/****************************************************************************
	**概述：
	*		获取外部串口ID列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		外部串口ID列表
	**功能：
	*		
	*******************************************************************************/
	const std::vector<int>& getExternComIDList() const;

	ExternComInfo& operator =(const ExternComInfo& p_objExternComInfo);
private:
	std::string			m_strExternComType;
	std::vector<int>	m_vecExternComIDList;
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
	#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif 
