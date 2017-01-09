#ifndef _PTZPreset_H_
#define _PTZPreset_H_

#include "DomainConst.h"

#include <string.h>
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

class SN_DLL_API PTZPreset
{

public:
	PTZPreset();
	~PTZPreset();

	PTZPreset(const PTZPreset& p_objPTZPreset);

public:
	/************************************************************************
	**概述：
	*		设置摄像头ID号
    **输入：
	*		p_nCameraId ：摄像头的ID号
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**概述：
	*		获取摄像头的ID号
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		摄像头的ID号
	**功能：
	*    
	************************************************************************/
	const int getCameraId() const;

	/************************************************************************
	**概述：
	*		设置云台预制点ID号
	**输入：
	*		p_nPresetId ：预制点的ID号
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setPresetId(const int p_nPresetId);

	/************************************************************************
	**概述：
	*		获取预制点的ID号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		预制点的ID号
	**功能：
	*    
	************************************************************************/
	const int getPresetId() const;

	/************************************************************************
	**概述：
	*		设置云台预制点的名字
    **输入：
	*	  p_pszPresetName ：云台预制点的名字，字符串，最大长度
	*						  为CONST_MAXLENTH_PTZ_PROTOCOL_NAME字节,结尾以‘\0’结束。 
	**输出：
	*		无
	**返回值：
	*		true ：成功
	*		false：失败
	*功能：
	*    若输入p_pszPresetName长度<=CONST_MAXLENGTH_PTZ_PRESET_NAME，返回true，并保存到m_szProtocolName;
	*	 若输入p_pszPresetName为null或者其长度>CONST_MAXLENGTH_PTZ_PRESET_NAME，返回false
	************************************************************************/
	bool setPresetName(const char* p_pszPresetName);

	/************************************************************************
	**概述：
	*		获取云台协议的名字
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		云台协议的名字的地址
	**功能：
	*		
	************************************************************************/
	const char* getPresetName() const;
	/************************************************************************
	**概述：
	*		设置云台PTZ ID号
	**输入：
	*		p_nPTZId :PTZ ID号
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setPTZId(const int p_nPTZId);

	/************************************************************************
	**概述：
	*		获取PTZ的ID号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		PTZ的ID号
	**功能：
	*    
	************************************************************************/
	const int getPTZId() const;

		/************************************************************************
	**概述：
	*		设置矫正模式
	**输入：
	*		p_nDewarpMode ：矫正模式
	**输出：
	*		无
	*返回值：
	*		无
	**功能：
	*		
	************************************************************************/
	void setDewarpMode(const int p_nDewarpMode);

	/************************************************************************
	**概述：
	*		获取矫正模式
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		矫正模式
	**功能：
	*    
	************************************************************************/
	const int getDewarpMode() const;
	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objPTZPreset：云台预制点
	**输出：
	*		无
	**返回值：
	*		云台预制点
	**功能：
	************************************************************************/
	PTZPreset& operator =(const PTZPreset& p_objPTZPreset);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objPTZPreset：PTZPreset类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个PTZPreset类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const PTZPreset& p_objPTZPreset) const;

	bool operator < (const PTZPreset& p_objPTZPreset) const;

private:

	int		m_nCameraId;													//摄像头ID号
	
	int		m_nPresetId;													//云台预制点的ID号
	
	char	m_szPresetName[CONST_MAXLENGTH_PTZ_PRESET_NAME + 1];			//云台预制点的名字

	int		m_nPTZId;
	int		m_nDewarpMode;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //__PTZPreset_H__

