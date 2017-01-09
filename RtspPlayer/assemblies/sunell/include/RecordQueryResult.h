#ifndef  _RECORD_QUERY_RESULT_
#define _RECORD_QUERY_RESULT_


#include "RecordTimeSegment.h"
#include "SNPlatOS.h"
#include "DomainConst.h"

#include <vector>
using namespace std;

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

class SN_DLL_API RecordQueryResult
{
public:
	RecordQueryResult();
	RecordQueryResult(const char* p_pszDeviceID, const char* p_szDeviceIP, int p_nCameraID);
	~RecordQueryResult(void);

	RecordQueryResult(const RecordQueryResult &p_RecordQueryResult);

public:

	/***********************************************************************
	**概述：
	*		设置设备Id。
	**输入：
	*		p_pszDeviceId：设备Id
	**输出：
	*		无
	**返回值：
	*		true	：设置成功
	*		false   ：设置失败
	**功能：
	************************************************************************/
	bool setDeviceID(const char* p_pszDeviceId);

	/************************************************************************
	**概述：
	*		获取设备Id
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		设备ID
	**功能：
	*
	***************************************************************************/
	const char* getDeviceID() const;


	/***********************************************************************
	**概述：
	*		设置设备IP地址
	**输入：
	*		p_strDeviceIP：设备IP地址
	**输出：
	*		无
	**返回值：
	*		true	：设置成功
	*		false   ：设置失败
	**功能：
	************************************************************************/
	bool setDeviceIP(const char* p_pszDeviceIP);

	/***********************************************************************
	**概述：
	*		获取设备IP地址
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		设备IP地址
	**功能：
	************************************************************************/
	const char* getDeviceIP() const;


	/************************************************************************
	**概述：
	*		设置设备通道号
	**输入：
	*		p_nCameraId	 ：设备通道号
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void setCameraID(int p_nCameraId);

	/************************************************************************
	**概述：
	*		获取设备通道号
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		设备通道号
	************************************************************************/
	const int getCameraID() const;


	/************************************************************************
	**概述：
	*		获取设备录像段列表信息
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		录像段列表信息
	************************************************************************/
	const vector<RecordTimeSegment>  &getRecordTimeSegment() const;

	/************************************************************************
	**概述：
	*		增加该设备的录像段信息
	**输入：
	*		p_objRecordTimeSegment	设备录像段信息
	**输出：
	*		无
	**返回值：
	*		无
	************************************************************************/
	void addRecordTimeSegment(const RecordTimeSegment &p_objRecordTimeSegment);
	void addNextDateSegmentList(const std::vector<RecordTimeSegment> &p_objRecordTimeSegmentList);
	
	void setRecordTimeSegment(const vector<RecordTimeSegment> &p_objRecordTimeSegmentList);

	
	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objRecordQueryResult ：录像查询结果信息
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	RecordQueryResult& operator = (const RecordQueryResult &p_objRecordQueryResult);

private:
	char								m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//设备id
	char								m_szDeviceIp[CONST_MAXLENGTH_IP + 1];					//设备IP地址
	int									m_nCameraID;											//摄像机编号
	vector<RecordTimeSegment>			m_objTimeSegmentList;									//时间段列表
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif  //_RECORD_QUERY_RESULT_
