#ifndef PTZScanParamV2_H_
#define PTZScanParamV2_H_


#include "DomainConst.h"
#include "PTZPresetV2.h"
#include <string.h>
#include <vector>
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
class SN_DLL_API PTZScanParamV2
{
public:
	PTZScanParamV2(void);
	~PTZScanParamV2(void);

public:
	/************************************************************************
	**概述：
	*		设置云台扫描ID号
	**输入：
	*		p_nScanId ：扫描的ID号
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setScanId(const int p_nScanId);

	/************************************************************************
	**概述：
	*		获取扫描的ID号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		扫描的ID号
	**功能：
	*    
	************************************************************************/
	const int getScanId() const;

	/************************************************************************
	**概述：
	*		设置云台扫描的名字
    **输入：
	*	  p_pszScanName ：云台扫描的名字，字符串，最大长度
	*						  为CONST_MAXLENTH_PTZ_PROTOCOL_NAME字节,结尾以‘\0’结束。 
	**输出：
	*		无
	**返回值：
	*		true ：成功
	*		false：失败
	************************************************************************/
	bool setScanName(const char* p_pszScanName);

	/************************************************************************
	**概述：
	*		获取云台扫描的名字
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		云台扫描的名字的地址
	**功能：
	*		
	************************************************************************/
	const char* getScanName() const;

	/************************************************************************
	**概述：
	*		设置扫描的起始点信息
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setStartPoint(const PTZPresetV2 &p_objPTZPresetV2);

	/************************************************************************
	**概述：
	*		获取扫描起始点信息
    **输入：
	*		无
	**输出：
	*		扫描起始点信息
	**返回值：
	*		true 获取成功
	*		false 获取失败
	**功能：
	*		
	************************************************************************/
	bool getStartPoint(PTZPresetV2 &p_objPTZPresetV2);

	/************************************************************************
	**概述：
	*		设置扫描的终止点信息
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setEndPoint(const PTZPresetV2 &p_objPTZPresetV2);

	/************************************************************************
	**概述：
	*		获取扫描终止点信息
    **输入：
	*		无
	**输出：
	*		扫描终止点信息
	**返回值：
	*		true 获取成功
	*		false 获取失败
	**功能：
	*		
	************************************************************************/
	bool getEndPoint(PTZPresetV2 &p_objPTZPresetV2);

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objPTZScanParamV2：云台扫描参数
	**输出：
	*		无
	**返回值：
	*		云台扫描参数
	**功能：
	************************************************************************/
	PTZScanParamV2& operator =(const PTZScanParamV2& p_objPTZScanParamV2);
		/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objPTZScanParamV2：PTZScanParamV2类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个PTZScanParamV2类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const PTZScanParamV2& p_objPTZScanParamV2) const;

private:
	int		m_nScanId;													//云台扫描的ID号
	char	m_szScanName[CONST_MAXLENGTH_PTZ_SCAN_NAME + 1];			//云台扫描的名字
	std::vector<PTZPresetV2> m_vecPTZPresetV2List;						//预置点信息列表
}_PACKED_1_;
/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
#endif


