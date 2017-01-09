#ifndef _FISHEYE_DEWARP_MODE_H_
#define _FISHEYE_DEWARP_MODE_H_

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

class  SN_DLL_API FisheyeDewarpMode
{
public:
	FisheyeDewarpMode();
	~FisheyeDewarpMode();

public:
	/************************************************************************
	**�������������۽���ģʽ����
	**���룺
	*		p_nDewarpMode������ģʽ����
	*		
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/	
	void setDewarpMode(const int p_nDewarpMode);
	/************************************************************************
	**��������ȡ���۽���ģʽ����
	**���룺
	*		��		
	**�����
	*		��
	**����ֵ��
	*		����ģʽ����
	*************************************************************************/
	int getDewarpMode(void)const;

	/************************************************************************
	**���������ÿ��ƶ�PTZ��־
	**���룺
	*		p_bMovable�����ƶ�PTZ��־
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void setMoveable(const bool p_bMovable);
	/************************************************************************
	**��������ȡ���ƶ�PTZ��־
	**���룺
	*		��	
	**�����
	*		��
	**����ֵ��
	*		���ƶ�PTZ��־ true ���ƶ�PTZ;
	*************************************************************************/
	bool getMoveable(void) const;
	
	bool operator==(const FisheyeDewarpMode& p_objFisheyeDewarpMode)const;
	bool operator!=(const FisheyeDewarpMode& p_objFisheyeDewarpMode)const;
private:
	int m_nDewarpMode;	//����ģʽ,���嶨��ɲ鿴FisheyeConst.h��FISHEYE_DEWARP_MODEö�ٶ���
	bool m_bMoveable;	//�Ƿ���ƶ���ʶ
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
	#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif //_FISHEYE_DEWARP_MODE_H_
