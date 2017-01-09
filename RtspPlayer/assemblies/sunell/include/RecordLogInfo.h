#ifndef _RECORDLOGINFO_H_
#define _RECORDLOGINFO_H_

#include "DomainConst.h"
#include "const.h"
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

class SN_DLL_API RecordLogInfo
{
public:
	enum
	{
		LOG_TYPE_SUCCESSFUL = 1,
		LOG_TYPE_FAILED
	};

public:
	RecordLogInfo();
	~RecordLogInfo();

public:
	void setId(const int p_nId);

	const int getId() const;

	bool setDeviceId(const char *p_pszDeviceId);

	const char* getDeviceId() const;

	bool setDeviceName(const char *p_pszDeviceName);

	const char* getDeviceName() const;

	void setCameraId(const int p_nCameraId);

	const int getCameraId() const;

	bool setCameraName(const char *p_pszCameraName);

	const char* getCameraName() const;

	bool setDeviceIp(const char * p_pszDeviceIp);

	const char * getDeviceIp() const;

	void setDeviceType(const int p_nDeviceType);

	const int getDeviceType() const;

	void setLogTime(const unsigned long p_nLogTime);

	const unsigned long getLogTime() const;

	void setLogType(const int p_nLogType);

	const int getLogType() const;

	bool setLogInformation(const char * p_pszLogInformation);

	const char * getLogInformation() const;


	RecordLogInfo(const RecordLogInfo &p_objRecordLogInfo);

	const RecordLogInfo& operator=(const RecordLogInfo &p_objRecordLogInfo);

private:
	int m_nId;	//数据库表中的Id

	char m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];	

	char m_szDeviceName[CONST_MAXLENGTH_DEVICENAME + 1]; 

	int	 m_nDeviceType;

	int m_nCameraId;

	char m_szCameraName[CONST_MAXLENGTH_CAMERA_NAME + 1];

	char m_szDeviceIp[CONST_MAXLENGTH_IP + 1];

	unsigned long m_nLogTime;

	int m_nLogType;

	char m_szLogInformation[CONST_MAXLENGTH_LOG_DATA];
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_RecordLogInfo_H_
