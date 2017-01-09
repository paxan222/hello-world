#ifndef _PIXEL_TO_REALSIZE_H
#define _PIXEL_TO_REALSIZE_H
#include "SNPlatOS.h"
#include "LineCross.h"

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

//���������֮���ӳ���ϵ����
class SN_DLL_API PixelToRealSize
{
public:
	PixelToRealSize();
	~PixelToRealSize();

	PixelToRealSize(const PixelToRealSize& p_objPixelToRealSize);
	PixelToRealSize& operator=(const PixelToRealSize& p_objPixelToRealSize);
public:
	void setRealSize(const int p_nRealSize);
	const int  getRealSize()const;

	void setSegmentLayType(const int p_nScene);
	const int  getSegmentLayType()const;

	void setSegment(const LineCross& p_objSegment);
	const LineCross&  getSegment()const;
private:
	int			m_nRealSize;					//����ʵ�ʳ��� ��λ����
	int			m_nSegmentLayType;	//�߶η�λ(ˮƽ/ ��ֱ) 
	LineCross			m_objSegment;				//�߶β���
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/
#endif
