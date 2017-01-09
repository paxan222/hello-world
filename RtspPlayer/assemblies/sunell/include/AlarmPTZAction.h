#ifndef _ALARMPTZACTION_H_
#define _ALARMPTZACTION_H_

#include "DomainConst.h"
#include "SNPlatOS.h"

#ifndef byte
typedef unsigned char byte;
#endif

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

class SN_DLL_API AlarmPTZAction
{
public:

	AlarmPTZAction();

	~AlarmPTZAction();

	//拷贝构造函数
	AlarmPTZAction(const AlarmPTZAction &p_objAlarmPTZAction);
public:

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


	/***********************************************************************
	**概述：
	*		设置网络视频设备的设备ID
	**输入：
	*		p_pszDeviceId ：字符串，最大长度为CONST_MAXLENGTH_DEVICEID字节,
	*		结尾以‘\0’结束。
	**输出：
	*		无
	**返回值：
	*		true ：成功
	*		false：失败 
	**功能：
	*		若输入p_pszDeviceId长度<=CONST_MAXLENGTH_DEVICEID，返回true，
	*		并保存到m_szDeviceId;
	*		若输入p_pszDeviceId为NULL或其长度>CONST_MAXLENGTH_DEVICEID，返回false
	************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**概述：
	*		获取网络视频设备的设备ID
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		网络视频设备的设备ID。 
	**功能：
	*	获取保存有DVR设备ID的字符串指针
	*************************************************************************/
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
	*		设置串口编号
	**输入：
	*		p_nComId ：串口编号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*       
	************************************************************************/
	void setComId(const int p_nComId);

	/************************************************************************
	**概述：
	*		获取串口编号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		串口编号
	**功能：
	* 	
	*************************************************************************/
	const int getComId() const;


	/************************************************************************
	**概述：
	*		设置云台编号
	**输入：
	*		p_nPtzId ：云台编号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*       
	************************************************************************/
	void setPtzId(const int p_nPtzId);

	/************************************************************************
	**概述：
	*		获取云台编号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		云台编号
	**功能：
	* 	
	*************************************************************************/
	const int getPtzId() const;


	/************************************************************************
	*概述：
	*		设置云台命令
	*输入：
	*		p_pszDeviceId ：云台命令, 参数内容，格式为(id1,value1)(id2,value2)……
	*		p_nCmdLen     ：云台命令长度
	*输出：
	*		无
	*返回值：
	*		true ：成功
	*		false：失败 
	*功能：
	*		若输入p_nCmdLen长度<=CONST_MAXLENTH_PTZOPERATION_CMD，返回true；
	*		若输入p_pbtPtzOperationCmd为NULL或p_nCmdLen>CONST_MAXLENTH_PTZOPERATION_CMD，返回false
	*************************************************************************/
	bool setPtzOperationCmd(const char* p_pbtPtzOperationCmd, const int p_nCmdLen);

	/************************************************************************
	**概述：
	*		获取云台命令
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		云台命令
	**功能：
	* 	
	*************************************************************************/
	const char* getPtzOperationCmd() const;

	/************************************************************************
	**概述：
	*		获取云台命令长度
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		云台命令长度
	**功能：
	* 	
	*************************************************************************/
	const int getPtzOperationCmdLen() const;


	/************************************************************************
	**概述：
	*		设置保留位
	**输入：
	*		p_nReserve ：保留位
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*       
	************************************************************************/
	void setReserve(const int p_nReserve);

	/************************************************************************
	**概述：
	*		获取保留位
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		保留位
	**功能：
	* 	
	*************************************************************************/
	const int getReserve() const;


	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objAlarmPTZAction：报警云台行为对象
	**输出：
	*		无
	**返回值：
	*		赋值后的报警云台行为对象
	**功能：
	*		
	*****************************************************************************/
	AlarmPTZAction& operator = (const AlarmPTZAction& p_objAlarmPTZAction);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objAlarmPTZAction：AlarmPTZAction类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true ：相等
	*		false：不相等
	**功能：
	*		两个AlarmPTZAction类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const AlarmPTZAction& p_objAlarmPTZAction) const;

	bool operator < (const AlarmPTZAction& p_objAlarmPTZAction) const;

private:

	int			m_nEventTypeId;											//报警事件类型

	char		m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//设备ID

	int			m_nCameraId;											//摄像机的ID号

	int			m_nComId;												//串口ID号

	int			m_nPtzId;												//云台设备的ID号

	char		m_btPtzOperationCmd[CONST_MAXLENTH_PTZOPERATION_CMD+1];	//云台操作命令
	int			m_nPtzOperationCmdLen;									//云台操作命令长度

	int			m_nReserve;												//保留位

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_ALARMPTZACTION_H_

