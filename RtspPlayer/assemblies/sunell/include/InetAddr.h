#ifndef _INETADDR_H_ 
#define _INETADDR_H_

#include "SNPlatOS.h"

#if (defined(WIN32) || defined(_WIN32_WCE))
#ifdef SN_DLL_EXPORTS
	#define INETADDR_API __declspec(dllexport)
#else
	#define INETADDR_API __declspec(dllimport)
#endif
#else
	#define INETADDR_API
#endif

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

namespace SNSocketConst
{
	const int MAXLENGTH_IP = 48;	//IP��ַ��󳤶�
};
class INETADDR_API InetAddr
{
public:
	
	InetAddr();

	~InetAddr();

	InetAddr (const InetAddr& p_objInetAddr);

public:

	/************************************************************************
	**������
	*		����IP�ĺϷ���
    **���룺
	*	  p_pszIP��IP��ַ,��ʽ�磺xxx.xxx.xxx.xxx,xxxΪ0-255���֡�
	**�����
	*		��
	**����ֵ��
	*	  true�� �ɹ�
	*	  false��ʧ�� 
	**���ܣ�
	*     ��p_pszIPΪ�Ϸ���IP������true;
	*	  ��p_pszIP���Ϸ���IP������false
	************************************************************************/
	static bool checkIP(const char * p_pszIP);

	/************************************************************************
	**������
	*		����IP��ַ
    **���룺
	*	   p_pszIP��IP��ַ,��ʽ�磺xxx.xxx.xxx.xxx��
	**�����
	*		��
	**����ֵ��
	*	  true�� �ɹ�
	*	  false��ʧ�� 
	**���ܣ�
	*	  ��p_pszIP���Ϸ���IP������false
	*	  ��ת��p_pszIPΪ�����ֽ�˳�򲻳ɹ��� ����false
	*	  ��p_pszIPΪ�Ϸ���IP������true�����Ҵ洢p_pszIPΪ�����ֽ�˳�������ֵ��
    ************************************************************************/
	bool setIP(const char* p_pszIP);

	/************************************************************************
	**������
	*		��ȡ����Ʊ�ʾ��IP��ַ
	**���룺
	*	   ��
	**�����
	*		��
	**����ֵ��
	*		��ʽ�磺xxx.xxx.xxx.xxx�ĵ��ʮ����IP��ַ�ַ���
	*���ܣ�
	*		
	************************************************************************/
	const char* getIP() const;


	/************************************************************************
	** ������
	*		���ö˿ں�
    **���룺
	*		�˿ں�
	**�����
	*	  ��
	**����ֵ��
	*	  true�� �ɹ�
	*	  false��ʧ�� 
	**���ܣ�
	*	  �����õĶ˿�Ϊ���Ϸ��Ķ˿ڣ�����false
	*	  �����õĶ˿�Ϊ�Ϸ��Ķ˿ڣ�����true�����Ҵ洢�ö˿ڡ�
    ************************************************************************/
	bool		setPORT(const unsigned short p_nPORT);
	
	/************************************************************************
	**������
	*		��ȡ�˿ں�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�����ֽ�˳��˿ں�
	**���ܣ�
	*		�õ������ֽ�˳��Ķ˿ڡ�
    ************************************************************************/
	const unsigned short getPORT()  const;

	/************************************************************************
	** ������
	*		����IPЭ������
	**���룺
	*		p_nIPProtoVer��IPЭ������
	**�����
	*	  ��
	**����ֵ��
	*	  ��
	************************************************************************/
	void setIPProtoVer(const int p_nIPProtoVer);

	/************************************************************************
	**������
	*		��ȡIPЭ������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		IPЭ������
	************************************************************************/
	const int getIPProtoVer()  const;

	/************************************************************************
	**������
	*		�Ƚ�������ַ�����Ƿ����
    **���룺
	*		InetAddr�����
	*�����
	*	  ��
	**����ֵ��
	*	  true��������ַ���
	*	  false��������ַ�����
	**���ܣ�
	*	  ��������ַ�е�IP��port����ȣ��򷵻�true
	*	  ��������ַ�е�IP��port��һ�������ȣ�����false��
    ************************************************************************/
	bool operator ==(InetAddr &) ;


	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		InetAddr�����
	*�����
	*	  ��
	**����ֵ��
	*	  InetAddr��ַ����
	**���ܣ�
	*	  
	************************************************************************/
	InetAddr & operator =(const InetAddr &) ;
	
private:
	
	char			m_szHostIP[SNSocketConst::MAXLENGTH_IP + 1];		//IP��ַ�������ֽ�˳��

	unsigned short	m_nPORT;				//�˿ں�

	int				m_nIPProtoVer;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_INETADDR_H_
