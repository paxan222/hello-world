#ifndef _OSDFONT_ABILITY_H_
#define _OSDFONT_ABILITY_H_

#include <vector>
#include "VideoOSDFontType.h"
#include "RGBColor.h"
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

class SN_DLL_API OSDFontAbility
{
public:
	OSDFontAbility();
	~OSDFontAbility();

	void setVideoOSDFontTypeList(const std::vector<VideoOSDFontType>  &p_objVideoOSDFontTypeList);
	const std::vector<VideoOSDFontType> &getVideoOSDFontTypeList() const;

	/*************************************************************
	*	��������ȡOSD��֧�ֵ���ɫ����
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		vector<RGBColor> ֧�ֵ���ɫ�б����RGBColor��RGBΪ(-1,-1,-1)�Ǵ���֧��
	*		��0,0,0��~(255,255,255)������ɫ��
	**************************************************************/
	const std::vector<RGBColor> &getVideoOSDFontColorList() const;

	void setVideoOSDFontColorList(const std::vector<RGBColor>  &p_objVideoOSDFontColorList);

	/*************************************************************
	*	��������ȡOSD��֧�ֵ�͸��������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		vector<int> ֧�ֵ���ɫ�б����Ϊ-1�Ǵ���֧��
	*		0~100��%������͸���ȡ�
	**************************************************************/
	const std::vector<int> &getVideoOSDFontAlphaList() const;

	void setVideoOSDFontAlphaList(const std::vector<int>  &p_objVideoOSDFontAlphaList);

	/*************************************************************
	*	��������ȡOSD��ɫ��֧�ֵ���ɫ����
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		vector<RGBColor> ֧�ֵ���ɫ�б����RGBColor��RGBΪ(-1,-1,-1)�Ǵ���֧��
	*		��0,0,0��~(255,255,255)������ɫ��
	**************************************************************/
	const std::vector<RGBColor> &getVideoOSDFontInverseColorList() const;

	void setVideoOSDFontInverseColorList(const std::vector<RGBColor> &p_objVideoOSDFontInverseColorList);

private:
	std::vector<VideoOSDFontType> m_objVideoOSDFontTypeList;
	std::vector<RGBColor> m_objVideoOSDFontColorList;
	std::vector<int> m_objVideoOSDFontAlphaList;
	std::vector<RGBColor> m_objVideoOSDFontInverseColorList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/

#endif //_OSDFONT_ABILITY_H_

