#ifndef _DEVICEDATETIME_H_
#define _DEVICEDATETIME_H_

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

class SN_DLL_API DeviceDateTime
{
public:
	DeviceDateTime(void);
	~DeviceDateTime(void);

	DeviceDateTime(const DeviceDateTime& p_objDeviceDateTime);

public:
	/****************************************************************************
	概述：设置DVR设备的设备ID
	输入：
	p_pszDeviceId ：字符串，最大长度为CONST_MAXLENGTH_DEVICEID字节,
	结尾以‘\0’结束。
	输出：
	无
	返回值：
	true： 成功
	false：失败 
	功能：
	若输入p_pszDeviceId长度<=CONST_MAXLENGTH_DEVICEID，返回true，
	并保存到m_szDeviceId;
	若输入p_pszDeviceId为NULL或其长度>CONST_MAXLENGTH_DEVICEID，返回false
	*****************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/****************************************************************************
	概述：获取DVR设备的设备ID
	输入：
	无
	输出：
	无
	返回值：
	返回保存DVR设备ID的m_szDeviceId字符串指针。 
	功能：
	获取保存有DVR设备ID的字符串指针
	*****************************************************************************/
	const char* getDeviceId() const;

	void setTimeZone(const int p_nTimeZone);
	const int getTimeZone() const;

	void setDataFormat(const int p_nDataFormat);
	const int getDataFormat() const;

	void setTimeFormat(const int p_nTimeFormat);
	const int getTimeFormat() const;

	void setDTSOpenFlag(const byte p_bDTSOpenFlag);
	const byte getDTSOpenFlag() const;

	void setBeginXun(const int p_nszBeginXun);
	const int getBeginXun() const;

	void setBeginMonth(const int p_nBeginMonth);
	const int getBeginMonth() const;

	void setBeginWeekly(const int p_nBeginWeekly);
	const int getBeginWeekly() const;

	void setBeginWeekDays(const int p_nBeginWeekDays);
	const int getBeginWeekDays() const;

	bool setBeginTime(const char* p_pszBeginTime);
	const char* getBeginTime() const;

	void  setEndXun(const int p_nEndXun);
	const int getEndXun() const;

	void setEndMonth(const int p_nEndMonth);
	const int getEndMonth() const;

	void setEndWeekly(const int p_nEndWeekly);
	const int getEndWeekly() const;

	void setEndWeekDays(const int p_nEndWeekDays);
	const int getEndWeekDays() const;

	bool setEndTime(const char* p_pszEndTime);
	const char* getEndTime() const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objDeviceDateTime：设备主机网络信息
	**输出：
	*		无
	**返回值：
	*		设备主机网络信息
	**功能：
	************************************************************************/
	DeviceDateTime& operator =(const DeviceDateTime& p_objDeviceDateTime);

	/****************************************************************************
	**概述：
	*		定义“等于”操作符
	**输入：
	*		p_objDeviceDateTime：DeviceDateTime类的一个对象的引用。
	**输出：
	*		无
	**返回值：
	*		true:相等
	*		false：不相等
	**功能：
	*		两个DeviceDateTime类的对象，所有属性均相等，则说明这两个对象相等，返回true
	*如果有一个属性不等，则返回false。
	*****************************************************************************/
	bool operator == (const DeviceDateTime& p_objDeviceDateTime);

private:
	
	char		m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];						//DVR设备的设备ID

	int			m_nTimeZone;												//时区
	int			m_nDataFormat;												//日期格式
	int			m_nTimeFormat;												//时间格式

	byte		m_bDTSOpenFlag;											//夏令时开启标志

	int			m_nBeginXun;												//夏令时开始（一月中的上中下旬）
	int			m_nBeginMonth;												//夏令时开始月份
	int			m_nBeginWeekly;												//夏令时开始周（一月中的第几周）
	int			m_nBeginWeekDays;											//星期几
	char		m_szBeginTime[CONST_MAXLENGTH_TIME + 1];						//夏令时开始时间

	int			m_nEndXun;													//夏令时结束（一月中的上中下旬）
	int			m_nEndMonth;												//夏令时结束月份
	int			m_nEndWeekly;												//夏令时结束周（一月中的第几周）
	int			m_nEndWeekDays;												//星期几
	char		m_szEndTime[CONST_MAXLENGTH_TIME + 1];							//夏令时结束时间
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_DEVICEDATETIME_H_
