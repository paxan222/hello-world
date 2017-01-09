#ifndef _VIDEORESOLUTION_H_
#define _VIDEORESOLUTION_H_

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

class SN_DLL_API VideoResolution
{
public:
	VideoResolution(void);
	~VideoResolution(void);

	VideoResolution (const VideoResolution &p_objVideoResolution);

public:
	/************************************************************************
	**概述：设置高度
	**输入：
	*		p_nHeight：高度
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setVideoHeight(int p_nHeight);

	/************************************************************************
	**概述：获取高度
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		高度
	*************************************************************************/
	int getVideoHeight() const;


	/************************************************************************
	**概述：设置宽度
	**输入：
	*		p_nWidth：宽度
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setVideoWidth(int p_nWidth);

	/************************************************************************
	**概述：获取宽度
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		宽度
	*************************************************************************/
	int getVideoWidth() const;


	/************************************************************************
	**概述：设置分辨率别名
	**输入：
	*		p_pszResolutionName：分辨率别名
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	bool setResolutionName(const char* p_pszResolutionName);

	/************************************************************************
	**概述：获取分辨率别名
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		分辨率别名
	*************************************************************************/
	const char* getResolutionName() const;


	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objVideoResolution ：视频分辨率对象
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	VideoResolution& operator = (const VideoResolution &p_objVideoResolution);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objVideoResolution：VideoResolution类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个VideoResolution类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const VideoResolution& p_objVideoResolution);

private:
	int		m_nVideoHeight;												//高度
	int		m_nVideoWidth;												//宽度
	char	m_szResolutionName[CONST_MAXLENTH_RESOLUTION_NAME + 1];		//分辨率别名
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_VideoResolution_H_
