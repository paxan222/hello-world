#ifndef _REMOTE_PTZ_CONFIGURE_H_
#define _REMOTE_PTZ_CONFIGURE_H_

#include "DeviceInfoEx.h"
#include <vector>
#include "PTZPreset.h"
#include "PTZTourPoint.h"
#include "PTZTourEx.h"
#include "PTZScan.h"
#include "PTZTrack.h"

class RemoteUserDefineParamConfigure;

//该类针对UserDefineParamConfigure.xml文件进行的操作，用户自定义文件，该文件保存在摄像机/mnt/mtd/code/code_configure下面


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

class SN_DLL_API RemotePTZConfigure
{
public:
	RemotePTZConfigure(void);
	~RemotePTZConfigure(void);

public:
	/************************************************************************
	**概述：
	*		设置DeviceInfo
	**输入：
	*		DeviceInfo 设备信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		当用不带参数的构造函数构造类时，在open之前必须调用该方法
	*************************************************************************/
	void	setDeviceInfo(const DeviceInfo &p_objDeviceInfo);

	void	setDeviceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

	/************************************************************************
	**概述：
	*		设置要打开的云台对应的摄像机号
	**输入：
	*		p_nCameraID 摄像机号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		当用不带参数的构造函数构造类时，在open之前必须调用该方法
	*************************************************************************/
	void	setCameraID(const int p_nCameraID);

public:
	/************************************************************************
	**概述：
	*		设置RemotePTZ2和网络视频设备之间的网络传输协议
	**输入：
	*		p_nTransferProtocol：指定网络传输的协议
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	void setTransferProtocol(const int p_nTransferProtocol);

	/************************************************************************
	**概述：
	*		打开云台设备，并建立和网络视频设备之间的传输会话
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int open();

	/************************************************************************
	**概述：
	*		关闭RemotePTZ2和网络视频设备之间的传输会话。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	*************************************************************************/
	void close();


	//预置点操作相关
	/************************************************************************
	**概述：
	*		设置预置点名称。
	**输入：
	*		p_nPresetID： 预置点编号
	*		p_pszPresetName：预置点名称
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	*************************************************************************/
	int setPTZPresetName(int p_nPresetID, const char* p_pszPresetName,const int p_nPTZid=1);

	/************************************************************************
	**概述：
	*		获取预置点
	**输入：
	*		p_nPresetID： 预置点编号
	**输出：
	*		p_objPTZPreset：预置点
	**返回值：
	*		无
	**功能：
	*	
	*************************************************************************/
	int getPTZPreset(int p_nPresetID, PTZPreset& p_objPTZPreset,const int p_nPTZid=1);

	/************************************************************************
	**概述：
	*		获取所有预置点
	**输入：
	*		无
	**输出：
	*		p_objPTZPreset：预置点
	**返回值：
	*		无
	**功能：
	*	
	*************************************************************************/
	int getAllPTZPreset(std::vector<PTZPreset>& p_objPTZPresetList,const int p_nPTZid=1);

	/************************************************************************
	**概述：
	*		删除预置点
	**输入：
	*		p_nPresetID： 预置点编号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	*************************************************************************/
	int deletePTZPreset(int p_nPresetID,const int p_nPTZid=1);

