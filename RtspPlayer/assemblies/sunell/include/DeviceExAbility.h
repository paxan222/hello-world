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
//�˴����ڿ����ļ������ֽڶ��룬����ʱ����ע�ͼ�������һ�𿽱���
//�������ġ�#ifdef PRAGMA_PACK������ҲҪһ�𿽱�������pragma pack��ջ��ջ��ƥ��
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
	**������
	*		������Ƶ����
	**���룺
	*		p_objVideoExAbility��	��Ƶ����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	************************************************************************/
	void setVideoExAbility(const VideoExAbility & p_objVideoExAbility);

	/************************************************************************
	**������
	*		��ȡ��Ƶ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ����
	**���ܣ�
	*	
	*************************************************************************/
	const VideoExAbility & getVideoExAbility() const;

	/************************************************************************
	**������
	*		������Ƶ����
	**���룺
	*		p_objAudioExAbility��	��Ƶ����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	************************************************************************/
	void setAudioExAbility(const AudioExAbility &p_objAudioExAbility);

	/************************************************************************
	**������
	*		��ȡ��Ƶ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ����
	**���ܣ�
	*	
	*************************************************************************/
	const AudioExAbility & getAudioExAbility() const;
	
	/************************************************************************
	**������
	*		����PTZ����
	**���룺
	*		p_objPTZAbility��	PTZ����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	************************************************************************/
	void setPTZAbility(const PTZAbility& p_objPTZAbility);

	/************************************************************************
	**������
	*		��ȡPTZ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		PTZ����
	**���ܣ�
	*	
	*************************************************************************/
	const PTZAbility& getPTZAbility() const;


	/************************************************************************
	**������
	*		��ȡ�ļ�ϵͳ��ʽ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�ļ�ϵͳ��ʽ����
	**���ܣ�
	*	
	*************************************************************************/
	const std::vector<FileSystemAbility> &getFileSystemAbilityList() const;
	bool getFileSystemAbility(int p_nDiskType, FileSystemAbility& p_objFileSystemAbility);

	/************************************************************************
	**������
	*		�����ļ�ϵͳ��ʽ����
	**���룺
	*		p_FileSystemAbilityList���ļ�ϵͳ��ʽ����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	*************************************************************************/
	void setFileSystemAbilityList(const std::vector<FileSystemAbility> &p_FileSystemAbilityList);

	/************************************************************************
	**������
	*		���ù���ģʽ����
	**���룺
	*		p_objWorkingModeAbility������ģʽ����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		���ù���ģʽ����
	*************************************************************************/
	void setWorkingModeAbility(const WorkingModeAbility& p_objWorkingModeAbility);

	/************************************************************************
	**������
	*		��ȡ����ģʽ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ģʽ����
	**���ܣ�
	*		��ȡ����ģʽ����
	*************************************************************************/
	const WorkingModeAbility& getWorkingModeAbility() const;

	/************************************************************************
	**������
	*		������������
	**���룺
	*		p_objLanguageAbility����������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		������������
	*************************************************************************/
	void setLanguageAbility(const LanguageAbility& p_objLanguageAbility);

	/************************************************************************
	**������
	*		��ȡ��������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��������
	**���ܣ�
	*		��ȡ��������
	*************************************************************************/
	const LanguageAbility& getLanguageAbility() const;

	/************************************************************************
	**������
	*		������������
	**���룺
	*		p_objNetWorkCardAbility����������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		������������
	*************************************************************************/
	void setNetworkAbility(const IPCNetworkAbility& p_objNetworkAbility);

	/************************************************************************
	**������
	*		��ȡ��������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��������
	**���ܣ�
	*		��ȡ��������
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
	**������
	*		����WIFI����
	**���룺
	*		p_objNetworkAbility��WIFI����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		����WIFI����
	*************************************************************************/
	void setWifiAbilityParam(const WifiAbilityParam& p_objWifiAbilityParam);

	/************************************************************************
	**������
	*		��ȡWIFI����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��������
	**���ܣ�
	*		��ȡWIFI����
	*************************************************************************/
	const WifiAbilityParam& getWifiAbilityParam() const;

	/************************************************************************
	**������
	*		������������
	**���룺
	*		p_objFisheyeAbility����������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		������������
	*************************************************************************/
	void setFisheyeAbility(const FisheyeAbility& p_objFisheyeAbility);
		/************************************************************************
	**������
	*		��ȡ��������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��������
	**���ܣ�
	*		��ȡ��������
	*************************************************************************/
	const FisheyeAbility& getFisheyeAbility() const;
private:
	VideoExAbility						m_objVideoExAbility;		//��Ƶ����
	AudioExAbility						m_objAudioExAbility;		//��Ƶ����
	PTZAbility							m_objPTZAbility;			//PTZ����
	std::vector<FileSystemAbility>		m_objFileSystemAbilityList;	//�����ļ�ϵͳ��ʽ����	
	WorkingModeAbility					m_objWorkingModeAbility;	//����ģʽ����
	LanguageAbility						m_objLanguageAbility;		//��������
	IPCNetworkAbility					m_objIPCNetworkAbility;		//��������
	//add by weihuiquam, 20140904
	PIRAlarmAbility						m_objPIRAlarmAbility;		//PIR��������
	WifiAbilityParam					m_objWifiAbilityParam;		//WIFI����
	FisheyeAbility						m_objFisheyeAbility;		//��������
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_DEVICEEXABILITY_
