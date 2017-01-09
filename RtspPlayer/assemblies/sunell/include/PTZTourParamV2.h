#ifndef PTZTourParamV2_H_
#define PTZTourParamV2_H_

#include "DomainConst.h"
#include "PTZTourPointV2.h"
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

class SN_DLL_API PTZTourParamV2
{
public:
	PTZTourParamV2(void);
	~PTZTourParamV2(void);
public:
	/************************************************************************
	**概述：
	*		设置云台巡游ID号
	**输入：
	*		p_nTourId ：巡游的ID号
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setTourId(const int p_nTourId);

	/************************************************************************
	**概述：
	*		获取巡游的ID号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		巡游的ID号
	**功能：
	*    
	************************************************************************/
	const int getTourId() const;

	/************************************************************************
	**概述：
	*		设置云台巡游的名字
    **输入：
	*	  p_pszTourName ：云台巡游的名字，字符串，最大长度
	*						  为CONST_MAXLENGTH_PTZ_TOUR_NAME字节,结尾以‘\0’结束。 
	**输出：
	*		无
	**返回值：
	*		true ：成功
	*		false：失败
	*功能：
	*    若输入p_pszTourName长度<=CONST_MAXLENGTH_PTZ_TOUR_NAME，返回true，并保存到m_pszTourName;
	*	 若输入p_pszTourName为null或者其长度>CONST_MAXLENGTH_PTZ_TOUR_NAME，返回false
	************************************************************************/
	bool setTourName(const char* p_pszTourName);

	/************************************************************************
	**概述：
	*		获取云台巡游的名字
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		云台巡游的名字的地址
	**功能：
	*		
	************************************************************************/
	const char* getTourName() const;

	/************************************************************************
	**概述：
	*		设置云台巡游预置点列表
	**输入：
	*		p_vecPTZPresetV2List ：巡游的预置点列表
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setPTZTourPointV2List(const std::vector<PTZTourPointV2> &p_vecPTZTourPointV2List);

	/************************************************************************
	**概述：
	*		获取巡游的预置点列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		巡游的预置点列表
	**功能：
	*    
	************************************************************************/
	const std::vector<PTZTourPointV2> &getPTZTourPointV2List() const;

	PTZTourParamV2& operator =(const PTZTourParamV2& p_objPTZTourParamV2);
private:
	int		m_nTourId;													//云台巡游的ID号
	char	m_szTourName[CONST_MAXLENGTH_PTZ_TOUR_NAME + 1];			//云台巡游的名字
	std::vector<PTZTourPointV2> m_vecPTZTourPointV2List;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
#endif


