#ifndef _MANUALSNAPSHOTPARAMETER_H_
#define _MANUALSNAPSHOTPARAMETER_H_
#include "SnapshotParameter.h"
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

class SN_DLL_API ManualSnapshotParameter
{
public:
	ManualSnapshotParameter();

	ManualSnapshotParameter(const int p_nCameraId,const SnapshotParameter &p_SnapshotParameter);

	~ManualSnapshotParameter();

public:
	void setCameraId(const int p_nCameraId);

	int getCameraId() const;

	void setSnapshotParameter(const SnapshotParameter &p_SnapshotParameter);

	const SnapshotParameter &getSnapshotParameter() const;

	/************************************************************************
	**������
	*		�еȺ���
	**���룺
	*		p_ManualSnapshotParameter	ManualSnapshotParameter����
	**�����
	*		��
	**����ֵ��
	*		true �����
	*		false�������
	************************************************************************/
	bool operator == (const ManualSnapshotParameter& p_ManualSnapshotParameter);
private:
	int					m_nCameraId;		
	SnapshotParameter	m_SnapshotParameter;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_MANUALSNAPSHOTPARAMETER_H_
