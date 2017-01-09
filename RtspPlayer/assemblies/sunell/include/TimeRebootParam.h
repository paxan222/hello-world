#ifndef TIMEREBOOTPARAM_H
#define TIMEREBOOTPARAM_H
#include <vector>
#include "SNPlatOS.h"
#include "RebootTime.h"

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

using std::vector;

class SN_DLL_API TimeRebootParam
{
public:
	TimeRebootParam(void);
	~TimeRebootParam(void);

public:

	/*************************************************************
	*	���������ö�ʱ������Ч��־
	*	���룺
	*		p_bEnableTimeReboot				��ʱ������Ч��־
	*	�����
	*		��
	*	����ֵ��
	*		0		���óɹ�
	*		-1		����ʧ��
	**************************************************************/
	int setTimeRebootEnableFlag( bool p_bEnableTimeReboot);
	const bool getTimeRebootEnableFlag() const;

	/*************************************************************
	*	���������ö�ʱ����ʱ�������Ϣ
	*	���룺
	*		p_objRebootTimeList				����ʱ���б�
	*	�����
	*		��
	*	����ֵ��
	*		0		���óɹ�
	*		-1		����ʧ��
	**************************************************************/
	int setRebootTimeList(const std::vector<RebootTime>& p_objRebootTimeList);
	const std::vector<RebootTime>& getRebootTimeList() const; 

	TimeRebootParam& operator = (const TimeRebootParam& p_other);
	bool operator == (const TimeRebootParam& p_other);
private:
	bool m_bEnableTimeReboot;
	std::vector<RebootTime> m_objRebootTimeList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/

#endif //TIMEREBOOTPARAM_H