#ifndef _NVR_DEVICE_ABILITY_
#define _NVR_DEVICE_ABILITY_

#include "MonitorAbility.h"
#include "LayoutAbility.h"
#include "DecodingAbility.h"
#include "FileSystemAbility.h"
#include "NetworkAbility.h"
#include <vector>
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

/************************************************************************
*	概述：NVR设备能力信息。
*	主要包含以下信息：录像支持的设备路数，监视器数量及类型，Layout类型
************************************************************************/
class SN_DLL_API NVRDeviceAbility
{
public:
	NVRDeviceAbility(void);
	~NVRDeviceAbility(void);

public:
	/************************************************************************
	*	概述：
	*			设置最多支持的视频路数
	*	输入：
	*			p_MaxChannelNumber	最多支持的视频路数
	*	输出：
	*			无
	*	返回值：
	*			无
	************************************************************************/
	void setMaxChannelNumber(int p_MaxChannelNumber);

	/************************************************************************
	*	概述：
	*			获取最多支持的视频路数
	*	输入：
	*			无
	*	输出：
	*			无
	*	返回值：
	*			最多支持的视频路数
	************************************************************************/
	int getMaxChannelNumber() const;

	/************************************************************************
	*	概述：
	*			设置支持的硬盘数
	*	输入：
	*			无
	*	输出：
	*			无
	*	返回值：
	*			
	************************************************************************/
	void setDiskNumber(int p_nDiskNumber);

	/************************************************************************
	*	概述：
	*			获取支持的硬盘数
	*	输入：
	*			无
	*	输出：
	*			无
	*	返回值：
	*			支持的硬盘数
	************************************************************************/
	int getDiskNumber() const;

	/************************************************************************
	*	概述：
	*			设置最大解码能力
	*	输入：
	*			p_nMaxDecodeAbility	最大解码能力
	*	输出：
	*			无
	*	返回值：
	*			无
	************************************************************************/
	void setMaxDecodeAbility(int p_nMaxDecodeAbility);

	/************************************************************************
	*	概述：
	*			获取最大解码能力
	*	输入：
	*			无
	*	输出：
	*			无
	*	返回值：
	*			最大解码能力
	************************************************************************/
	int getMaxDecodeAbility() const;

	/************************************************************************
	*	概述：
	*			设置最大回放路数
	*	输入：
	*			p_nMaxPlaybackChannelNumber	最大回放路数
	*	输出：
	*			无
	*	返回值：
	*			无
	************************************************************************/
	void setMaxPlaybackChannelNumber(int p_nMaxPlaybackChannelNumber);

	/************************************************************************
	*	概述：
	*			获取最大回放路数
	*	输入：
	*			无
	*	输出：
	*			无
	*	返回值：
	*			最大解码能力
	************************************************************************/
	int getMaxPlaybackChannelNumber() const;

	/************************************************************************
	*	概述：
	*			设置最大支持码流
	*	输入：
	*			p_nMaxBitRate	最大支持码流
	*	输出：
	*			无
	*	返回值：
	*			无
	************************************************************************/
	void setMaxBitRate(int p_nMaxBitRate);

	/************************************************************************
	*	概述：
	*			获取最大支持码流
	*	输入：
	*			无
	*	输出：
	*			无
	*	返回值：
	*			最大支持码流
	************************************************************************/
	int getMaxBitRate() const;

	/************************************************************************
	*	概述：
	*		设置监视器能力列表
	*	输入：
	*		p_objMonitorAbilityList	监视器能力列表
	*	输出：
	*		无
	*	返回值：
	*		无
	************************************************************************/
	void setMonitorAbilityList(const std::vector<MonitorAbility> &p_objMonitorAbilityList);

	/************************************************************************
	*	概述：
	*		获取监视器能力列表
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		监视器能力列表
	************************************************************************/
	const std::vector<MonitorAbility> &getMonitorAbilityList() const;

	/************************************************************************
	*	概述：
	*			设置Layout能力
	*	输入：
	*			p_objLayoutAbility	Layout能力
	*	输出：
	*			无
	*	返回值：
	*			无
	************************************************************************/
	void setLayoutAbility(const LayoutAbility& p_objLayoutAbility);

	/************************************************************************
	*	概述：
	*			获取Layout能力
	*	输入：
	*			无
	*	输出：
	*			无
	*	返回值：
	*			Layout能力
	************************************************************************/
	const LayoutAbility &getLayoutAbility() const;

	/************************************************************************
	*	概述：
	*			设置解码能力
	*	输入：
	*			p_objDecodingAbility	解码能力
	*	输出：
	*			无
	*	返回值：
	*			无
	************************************************************************/
	void setDecodingAbility(const DecodingAbility& p_objDecodingAbility);

	/************************************************************************
	*	概述：
	*			获取解码能力
	*	输入：
	*			无
	*	输出：
	*			无
	*	返回值：
	*			解码能力
	************************************************************************/
	const DecodingAbility &getDecodingAbility() const;

	/************************************************************************
	*	概述：
	*		获取文件系统格式能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		文件系统格式能力
	*	功能：
	*	
	*************************************************************************/
	const std::vector<FileSystemAbility> &getFileSystemAbilityList() const;

	/************************************************************************
	*	概述：
	*		获取文件系统格式能力
	*	输入：
	*		p_nDiskType		磁盘类型
	*	输出：
	*		p_objFileSystemAbility	文件系统格式能力
	*	返回值：
	*		
	*************************************************************************/
	bool getFileSystemAbility(int p_nDiskType, FileSystemAbility& p_objFileSystemAbility);

	/************************************************************************
	*	概述：
	*		设置文件系统格式能力
	*	输入：
	*		p_FileSystemAbilityList：文件系统格式能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*	功能：
	*	
	*************************************************************************/
	void setFileSystemAbilityList(const std::vector<FileSystemAbility> &p_FileSystemAbilityList);


	/************************************************************************
	*	概述：
	*			设置Network能力
	*	输入：
	*			p_objNetworkAbility	Network能力
	*	输出：
	*			无
	*	返回值：
	*			无
	************************************************************************/
	void setNetworkAbility(const NetworkAbility& p_objNetworkAbility);

	/************************************************************************
	*	概述：
	*			获取Network能力
	*	输入：
	*			无
	*	输出：
	*			无
	*	返回值：
	*			Network能力
	************************************************************************/
	const NetworkAbility &getNetworkAbility() const;

	NVRDeviceAbility& operator = (const NVRDeviceAbility& p_objNVRDeviceAbility);
private:
	int									m_MaxChannelNumber;			//支持的最大路数
	int									m_nDiskNumber;				//支持的硬盘个数
	int									m_nMaxDecodeAbility;		//最大解码能力，D1为单位
	int									m_nMaxBitRate;				//录像最大码流
	int									m_nMaxPlaybackChannelNumber;//最大回放路数
	std::vector<MonitorAbility>			m_objMonitorAbilityList;
	LayoutAbility						m_objLayoutAbility;
	DecodingAbility						m_objDecodingAbility;
	std::vector<FileSystemAbility>		m_objFileSystemAbilityList;	//磁盘文件系统格式能力	
	NetworkAbility						m_objNetworkAbility;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_NVR_DEVICE_ABILITY_
