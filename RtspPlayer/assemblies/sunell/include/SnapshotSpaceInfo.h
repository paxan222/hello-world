#ifndef  _SNAP_SHOT_SPACE_INFO_
#define  _SNAP_SHOT_SPACE_INFO_


#include "SNPlatOS.h"
#include "DomainConst.h"

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

class SN_DLL_API SnapshotSpaceInfo
{
public:
	SnapshotSpaceInfo(void);
	~SnapshotSpaceInfo(void);

	SnapshotSpaceInfo(const SnapshotSpaceInfo &p_SnapshotSpaceInfo);

public:
	

	/************************************************************************
	**������
	*		����ץ�Ŀ��ÿռ�
	**���룺
	*		p_nUseableSpace	:����ץ�Ŀ��ÿռ�
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setUseableSpace(int p_nUseableSpace);

	/************************************************************************
	**������
	*		��ȡץ�Ŀ��ÿռ�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ץ�Ŀ��ÿռ�
	************************************************************************/
	const int getUseableSpace() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objSnapshotSpaceInfo ��ץ�Ŀռ���Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	SnapshotSpaceInfo& operator = (const SnapshotSpaceInfo &p_objSnapshotSpaceInfo);

private:
	int					m_nUseableSpace;									//ץ�Ŀ��ÿռ���Ϣ,��λMB
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_SNAP_SHOT_SPACE_INFO_
