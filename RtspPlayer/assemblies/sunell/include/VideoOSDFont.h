#ifndef _VIDEO_OSD_FONT_H_
#define _VIDEO_OSD_FONT_H_


#include "SNPlatOS.h"

/**********************************************************************/
//�˴����ڿ����ļ������ֽڶ��룬����ʱ����ע�ͼ�������һ�𿽱���
//�������ġ�#ifdef PRAGMA_PACK������ҲҪһ�𿽱�������pragma pack��ջ��ջ��ƥ��
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

class SN_DLL_API VideoOSDFont
{
public:
	enum FontID
	{
		FONTID_DEFAULT				= 0,	//�Զ���
		FONTID_16_16				= 1,	//16��16
		FONTID_24_24				= 2,	//24��24
		FONTID_32_32				= 3,	//32��32
		FONTID_48_48				= 4,	//48��48
		FONTID_56_56				= 5,	//56��56
		FONTID_64_64				= 6,	//64��64
		FONTID_72_72				= 7,	//72��72
		FONTID_96_96				= 8,	//96��96 //�ݲ�֧��,Ԥ��
		FONTID_128_128				= 9  	//128��128 //�ݲ�֧��,Ԥ��
	};

public:
	VideoOSDFont();
	~VideoOSDFont();

	VideoOSDFont(const VideoOSDFont &p_objVideoOSDFont);

public:
	void setCameraID(int p_nCameraID);
	int getCameraID() const;

	void setStreamID(int p_nStreamID); //�˷�����Ч������
	int getStreamID() const;		   //�˷�����Ч������

	void setFontID(int p_nFontID);
	int getFontID() const;

	void setFontColorRGB(const int p_nRed,const int p_nGreen,const int p_nBlue,const int p_nAlpha,const int p_nRed1,const int p_nGreen1,const int p_nBlue1,const int p_nAlpha1);
	void getFontColorRGB(int &p_nRed,int &p_nGreen,int &p_nBlue,int &p_nAlpha,int &p_nRed1,int &p_nGreen1,int &p_nBlue1,int &p_nAlpha1) const;

	void setInverseFlag(const bool p_bInverseFlag);
	bool getInverseFlag() const;

	VideoOSDFont& operator =(const VideoOSDFont &p_objVideoOSDFont);

private:
	int		m_nCameraID;
	int		m_nStreamID;			//�˲�����Ч������

	int		m_nFontID;

	int m_nRed;
	int m_nGreen;
	int m_nBlue;
	int m_nAlpha;

	int m_nRed1;
	int m_nGreen1;
	int m_nBlue1;
	int m_nAlpha1;
	
	bool	m_bInverseFlag;

}_PACKED_1_;


/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/


#endif	//_VIDEO_OSD_FONT_H_



