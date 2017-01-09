#ifndef _VIDEO_OSD_FONTTYPE_H_
#define _VIDEO_OSD_FONTTYPE_H_


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

class SN_DLL_API VideoOSDFontType
{
public:
	VideoOSDFontType();
	~VideoOSDFontType();

	VideoOSDFontType(const VideoOSDFontType &p_objVideoOSDFontType);

public:
	bool setDescription(const char* p_pszDescription);
	const char* getDescription() const;

	void setFontID(int p_nFontID);
	int getFontID() const;

	VideoOSDFontType& operator =(const VideoOSDFontType &p_objVideoOSDFontType);

private:
	int			m_nFontID;
	char		m_szDescription[CONST_OSD_FONT_DESCRIPTION + 1];		//OSD字体

}_PACKED_1_;


/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/


#endif	//_VIDEO_OSD_FONTTYPE_H_



