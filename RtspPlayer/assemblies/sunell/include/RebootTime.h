#ifndef REBOOTTIME_H
#define REBOOTTIME_H
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

/*************************************************************
*����ʱ����ʹ��˵����
*	Ŀǰ֧�ְ�������������������������������������
*����������
*	��Ҫ�����·ݡ����ں�����
*����������
*	��Ҫ�������ں����������������·�
*����������
*	��Ҫ�������ڼ��������������Ƿ������·ݺ����ڲ�Ӱ�찴������
*����������
*	��Ҫ�����������Ҳ��������·ݡ����ں����ڼ�����
*��ע��
*	���������Ͱ��ꡢ���������ǻ���Ӱ��ġ������������ʱ���4������������������Ч
*��ô�豸���ᰴ��������Ҳ�ᰴ�����������������õ�ÿ��ļ��¼��ż��㣬�豸��������
*�������õ�ÿ�ܼ��ļ��㣬���Ҳ��������
**************************************************************/

using std::vector;

class SN_DLL_API RebootTime
{
public:
	RebootTime(void);
	~RebootTime(void);

public:
	/*************************************************************
	*	��������������һ������
	*	���룺
	*		p_nMonth				�����·�
	*	�����
	*		��
	*	����ֵ��
	*		0		���óɹ�
	*		-1		����ʧ��
	*	���ܣ�
	*		1�������·ݵ�ֵ����Ч��ΧΪ1~12��������Ĭ��ֵΪ0
	*		2����������ʱ����Ҫ���ø���
	**************************************************************/
	int setMonth(const int p_nMonth);
	const int getMonth() const;

	/*************************************************************
	*	��������������һ������
	*	���룺
	*		p_nDay				��������
	*	�����
	*		��
	*	����ֵ��
	*		0		���óɹ�
	*		-1		����ʧ��
	*	���ܣ�
	*		1���������ڵ�ֵ����Ч��ΧΪ1~31��������Ĭ��ֵΪ0
	*		2�����ꡢ��������ʱ����Ҫ���ø���
	**************************************************************/
	int setDay(const int p_nDay);
	const int getDay() const;

	/*************************************************************
	*	�������������ڼ�����
	*	���룺
	*		p_nWeekday				���ڼ�����
	*	�����
	*		��
	*	����ֵ��
	*		0		���óɹ�
	*		-1		����ʧ��
	*	���ܣ�
	*		1�����ڼ�������ֵ����Ч��ΧΪ0~6��0Ϊ�����죬������Ĭ��ֵΪ-1
	*		2����������ʱ����Ҫ���ø���
	**************************************************************/
	int setWeekday(const int p_nWeekday);
	const int getWeekday() const;

	/*************************************************************
	*	�����������ڸ���ĵڼ�������
	*	���룺
	*		p_nWeekday				��������
	*	�����
	*		��
	*	����ֵ��
	*		0		���óɹ�
	*		-1		����ʧ��
	*	���ܣ�
	*		1������������ֵ����Ч��ΧΪ0~86399��������Ĭ��ֵΪ-1
	*		2����ʱ������Ч�������������
	**************************************************************/
	int setSecond(const int p_nSecond);
	const int getSecond() const;

	RebootTime& operator = (const RebootTime& p_other);
	bool operator == (const RebootTime& p_other);
private:
	int m_nMonth;
	int m_nDay;
	int m_nWeekday;
	int m_nSecond;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/

#endif