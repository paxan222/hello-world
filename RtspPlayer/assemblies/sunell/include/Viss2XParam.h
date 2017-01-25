#ifndef _VISS2XPARAM_H_
#define _VISS2XPARAM_H_

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

class SN_DLL_API Viss2XParam
{
public:
	Viss2XParam();
	~Viss2XParam();


	//�������캯��
	Viss2XParam(const Viss2XParam &p_objViss2XParam);

public:

	/************************************************************************
	**������
	*		����ǰ���豸ID
	**���룺
	*	   p_pszId��ǰ���豸ID
	**�����
	*		��
	**����ֵ��
	*		true: ���óɹ�
	*		false:����ʧ��
	**����
	*		����ǰ���豸ID�����óɹ�������true������ʧ�ܣ�����false
	************************************************************************/
	bool setID(const char* p_pszID);

	/************************************************************************
	**������
	*		��ȡǰ���豸ID
	**���룺
	*	   ��
	**�����
	*		��
	**����ֵ��
	*		ǰ���豸ID
	**����
	*		��ȡǰ���豸ID
	************************************************************************/
	const char* getID()const;

	/************************************************************************
	**������
	*		����ע���û���
	**���룺
	*	   p_pszName��ע���û���
	**�����
	*		��
	**����ֵ��
	*		true: ���óɹ�
	*		false:����ʧ��
	**����
	*		����ע���û��������óɹ�������true������ʧ�ܣ�����false
	************************************************************************/
	bool setName(const char* p_pszName);

	/************************************************************************
	**������
	*		��ȡע���û���
	**���룺
	*	   ��
	**�����
	*		��
	**����ֵ��
	*		ע���û���
	**����
	*		��ȡע���û���
	************************************************************************/
	const char* getName() const;

	/************************************************************************
	**������
	*		����ע������
	**���룺
	*	   p_pszPassword��ע������
	**�����
	*		��
	**����ֵ��
	*		true:  ���óɹ�
	*		false: ����ʧ��
	**����
	*		����ע�����룬���óɹ�������true������ʧ�ܣ�����false
	************************************************************************/
	bool setPassword(const char* p_pszPassword);

	/************************************************************************
	**������
	*		��ȡע������
	**���룺
	*	    ��
	**�����
	*		��
	**����ֵ��
	*		ע������
	**����
	*		��ȡע������
	************************************************************************/
	const char* getPassword()const;

	/************************************************************************
	**������
	*		����ע���ַ
	**���룺
	*	   p_pszRegisterIP��ע���ַ
	**�����
	*		��
	**����ֵ��
	*		true: ���óɹ�
	*		false:����ʧ��
	**����
	*		����ע���ַ�����óɹ�������true������ʧ�ܣ�����false
	************************************************************************/
	bool setRegisterIP(const char* p_pszRegisterIP);

	/************************************************************************
	**������
	*		��ȡע���ַ
	**���룺
	*	    ��
	**�����
	*		��
	**����ֵ��
	*		ע���ַ
	**����
	*		��ȡע���ַ
	************************************************************************/
	const char* getRegisterIP() const;

	/************************************************************************
	**������
	*		����ע��˿�
	**���룺
	*	   p_nRegisterPort��ע��˿�
	**�����
	*		��
	**����ֵ��
	*		ע��˿�
	**����
	*		����ע��˿�
	************************************************************************/
	void setRegiserPort(const int p_nRegisterPort);

	/************************************************************************
	**������
	*		��ȡע��˿�
	**���룺
	*	    ��
	**�����
	*		��
	**����ֵ��
	*		ע��˿�
	**����
	*		��ȡע��˿�
	************************************************************************/
	const int getRegisterPort()const;

	/************************************************************************
	**������
	*		����������ַ
	**���룺
	*	   p_pszHeartBeatIP��������ַ
	**�����
	*		��
	**����ֵ��
	*		true:���óɹ�
	*		false:����ʧ��
	**����
	*		����������ַ�����óɹ�������true������ʧ�ܣ�����false
	************************************************************************/
	bool setHeartBeatIP(const char* p_pszHeartBeatIP);

	/************************************************************************
	**������
	*		��ȡ������ַ
	**���룺
	*	   ��
	**�����
	*		��
	**����ֵ��
	*		��ȡ������ַ
	**����
	*		��ȡ������ַ
	************************************************************************/
	const char* getHeartBeatIP() const;

