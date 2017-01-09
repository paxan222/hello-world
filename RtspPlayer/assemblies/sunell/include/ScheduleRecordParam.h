#ifndef _SCHEDULERECORDPARAM_H_
#define _SCHEDULERECORDPARAM_H_

#include "DomainConst.h"
#include "ScheduleTimeParam.h"
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

class SN_DLL_API ScheduleRecordParam
{
public:
	ScheduleRecordParam(void);
	~ScheduleRecordParam(void);

	//拷贝构造函数
	ScheduleRecordParam(const ScheduleRecordParam& p_objScheduleRecordParam);

public:
	enum RuleType
	{
		RECORD_RULE_TYPE_ALWAYS = 1,			//总是录像
		RECORD_RULE_TYPE_SCHEDULE = 2			//计划录像
	};

public:
	/************************************************************************
	**概述：设置设备ID
	*
	**输入：
	*		p_pszDeviceId ：设备ID
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		设置设备ID
	************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**概述：获取设备ID
	*
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		设备ID
	**功能：       
	*		获取设备ID
	************************************************************************/
	const char* getDeviceId() const;


	/************************************************************************
	**概述：设置摄像机ID号
	*
	**输入：
	*		p_nCameraId ：摄像机ID号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		设置摄像机ID号
	************************************************************************/
	void setCameraId(const int p_nCameraId);

	/************************************************************************
	**概述：获取摄像机ID号
	*
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		摄像机ID
	**功能：       
	*		获取摄像机ID号
	************************************************************************/
	const int getCameraId() const;


	/************************************************************************
	**概述：设置是否录像标志
	*
	**输入：
	*		p_bIsEnableRecord ：true表示启动本地录像，false表示不启动本地录像
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		设置是否录像标志
	************************************************************************/
	void setEnableRecord(const bool p_bIsEnableRecord);

	/************************************************************************
	**概述：获取是否录像标志
	*
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		true表示启动本地录像，false表示不启动本地录像
	**功能：       
	*		获取是否录像标志
	************************************************************************/
	const bool getEnableRecord() const;


	/************************************************************************
	**概述：设置录像规则类型
	*
	**输入：
	*		p_nRuleType ：RECORD_RULE_TYPE_ALWAYS表示7*24小时录像
	*					  RECORD_RULE_TYPE_SCHEDULE表示计划录像
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		设置录像规则类型
	************************************************************************/
	void setScheduleRecordType(const int p_nScheduleRecordType);

	/************************************************************************
	**概述：获取录像规则类型
	*
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录像规则类型， RECORD_RULE_TYPE_ALWAYS表示7*24小时录像
	*					  RECORD_RULE_TYPE_SCHEDULE表示计划录像
	**功能：       
	*		获取录像规则类型
	************************************************************************/
	const  int getScheduleRecordType() const;


	/************************************************************************
	**概述：设置计划录像时间参数，当设置为录像规则为计划录像时需通过此方法设置
	*		计划录像参数
	*
	**输入：
	*		p_objScheduleTimeParam ：计划录像时间参数
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	void setScheduleTimeParam(const ScheduleTimeParam &p_objScheduleTimeParam);

	/************************************************************************
	**概述：获取计划录像时间参数，当设置为录像规则为计划录像时需通过此方法获取
	*		计划录像参数
	*
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		计划录像时间参数
	**功能：       
	*		
	************************************************************************/
	const ScheduleTimeParam& getScheduleTimeParam() const;


	/************************************************************************
	**概述：设置是否录制音频
	*
	**输入：
	*		p_bIsRecordAudio：录制音频标志，true表示录制音频，false表示不录制音频
	**输出：
	*		无
	**返回值：
	*		无
	**功能：       
	*		
	************************************************************************/
	void setEnableRecordAudio(const bool p_bIsRecordAudio);

	/************************************************************************
	**概述：获取是否录制音频
	*
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录制音频标志，true表示录制音频，false表示不录制音频
	**功能：       
	*		
	************************************************************************/
	const bool getEnableRecordAudio() const ;


	/****************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objScheduleRecordParam：计划录制参数对象
	**输出：
	*		无
	**返回值：
	*		赋值后的计划录制参数对象
	**功能：
	*		
	*****************************************************************************/
	ScheduleRecordParam & operator =(const ScheduleRecordParam &p_objScheduleRecordParam);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objScheduleRecordParam：ScheduleRecordParam类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true ：相等
	*		false：不相等
	**功能：
	*		两个ScheduleRecordParam类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*		如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const ScheduleRecordParam &p_objScheduleRecordParam) const;

	bool operator < (const ScheduleRecordParam &p_objScheduleRecordParam) const;

private:
	char						m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];		//设备ID

	int							m_nCameraId;									//摄像机ID号

	bool						m_bIsEnableRecord;								//开启录像标志 false:关闭录像；true开启录像

	int							m_nScheduleRecordType;							//录像规则类型

	ScheduleTimeParam			m_objScheduleTimeParam;							//计划录像时间

	bool						m_bIsEnableRecordAudio;							//是否录制音频
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_SCHEDULERECORDPARAM_H_
