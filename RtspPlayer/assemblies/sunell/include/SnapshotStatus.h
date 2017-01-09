#ifndef _SNAPSHOTSTATUS_H_
#define _SNAPSHOTSTATUS_H_

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

class SN_DLL_API SnapshotStatus
{
public:
	SnapshotStatus(void);
	~SnapshotStatus(void);

	SnapshotStatus(const int p_CameraId,const int p_Status);

	//拷贝构造函数
	SnapshotStatus(const SnapshotStatus& p_SnapshotStatus);

public:
	/************************************************************************
	**概述：
	*		设置摄像机编号
	**输入：
	*		p_nCameraId：摄像机编号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setCameraId(const int p_nCameraId);
	
	/************************************************************************
	*概述：
	*		获取摄像机编号
	*输入：
	*		无
	*输出：
	*		无
	*返回值：
	*		摄像机编号
	*功能：       
	*************************************************************************/
	const int getCameraId() const;

	/************************************************************************
	**概述：
	*		设置抓拍状态
	**输入：
	*		p_Status	抓拍状态(0:表示没有抓拍，非0值：表示当前正在抓拍的类型)
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	************************************************************************/
	void setStatus(const int p_Status);
	
	/************************************************************************
	*	概述：
	*		获取录制状态
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		录制状态
	*************************************************************************/
	const int getStatus() const;

	/************************************************************************
	*概述：
	*		赋值函数
	**输入：
	*		p_SnapshotStatus：视频通道状态信息
	**输出：
	*		无
	**返回值：
	*		视频通道状态信息
	**功能：
	*
	*************************************************************************/
	SnapshotStatus& operator =(const SnapshotStatus& p_SnapshotStatus);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_SnapshotStatus：SnapshotStatus类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个SnapshotStatus类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const SnapshotStatus& p_SnapshotStatus)  const;

private:
	int		m_CameraId;					//摄像机编号
	int		m_Status;					//录制状态
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_SNAPSHOTSTATUS_H_
