#ifndef _SNAPSHOTPARAMEX_H_
#define _SNAPSHOTPARAMEX_H_

#include <vector>
#include "SNPlatOS.h"
#include "SnapshotStorageParam.h"

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

class SN_DLL_API SnapshotParamEX
{
public:
	SnapshotParamEX(void);
	~SnapshotParamEX(void);

	/************************************************************************
	**������
	*		����ץ�Ĵ洢�����б�
	**���룺
	*		p_objSnapshotStorageParamList:    ץ�Ĵ洢�����б�
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setSnapshotStorageParamList(const std::vector<SnapshotStorageParam> &p_objSnapshotStorageParamList);
	
	/************************************************************************
	**������
	*		���ץ�Ĵ洢�����б�
	**���룺
	*		��  
	**�����
	*		��
	**����ֵ��
	*		ץ�Ĵ洢�����б�
	************************************************************************/
	const std::vector<SnapshotStorageParam> &getSnapshotStorageParamList() const;

private:
	std::vector<SnapshotStorageParam> m_objSnapshotStorageParamList;    //ץ�Ĵ洢�����б�

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/



#endif
