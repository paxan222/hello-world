#ifndef _PTZTOURRX_H_
#define _PTZTOURRX_H_

#include "PTZTourPoint.h"
#include "DomainConst.h"
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

class SN_DLL_API PTZTourEx
{
public:
	PTZTourEx(void);
	~PTZTourEx(void);

	PTZTourEx(const PTZTourEx& p_objPTZTourEx);
	PTZTourEx& operator =(const PTZTourEx& p_objPTZTourEx);
public:
	void setTourID(const int p_nTourID);
	const int getTourID()const;

	bool setTourName(const char* p_pszTrackName);
	const char* getTourName() const;

	void setTourPointVec(const std::vector<PTZTourPoint>& p_objTourPointVec);
	void getTourPointVec(std::vector<PTZTourPoint>& p_objTourPointVec);

	void addTourPoint(const PTZTourPoint& p_objTourPoint);

private:
	int							m_nTourID;											//轨迹编号
	char						m_szTourName[CONST_MAXLENGTH_PTZ_TOUR_NAME + 1];	//云台巡游的名字
	std::vector<PTZTourPoint>	m_objTourPointVec;									//组成轨迹的预置点集合
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif // _PTZTOURRX_H_


