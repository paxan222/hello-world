#ifndef _REMOTEPTZCONTAINER_H_
#define _REMOTEPTZCONTAINER_H_

#include "DeviceInfoEx.h"
#include "PTZPreset.h"
#include "PTZTourPoint.h"
#include "PTZScan.h"
#include "PTZTrack.h"
#include "PTZTourEx.h"
#include "SNPlatOS.h"
#include <vector>


class RemotePTZEx;
class RemotePTZConfigure;

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


class SN_DLL_API RemotePTZContainer
{
public:
	RemotePTZContainer();
	/************************************************************************
	**概述：
	*		构造函数
	**输入：
	*		p_objDeviceInfo：指定要打开的网络视频设备
	*		p_nCameraID	   ：指定要操作的云台设备所对应的摄像机编号（也称通道channel）
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*************************************************************************/
	RemotePTZContainer(const DeviceInfo &p_objDeviceInfo, const int p_nCameraID);

	RemotePTZContainer(const DeviceInfoEx &p_objDeviceInfoEx, const int p_nCameraID);

	~RemotePTZContainer(void);
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
	*		设置RemotePTZContainer和网络视频设备之间的网络传输协议
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
	*		关闭RemotePTZContainer和网络视频设备之间的传输会话。
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

public:
	/************************************************************************
	**概述：
	*		停止云台正在进行的操作
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int stop(const int p_nPTZid = 1);

	/************************************************************************
	**概述：
	*		操作云台向上旋转
	**输入：
	*		p_nSpeedValue：云台向上旋转的速度值
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int rotateUp(const int p_nSpeedValue,const int p_nPTZid = 1);

	/************************************************************************
	**概述：
	*		操作云台向下旋转
	**输入：
	*		p_nSpeedValue：云台向下旋转的速度值
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int rotateDown(const int p_nSpeedValue,const int p_nPTZid = 1);

	/************************************************************************
	**概述：
	*		操作云台向左旋转
	**输入：
	*		p_nSpeedValue：云台向左旋转的速度值
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int rotateLeft(const int p_nSpeedValue,const int p_nPTZid = 1);

	/************************************************************************
	**概述：
	*		操作云台向左旋转
	**输入：
	*		p_nSpeedValue：云台向右旋转的速度值
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int rotateRight(const int p_nSpeedValue,const int p_nPTZid = 1);

	/************************************************************************
	**概述：
	*		操作云台向左上旋转
	**输入：
	*		p_nSpeedValue：云台向左上旋转的速度值
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int rotateLeftUp(const int p_nSpeedValue);
	int rotateLeftUp(const int p_nPanSpeedValue, const int p_nTiltSpeedValue,const int p_nPTZid = 1);

	/************************************************************************
	**概述：
	*		操作云台向左下旋转
	**输入：
	*		p_nSpeedValue：云台向左下旋转的速度值
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int rotateLeftDown(const int p_nSpeedValue);
	int rotateLeftDown(const int p_nPanSpeedValue, const int p_nTiltSpeedValue,const int p_nPTZid = 1);

	/************************************************************************
	**概述：
	*		操作云台向右上旋转
	**输入：
	*		p_nSpeedValue：云台向右上旋转的速度值
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int rotateRightUp(const int p_nSpeedValue);		
	int rotateRightUp(const int p_nPanSpeedValue, const int p_nTiltSpeedValue,const int p_nPTZid = 1);		

	/************************************************************************
	**概述：
	*		操作云台向右下旋转
	**输入：
	*		p_nSpeedValue：云台向右下旋转的速度值
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int rotateRightDown(const int p_nSpeedValue);
	int rotateRightDown(const int p_nPanSpeedValue, const int p_nTiltSpeedValue,const int p_nPTZid = 1);

	/************************************************************************
	**概述：
	*		360°水平旋转扫描
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int rotateHorizontalScan();

	/************************************************************************
	**概述：
	*		垂直扫描
	**输入：
	*		p_nSpeedValue：垂直扫描的速度值，速度应在0-7之间。
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int rotatePerpendicularScan(const int p_nSpeedValue);

	/************************************************************************
	**概述：
	*		对摄像机的镜头进行拉近操作
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int zoomIn(const int p_nPTZid = 1);

	/************************************************************************
	**概述：
	*		对摄像机的镜头进行拉远操作
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int zoomOut(const int p_nPTZid = 1);

	/************************************************************************
	**概述：
	*		设置摄像机的镜头拉近拉远的速度
	**输入：
	*		p_nSpeedValue：待设置的速度值，范围应在0-63之间，
	*                      如果速度值小于0则设置为0，大于63则设置为63.
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息.
	*************************************************************************/
	int setZoomSpeed(const int p_nSpeedValue,const int p_nPTZid = 1);

