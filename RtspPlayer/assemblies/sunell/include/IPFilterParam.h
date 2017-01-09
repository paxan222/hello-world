#ifndef IPFILTERPARAM_H_
#define IPFILTERPARAM_H_

#include <vector>
#include "SNPlatOS.h"
#include "IPAddrSegment.h"


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


/*****************************************************
*	������IP��ַ������Ϣ�࣬���ڴ��IP������Ϣ
*				
*	��Ҫ���ܣ�
*		����IP���˵�״̬�����ͺ���Ҫ���й��˵�IP�б�
************************************************************************/
namespace IPFilterType
{
	enum
	{
		 UNABLE_IP = 1, //��ֹ
		 ENABLE_IP = 2  //����
	};
};


class SN_DLL_API IPFilterParam
{
public:
	IPFilterParam(void);
	IPFilterParam(const IPFilterParam &p_objIPFilterParam);
	~IPFilterParam();

public:
	/************************************************************************
	*	���������ù���״̬��true�����ù��ˣ�false�������ù��ˣ�
	*	���룺
	*		p_bEnableFlag  ����״̬
	*	�����
	*		��
	*	����ֵ��
	*		��
	*	ע�⣺
	*		��
	*************************************************************************/
	void setEnableFlag(const bool p_bEnableFlag);
	/************************************************************************
	*	��������ȡ����״̬��true�����ù��ˣ�false�������ù��ˣ�
	*	���룺
	*		��  
	*	�����
	*		��
	*	����ֵ��
	*		true  ���ù���
	*		false �����ù���
	*	ע�⣺
	*		��
	*************************************************************************/
	bool getEnableFlag()const;
	/************************************************************************
	*	���������ù����������ͣ�1����ֹ��2������
	*	���룺
	*		p_nFilterType  �б���������
	*	�����
	*		��
	*	����ֵ��
	*		��
	*	ע�⣺
	*		��
	*************************************************************************/
	void setFilterType(const int p_nFilterType);
	/************************************************************************
	*	��������ȡ�����������ͣ�1����ֹ��2������
	*	���룺
	*		��  
	*	�����
	*		��
	*	����ֵ��
	*		IP�б�����
	*	ע�⣺
	*		��
	*************************************************************************/
	const int getFilterType()const;
	/************************************************************************
	*	����������IP�б�
	*	���룺
	*		p_vecIPAddrList  IP�б�
	*	�����
	*		��
	*	����ֵ��
	*		��
	*	ע�⣺
	*		��
	*************************************************************************/
	void setIPAddrList(const std::vector<IPAddrSegment> &p_vecIPAddrSegmentList);
	/************************************************************************
	*	��������ȡIP�б�
	*	���룺
	*		��  
	*	�����
	*		��
	*	����ֵ��
	*		IP�б�
	*	ע�⣺
	*		��
	*************************************************************************/
	const std::vector<IPAddrSegment> &getIPAddrList() const;

	IPFilterParam& operator=(const IPFilterParam &p_objIPFilterParam);

	bool operator==(const IPFilterParam &p_objIPFilterParam);

private:
	bool m_bEnableFlag;						//�Ƿ����ù���״̬
	int m_nFilterType;						//IP�б�����
	std::vector<IPAddrSegment>  m_vecIPAddrSegmentList;  //IP�б�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
		#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif