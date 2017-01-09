#ifndef _LAYOUT_WINDOW_H_
#define _LAYOUT_WINDOW_H_

#include <string>
#include <vector>
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
/**********************************************************************/

class SN_DLL_API LiveVideoChannel
{
public:
	LiveVideoChannel();
	~LiveVideoChannel();

	void setDeviceID(const std::string& p_strDeviceID);
	const std::string getDeviceID() const;

	void setChannelID(const int p_nChannelID);
	const int getChannelID() const;

	LiveVideoChannel& operator = (const LiveVideoChannel& p_LiveVideoChannel);
	bool operator == (const LiveVideoChannel &p_objLiveVideoChannel);

private:
	std::string m_strDeviceID;
	int m_nChannelID;
}_PACKED_1_;

class SN_DLL_API LayoutWindow
{
public:
	LayoutWindow(void);
	~LayoutWindow(void);

	void setWinId(const int p_nWinId);
	const int getWinId() const;

	void setLiveVideoChannelList(const std::vector<LiveVideoChannel>& p_LiveVideoChannelList);
	const std::vector<LiveVideoChannel>& getLiveVideoChannelList() const;

	LayoutWindow& operator = (const LayoutWindow& p_LayoutWindow);
	bool operator == (const LayoutWindow &p_objLayoutWindow);

private:
	int m_nWinId;
	std::vector<LiveVideoChannel> m_LiveVideoChannelList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif
