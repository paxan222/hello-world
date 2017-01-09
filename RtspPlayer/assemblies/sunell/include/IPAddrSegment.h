#ifndef  _IPADDR_SEGMENT_H
#define  _IPADDR_SEGMENT_H

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

class SN_DLL_API IPAddrSegment
{

public:
	IPAddrSegment(void);
	IPAddrSegment(const IPAddrSegment& p_objIPAddrSegment);
	~IPAddrSegment(void);


	/************************************************************************
	**������
	*		����IP����
	**���룺
	*		IP����
	*�����
	*	  ��
	**����ֵ��
	*	  
	**���ܣ�
	*	  
	************************************************************************/
	void setIPProVer(const int& p_IPProVer);

	/************************************************************************
	**������
	*		����IP����
	**���룺
	*		
	*�����
	*	  ��
	**����ֵ��
	*	  IP����
	**���ܣ�
	*	  
	************************************************************************/
	const int& getIPProVer(void)const;

	/************************************************************************
	**������
	*		���ÿ�ʼIP��ַ  
	**���룺
	*		��ʼIP��ַ  ��ʽ�磺xxx.xxx.xxx.xxx�ĵ��ʮ����IP��ַ�ַ���
	*�����
	*	  ��
	**����ֵ��
	*	  true�����óɹ�
	*	  false������ʧ��
	**���ܣ�
	*	  
	************************************************************************/
	bool setBeginIP(const char* p_szBeginIP);


	/************************************************************************
	**������
	*		��ȡ��ʼIP��ַ
	**���룺
	*		��
	*�����
	*	  
	**����ֵ��
	*	  ��ʼIP��ַ  ��ʽ�磺xxx.xxx.xxx.xxx�ĵ��ʮ����IP��ַ�ַ���
	**���ܣ�
	*	  
	************************************************************************/
	const char* getBeginIP()const;


	/************************************************************************
	**������
	*		���ý���IP��ַ
	**���룺
	*		����IP��ַ  ��ʽ�磺xxx.xxx.xxx.xxx�ĵ��ʮ����IP��ַ�ַ���
	*�����
	*	  ��
	**����ֵ��
	*	  true�����óɹ�
	*	  false������ʧ��
	**���ܣ�
	*	  
	************************************************************************/
	bool setEndIP(const char* p_szEndIP);

	/************************************************************************
	**������
	*		��ȡ����IP��ַ
	**���룺
	*		��
	*�����
	*	  ����IP��ַ  ��ʽ�磺xxx.xxx.xxx.xxx�ĵ��ʮ����IP��ַ�ַ���
	**����ֵ��
	*	  ��
	**���ܣ�
	*	  
	************************************************************************/
	const char* getEndIP()const;


	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		IPAddrSegment�����
	*�����
	*	  ��
	**����ֵ��
	*	  IPAddrSegment����
	**���ܣ�
	*	  
	************************************************************************/
	IPAddrSegment& operator=(const IPAddrSegment& IPAddrSegment);

	/************************************************************************
	**������
	*		�Ƚ�������ַ�ζ����Ƿ����
    **���룺
	*		IPAddrSegment�����
	*�����
	*	  ��
	**����ֵ��
	*	  true��������ַ���
	*	  false��������ַ�����
	**���ܣ�
	*	  ��������ַ���е�IP�κ�IPProVer����ȣ��򷵻�true
	*	  ��������ַ���е�IP�κ�IPProVer��һ�������ȣ�����false��
    ************************************************************************/
	bool operator ==(IPAddrSegment & p_objIPAddrSegment) ;

private:
	int m_nIPProVer ;                         //IP����
	char m_szBeginIP[CONST_MAXLENGTH_IP + 1];	//��ʼip
	char m_szEndIP[CONST_MAXLENGTH_IP + 1];		//����ip



}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
#ifdef WIN32  
#pragma pack(pop)
#endif
#endif
/**********************************************************************/

#endif //_IPADDR_SEGMENT_H