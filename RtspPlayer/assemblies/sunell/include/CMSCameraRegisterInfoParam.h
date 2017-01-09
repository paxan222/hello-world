#ifndef _CMSCAMERAREGISTERINFOPARAM_H_
#define _CMSCAMERAREGISTERINFOPARAM_H_

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

class SN_DLL_API CMSCameraRegisterInfoParam
{
public:
	CMSCameraRegisterInfoParam();

	~CMSCameraRegisterInfoParam();
	
	CMSCameraRegisterInfoParam(const CMSCameraRegisterInfoParam &p_objCameraRegisterInfoParam);

public:

	//设置通道号
	void setCameraID(const int p_nCameraID);
	//获取通道号
	const int getCameraID() const;

	/****************************************************************************
	**概述：
	*		设置通道注册ID
    **输入：
	*	p_pszCameraRegisterID ：字符串，最大长度为CONST_MAXLENGTH_CAMERA_REGISTER_ID字节,
	*	结尾以‘\0’结束。
	**输出：
	*	无
	**返回值：
	*	true： 成功
	*	false：失败 
	**功能：
	*	若输入p_pszCameraRegisterID长度<=CONST_MAXLENGTH_CAMERA_REGISTER_ID，返回true，
	*	并保存到m_szCameraRegisterID;
	*	若输入p_pszCameraRegisterID长度>CONST_MAXLENGTH_CAMERA_REGISTER_ID，返回false
	*****************************************************************************/	
	bool setCameraRegisterID(const char *p_pszCameraRegisterID);

	/****************************************************************************
	**概述：
	*		获取通道注册ID
    **输入：
	*	无
	**输出：
	*	无
	**返回值：
	*	返回保存通道注册ID的m_szCameraRegisterID字符串指针。 
	*功能：
	*	获取保存有通道注册ID的字符串指针
	*****************************************************************************/
	const char *getCameraRegisterID() const;


	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*****************************************************************************/
	CMSCameraRegisterInfoParam &operator =(const CMSCameraRegisterInfoParam &p_objCameraRegisterInfoParam);

private:

	int				m_nCameraID;													//通道号

	char			m_szCameraRegisterID[CONST_MAXLENGTH_CAMERA_REGISTER_ID + 1];	//通道注册ID
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSCAMERAREGISTERINFOPARAM_H_
