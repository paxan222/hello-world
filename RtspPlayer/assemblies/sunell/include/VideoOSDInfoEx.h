#ifndef _VIDEOOSDINFOEX_H_
#define _VIDEOOSDINFOEX_H_

#include "OSDInfoEx.h"
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

class SN_DLL_API VideoOSDInfoEx
{
public:
	VideoOSDInfoEx();
	~VideoOSDInfoEx();

	//拷贝构造函数
	VideoOSDInfoEx(const VideoOSDInfoEx &p_objVideoOSDInfoEx);
public:
	
	/************************************************************************
	**概述：
	*		设置摄像机编号
	**输入：
	*		p_nCameraId ：摄像机编号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**概述：
	*		获取摄像机编号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		摄像机编号
	**功能：
	*
	**************************************************************************/
	const int getCameraId() const;

	/************************************************************************
	**概述：
	*		设置水印信息
	**输入：
	*		p_objOSDInfoList ：水印信息列表
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setOSDInfoList(const std::vector<OSDInfoEx>& p_objOSDInfoList);

	/************************************************************************
	**概述：
	*		获取水印信息
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		水印信息
	**功能：
	*
	**************************************************************************/
	const std::vector<OSDInfoEx>& getOSDInfoList() const;

	bool findOSDInfo(int p_nOSDType, OSDInfoEx& p_objOSDInfo) const;

	/****************************************************************************
	**概述：
	*		赋值函数
    **输入：
	*		OSD类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		OSD类对象的引用
	**功能：
	*	将参数对象的所有属性赋值给另外一个对象，将另外一个对象的引用返回。
	*****************************************************************************/
	VideoOSDInfoEx & operator =(const VideoOSDInfoEx &p_objVideoOSDInfoEx) ;
	
private:
	int					m_nCameraId;				//摄像机ID

	std::vector<OSDInfoEx>		m_objOSDInfoList;			//水印列表
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_OSDINFO_H_


