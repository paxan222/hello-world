#ifndef _IMAGEFORMAT_H_
#define _IMAGEFORMAT_H_

#include "DomainConst.h"
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

class SN_DLL_API ImageFormat
{
public:
	enum Format
	{
		IMAGEFORMAT_D1					= 1,	//PAL 704*576,1-25frame�� NTSC 704*480 1-30framre
		IMAGEFORMAT_LOW_BITRATE_D1		= 2,	//PAL 704*576 1-12frame��NTSC 704*480 1-15framre
		IMAGEFORMAT_CIF					= 4,	//PAL 352*288 1-25frame��NTSC 352*240 1-30framre
		IMAGEFORMAT_QCIF				= 5,	//PAL 176*144 1-25frame��NTSC 240*160 1-30framre
		IMAGEFORMAT_SXGA				= 6,	//NA 1280*960 1-22frame
		IMAGEFORMAT_QVGA				= 7,	//NA 320*240 1-22frame
		IMAGEFORMAT_1280_720			= 8,	//NA 1280*720 1-25frame
		IMAGEFORMAT_360_160				= 9,	//NA 320*160 1-25frame
		IMAGEFORMAT_640_360				= 10,	//NA 640*368 1-25frame
		IMAGEFORMAT_VGA					= 11,	//NA 640*480 1-25frame
		IMAGEFORMAT_UXGA				= 12,	//NA 1600*1200 1-25frame
		IMAGEFORMAT_1920_1080			= 13,	//NA 1920*1080 1-25frame
		IMAGEFORMAT_640_360_EX			= 14,	//NA 640*360 1-25frame

		IMAGEFORMAT_QXGA				= 15,	//NA 2048*1536 1-25frame
		IMAGEFORMAT_2592_1920			= 16	//NA 2592*1920 1-25frame
	} ;

public:
	ImageFormat(void);
	~ImageFormat(void);

	ImageFormat(const ImageFormat& p_objImageFormat);

public:
	
	/************************************************************************
	**������
	*		����ͼ���ʽID
	**���룺
	*		p_nImageFormatId ��Ҫ���õ�ͼ���ʽID
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setImageFormatId(const int p_nImageFormatId);

	/************************************************************************
	*������
	*		��ȡͼ���ʽid
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		ͼ���ʽId
	*���ܣ�       
	*************************************************************************/
	const int getImageFormatId() const;


	/************************************************************************
	**������
	*		����ͼ���ʽ����
	**���룺
	*		p_pszImageFormatName��Ҫ���õ�ͼ���ʽ����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	bool setImageFormatName(const char* p_pszImageFormatName);

	/************************************************************************
	*������
	*		��ȡͼ���ʽ����
	*���룺
	*		��
	*�����
	*		��
	*����ֵ��
	*		ͼ���ʽ����
	*���ܣ�       
	*************************************************************************/
	const char* getImageFormatName() const;

	/************************************************************************
	*������
	*		��ֵ����
	*���룺
	*		p_objImageFormat��DDNS��Ϣ
	*�����
	*		��
	*����ֵ��
	*		DDNS��Ϣ
	*���ܣ�
	*************************************************************************/
	ImageFormat& operator =(const ImageFormat& p_objImageFormat);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objImageFormat��ImageFormat���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����ImageFormat��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const ImageFormat& p_objImageFormat);

	//ͨ���߿��ȡͼ���ʽIDֵ
	static int getImageFormat(int p_nVideoWidth, int p_nVideoHeight);
	static bool getImageFormatName(const int p_nImageFormatID, char* p_nImageFormatName);

private:
	int			m_nImageFormatId;											//ͼ���ʽid
	char		m_szImageFormatName[CONST_MAXLENGTH_IMAGEFORMAT_NAME + 1];	//ͼ���ʽ����
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_IMAGEFORMAT_H_
