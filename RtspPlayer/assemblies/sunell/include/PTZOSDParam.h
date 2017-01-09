#ifndef _PTZOSDPARAM_H_
#define _PTZOSDPARAM_H_

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

class SN_DLL_API PTZOSDParam
{

public:

	enum OSDType
	{
		Version			= 1,   //版本信息
		PTZStatus		= 2,  //PTZ操作状态
		KeeperStatus	= 3   //看守位
	};
	PTZOSDParam();
	~PTZOSDParam();

	PTZOSDParam(const PTZOSDParam& p_objPTZOSDParam);
	void setOSDType(const int p_nOSDType);
	const int getOSDType()const;
	void setShowTime(const int p_nShowTime);
	const int getShowTime()const;
	void setX(const int p_nX);
	const int getX()const;
	void setY(const int p_nY);
	const int getY()const;
public:
	PTZOSDParam& operator =(const PTZOSDParam& p_objPTZOSDParam);
	
	bool operator == (const PTZOSDParam& p_objPTZOSDParam) const;

private:
	int m_nOSDType;
	int m_nShowTime;
	int m_nX;
	int m_nY;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_PTZOSDPARAM_H_

