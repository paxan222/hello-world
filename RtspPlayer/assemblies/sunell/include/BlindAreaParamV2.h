#ifndef _BLINDAREAPARAM_V2_H_
#define _BLINDAREAPARAM_V2_H_

#include "SNPlatOS.h"
#include "AreaParamV2.h"
#include "ColorParam.h"
#include <string>

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

class SN_DLL_API BlindAreaParamV2
{
public:
	BlindAreaParamV2(void);
	~BlindAreaParamV2(void);

	//拷贝构造函数
	BlindAreaParamV2 (const BlindAreaParamV2 &p_objBlindAreaParam);

	/************************************************************************
	**概述：
	*		设置移动区域ID
	**输入：
	*		p_nAreaId：移动区域ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	************************************************************************/
	void setAreaId(const int p_nAreaId) ;

	/************************************************************************
	**概述：
	*		获取移动区域ID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		通道号
	**功能：
	*	
	************************************************************************/
	const int getAreaId() const ;

	/************************************************************************
	**概述：
	*		设置是否启用遮蔽
	**输入：
	*		p_bFlag ：启用遮蔽标识
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	************************************************************************/
	void setEnableFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取启用遮蔽标识
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		启用遮蔽表示
	**功能：
	*		
	*************************************************************************/
	const bool getEnableFlag() const;

	/************************************************************************
	**概述：
	*		设置颜色（此方法预留，不可使用）
	**输入：
	*		p_objColorParam：颜色
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	************************************************************************/
	void setColor(const ColorParam& p_objColorParam);

	/************************************************************************
	**概述：
	*		获取颜色（此方法预留，不可使用）
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		颜色
	**功能：
	*	
	************************************************************************/
	const ColorParam& getColor() const ;


	/************************************************************************
	**概述：
	*		设置区域
	**输入：
	*		p_objAreaParamV2：区域对象
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	************************************************************************/
	void setAreaParamV2(const AreaParamV2& p_objAreaParamV2);


	/************************************************************************
	**概述：
	*		获取区域
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		区域对象
	**功能：
	*      
	**************************************************************************/
	const AreaParamV2& getAreaParamV2() const;


	/************************************************************************
	**概述：
	*		设置区域名称
	**输入：
	*		p_strAreaName：区域名称
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	************************************************************************/
	void setAreaName(const std::string& p_strAreaName);


	/************************************************************************
	**概述：
	*		获取区域名称
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		区域名称
	**功能：
	*      
	**************************************************************************/
	const std::string& getAreaName() const;

		/************************************************************************
	**概述：
	*		设置镜像值
	**输入：
	*		p_nMirrorValue：镜像值
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	************************************************************************/
	void setMirrorValue(const int p_nMirrorValue);


	/************************************************************************
	**概述：
	*		获取区域对象列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		区域对象列表
	**功能：
	*      
	**************************************************************************/
	const int getMirrorValue() const;

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
	BlindAreaParamV2& operator = (const BlindAreaParamV2 &p_objBlindAreaParam);

private:
	int						m_nAreaId;					//移动区域ID

	bool					m_bEnableFlag;					//是否启用遮蔽（true：启用，false：不启用）

	ColorParam				m_nColorParam;					//区域颜色，此参数预留

	AreaParamV2				m_objAreaParamV2;					//移动区域

	std::string				m_strAreaName;				//移动区域名称

	int						m_nMirrorValue;					//镜像类型

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_BLINDAREAPARAM_V2_H_