	/************************************************************************
	**概述：
	*		删除所有预置点
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*	
	*************************************************************************/
	int deleteAllPTZPreset();

	
	//看守位相关
	/************************************************************************
	**概述：
	*		设置看守位
	**输入：
	*		p_nTypeValue：执行看守位的类型（1：预置位，2：扫描，3：自学习，4：巡游）。
			p_nIdValue：对应于p_nTypeValue类型的编号。
			p_nTimeValue：执行看守位时间，即云台最后一次执行操作的p_nTimeValue时间后执行看守位动作
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setPTZKeeper(int p_nKeeperType, int p_nPresetID, int p_nKeepTime);

	/************************************************************************
	**概述：
	*		获取看守位
	**输入：
	*		无
	**输出：
	*		p_nTypeValue：执行看守位的类型（1：预置位，2：扫描，3：自学习，4：巡游）。
			p_nIdValue：对应于p_nTypeValue类型的编号。
			p_nTimeValue：执行看守位时间，即云台最后一次执行操作的p_nTimeValue时间后执行看守位动作
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getPTZKeeper(int& p_nPresetType, int& p_nPresetID, int& p_nKeeperTime);

	/************************************************************************
	**概述：
	*		删除看守位
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int deletePTZKeeper();

	
	/************************************************************************
	**概述：
	*		设置看守位状态
	*		出厂值，默认为关闭状态，2：表示开启，O：表示关闭
	**输入：
	*		p_nKeeperState：看守位状态
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setPTZKeeperState(int p_nKeeperState);

	/************************************************************************
	**概述：
	*		获取看守位状态
	*		出厂值，默认为关闭状态，2：表示开启，O：表示关闭
	**输入：
	*		无
	**输出：
	*		p_nKeeperState：看守位状态
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getPTZKeeperState(int& p_nKeeperState);

	/************************************************************************
	**概述：
	*		删除看守位状态
	*		出厂值，默认为关闭状态，2：表示开启，O：表示关闭
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int deleteKeeperState();

	/************************************************************************
	**概述：
	*		设置巡游
	**输入：
	*		p_nTourID：巡游编号
	*		p_pszTourName：巡游名称
	**输出：
	*		p_objPTZTourPointList：巡游信息
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setPTZTour(const int p_nTourID, const char* p_pszTourName, const std::vector<PTZTourPoint>& p_objPTZTourPointList);

	/************************************************************************
	**概述：
	*		获取巡游
	**输入：
	*		p_nTourID：巡游编号
	**输出：
	*		p_objPTZTourEx：巡游
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getPTZTour(int p_nTourID, PTZTourEx& p_objPTZTourEx);

	/************************************************************************
	**概述：
	*		获取所有巡游
	**输入：
	*		无
	**输出：
	*		p_objPTZTourList：巡游列表
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getPTZAllTour(std::vector<PTZTourEx>& p_objPTZTourList);

	/************************************************************************
	**概述：
	*		巡游删除
	**输入：
	*		p_nValue：巡游编号（0-7）
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int deletePTZTour(const int p_nTourID);

	//
	/************************************************************************
	**概述：
	*		设置扫描
	**输入：
	*		p_nPresetID：扫描编号
			p_pszScanName：扫描名称
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setPTZScan(const int p_nScanID, const char* p_pszScanName);

	/************************************************************************
	**概述：
	*		获取扫描
	**输入：
	*		p_nPresetID：扫描编号
	**输出：
	*		p_objPTZScan：扫描
	**返回值：
	*		无
	**功能：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getPTZScan(const int p_nScanID, PTZScan& p_objPTZScan);

	/************************************************************************
	**概述：
	*		获取所有扫描
	**输入：
	*		无
	**输出：
	*		p_objPTZScanList：扫描列表
	**返回值：
	*		无
	**功能：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAllPTZScan(std::vector<PTZScan>& p_objPTZScanList);

	/************************************************************************
	**概述：
	*		删除扫描
	**输入：
	*		p_nPresetID：扫描编号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int deletePTZScan(const int p_nScanID);

	//轨迹
	/************************************************************************
	**概述：
	*		设置轨迹名称
	**输入：
	*		p_nTrackID：轨迹编号
	*		p_pszTrackName：轨迹名称
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setPTZTrack(const int p_nTrackID, const char* p_pszTrackName);

	/************************************************************************
	**概述：
	*		获取轨迹
	**输入：
	*		p_nTrackID：轨迹编号
	**输出：
	*		p_objPTZTrack：轨迹
	**返回值：
	*		无
	**功能：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。	
	*************************************************************************/
	int getPTZTrack(const int p_nTrackID, PTZTrack& p_objPTZTrack);

	/************************************************************************
	**概述：
	*		获取所有轨迹
	**输入：
	*		p_nTrackID：轨迹编号
	**输出：
	*		p_objPTZTrack：轨迹
	**返回值：
	*		无
	**功能：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getAllPTZTrack(std::vector<PTZTrack>& p_objPTZTrackList);

	/************************************************************************
	**概述：
	*		删除轨迹
	**输入：
	*		p_nTrackID：轨迹编号
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int deletePTZTrack(const int p_nTrackID);

	/************************************************************************
	**概述：
	*		获取清空PTZ配置文件
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int deleteAllParam();

	////////////////////////////////////////////////////////////


private:
	DeviceInfoEx		m_objDeviceInfoEx;			//设备信息
	int					m_nCameraID;				//云台对应的摄像机编号
	int					m_nTransferProtocol;

	RemoteUserDefineParamConfigure*  m_pobjRemoteUserDefineParamConfigure;
	
}_PACKED_1_;

	/**********************************************************************/
	#ifdef PRAGMA_PACK
		#ifdef WIN32  
			#pragma pack(pop)
		#endif
	#endif
	/**********************************************************************/

#endif //_RemotePTZEx_H_



