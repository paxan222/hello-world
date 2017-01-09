#ifndef _DEVICEEXABILITY_
#define _DEVICEEXABILITY_

#include "PTZAbility.h"
#include "VideoExAbility.h"
#include "AudioExAbility.h"
#include "FileSystemAbility.h"
#include "WorkingModeAbility.h"
#include "LanguageAbility.h"
#include "SNPlatOS.h"
#include "IPCNetworkAbility.h"
#include "PIRAlarmAbility.h"
#include "WifiAbilityParam.h"
#include "FisheyeAbility.h"
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

class SN_DLL_API DeviceExAbility
{
public:
	DeviceExAbility(void);
	~DeviceExAbility(void);

public:
	/************************************************************************
	**概述：
	*		设置视频能力
	**输入：
	*		p_objVideoExAbility：	视频能力
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	************************************************************************/
	void setVideoExAbility(const VideoExAbility & p_objVideoExAbility);

	/************************************************************************
	**概述：
	*		获取视频能力
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		视频能力
	**功能：
	*	
	*************************************************************************/
	const VideoExAbility & getVideoExAbility() const;

	/************************************************************************
	**概述：
	*		设置音频能力
	**输入：
	*		p_objAudioExAbility：	音频能力
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	************************************************************************/
	void setAudioExAbility(const AudioExAbility &p_objAudioExAbility);

	/************************************************************************
	**概述：
	*		获取音频能力
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		音频能力
	**功能：
	*	
	*************************************************************************/
	const AudioExAbility & getAudioExAbility() const;
	
	/************************************************************************
	**概述：
	*		设置PTZ能力
	**输入：
	*		p_objPTZAbility：	PTZ能力
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	************************************************************************/
	void setPTZAbility(const PTZAbility& p_objPTZAbility);

	/************************************************************************
	**概述：
	*		获取PTZ能力
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		PTZ能力
	**功能：
	*	
	*************************************************************************/
	const PTZAbility& getPTZAbility() const;


	/************************************************************************
	**概述：
	*		获取文件系统格式能力
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		文件系统格式能力
	**功能：
	*	
	*************************************************************************/
	const std::vector<FileSystemAbility> &getFileSystemAbilityList() const;
	bool getFileSystemAbility(int p_nDiskType, FileSystemAbility& p_objFileSystemAbility);

	/************************************************************************
	**概述：
	*		设置文件系统格式能力
	**输入：
	*		p_FileSystemAbilityList：文件系统格式能力
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	*************************************************************************/
	void setFileSystemAbilityList(const std::vector<FileSystemAbility> &p_FileSystemAbilityList);

	/************************************************************************
	**概述：
	*		设置工作模式能力
	**输入：
	*		p_objWorkingModeAbility：工作模式能力
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		设置工作模式能力
	*************************************************************************/
	void setWorkingModeAbility(const WorkingModeAbility& p_objWorkingModeAbility);

	/************************************************************************
	**概述：
	*		获取工作模式能力
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		工作模式能力
	**功能：
	*		获取工作模式能力
	*************************************************************************/
	const WorkingModeAbility& getWorkingModeAbility() const;

	/************************************************************************
	**概述：
	*		设置语言能力
	**输入：
	*		p_objLanguageAbility：语言能力
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		设置语言能力
	*************************************************************************/
	void setLanguageAbility(const LanguageAbility& p_objLanguageAbility);

	/************************************************************************
	**概述：
	*		获取语言能力
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		语言能力
	**功能：
	*		获取语言能力
	*************************************************************************/
	const LanguageAbility& getLanguageAbility() const;

	/************************************************************************
	**概述：
	*		设置网卡能力
	**输入：
	*		p_objNetWorkCardAbility：网卡能力
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		设置网卡能力
	*************************************************************************/
	void setNetworkAbility(const IPCNetworkAbility& p_objNetworkAbility);

	/************************************************************************
	**概述：
	*		获取网卡能力
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		网卡能力
	**功能：
	*		获取网卡能力
	*************************************************************************/
	const IPCNetworkAbility& getNetworkAbility() const;

	DeviceExAbility & operator=(const DeviceExAbility &p_objDeviceExAbility);

	/************************************************************************/
	/* add: weihuiquam
	/* why: for PIR Alarm
	/* date:2014.09.04
	/************************************************************************/
	//set PIR Ability
	void setPIRAlarmAbility(const PIRAlarmAbility& p_objPIRAlarmAbility);
	//get PIR Ability
	const PIRAlarmAbility& getPIRAlarmAbility() const;

	/************************************************************************
	**概述：
	*		设置WIFI能力
	**输入：
	*		p_objNetworkAbility：WIFI能力
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		设置WIFI能力
	*************************************************************************/
	void setWifiAbilityParam(const WifiAbilityParam& p_objWifiAbilityParam);

	/************************************************************************
	**概述：
	*		获取WIFI能力
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		网卡能力
	**功能：
	*		获取WIFI能力
	*************************************************************************/
	const WifiAbilityParam& getWifiAbilityParam() const;

	/************************************************************************
	**概述：
	*		设置鱼眼能力
	**输入：
	*		p_objFisheyeAbility：鱼眼能力
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		设置鱼眼能力
	*************************************************************************/
	void setFisheyeAbility(const FisheyeAbility& p_objFisheyeAbility);
		/************************************************************************
	**概述：
	*		获取鱼眼能力
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		鱼眼能力
	**功能：
	*		获取鱼眼能力
	*************************************************************************/
	const FisheyeAbility& getFisheyeAbility() const;
private:
	VideoExAbility						m_objVideoExAbility;		//视频能力
	AudioExAbility						m_objAudioExAbility;		//音频能力
	PTZAbility							m_objPTZAbility;			//PTZ能力
	std::vector<FileSystemAbility>		m_objFileSystemAbilityList;	//磁盘文件系统格式能力	
	WorkingModeAbility					m_objWorkingModeAbility;	//工作模式能力
	LanguageAbility						m_objLanguageAbility;		//语言能力
	IPCNetworkAbility					m_objIPCNetworkAbility;		//网卡能力
	//add by weihuiquam, 20140904
	PIRAlarmAbility						m_objPIRAlarmAbility;		//PIR报警能力
	WifiAbilityParam					m_objWifiAbilityParam;		//WIFI能力
	FisheyeAbility						m_objFisheyeAbility;		//鱼眼能力
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_DEVICEEXABILITY_
