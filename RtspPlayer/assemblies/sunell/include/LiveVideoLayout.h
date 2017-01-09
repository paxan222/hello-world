#ifndef _DECODER_LAYOUT_H_
#define _DECODER_LAYOUT_H_

#include "LayoutWindow.h"
#include <vector>
#include "SNPlatOS.h"
#include "DomainConst.h"

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

class SN_DLL_API LiveVideoLayout
{
public:
	LiveVideoLayout(void);
	~LiveVideoLayout(void);

	enum AccessControlType
	{
		SHARE = 0,
		PRIVATE = 1
	};

	void setLayoutName(const char* p_strLayoutName);
    const char* getLayoutName() const;
	void setUserName(const char* p_strUserName);
	const char* getUserName() const;

	void setAccessControlType(const int p_nAccessControlType);
	const int getAccessControlType() const;

	void setLayoutMode(const int p_nLayoutMode);
	const int getLayoutMode() const;

	void setCycleScanInterval(const int p_nCycleScanInterval);
	const int getCycleScanInterval() const;

	void setLayoutWindowNum(const int p_nWinNum);
	const int getLayoutWindowNum() const;

	void setLayoutWindowList(const std::vector<LayoutWindow>& p_LayoutWindowList);
	const std::vector<LayoutWindow>& getLayoutWindowList() const;

	LiveVideoLayout& operator = (const LiveVideoLayout& p_LiveVideoLayout);
	bool operator == (const LiveVideoLayout &p_objLiveVideoLayout);

public:
	void addLayoutWindow(const LayoutWindow& p_objLayoutWindow);
	void removeLayoutWindow(const int p_nWinId);
	void removeLiveVideoChannel(const LiveVideoChannel& p_objLiveVideoChannel);
	void removeLiveVideoChannel(const int p_nChannelID);
	void removeLiveVideoLayoutByDeviceId(const std::string& p_strDeviceId);

private:
	
	char      m_szLayoutName[CONST_MAXLENGTH_LAYOUT_NAME+1];
	char      m_szUserName[CONST_MAXLENGTH_USERNAME+1];
	int m_nAccessControlType;
	int m_nLayoutMode;
	int m_nLayoutWindowNum;
	int m_nCycleScanInterval;
	std::vector<LayoutWindow> m_LayoutWindowList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif
