#ifndef _PPPOEPARAM_H_
#define _PPPOEPARAM_H_

#include "DomainConst.h"
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

class SN_DLL_API PPPoEParam
{

public:
	PPPoEParam(void);
	~PPPoEParam(void);

	//�������캯��
	PPPoEParam(const PPPoEParam& p_objPPPoEParam);

public:
	/************************************************************************
	**������
	*		�����Ƿ�����PPPoE
	**���룺
	*		p_bFlag ������PPPoE��ʶ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	void setPPPoEEnableFlag(const bool p_bFlag);

	/************************************************************************
	**������
	*		��ȡ����PPPoE��ʶ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����PPPoE��ʶ
	**���ܣ�
	*		��ȡ����PPPoE��״̬
	**************************************************************************/
	const bool getPPPoEEnableFlag() const;


	/************************************************************************
	**������
	*		���� PPPoE�û���
	**���룺
	*		p_pszPPPoEUserName ��PPPoE�û�����һ���ԡ�\0����β���ַ�����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		��p_pszPPPoEUserNameΪ��ʱ������false
	*		���ַ����ĳ��ȴ��� CONST_MAXLENGTH_PPPOE_USERNAME ʱ������false
	*		������PPPoE�û����ɹ�������true
	************************************************************************/
	bool setPPPoEUserName(const char *p_pszPPPoEUserName);

	/************************************************************************
	**������
	*		��ȡPPPoE�û���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		PPPoE�û���
	**���ܣ�
	*		
	**************************************************************************/
	const char *getPPPoEUserName() const;


	/************************************************************************
	**������
	*		����PPPoE����
	**���룺
	*		p_pszPPPoEPassword ��PPPoE���룬һ���ԡ�\0����β���ַ�����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		��p_pszPPPoEPasswordΪ��ʱ������false
	**		���ַ����ĳ��ȴ��� CONST_MAXLENGTH_PPPOE_PASSWORD ʱ������false
	**		����������ɹ�������true
	************************************************************************/
	bool setPPPoEPassword(const char *p_pszPPPoEPassword);

	/************************************************************************
	**������
	*		��ȡPPPoE����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		PPPoE����
	**���ܣ�
	*
	**************************************************************************/
	const char *getPPPoEPassword() const;


	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objPPPoEParam���豸������Ϣ
	**�����
	*		��
	**����ֵ��
	*		PPPoE��Ϣ
	**���ܣ�
	*************************************************************************/
	PPPoEParam &operator =(const PPPoEParam &p_objPPPoEParam);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objPPPoEParam��PPPoEParam���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����PPPoEParam��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const PPPoEParam& p_objPPPoEParam);


	/****************************************************************************
	**������
	*		��λ������Ա�����ָ���ʼĬ��ֵ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		����Ա�����ָ���ʼĬ��ֵ
	*****************************************************************************/
	void reset();

private:
	bool		m_bPPPoEEnableFlag;											//����PPPoE��ʶ(true�����ã�false��������)

	char		m_szPPPoEUserName[CONST_MAXLENGTH_PPPOE_USERNAME + 1];		//PPPoE�û���

	char		m_szPPPoEPassword[CONST_MAXLENGTH_PPPOE_PASSWORD + 1];		//PPPoE����
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif //_PPPOEPARAM_H_

