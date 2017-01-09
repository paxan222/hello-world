#ifndef _AVSTREAMABILITY_H_
#define _AVSTREAMABILITY_H_

#include <vector>
#include "StreamEncodeAbility.h"
#include "AVStreamAttributeAbility.h"
#include "ROIAbility.h"
#include "DomainConst.h"
#include "SNPlatOS.h"

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

class SN_DLL_API AVStreamAbility
{
public:
	AVStreamAbility(void);
	~AVStreamAbility(void);

public:
	/************************************************************************
	*	概述：设置码流ID
	*	输入：
	*		p_nStreamId：	码流ID
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setStreamId(int p_nStreamId);

	/************************************************************************
	*	概述：获取码流ID
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		码流ID
	*************************************************************************/
	int getStreamId() const;

	/************************************************************************
	*	概述：设置码流属性参数
	*	输入：
	*		p_objAVStreamAttributeAbility：	码流属性参数
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setAVStreamAttributeAbility(const AVStreamAttributeAbility &p_objAVStreamAttributeParam);

	/************************************************************************
	*	概述：获取码流属性参数
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		码流属性参数
	*************************************************************************/
	const AVStreamAttributeAbility &getAVStreamAttributeAbility() const;

	/************************************************************************
	*	概述：设置支持的码流编码能力列表
	*	输入：
	*		p_objStreamEncodeAbilityList：	码流编码能力列表
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setStreamEncodeAbilityList(const vector<StreamEncodeAbility> & p_objStreamEncodeAbilityList);

	/************************************************************************
	*	概述：获取支持的码流编码能力列表
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		码流编码能力列表
	*************************************************************************/
	const vector<StreamEncodeAbility> & getStreamEncodeAbilityList() const;

	/************************************************************************
	*	概述：设置ROI能力
	*	输入：
	*		p_objROIAbility：	ROI能力
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setROIAbility(const ROIAbility & p_objROIAbility);

	/************************************************************************
	*	概述：获取ROI能力
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		ROI能力
	*************************************************************************/
	const ROIAbility & getROIAbility() const;

	bool findStreamEncodeAbility(int p_nEncoderType, StreamEncodeAbility & p_objStreamEncodeAbility) const;

	const bool getSupportROI()const;
	void setSupportROI(const bool p_SupportROI);
private:
	int							m_nStreamId;						//码流ID
	vector<StreamEncodeAbility>	m_objStreamEncodeAbilityList;		//码流编码能力列表
	AVStreamAttributeAbility    m_objAVStreamAttributeAbility;	//特殊码流能力
	bool						m_bSupportROI;
	ROIAbility					m_objROIAbility;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_AVSTREAMABILITY_H_
