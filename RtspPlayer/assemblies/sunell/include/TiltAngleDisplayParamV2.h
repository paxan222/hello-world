#ifndef __TILT_ANGLE_DISPLAY_PARAM_V2_H__
#define __TILT_ANGLE_DISPLAY_PARAM_V2_H__
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

class SN_DLL_API TiltAngleDisplayParamV2
{
public:
	TiltAngleDisplayParamV2();
	~TiltAngleDisplayParamV2();

	const int getMotorTiltMinAngle() const ;
	const int getMotorTiltMaxAngle() const ;
	const int getDisplayTiltMinAngle() const ;
	const int getDisplayTiltMaxAngle() const ;

	void setMotorTiltMinAngle(const int &p_nMotorTiltMinAngle);
	void setMotorTiltMaxAngle(const int &p_nMotorTiltMaxAngle);
	void setDisplayTiltMinAngle(const int &p_nDisplayTiltMinAngle);
	void setDisplayTiltMaxAngle(const int &p_nDisplayTiltMaxAngle);

	//赋值函数
	TiltAngleDisplayParamV2& operator=(const TiltAngleDisplayParamV2 &p_objTiltAngleDisplayParamV2);

private:
	int m_nMotorTiltMinAngle;
	int m_nMotorTiltMaxAngle;
	int m_nDisplayTiltMinAngle;
	int m_nDisplayTiltMaxAngle;

}_PACKED_1_;









/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif