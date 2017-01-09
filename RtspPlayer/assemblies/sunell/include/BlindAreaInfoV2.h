#ifndef _BLINDAREAINFOV2_H_
#define _BLINDAREAINFOV2_H_

#include "SNPlatOS.h"
#include "BlindAreaParamV2.h"
#include "PTZPointParamV2.h"

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

class SN_DLL_API BlindAreaInfoV2
{
public:
	BlindAreaInfoV2(void);
	~BlindAreaInfoV2(void);

	//拷贝构造函数
	BlindAreaInfoV2 (const BlindAreaInfoV2 &p_objBlindAreaInfoV2);

	/************************************************************************
	**概述：
	*		设置隐私遮蔽信息
	**输入：
	*		p_objBlindAreaParamV2:隐私遮蔽信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*      
	**************************************************************************/
	void setBlindAreaParamV2(const BlindAreaParamV2& p_objBlindAreaParamV2);


	/************************************************************************
	**概述：
	*		获取隐私遮蔽信息
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		隐私遮蔽信息
	**功能：
	*      
	**************************************************************************/
	const BlindAreaParamV2& getBlindAreaParamV2() const;

	/************************************************************************
	**概述：
	*		设置PTZ坐标信息
	**输入：
	*		p_objPTZPointParamV2:PTZ坐标信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*      
	**************************************************************************/
	void setPTZPointParamV2(const PTZPointParamV2& p_objPTZPointParamV2);


	/************************************************************************
	**概述：
	*		获取PTZ坐标信息
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		PTZ坐标信息
	**功能：
	*      
	**************************************************************************/
	const PTZPointParamV2& getPTZPointParamV2() const;


	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objBlindAreaParam：移动侦测规则对象
	**输出：
	*		无
	**返回值：
	*		赋值后的移动侦测规则对象
	**功能：
	*		
	*****************************************************************************/
	BlindAreaInfoV2& operator = (const BlindAreaInfoV2 &p_objBlindAreaParam);

private:
	BlindAreaParamV2		m_objBlindAreaParamV2;			//移动区域信息

	PTZPointParamV2			m_objPTZPointParamV2;			//PTZ坐标信息

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_BLINDAREAINFOV2_H_
