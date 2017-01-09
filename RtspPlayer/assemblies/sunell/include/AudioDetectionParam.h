#ifndef _AudioDetectionParam_
#define _AudioDetectionParam_

#include "SNPlatOS.h"
#include "DomainConst.h"

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

class SN_DLL_API AudioDetectionParam
{
public:
	AudioDetectionParam(void);
	~AudioDetectionParam(void);

public:
	/************************************************************************
	*	概述：设置灵敏度
	*	输入：
	*		p_nSensitivity	灵敏度
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setSensitivity(int p_nSensitivity);

	/************************************************************************
	*	概述：获取灵敏度
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		灵敏度
	*************************************************************************/
	int getSensitivity() const;

	/************************************************************************
	*	概述：设置报警阀值
	*	输入：
	*		p_nAlarmLevel	报警阀值
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setAlarmLevel(int p_nAlarmLevel);

	/************************************************************************
	*	概述：获取报警阀值
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		报警阀值
	*************************************************************************/
	int getAlarmLevel() const;
	/************************************************************************
	*	概述：设置语音检测类型
	*	输入：
	*		p_nAlarmLevel	语音检测类型
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setDetectType(int p_nDetectType);

	/************************************************************************
	*	概述：获取语音检测类型
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		语音检测类型
	*************************************************************************/
	int getDetectType() const;
	AudioDetectionParam& operator = (const AudioDetectionParam& p_objAudioDetectionParam);
private:
	int		m_nSensitivity;
	int		m_nDetectType;
	int		m_nAlarmLevel;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_AudioDetectionParam_
