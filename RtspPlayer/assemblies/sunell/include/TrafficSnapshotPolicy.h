#ifndef _TRAFFICSNAPSHOTPOLICY_H_
#define _TRAFFICSNAPSHOTPOLICY_H_

#include <vector>
#include "SNPlatOS.h"
#include "SnapshotTriggerParameter.h"

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

class SN_DLL_API TrafficSnapshotPolicy
{
public:
	TrafficSnapshotPolicy();
	~TrafficSnapshotPolicy();

	/************************************************************************
	**������
	*		����ץ�Ĵ��������б�
	**���룺
	*		p_SnapshotTriggerParameterList:    ץ�Ĵ��������б�
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setSnapshotTriggerParameterList(const std::vector<SnapshotTriggerParameter> &p_SnapshotTriggerParameterList);
	
	/************************************************************************
	**������
	*		��ȡץ�Ĵ��������б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ץ�Ĵ��������б�
	************************************************************************/
	const std::vector<SnapshotTriggerParameter> & getSnapshotTriggerParameterList() const;

private:
	std::vector<SnapshotTriggerParameter> m_SnapshotTriggerParameterList;   //ץ�Ĳ����б�
	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif

