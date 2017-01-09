#ifndef _AUDIOINFO_H_
#define _AUDIOINFO_H_

#include "SNPlatOS.h"


#if (defined(WIN32) || defined(_WIN32_WCE))
	#ifdef SN_DLL_EXPORTS
		#define AUDIOINFO_API __declspec(dllexport)
	#else
		#define AUDIOINFO_API __declspec(dllimport)
	#endif
#else
	#define AUDIOINFO_API
#endif

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

class AUDIOINFO_API AudioInfo
{
public:

	AudioInfo(void);

	~AudioInfo(void);

	AudioInfo(const AudioInfo& p_objAudioInfo);

public:

	void setFormatTag(const unsigned short p_nFormatTag);
	const unsigned short getFormatTag() const;

	void setChannels(const unsigned short p_nChannels);
	const unsigned short getChannels() const;

	void setSamplesPerSec(const unsigned long p_nSamplesPerSec);
	const unsigned long getSamplesPerSec() const;

	void setAvgBytesPerSec(const unsigned long p_nAvgBytesPerSec);
	const unsigned long getAvgBytesPerSec() const;

	void setBlockAlign(const unsigned short p_nBlockAlign);
	const unsigned short getBlockAligns() const;

	void setBitsPerSample(const unsigned short p_nBitsPerSample);
	const unsigned short getBitsPerSample() const;

	void setCBSize(const unsigned short p_nCBSize);
	const unsigned short getCBSize() const;

	void setEncodeType(const int p_nEncodeType);
	const int getEncodeType() const;

	AudioInfo & operator =(const AudioInfo &p_objAudioInfo);

private:

	unsigned short m_nFormatTag;		//格式标记

	unsigned short m_nChannels;			//声音通道数（声道）

	unsigned long m_nSamplesPerSec;		//每秒采样数

	unsigned long  m_nAvgBytesPerSec;	//

	unsigned short m_nBlockAlign;		//

	unsigned short m_nBitsPerSample;	//每次采样的大小

	unsigned short m_nCBSize;			//后面追加数据长度

	int m_nEncodeType;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_AudioInfo_H_
