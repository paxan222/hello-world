#ifndef _RESOLUTION_H_
#define _RESOLUTION_H_

#include "DomainConst.h"
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

class SN_DLL_API Resolution
{
public:
	Resolution(void);
	~Resolution(void);

	Resolution(const Resolution& p_objResolution);

public:
	
	/************************************************************************
	**概述：
	*		设置分辨率ID
	**输入：
	*		p_nResolutionId ：要设置的分辨率ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setResolutionId(const int p_nResolutionId);

	/************************************************************************
	*概述：
	*		获取分辨率id
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		分辨率Id
	*功能：       
	*************************************************************************/
	const int getResolutionId() const;


	/************************************************************************
	**概述：
	*		设置分辨率名称
	**输入：
	*		p_pszResolutionName：要设置的分辨率名称
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	bool setResolutionName(const char* p_pszResolutionName);

	/************************************************************************
	*概述：
	*		获取分辨率名称
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		分辨率名称
	*功能：       
	*************************************************************************/
	const char* getResolutionName() const;

	/************************************************************************
	*概述：
	*		赋值函数
	*输入：
	*		p_objResolution：DDNS信息
	*输出：
	*		无
	*返回值：
	*		DDNS信息
	*功能：
	*************************************************************************/
	Resolution& operator =(const Resolution& p_objResolution);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objResolution：Resolution类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个Resolution类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const Resolution& p_objResolution);


private:
	int			m_nResolutionId;											//分辨率id
	char		m_szResolutionName[CONST_MAXLENGTH_RESOLUTION_NAME + 1];	//分辨率名称
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_RESOLUTION_H_