	/************************************************************************
	**概述：
	*		对摄像机的镜头进行远焦操作
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int focusFar();

	/************************************************************************
	**概述：
	*		对摄像机的镜头进行近焦操作
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int focusNear();

	/************************************************************************
	**概述：
	*		对摄像机的镜头进行光圈增大操作
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int irisIncrease();

	/************************************************************************
	**概述：
	*		对摄像机的镜头进行光圈减小操作
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int irisDecrease();

	/************************************************************************
	**概述：
	*		自动聚焦
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int runAutoFocus();	

	/************************************************************************
	**概述：
	*		自动光圈
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int runAutoIris();

	/************************************************************************
	**概述：
	*		云台的预置位设置
	**输入：
	*		p_nValue：			云台预置位编号
	*		p_strPresetName:	云台预置点名称		
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int presetSet(const int p_nValue, const char* p_pszPresetName,const int p_nPTZid = 1);

	//获取预置点
	int getPreset(const int p_nValue, PTZPreset& p_objPTZPreset,const int p_nPTZid = 1);
	
	//获取所有预置点
	int getAllPreset(std::vector<PTZPreset>& p_objPTZPresetList,const int p_nPTZid=1);

	/************************************************************************
	**概述：
	*		云台的预置位调用，云台旋转至预先设定的位置
	**输入：
	*		p_nValue：云台预置位编号
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int presetInvoke(const int p_nValue,const int p_nPTZid = 1);

	/************************************************************************
	**概述：
	*		云台的预置位删除
	**输入：
	*		p_nValue：云台预置位编号
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int presetRemove(const int p_nValue,const int p_nPTZid = 1);

	/************************************************************************
	**概述：
	*		启动扫描
	**输入：
	*		p_nValue：扫描编号
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int scan(const int p_nValue);

	/************************************************************************
	**概述：
	*		删除扫描
	**输入：
	*		p_nValue：扫描编号
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int scanRemove(const int p_nValue);

	/************************************************************************
	**概述：
	*		设置扫描起始点
	**输入：
	*		p_nValue：扫描起始点位置
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int scanSetStartPoint(const int p_nValue);

	/************************************************************************
	**概述：
	*		设置扫描结束点
	**输入：
	*		p_nValue：扫描结束点
	*		p_pszScanName:该条扫描的名称
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int scanSetStopPoint(const int p_nValue, const char* p_pszScanName);

	int getScan(const int p_nValue, PTZScan& p_objPTZScan);

	int getAllScan(std::vector<PTZScan>& p_objPTZScanList);


	/************************************************************************
	**概述：
	*		自学习开始点设置
	**输入：
	*		p_nValue：自学习编号
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setAutoStudyStartPoint(const int p_nValue);

	/************************************************************************
	**概述：
	*		自学习结束点设置
	**输入：
	*		p_nValue：自学习编号
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setAutoStudyEndPoint(const int p_nValue, const char* p_pszAutoStudyName);

	int getAutoStudy(const int p_nValue, PTZTrack& p_objPTZTrack);

	int getAllAutoStudy(std::vector<PTZTrack>& p_objPTZTrackList);

	/************************************************************************
	**概述：
	*		自学习调用
	**输入：
	*		p_nValue：自学习编号
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int runAutoStudy(const int p_nValue);

	/************************************************************************
	**概述：
	*		自学习删除
	**输入：
	*		p_nValue：自学习编号
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int autoStudyRemove(const int p_nValue);

	/************************************************************************
	**概述：
	*		三维智能定位,
	**输入：
	*		p_nX：定位位置水平坐标与视频图像中心点水平坐标的比值，定位位置位于中心点的右边用正数表示，
	*			  左边用负数表示。坐标原点为视频图像的左上角。
	*		p_nY：定位位置垂直坐标与视频图像中心点垂直坐标的比值，定位位置位于中心点的下边用正数表示，
	*			  上边用负数表示。
	*		p_nZoomRate：缩放倍数，放大用正数表示，缩小用负数表示
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int threeDimensionalPositioning(const int p_nX, const int p_nY, const int p_nZoomRate);

	/************************************************************************
	**概述：
	*		巡游开始点设置
	**输入：
	*		p_nValue：巡游编号（0-7）
	*		p_objPTZTourPointList:巡游预置点信息
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setTour(const int p_nTourID, const char* p_pszTourName, const std::vector<PTZTourPoint>& p_objPTZTourPointList);

	int setTourStartPoint(const int p_nValue);
	int addTourPoint(const PTZTourPoint& p_objPTZTourPoint);
	int setTourEndPoint(const int p_nValue, const char* p_pszTourName);


	int getTour(const int p_nTourID, PTZTourEx& p_objPTZTourEx);

	//获取所有的轮询
	int getAllTour(std::vector<PTZTourEx>& p_objPTZTourExList);

	/************************************************************************
	**概述：
	*		巡游调用
	**输入：
	*		p_nValue：预置点编号（0-7）
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int runTour(const int p_nValue);

	/************************************************************************
	**概述：
	*		巡游停止
	**输入：
	*		p_nValue：巡游编号（0-7）
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int stopTour(const int p_nValue);

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
	int deleteTour(const int p_nValue);

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
	int setKeeper(const int p_nTypeValue, const int p_nIdValue, const int p_nTimeValue);

	int getKeeper(int& p_nTypeValue, int& p_nIdValue, int& p_nTimeValue);

	/************************************************************************
	**概述：
	*		启动及关闭看守位
	**输入：
	*		p_nValue：0：关闭看守位，2：启动看守位，具体可查看PTZ_RUN_KEEPER枚举
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int runKeeper(const int p_nValue);

	int getKeeperState(int& p_nState);

	/************************************************************************
	**概述：
	*		云台复位操作
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int reset();

	/************************************************************************
	**概述：
	*		开启雨刷操作
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int runBrush();

	/************************************************************************
	**概述：
	*		停止雨刷操作
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int stopBrush();

	/************************************************************************
	**概述：
	*		开启灯操作
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int openLight();

	/************************************************************************
	**概述：
	*		关闭灯操作
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int closeLight();

	/************************************************************************
	**概述：
	*		红外灯功率控制
	**输入：
	*		p_nMode	 ：模式：0-自动；1-手动
	*		p_nNear	 ：近灯功率，范围为0-100
	*		p_nMiddle：中灯功率，范围为0-100
	*		p_nFar	 ：远灯功率，范围为0-100
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setInfrared(const int p_nMode, const int p_nNear, const int p_nMiddle, const int p_nFar);

	/************************************************************************
	**概述：
	*		红外灯功率控制
	**输入：
	*		p_nOpenMode	 ：开关模式：0-自动, 1-开, 2-关
	*		p_nBrightnessMode	 ：亮度模式：0-自动；1-手动
	*		p_nNear	 ：近灯功率，范围为0-100
	*		p_nMiddle：中灯功率，范围为0-100
	*		p_nFar	 ：远灯功率，范围为0-100
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setInfraredV2(const int p_nOpenMode, const int p_nBrightnessMode, const int p_nNear, const int p_nMiddle, const int p_nFar);

	int getInfraredV2(int& p_nOpenMode, int& p_nBrightnessMode, int& p_nNear, int& p_nMiddle, int& p_nFar);


	/************************************************************************
	**概述：
	*		设置当前位置为正北方向
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setNorthPostion();

	/************************************************************************
	**概述：
	*		获取当前PTZ的位置
	**输入：
	*		p_nPan		：水平度数
	*		p_nTilt		：垂直度数
	*		p_nZoom		：倍数
	*		p_nDirection：方位，具体可查看PTZ_DIRECTION枚举，方位值如下：
	*						EAST		= 0x00,
	*						SOUTHEAST	= 0x01,
	*						SOUTH		= 0x02,
	*						SOUTHWEST	= 0x03,
	*						WEST		= 0x04,
	*						NORTHWEST	= 0x05,
	*						NORTH		= 0x06,
	*						NORTHEAST	= 0x07
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int getPostion(float& p_nPan, float& p_nTilt, float& p_nZoom, int& p_nDirection,const int p_nPTZid = 1);

	/************************************************************************
	**概述：
	*		设置当前PTZ的位置
	**输入：
	*		p_nType		：设置位置类型，具体看查看SET_PTZ_POSION_TYPE枚举，值如下：
	*						POSTION_TYPE_PAN  = 0x01, //水平位置 
	*						POSTION_TYPE_TILE = 0x02, //垂直位置
	*						POSTION_TYPE_ZOOM = 0x04  //放大倍数
	*						如：要设置水平位置和垂直位置：p_nType = POSTION_TYPE_PAN|POSTION_TYPE_TILE
	*		p_nPan		：水平度数
	*		p_nTilt		：垂直度数
	*		p_nZoom		：倍数
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	**功能
	*		eg:如要设置水平位置100和垂直位置50，则函数为：
	*			setPostion(POSTION_TYPE_PAN|POSTION_TYPE_TILE，100.00， 50.00，0);
	*************************************************************************/
	int setPostion(const int p_nType, const float p_nPan, const float p_nTilt, const float p_nZoom,const int p_nPTZid = 1);

