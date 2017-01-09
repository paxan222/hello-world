#ifndef _ILIVERECORDER_H_
#define _ILIVERECORDER_H_


class ILiveRecorder
{

public:
	enum
	{
		RECORD_RUNNING = 1,
		RECORD_STOP  = 2
	};

public:

	ILiveRecorder() {};

	virtual ~ILiveRecorder(){};
	
public:

	/************************************************************************
	**概述：
	*		设置录像文件的文件名。
	**输入：
	*		p_pszFileName：录像文件的文件名，包含完整路径，如:“C:\record\sample.ts”
	**输出：
	*		无
	**返回值：
	*		无。
	*************************************************************************/
	virtual void setRecordFile(const char * p_pszFileName) = 0; 


	/************************************************************************
	**概述：
	*		设置录像文件类型。
	**输入：
	*		p_nFileFormat：录像文件类型（1：TS流，4：PS流,具体可查看RecorderParam.h定义）
	**输出：
	*		无
	**返回值：
	*		无。
	*************************************************************************/
	virtual void setRecordFileFormat(const int p_nFileFormat) = 0;

	/************************************************************************
	**概述：
	*		设置录像文件头。
	**输入：
	*		p_pszRecordFileHead：录像文件头
	*		p_nRecordFileHeadLength：录像文件头长度
	**输出：
	*		无
	**返回值：
	*		无。
	*************************************************************************/
	virtual void setRecordFileHead(const char* p_pszRecordFileHead, const int p_nRecordFileHeadLength) = 0;


	/************************************************************************
	**概述：
	*		设置单个录像文件的占用最大磁盘空间大小。
	**输入：
	*		p_nMaxSize：最大磁盘空间大小，以M为单位，默认为128M。
	**输出：
	*		无
	**返回值：
	*		无。
	*************************************************************************/
	//virtual void setFileMaxSize(const int p_nMaxSize) = 0;

	/************************************************************************
	**概述：
	*		启动音视频录制。
	**输入：
	*		无
	**输出：
	*		无。
	**返回值：
	*		启动音视频录制成功返回true
	*		失败返回false。
	*************************************************************************/
	virtual bool startRecord() = 0;

	/************************************************************************
	**概述：
	*		关闭音视频录制。
	**输入：
	*		无
	**输出：
	*		无。
	**返回值：
	*		无
	*************************************************************************/
	virtual void stopRecord() = 0;

	/************************************************************************
	**概述：
	*		获取当前音视频录制的状态。
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		当前音视频录制的状态，其值由ILiveRecorder提供的录制状态常量提供，包括：
	*		ILiveRecorder::RECORD_RUNNING正在录制
	*		ILiveRecorder::RECORD_STOP停止录制。
	**功能：
	*		
	*************************************************************************/
	virtual int getRecordStatus() = 0;

	virtual void setNotifyWindow(const unsigned int &p_nNotifyWnd,const unsigned int& p_nMessageID, const void * p_pParam) = 0;

};

#endif
