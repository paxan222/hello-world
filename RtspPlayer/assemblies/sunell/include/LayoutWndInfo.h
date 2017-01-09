#ifndef _LAYOUT_WND_INFO_H_
#define _LAYOUT_WND_INFO_H_

#include "SNPlatOS.h"
#include "DomainConst.h"

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

class SN_DLL_API LayoutWndInfo
{
public:
	LayoutWndInfo(void);
	~LayoutWndInfo(void);

	//拷贝构造函数
	LayoutWndInfo(const LayoutWndInfo& p_objLayoutWndInfo);

public:

	/****************************************************************************
	**概述：
	*		设置网络视频设备的唯一标识符
	**输入：
	*		p_pszDeviceId ：网络视频设备的唯一标识符，字符串，最大长度为CONST_MAXLENGTH_DEVICEID字节,
	*						结尾以‘\0’结束。
	**输出：
	*		无
	**返回值：
	*		true： 成功
	*		false：失败 
	**功能：
	*		若输入p_pszDeviceId长度<=CONST_MAXLENGTH_DEVICEID，返回true.
	*		若输入p_pszDeviceId为NULL或其长度>CONST_MAXLENGTH_DEVICEID，返回false.
	*****************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/****************************************************************************
	**概述：
	*		获取网络设备的唯一标识符
	**输入：
	*		无
	**输出：
	*		无
	*返回值：
	*		网络设备的唯一标识符，字符串类型 
	**功能：
	*		
	*****************************************************************************/
	const char* getDeviceId() const;

	/************************************************************************
	**概述：
	*		设置摄像机的ID号
	**输入：
	*		p_nCameraId ： 摄像机的ID号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*      
	************************************************************************/
	void setCameraId(int p_nCameraId);

	/************************************************************************
	**概述：
	*		获取摄像机的ID号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		摄像机的ID号
	**功能：
	*
	************************************************************************/
	const int getCameraId() const;

	/************************************************************************
	**概述：
	*		设置播放窗口的ID号
	**输入：
	*		p_nWndId ： 播放窗口的ID号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*      
	************************************************************************/
	void setPlayWndId(int p_nWndId);

	/************************************************************************
	**概述：
	*		获取播放窗口的ID号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		播放窗口的ID号
	**功能：
	*
	************************************************************************/
	const int getPlayWndId() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objRecordBackupParam ：录像备份参数对象
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	**************************************************************************/
	LayoutWndInfo& operator = (const LayoutWndInfo& p_objLayoutWndInfo);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objRecordBackupParam：LayoutWndInfo类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个LayoutWndInfo类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const LayoutWndInfo& p_objPlayLayout);

private:

	int m_nPlayWndId;

	char m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];

	int m_nCameraId;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_LAYOUT_WND_INFO_H_