	/************************************************************************
	**概述：
	*		设置云台操作
	**输入：
	*		p_szPTZOperation：PTZ操作内容，格式为(操作Id,操作值)
	*		p_nDateLen：数据长度
	**输出：
	*		无
	**返回值：
	*		若方法成功，返回SN_SUCCESS；
	*		若方法失败则返回小于0的值，可以通过ErrorInfo::formatMessage来获取错误信息。
	*************************************************************************/
	int setPTZOperation(const char * p_szPTZOperation, int p_nDateLen);



	int presetSet(const int p_nValue,const int p_nPTZid = 1);
	int setAutoStudyEndPoint(const int p_nValue);

private:

	//拷贝构造函数
	RemotePTZContainer(const RemotePTZContainer& p_objObject)
	{
	}

	//赋值函数
	RemotePTZContainer& operator = (const RemotePTZContainer& p_objObject)
	{
		return *this;
	}

private:
	DeviceInfoEx			m_objDeviceInfoEx;			//设备信息
	int						m_nCameraID;				//云台对应的摄像机编号
	int						m_nTransferProtocol;

	RemotePTZEx*			m_pobjRemotePTZEx;
	RemotePTZConfigure*		m_pobjRemotePTZConfigure;

	std::vector<PTZTourPoint> m_objPTZTourPointList;

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTEPTZCONTAINER_H_
