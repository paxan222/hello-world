#ifndef _FISHEYE_VIDEO_LAYOUT_H_
#define _FISHEYE_VIDEO_LAYOUT_H_

#include "SNPlatOS.h"
#include "VideoRect.h"
#include <vector>
using namespace std;

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

class SN_DLL_API FisheyeVideoLayout
{
public:
	FisheyeVideoLayout();
	~FisheyeVideoLayout();

public:
	//安装模式
	void setCameraId(const int p_nCameraId);
	const int getCameraId()const;

	//安装模式
	void setVideoRectList(const std::vector<VideoRect> &p_objVideoRectList);
	void getVideoRectList(std::vector<VideoRect> &p_objVideoRectList)const;

	/************************************************************************
	**概述：两个对象判等操作
	*
	**输入：
	*		p_objRhs：判等操作右操作符
	**输出：
	*		无
	**返回值：
	*		相等返回true， 不等返回false
	*************************************************************************/
	bool operator == (const FisheyeVideoLayout& p_objRhs);

	/************************************************************************
	**概述：赋值操作
	*
	**输入：
	*		p_objRhs：赋值操作右操作符
	**输出：
	*		无
	**返回值：
	*		返回FisheyeVideoLayout对象的引用
	*************************************************************************/
	FisheyeVideoLayout& operator =(const FisheyeVideoLayout& objRhs);
private:
	int m_nCameraId;						//通道号

	std::vector<VideoRect> m_nVideoRectList; //鱼眼、全景或PTZ显示区域
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
	#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif //_FISHEYE_VIDEO_LAYOUT_H_