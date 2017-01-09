#ifndef _LOUDHAILERPARAM_H_
#define _LOUDHAILERPARAM_H_

#include "SNPlatOS.h"

#ifndef byte
typedef unsigned char byte;
#endif

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

class SN_DLL_API LoudhailerParam
{
public:

	enum LoudhailerType
	{
		LOUDHAILER_TYPE_IN			= 1,	//内置
		LOUDHAILER_TYPE_OUT			= 2		//外置
	};

public:
	LoudhailerParam();
	~LoudhailerParam();

	//拷贝构造函数
	LoudhailerParam(const LoudhailerParam &p_objLoudhailerParam);

public:
	/************************************************************************
	**概述：
	*		设置摄像机的Id号
    **输入：
	*		p_nCameraId ：摄像机的Id号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*    设置摄像机的Id号
	************************************************************************/
	void setCameraId(const int p_nCameraId);
	
	/************************************************************************
	**概述：
	*		获取摄像机的Id号
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		摄像机的Id号
	**功能：
	*     获取摄像机的Id号
	**************************************************************************/
	const int getCameraId() const ;

	/************************************************************************
	**概述：
	*		设置是否启用扬声器
	**输入：
	*		p_bFlag：启用扬声器标识（false：不启用，true：启用）
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	**************************************************************************/	
	void setLoudhailerEnableFlag(const bool p_bFlag);

	/************************************************************************
	**概述：
	*		获取是否启用扬声器标识
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		是否扬声器标识（false：不启用，true：启用）
	**功能：
	*     
	**************************************************************************/
	const bool getLoudhailerEnableFlag() const ;


	/************************************************************************
	**概述：
	*		设置扬声器类型
	**输入：
	*		p_nLoudhailerType：扬声器类型
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	**************************************************************************/
	void setLoudhailerType(const int p_nLoudhailerType);

	/************************************************************************
	**概述：
	*		获取扬声器类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		扬声器类型
	**功能：
	*     
	**************************************************************************/
	const int getLoudhailerType() const ;


	/************************************************************************
	**概述：
	*		设置音量
	**输入：
	*		p_nVolume：音量
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	**************************************************************************/
	void setVolume(const int p_nVolume);

	/************************************************************************
	**概述：
	*		获取音量
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		音量
	**功能：
	*     
	**************************************************************************/
	const int getVolume() const ;


	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objLoudhailerParam ：扬声器对象
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	**************************************************************************/
	LoudhailerParam& operator = (const LoudhailerParam& p_objLoudhailerParam);

	bool operator == (const LoudhailerParam& p_objLoudhailerParam) const;

	bool operator < (const LoudhailerParam& p_objLoudhailerParam) const;

private:
	
	int				m_nCameraId;										//摄像机的ID号

	bool			m_bLoudhailerEnableFlag;							//是否启用扬声器（false：不启用，true：启用）
	
	int				m_nLoudhailerType;									//扬声器类型

	int				m_nVolume;											//音量
		
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_LOUDHAILERPARAM_H_
