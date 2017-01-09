#ifndef _VIDEO_ABILITY_
#define _VIDEO_ABILITY_

#include "CameraAbility.h"
#include "SNPlatOS.h"
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

/************************************************************************
**概述：视频能力信息
*	主要包含以下信息：摄像机能力信息列表。
************************************************************************/
class SN_DLL_API VideoAbility
{
public:
	VideoAbility(void);
	~VideoAbility(void);

public:
	/************************************************************************
	**概述：获取摄像机数量
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		摄像机数量
	*************************************************************************/
	const int getCameraNum() const;

	/************************************************************************
	**概述：添加一个摄像机能力
	**输入：
	*		p_objCameraAbility	摄像机能力
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void addCameraAbility(CameraAbility p_objCameraAbility);

	/************************************************************************
	**概述：查找一个摄像机能力
	**输入：
	*		p_nCameraId	摄像机ID号
	**输出：
	*		p_objCameraAbility 摄像机能力
	**返回值：
	*		true：查找成功
	*		false：未查找到摄像机能力
	*************************************************************************/
	bool findCameraAbility(const int p_nCameraId, CameraAbility & p_objCameraAbility) const;

	/************************************************************************
	**概述：获取摄像机能力列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		摄像机能力列表
	*************************************************************************/
	const vector<CameraAbility> &getCameraAbilityList() const;

private:
	vector<CameraAbility>	m_objCameraAbilityList;		//摄像机能力列表
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_VIDEO_ABILITY_
