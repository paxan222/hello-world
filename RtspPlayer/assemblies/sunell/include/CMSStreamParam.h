#ifndef _CMSSTREAMPARAM_H_
#define _CMSSTREAMPARAM_H_

#include "DomainConst.h"
#include "SNPlatOS.h"
#include "VideoEncodeQuality.h"
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

class SN_DLL_API CMSStreamParam
{
public:
	CMSStreamParam();

	~CMSStreamParam();
	
	CMSStreamParam(const CMSStreamParam &p_objCMSStreamParam);

public:

	void setCameraID(const int p_nCameraID);
	const int getCameraID() const ;

	void setVideoEncodeQualityList(const vector<VideoEncodeQuality>& p_objVideoEncodeQualityList);
	const vector<VideoEncodeQuality>& getVideoEncodeQualityList() const;

	
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
	CMSStreamParam &operator =(const CMSStreamParam &p_objCMSStreamParam);

private:
	int									m_nCameraID;
	vector<VideoEncodeQuality>			m_objVideoEncodeQualityList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_CMSSTREAMPARAM_H_
