#ifndef _FISHEYE_VIDEO_ABILITY_H_
#define _FISHEYE_VIDEO_ABILITY_H_

#include <vector>
#include "FisheyeDewarpMode.h"
#include "FisheyeConst.h"
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

class  SN_DLL_API FisheyeVideoAbility
{
public:
	FisheyeVideoAbility();
	~FisheyeVideoAbility();

public:
	/************************************************************************
	**����������������Ƶģʽ����
	**���룺
	*		p_nFisheyeVideoMode����Ƶģʽ������ģʽ�Ͷ���ģʽ
	*		
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/	
	void setFisheyeVideoMode(const int &p_nFisheyeVideoMode);
	/************************************************************************
	**��������ȡ������Ƶģʽ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		p_nFisheyeVideoMode����Ƶģʽ������ģʽ�Ͷ���ģʽ
	*************************************************************************/	
	const int getFisheyeVideoMode()const;

	/************************************************************************
	**�������������۽���ģʽ�б�
	**���룺
	*		p_nDewarpModeList�����۽���ģʽ�б�	
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/	
	void setDewardModeList(const std::vector<FisheyeDewarpMode> &p_nDewarpModeList);
	/************************************************************************
	**��������ȡ���۽���ģʽ�б�
	**���룺
	*		��
	**�����
	*		p_nDewarpModeList�����۽���ģʽ�б�	
	**����ֵ��
	*		��
	*************************************************************************/	
	void getDewardModeList(std::vector<FisheyeDewarpMode> &p_nDewarpModeList)const;

	bool operator==(const FisheyeVideoAbility& p_objFisheyeVideoAbility)const;
private:
	int m_nFisheyeVideoMode;	//������Ƶģʽ,���嶨��ɲ鿴FisheyeConst.h��FISHEYE_VIDEO_MODEö�ٶ���
	std::vector<FisheyeDewarpMode> m_objDewarpModeList; //���۽���ģʽ
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
	#pragma pack(pop)
	#endif
#endif
/**********************************************************************/
#endif //_FISHEYE_VIDEO_ABILITY_H_
