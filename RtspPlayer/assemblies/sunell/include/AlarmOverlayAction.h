#ifndef _ALARMOVERLAYACTION_H_
#define _ALARMOVERLAYACTION_H_

#include "DomainConst.h"
#include "OSDInfo.h"
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

class SN_DLL_API AlarmOverlayAction
{
public:
	AlarmOverlayAction();
	~AlarmOverlayAction();

	//拷贝构造函数
	AlarmOverlayAction(const AlarmOverlayAction &p_objAlarmOverlayAction);

public:
	/***********************************************************************
	**概述：
	*		设置网络视频设备的设备ID
    **输入：
	*		p_pszDeviceId ：字符串，最大长度为CONST_MAXLENGTH_DEVICEID字节,
	*		结尾以‘\0’结束。
	**输出：
	*		无
	**返回值：
	*		true ： 成功
	*		false：失败 
	**功能：
	*		若输入p_pszDeviceId长度<=CONST_MAXLENGTH_DEVICEID，返回true，
	*		并保存到m_szDeviceId;
	*		若输入p_pszDeviceId为NULL或其长度>CONST_MAXLENGTH_DEVICEID，返回false
	**************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**概述：
	*		获取网络视频设备的设备ID
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		网络视频设备的设备ID
	**功能：
	*	
	*************************************************************************/
	const char* getDeviceId() const;


	/****************************************************************************
	**概述：
	*	设置摄像机的Id号
    **输入：
	*		p_nCamaraId：摄像机的Id号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	*****************************************************************************/
	void setCameraId(int p_nCamaraId);

	/****************************************************************************
	**概述：
	*		获得摄像机ID号
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		摄像机ID号
	**功能：
	*	
	*****************************************************************************/
	const int getCameraId() const;


	/****************************************************************************
	**概述：
	*		设置OSD信息
    **输入：
	*		p_objOSDInfo：OSDInfo类的一个对象的引用，该引用只读。
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	*****************************************************************************/
	void setOSDInfo(const OSDInfo& p_objOSDInfo);

	/****************************************************************************
	**概述：
	*		获得OSD信息
    **输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		OSD信息
	**功能：
	*	
	*****************************************************************************/
	const OSDInfo& getOSDInfo() const ;


	/************************************************************************
	**概述：
	*		设置报警事件类型
	**输入：
	*		p_nEventTypeId ：报警事件类型
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	void setEventTypeId(int p_nEventTypeId);

	/************************************************************************
	**概述：
	*		获取报警事件类型
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		报警事件类型
	**功能：
	*		
	************************************************************************/
	const int getEventTypeId() const;


	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objAlarmOverlayAction：报警水印行为对象
	**输出：
	*		无
	**返回值：
	*		赋值后的报警水印行为对象
	**功能：
	*		
	*****************************************************************************/
	AlarmOverlayAction& operator = (const AlarmOverlayAction& p_objAlarmOverlayAction);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objAlarmOverlayAction：AlarmOverlayAction类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true ：相等
	*		false：不相等
	**功能：
	*		两个AlarmOverlayAction类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const AlarmOverlayAction& p_objAlarmOverlayAction) const;

	bool operator < (const AlarmOverlayAction& p_objAlarmOverlayAction) const;

private:
	
	int			m_nEventTypeId;									//报警事件类型

	char		m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];		//设备ID
	
	int			m_nCameraId;									//摄像机ID号
	
	OSDInfo		m_objOSDInfo;									//水印信息
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_ALARMOVERLAYACTION_H_


