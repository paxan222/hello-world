#ifndef PTZ_STAGE_TO_SPEED_PARAM_h__
#define PTZ_STAGE_TO_SPEED_PARAM_h__

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


/***************************************************************************//**
 @brief 速度档转速度一项的实体类
******************************************************************************/

class SN_DLL_API PTZStageToSpeedParam
{
public:
	PTZStageToSpeedParam();
	~PTZStageToSpeedParam();

	// 获取速度档
	const int getStage() const;

	// 设置速度档
	void setStage(const int p_nStage);

	// 获取pan速度
	const int getPanSpeed() const;

	// 设置pan速度
	void setPanSpeed(const int p_nSpeed);

	// 获取tilt速度
	const int getTiltSpeed() const;

	// 设置tilt速度
	void setTiltSpeed(const int p_nSpeed);


private:
	int m_nStage;		// 速度档
	int m_nPanSpeed;	// pan速度
	int m_nTiltSpeed;	// tilt速度

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif

/**********************************************************************/


#endif // PTZ_STAGE_TO_SPEED_PARAM_h__