#ifndef _DEVICEAVSTREAMPARAM_H_
#define _DEVICEAVSTREAMPARAM_H_

#include "SNPlatOS.h"
#include "DomainConst.h"
#include "AVStreamParam.h"
#include <vector>

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

class SN_DLL_API DeviceAVStreamParam
{
public:
	DeviceAVStreamParam(void);
	~DeviceAVStreamParam(void);

	DeviceAVStreamParam(const DeviceAVStreamParam &p_objDeviceAVStreamParam);

public:

	/************************************************************************
	**概述：
	*		设置网络视频设备的唯一标识符
	**输入：
	*		p_pszDeviceId：网络视频设备的唯一标识符
	**输出：
	*		无
	**返回值：
	*		true ：设置成功
	*		false：设置失败
	**功能：
	*
	*************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);


	/************************************************************************
	**概述：
	*		获取网络视频设备的唯一标识符
	**输入：
	*		无
	**输出 ：
	*		无
	*返回值 ：
	*		网络视频设备的唯一标识符
	**功能：
	*    
	*************************************************************************/
	const char* getDeviceId() const;


	void setAVStreamParamList(const std::vector<AVStreamParam>& p_objAVStreamParamList);
	const std::vector<AVStreamParam>& getAVStreamParamList()const;

	/************************************************************************
	**概述：
	*		赋值函数
	**输入：
	*		p_objDeviceAVStreamParam ：流参数对象
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*
	************************************************************************/
	DeviceAVStreamParam& operator = (const DeviceAVStreamParam &p_objDeviceAVStreamParam);

private:
	char						m_szDeviceId[CONST_MAXLENGTH_UUID + 1];		
	std::vector<AVStreamParam>	m_objAVStreamParamList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_ENCODER_ABILITY_
