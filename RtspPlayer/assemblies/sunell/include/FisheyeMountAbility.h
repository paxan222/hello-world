#ifndef _FISHEYEMOUNTABILITY_H_
#define _FISHEYEMOUNTABILITY_H_

#include <vector>
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

class SN_DLL_API FisheyeMountAbility
{
public:
	FisheyeMountAbility(void);
	~FisheyeMountAbility(void);
	//��װģʽ
	void setFisheyeMountTypeList(const std::vector<int> &p_objFisheyeMountTypeList);
	void getFisheyeMountTypeList(std::vector<int> &p_objFisheyeMountTypeList)const;

	//�ж� m_objFisheyeMountTypeList �Ƿ�Ϊ�գ����򷵻�true,
	bool empty()const;

	FisheyeMountAbility& operator=(const FisheyeMountAbility& p_objFisheyeMountAbility);

private:
	std::vector<int> m_objFisheyeMountTypeList; //��װģʽ�����嶨��ɲ鿴FisheyeConst.h��FISHEYE_MOUNT_TYPEö�ٶ���
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
	#pragma pack(pop)
	#endif
#endif
/**********************************************************************/
#endif // _FISHEYEMOUNTABILITY_H_