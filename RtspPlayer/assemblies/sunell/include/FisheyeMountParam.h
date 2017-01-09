#ifndef _FISHEYE_MOUNT_PARAM_H_
#define _FISHEYE_MOUNT_PARAM_H_

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

class  SN_DLL_API FisheyeMountParam
{
public:
	FisheyeMountParam();
	~FisheyeMountParam();

public:
	/****************************************************************************
	**������
	*		�������۰�װ��ʽ����
	**���룺
	*		p_nFisheyeMountType����װ��ʽ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ��������۰�װ��ʽ
	*****************************************************************************/
	void setFisheyeMountType(const int p_nFisheyeMountType);
	/****************************************************************************
	**������
	*		��ȡ���۰�װ��ʽ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���۰�װ��ʽ
	**���ܣ���ȡ���۰�װ��ʽ
	*****************************************************************************/
	int getFisheyeMountType(void)const;

	/****************************************************************************
	**������
	*	�еȺ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��ȷ���true, ���ȷ���false
	**���ܣ�
	*****************************************************************************/
	bool operator == (const FisheyeMountParam& p_objRhs);
private:
	int m_nFisheyeMountType;	//��װģʽ

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
	#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif//_FISHEYE_MOUNT_PARAM_H_
