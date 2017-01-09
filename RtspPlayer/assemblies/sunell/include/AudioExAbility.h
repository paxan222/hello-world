#ifndef _AUDIO_EX_ABILITY_
#define _AUDIO_EX_ABILITY_

#include "SNPlatOS.h"
#include <vector>
#include "AudioInType.h"
#include "AudioOutType.h"
#include "AudioEncodeType.h"
#include "AudioDecodeType.h"
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
*	概述：音频能力信息
*	主要包含以下信息：
*		是否支持对讲功能，音频输入方式列表，音频编码类型列表，音频解码类型列表。
************************************************************************/
class SN_DLL_API AudioExAbility
{
public:
	AudioExAbility(void);
	~AudioExAbility(void);

public:
	/************************************************************************
	*	概述：设置音频对讲有效标志
	*	输入：
	*		p_bInterPhoneFlag	音频对讲有效标志	true表示支持对讲，false表示不支持对讲功能。
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setInterPhoneFlag(const bool p_bInterPhoneFlag);

	/************************************************************************
	*	概述：获取音频对讲有效标志
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		音频对讲有效标志	true表示支持对讲，false表示不支持对讲功能。
	*************************************************************************/
	const bool getInterPhoneFlag() const;

	/************************************************************************
	*	概述：设置音频输入有效标志
	*	输入：
	*		p_bAudioInFlag	音频输入有效标志	true表示支持音频输入，false表示不支持音频输入功能。
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setAudioInFlag(const bool p_bAudioInFlag);

	/************************************************************************
	*	概述：获取音频输入有效标志
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		音频输入有效标志	true表示支持音频输入，false表示不支持音频输入功能。
	*************************************************************************/
	const bool getAudioInFlag() const;

	/************************************************************************
	*	概述：设置音频输入类型列表
	*	输入：
	*		p_objAudioEncodeTypeList	音频输入类型列表
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setAudioInTypeList(const vector<AudioInType> &p_objAudioEncodeTypeList);

	/************************************************************************
	*	概述：获取音频输入类型列表
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		音频输入类型列表
	*************************************************************************/
	const vector<AudioInType> &getAudioInTypeList() const;


	/************************************************************************
	*	概述：设置音频输出有效标志
	*	输入：
	*		p_bAudioOutFlag	音频输入有效标志	true表示支持音频输出，false表示不支持音频输出功能。
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setAudioOutFlag(const bool p_bAudioOutFlag);

	/************************************************************************
	*	概述：获取音频输出有效标志
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		音频输出有效标志	true表示支持音频输出，false表示不支持音频输出功能。
	*************************************************************************/
	const bool getAudioOutFlag() const;

	/************************************************************************
	*	概述：设置音频输出类型列表
	*	输入：
	*		p_objAudioOutTypeList	音频输出类型列表
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setAudioOutTypeList(const vector<AudioOutType> &p_objAudioOutTypeList);

	/************************************************************************
	*	概述：获取音频输出类型列表
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		音频输出类型列表
	*************************************************************************/
	const vector<AudioOutType> &getAudioOutTypeList() const;

	/************************************************************************
	*	概述：设置音频编码类型列表
	*	输入：
	*		p_objAudioEncodeTypeList	音频编码类型列表
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setAudioEncodeTypeList(const vector<AudioEncodeType> &p_objAudioEncodeTypeList);

	/************************************************************************
	*	概述：获取音频编码类型列表
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		音频编码类型列表
	*************************************************************************/
	const vector<AudioEncodeType> &getAudioEncodeTypeList() const;

	/************************************************************************
	*	概述：设置音频解码类型列表
	*	输入：
	*		p_objAudioDecodeTypeList	音频解码类型列表
	*	输出：
	*		无
	*	返回值：
	*		无
	*************************************************************************/
	void setAudioDecodeTypeList(const vector<AudioDecodeType> &p_objAudioDecodeTypeList);

	/************************************************************************
	*	概述：获取音频解码类型列表
	*	输入：
	*		无
	*	输出：
	*		无
	*	返回值：
	*		音频解码类型列表
	*************************************************************************/
	const vector<AudioDecodeType> &getAudioDecodeTypeList() const;

	AudioExAbility& operator =(const AudioExAbility & p_objAudioExAbility);

private:
	bool				m_bInterPhoneFlag;				//音频对讲有效标志	true表示支持对讲，false表示不支持对讲功能。
	bool				m_bAudioInFlag;					//音频输入有效标志	true表示支持音频输入，false表示不支持音频输入功能。
	vector<AudioInType>	m_objAudioInTypeList;			//音频输入类型列表
	bool				m_bAudioOutFlag;				//音频输出有效标志	true表示支持音频输出，false表示不支持音频输出功能。
	vector<AudioOutType>	m_objAudioOutTypeList;		//音频输出类型列表

	vector<AudioEncodeType> m_objAudioEncodeTypeList;	//音频编码类型列表
	vector<AudioDecodeType>	m_objAudioDecodeTypeList;	//音频解码类型列表
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_AUDIO_ABILITY_
