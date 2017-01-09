#ifndef _EXTERNDEVICEABILITY_H_
#define _EXTERNDEVICEABILITY_H_

#include <vector>
#include <string>
#include "ExternComInfo.h"
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
/*********************************************************************
外部串口能力：设备支持串口相关信息
**********************************************************************/

class SN_DLL_API ExternDeviceAbility
{
public:
	ExternDeviceAbility(void);
	~ExternDeviceAbility(void);
	
	/****************************************************************************
	**概述：
	*		设置外部串口信息列表
	**输入：
	*		p_vecExternComInfoList：外部串口信息列表
	**输出：
	*		无
	**返回值：
	*		无 
	**功能：
	*		
	*******************************************************************************/
	void setExternComInfoList(const std::vector<ExternComInfo>& p_vecExternComInfoList);

	/****************************************************************************
	**概述：
	*		获取外部串口信息列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		外部串口信息列表
	**功能：
	*		
	*******************************************************************************/
	const std::vector<ExternComInfo>& getExternComInfoList() const;

	/****************************************************************************
	**概述：
	*		设置波特率列表
	**输入：
	*		p_vecBaudRateList：波特率列表
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*******************************************************************************/
	void setBaudRateList(const std::vector<int>& p_vecBaudRateList);

	/****************************************************************************
	**概述：
	*		获取波特率列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		波特率列表
	**功能：
	*		
	*******************************************************************************/
	const std::vector<int>& getBaudRateList() const;

	/****************************************************************************
	**概述：
	*		设置数据位列表
	**输入：
	*		p_vecDataBitsList：数据位列表
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*******************************************************************************/
	void setDataBitsList(const std::vector<int>& p_vecDataBitsList);

	/****************************************************************************
	**概述：
	*		获取数据位列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		数据位列表
	**功能：
	*		
	*******************************************************************************/
	const std::vector<int>& getDataBitsList() const;

	/****************************************************************************
	**概述：
	*		设置停止位列表
	**输入：
	*		p_vecStopBitsList：停止位列表
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*******************************************************************************/
	void setStopBitsList(const std::vector<std::string>& p_vecStopBitsList);

	/****************************************************************************
	**概述：
	*		获取停止位列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		停止位列表
	**功能：
	*		
	*******************************************************************************/
	const std::vector<std::string>& getStopBitsList() const;

	/****************************************************************************
	**概述：
	*		设置奇偶校验位列表
	**输入：
	*		p_vecParityList：奇偶校验位列表
	**输出：
	*		无
	**返回值：
	*		无
	**功能：
	*		
	*******************************************************************************/
	void setParityList(const std::vector<std::string>& p_vecParityList);

	/****************************************************************************
	**概述：
	*		获取奇偶校验位列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		奇偶校验位列表
	**功能：
	*		
	*******************************************************************************/
	const std::vector<std::string>& getParityList() const;

	ExternDeviceAbility& operator =(const ExternDeviceAbility& p_objExternDeviceAbility);
private:
	std::vector<ExternComInfo>	m_objExternComInfoList;
	std::vector<int>			m_vecBaudRateList;
	std::vector<int>			m_vecDataBitsList;
	std::vector<std::string>	m_vecStopBitsList;
	std::vector<std::string>	m_vecParityList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
	#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif //_DEVICETYPE_H_
