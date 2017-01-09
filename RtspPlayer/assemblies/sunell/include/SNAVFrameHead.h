#ifndef _SN_AV_FRAME_HEAD_H_
#define _SN_AV_FRAME_HEAD_H_

#include "SNPlatOS.h"

#if defined( WIN32 )
typedef __int64				INT64;
#else
typedef long long			INT64;
#endif

#define SN_START_CODE		"s~u!n@el%l"
#define LENGTH_START_CODE	10

#if defined( WIN32 )
typedef __int64				INT64;
#else
typedef long long			INT64;
#endif


//#ifdef WIN32
#if (defined(WIN32)||defined(_WIN32_WCE))
#define arm_pack
#else 
#define arm_pack __attribute__((packed));
#endif

struct ST_SN_AV_FRAME_HEAD
{
	char				m_szStartCode[LENGTH_START_CODE];	//起始标志,每帧数据前均存储该标志位
	unsigned int		m_nSequenceId;		// 帧序列号
	unsigned int		m_nHigh32;			// 时间戳的高32位
	unsigned int		m_nLow32;			// 时间戳的低32位
	unsigned int		m_nFrameLength;		// 帧长度
	unsigned short		m_nBitRate;			// 码率
	unsigned char		m_nFrameType;		// 帧类型 (1表示I帧, 2表示P帧, 3表示B帧, 0表示未知类型)
	unsigned char		m_nImageFormatId;	// 当前图像格式
	unsigned char		m_nVideoSystem;		// 当前视频制式
	unsigned char		m_nStreamFormat;	// 流格式
	unsigned char		m_nESStreamType;	// 原始流类型
	unsigned char		m_nEncodeType;		// 编码类型
	unsigned char		m_nFrameRate;		// 帧率
	unsigned char		m_nTimezone;			// 时区
	unsigned short		m_nDaylightSavingTime;				//夏令时
	unsigned short		m_nCheckNum;		//校验和
}arm_pack;


class SN_DLL_API SNAVFrameHead
{
public:
	SNAVFrameHead();
	~SNAVFrameHead();
	SNAVFrameHead(const SNAVFrameHead& p_objFrameHead);

	SNAVFrameHead& operator=(const SNAVFrameHead& p_objFrameHead);

public:
	bool getFrameHead(char* p_pszBuffer, int& p_nBufferLen) const;
	bool toByteFrameHead(char* p_pszBuffer, const int p_nBufferSize, int& p_nOutputLen) const;

	bool parseFrameHead(const char * p_pszBuffer, const int p_pszBufferLen);

public:
	static int getFrameHeadLength();

public:

	char* getStartCode();//起始标志,每帧数据前均存储该标志位

	void setSequenceId(unsigned int p_nSequenceId);

	unsigned int getSequenceId() const;

	void setFrameType(unsigned char p_nFrameType);

	unsigned char getFrameType() const;

	void setTimeStamp(INT64 p_nTimeStamp);

	INT64 getTimeStamp() const;

	void setBitRate(unsigned short p_nBitRate);

	unsigned short getBitRate() const;

	void setImageFormatId(unsigned char p_nImageFormatId);

	unsigned char getImageFormatId() const;

	void setVideoSystem(unsigned char p_nVideoSystem);

	unsigned char getVideoSystem() const;

	void setFrameLength(int p_nFrameLength);

	int getFrameLength() const;

	void setStreamFormat(unsigned char p_nStreamFormat);

	unsigned char getStreamFormat() const;

	void setESStreamType(unsigned char p_nESStreamType);

	unsigned char getESStreamType() const;

	void setEncodeType(unsigned char p_nEncodeType);

	unsigned char getEncodeType() const;

	void setFrameRate(unsigned char p_nFrameRate);
	unsigned char getFrameRate() const;

	void setTimezone(unsigned char p_nTimezone);
	unsigned char getTimezone()const;

	void setDaylightSavingTime(unsigned short p_DaylightSavingTime);
	unsigned short getDaylightSavingTime()const;

	void setCheckNum(unsigned short p_nCheckNum);
	unsigned short getCheckNum()const;




private:

	//char				m_szStartCode[NS_ST_AVStream::LENGTH_START_CODE];	起始标志,每帧数据前均存储该标志位

	unsigned int		m_nSequenceId;		// 帧序列号

	unsigned int		m_nHigh32;			// 时间戳的高32位

	unsigned int		m_nLow32;			// 时间戳的低32位

	unsigned int		m_nFrameLength;		// 帧长度

	unsigned short		m_nBitRate;			// 码率

	unsigned char		m_nFrameType;		// 帧类型 (1表示I帧, 2表示P帧, 3表示B帧, 0表示未知类型)

	unsigned char		m_nImageFormatId;	// 当前图像格式

	unsigned char		m_nVideoSystem;		// 当前视频制式

	unsigned char		m_nStreamFormat;	// 流格式

	unsigned char		m_nESStreamType;	// 原始流类型

	unsigned char		m_nEncodeType;		// 编码类型

	unsigned char		m_nFrameRate;		// 帧率

	unsigned char		m_nTimezone;			// 时区

	unsigned short		m_nDaylightSavingTime;				//夏令时

	unsigned short		m_nCheckNum;		//校验和
};


#endif //_SN_AV_FRAME_HEAD_H_
