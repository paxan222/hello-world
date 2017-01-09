#ifndef _AUDIO_ABILITY_
#define _AUDIO_ABILITY_

#include "SNPlatOS.h"
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

/************************************************************************
**概述：音频能力信息
*	主要包含以下信息：
*		是否支持对讲功能，音频输入方式列表，音频编码类型列表，音频解码类型列表。
************************************************************************/
class SN_DLL_API AudioAbility
{
public:
	AudioAbility(void);
	~AudioAbility(void);

public:
	/************************************************************************
	**概述：设置音频对讲有效标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		音频对讲有效标志	true表示支持对讲，false表示不支持对讲功能。
	*************************************************************************/
	void setInterPhoneFlag(const bool p_bInterPhoneFlag);

	/************************************************************************
	**概述：获取音频对讲有效标志
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		音频对讲有效标志	true表示支持对讲，false表示不支持对讲功能。
	*************************************************************************/
	const bool getInterPhoneFlag() const;

	/************************************************************************
	**概述：设置音频输入类型列表
	**输入：
	*		p_objAudioEncodeTypeList	音频输入类型列表
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setAudioInTypeList(const vector<int> &p_objAudioEncodeTypeList);

	/************************************************************************
	**概述：获取音频输入类型列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		音频输入类型列表
	*************************************************************************/
	const vector<int> &getAudioInTypeList() const;

	/************************************************************************
	**概述：设置音频编码类型列表
	**输入：
	*		p_objAudioEncodeTypeList	音频编码类型列表
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setAudioEncodeTypeList(const vector<int> &p_objAudioEncodeTypeList);

	/************************************************************************
	**概述：获取音频编码类型列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		音频编码类型列表
	*************************************************************************/
	const vector<int> &getAudioEncodeTypeList() const;

	/************************************************************************
	**概述：设置音频解码类型列表
	**输入：
	*		p_objAudioDecodeTypeList	音频解码类型列表
	**输出：
	*		无
	**返回值：
	*		无
	*************************************************************************/
	void setAudioDecodeTypeList(const vector<int> &p_objAudioDecodeTypeList);

	/************************************************************************
	**概述：获取音频解码类型列表
	**输入：
	*		无
	**输出：
	*		无
	**返回值：
	*		音频解码类型列表
	*************************************************************************/
	const vector<int> &getAudioDecodeTypeList() const;

private:
	bool				m_bInterPhoneFlag;				//音频对讲有效标志	true表示支持对讲，false表示不支持对讲功能。
	vector<int>			m_objAudioInTypeList;			//音频输入类型列表
	vector<int>			m_objAudioEncodeTypeList;		//音频编码类型列表
	vector<int>			m_objAudioDecodeTypeList;		//音频解码类型列表
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_AUDIO_ABILITY_