	/************************************************************************
	**������
	*		���������˿�
	**���룺
	*	   p_nHeartBeatPort�������˿�
	**�����
	*		��
	**����ֵ��
	*		��
	**����
	*		����������ַ
	************************************************************************/
	void setHeartBeatPort(const int p_nHeartBeatPort);

	/************************************************************************
	**������
	*		��ȡ�����˿�
	**���룺
	*	   ��
	**�����
	*		��
	**����ֵ��
	*		�����˿�
	**����
	*		��ȡ�����˿�
	************************************************************************/
	const int getHeartBeatPort()const;

	/************************************************************************
	**������
	*		���ø澯��ַ
	**���룺
	*	   p_pszAlarmIP���澯��ַ
	**�����
	*		��
	**����ֵ��
	*		true:���óɹ�
	*		false:����ʧ��
	**����
	*		���ø澯��ַ�����óɹ�������true������ʧ�ܣ�����false
	************************************************************************/
	bool setAlarmIP(const char* p_pszAlarmIP);

	/************************************************************************
	**������
	*		��ȡ�澯��ַ
	**���룺
	*	    ��
	**�����
	*		��
	**����ֵ��
	*		�澯��ַ
	**����
	*		��ȡ�澯��ַ
	************************************************************************/
	const char* getAlarmIP()const;

	/************************************************************************
	**������
	*		���ø澯�˿�
	**���룺
	*	   p_nAlarmPort���澯�˿�
	**�����
	*		��
	**����ֵ��
	*		��
	**����
	*		���ø澯�˿�
	************************************************************************/
	void setAlarmPort(const int p_nAlarmPort);

	/************************************************************************
	**������
	*		��ȡ�澯�˿�
	**���룺
	*	    ��
	**�����
	*		��
	**����ֵ��
	*		�澯�˿�
	**����
	*		��ȡ�澯�˿�
	************************************************************************/
	const int getAlarmPort()const;

	/************************************************************************
	**������
	*		���ÿ��ƶ˿�
	**���룺
	*	   p_nVapPort�����ƶ˿�
	**�����
	*		��
	**����ֵ��
	*		��
	**����
	*		���ÿ��ƶ˿�
	************************************************************************/
	void setVapPort(const int p_nVapPort);

	/************************************************************************
	**������
	*		��ȡ���ƶ˿�
	**���룺
	*	   ��
	**�����
	*		��
	**����ֵ��
	*		���ƶ˿�
	**����
	*		��ȡ���ƶ˿�
	************************************************************************/
	const int getVapPort()const;

	/************************************************************************
	**������
	*		������Ƶ�˿�
	**���룺
	*	   p_nVspVideoPort����Ƶ�˿�
	**�����
	*		��
	**����ֵ��
	*		��
	**����
	*		������Ƶ�˿�
	************************************************************************/
	void setVspVideoPort(const int p_nVspVideoPort);

	/************************************************************************
	**������
	*		��ȡ��Ƶ�˿�
	**���룺
	*	    ��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ�˿�
	**����
	*		��ȡ��Ƶ�˿�
	************************************************************************/
	const int getVspVideoPort()const;

	/************************************************************************
	**������
	*		������Ƶ�˿�
	**���룺
	*	   p_nVspAudioPort����Ƶ�˿�
	**�����
	*		��
	**����ֵ��
	*		��
	**����
	*		������Ƶ�˿�
	************************************************************************/
	void setVspAudioPort(const int p_nVspAudioPort);

	/************************************************************************
	**������
	*		��ȡ��Ƶ�˿�
	**���룺
	*	    ��
	**�����
	*		��
	**����ֵ��
	*		��Ƶ�˿�
	**����
	*		��ȡ��Ƶ�˿�
	************************************************************************/
	const int getVspAudioPort()const;

	/************************************************************************
	**������
	*		����ͼƬ�ϴ���ַ
	**���룺
	*	   p_pszPictureServerIP��ͼƬ�ϴ���ַ
	**�����
	*		��
	**����ֵ��
	*		true:���óɹ�
	*		false:����ʧ��
	**����
	*		����ͼƬ�ϴ���ַ,���óɹ�,����true,����ʧ��,����false
	************************************************************************/
	bool setPictureServerIP(const char* p_pszPictureServerIP);

	/************************************************************************
	**������
	*		��ȡͼƬ�ϴ���ַ
	**���룺
	*	   ��
	**�����
	*		��
	**����ֵ��
	*		ͼƬ�ϴ���ַ
	**����
	*		��ȡͼƬ�ϴ���ַ
	************************************************************************/
	const char* getPictureServerIP()const;

