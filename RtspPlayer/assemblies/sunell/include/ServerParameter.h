#ifndef _SYSTEMSERVERINFO_H_
#define _SYSTEMSERVERINFO_H_
#include "DevicePort.h"

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

class  SN_DLL_API  ServerParameter
{
public:
	ServerParameter(void);
	~ServerParameter(void);


	void setDeviceID(const char *p_szDeviceID);

	const char *getDeviceID() const;

	void setDeviceName(const char *p_szDeviceName);

	const char *getDeviceName() const;


	void setClientBroadcastPort(unsigned short p_nClientBroadcastPort);

	unsigned short getClientBroadcastPort() const;

	void setWebServicePort(unsigned short p_nWebServicePort);

	unsigned short getWebServicePort() const;

	void setAlarmCenterPort(unsigned short p_nAlarmCenterPort);

	unsigned short getAlarmCenterPort() const;

	void setVersion(int p_nVersion);

	int getVersion() const;

	void setWorkingModeID(int p_nWorkingModeID);

	int getWorkingModeID() const;

	void setLanguageID(int p_nLanguageID);

	int getLanguageID() const;

	void setNTPStartFlag(bool p_bNTPStartFlag);

	bool getNTPStartFlag() const;

	void setDevicePort(const DevicePort &p_objDevicePort);
	const DevicePort& getDevicePort() const;


	bool operator == (const ServerParameter p_objSystemServerInfo);

private:
	
	char			m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];

	char			m_szDeviceName[CONST_MAXLENGTH_DEVICENAME + 1];

	int				m_nVersion;

	unsigned short	m_nClientBroadcastPort;

	unsigned short	m_nWebServicePort;

	unsigned short	m_nAlarmCenterPort;

	int				m_nWorkingModeID;
	int             m_nLanguageID;

	bool			m_btNTPStartFlag;
	
	DevicePort		m_objDevicePort;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif
