#ifndef _SNAPSHOTPARAMETER_H_
#define _SNAPSHOTPARAMETER_H_
#include "VideoResolution.h"
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

class SN_DLL_API SnapshotParameter
{
public:
	SnapshotParameter();

	SnapshotParameter(const int p_Duration,const VideoResolution &p_VideoResolution,const unsigned int p_Quality,
		const int p_Interval,const int p_ShootTimes);

	~SnapshotParameter();

public:
	/************************************************************************
	**	������
	*		����ץ�ĳ���ʱ��
	**	���룺
	*		p_Duration	ץ�ĳ���ʱ�䣬��λs
	**	�����
	*		��
	**	����ֵ��
	*		��
	************************************************************************/
	void setDuration(const int p_Duration);

	/************************************************************************
	**������
	*		��ȡץ�ĳ���ʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ץ�ĳ���ʱ�䣬��λs
	************************************************************************/
	int getDuration() const;

	/************************************************************************
	*	������
	*		����ͼ��ֱ���
	*	���룺
	*		p_VideoResolution	ͼ��ֱ���
	*	�����
	*		��
	*	����ֵ��
	*		��
	************************************************************************/
	void setVideoResolution(const VideoResolution &p_VideoResolution);

	/************************************************************************
	*	������
	*		��ȡͼ��ֱ���
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		ͼ��ֱ���
	************************************************************************/
	const VideoResolution &getVideoResolution() const;

	/************************************************************************
	**������
	*		����ץ������
	**���룺
	*		p_Quality	ץ������(1-9)
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	************************************************************************/
	void setQuality(const unsigned int p_Quality);

	/************************************************************************
	**������
	*		��ȡץ������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ץ������
	**���ܣ�       
	************************************************************************/
	const unsigned int getQuality() const;

	/************************************************************************
	*	������
	*		����ץ��ʱ����
	*	���룺
	*		p_Interval	ץ��ʱ����(��λΪ��)
	*	�����
	*		��
	*	����ֵ��
	*		��     
	************************************************************************/
	void setInterval(const int p_Interval);

	/************************************************************************
	*	������
	*		��ȡץ��ʱ����
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		ץ��ʱ����
	************************************************************************/
	const int getInterval() const;

	/************************************************************************
	*	������
	*		����ÿ��ץ������
	*	���룺
	*		p_ShootTimes	ÿ��ץ������
	*	�����
	*		��
	*	����ֵ��
	*		��     
	************************************************************************/
	void setShootTimes(const int p_ShootTimes);

	/************************************************************************
	*	������
	*		��ȡÿ��ץ������
	*	���룺
	*		��
	*	�����
	*		��
	*	����ֵ��
	*		ÿ��ץ������
	************************************************************************/
	const int getShootTimes() const;

	/************************************************************************
	**������
	*		�еȺ���
	**���룺
	*		p_SnapshotParameter	SnapshotParameter����
	**�����
	*		��
	**����ֵ��
	*		true �����
	*		false�������
	************************************************************************/
	bool operator == (const SnapshotParameter& p_SnapshotParameter);
private:
	int		m_Duration;					//ץ�ĳ���ʱ�䣬0��ʾ��ͣץ�ġ���λ��s

	VideoResolution m_VideoResolution;		//�ֱ���

	unsigned int m_Quality;					//ץ������(1-9)

	unsigned int m_Interval;				//ץ��ʱ����
	
	unsigned int m_ShootTimes;				//ÿ��ץ������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_SNAPSHOTPARAMETER_H_
