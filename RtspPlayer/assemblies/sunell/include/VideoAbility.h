#ifndef _VIDEO_ABILITY_
#define _VIDEO_ABILITY_

#include "CameraAbility.h"
#include "SNPlatOS.h"
#include <vector>
using namespace std;

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

/************************************************************************
**��������Ƶ������Ϣ
*	��Ҫ����������Ϣ�������������Ϣ�б�
************************************************************************/
class SN_DLL_API VideoAbility
{
public:
	VideoAbility(void);
	~VideoAbility(void);

public:
	/************************************************************************
	**��������ȡ���������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���������
	*************************************************************************/
	const int getCameraNum() const;

	/************************************************************************
	**���������һ�����������
	**���룺
	*		p_objCameraAbility	���������
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void addCameraAbility(CameraAbility p_objCameraAbility);

	/************************************************************************
	**����������һ�����������
	**���룺
	*		p_nCameraId	�����ID��
	**�����
	*		p_objCameraAbility ���������
	**����ֵ��
	*		true�����ҳɹ�
	*		false��δ���ҵ����������
	*************************************************************************/
	bool findCameraAbility(const int p_nCameraId, CameraAbility & p_objCameraAbility) const;

	/************************************************************************
	**��������ȡ����������б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����������б�
	*************************************************************************/
	const vector<CameraAbility> &getCameraAbilityList() const;

private:
	vector<CameraAbility>	m_objCameraAbilityList;		//����������б�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_VIDEO_ABILITY_