	/************************************************************************
	**������
	*		����ͼƬ�ϴ��˿�
	**���룺
	*	   p_nPictureServerPort��ͼƬ�ϴ��˿�
	**�����
	*		��
	**����ֵ��
	*		��
	**����
	*		����ͼƬ�ϴ��˿�
	************************************************************************/
	void setPictureServerPort(const int p_nPictureServerPort);

	/************************************************************************
	**������
	*		��ȡͼƬ�ϴ��˿�
	**���룺
	*	   ��
	**�����
	*		��
	**����ֵ��
	*		ͼƬ�ϴ��˿�
	**����
	*		��ȡͼƬ�ϴ��˿�
	************************************************************************/
	const int getPictureServerPort()const;

	/************************************************************************
	**������
	*		����VAP·��
	**���룺
	*	   p_pszVapUrl��VAP·��
	**�����
	*		��
	**����ֵ��
	*		true:���óɹ�
	*		false:����ʧ��
	**����
	*		����VAP·��,���óɹ�,����true,����ʧ��,����false
	************************************************************************/
	bool setVapUrl(const char* p_pszVapUrl);

	/************************************************************************
	**������
	*		��ȡVAP·��
	**���룺
	*	    ��
	**�����
	*		��
	**����ֵ��
	*		VAP·��
	**����
	*		��ȡVAP·��
	************************************************************************/
	const char* getVapUrl()const;

	/************************************************************************
	**������
	*		�����������ڣ��룩
	**���룺
	*	   p_nHeartBeatTime���������ڣ��룩
	**�����
	*		��
	**����ֵ��
	*		��
	**����
	*		�����������ڣ��룩
	************************************************************************/
	void setHeartBeatTime(const int p_nHeartBeatTime);

	/************************************************************************
	**������
	*		��ȡ�������ڣ��룩
	**���룺
	*	    ��
	**�����
	*		��
	**����ֵ��
	*		�������ڣ��룩
	**����
	*		��ȡ�������ڣ��룩
	************************************************************************/
	const int getHeartBeatTime()const;

	/************************************************************************
	**������
	*		����ע����Ч�ڣ�Сʱ)
	**���룺
	*	   p_nTimeOut��ע����Ч�ڣ�Сʱ)
	**�����
	*		��
	**����ֵ��
	*		��
	**����
	*		����ע����Ч�ڣ�Сʱ)
	************************************************************************/
	void setTimeOut(const int p_nTimeOut);

	/************************************************************************
	**������
	*		��ȡע����Ч�ڣ�Сʱ)
	**���룺
	*	    ��
	**�����
	*		��
	**����ֵ��
	*		ע����Ч�ڣ�Сʱ)
	**����
	*		��ȡע����Ч�ڣ�Сʱ)
	************************************************************************/
	const int getTimeOut()const;

	Viss2XParam& operator = (const Viss2XParam &p_objProtocolConfigParam);

private:

	char    m_szID[CONST_MAXLENGTH_PROTOCOL_PARAM];						//ǰ���豸ID

	char    m_szName[CONST_MAXLENGTH_PROTOCOL_PARAM];					//ע���û���
	char    m_szPassword[CONST_MAXLENGTH_PROTOCOL_PARAM];				//ע������

    char    m_szRegisterIP[CONST_MAXLENGTH_PROTOCOL_PARAM];				//ע���ַ
	int     m_nRegisterPort;											//ע��˿�

    char    m_szHeartBeatIP[CONST_MAXLENGTH_PROTOCOL_PARAM];			//������ַ
	int     m_nHeartBeatPort;											//�����˿�

    char    m_szAlarmIP[CONST_MAXLENGTH_PROTOCOL_PARAM];				//�澯��ַ
	int     m_nAlarmPort;												//�澯�˿�

    int     m_nVapPort;													//���ƶ˿�
	int     m_nVspVideoPort;											//��Ƶ�˿�
	int     m_nVspAudioPort;											//��Ƶ�˿�

	char    m_szPictureServerIP[CONST_MAXLENGTH_PROTOCOL_PARAM];		//ͼƬ�ϴ���ַ
	int     m_nPictureServerPort;										//ͼƬ�ϴ��˿�

	char    m_szVapUrl[CONST_MAXLENGTH_PROTOCOL_PARAM];					//VAP·��
	int		m_nHeartBeatTime;											//�������ڣ��룩
	int		m_nTimeOut;													//ע����Ч�ڣ�Сʱ��

	
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif//_VISS2XPARAM_H_