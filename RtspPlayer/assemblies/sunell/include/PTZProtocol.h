#ifndef _PTZPROTOCOL_H_
#define _PTZPROTOCOL_H_

#include "DomainConst.h"

#include <string.h>
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

class SN_DLL_API PTZProtocol
{
public:
	enum 
	{
		PROTOCOL_PELCO_D		= 0,	//PELCO_DЭ��
		PROTOCOL_PELCO_P		= 1,	//PELCO_PЭ��
		PROTOCOL_SN				= 2,	//SN�Զ���Э��
		PROTOCOL_PELCO_D_YA		= 3		//�ǰ�PELCO_DЭ��
	};

public:
	PTZProtocol();
	~PTZProtocol();

	PTZProtocol(const PTZProtocol& p_objPTZProtocol);

public:
	/************************************************************************
	**������
	*		������̨Э���ID��
    **���룺
	*		p_nProtocolId ����̨Э���ID��
	**�����
	*		��
	*����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void setProtocolId(const int p_nProtocolId);

	/************************************************************************
	**������
	*		��ȡ��̨Э���ID��
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��̨Э���ID��
	**���ܣ�
	*    
	************************************************************************/
	const int getProtocolId() const;

	/************************************************************************
	**������
	*		������̨Э�������
    **���룺
	*	  p_pszProtocolName ����̨Э������֣��ַ�������󳤶�
	*						  ΪCONST_MAXLENTH_PTZ_PROTOCOL_NAME�ֽ�,��β�ԡ�\0�������� 
	**�����
	*		��
	**����ֵ��
	*		true ���ɹ�
	*		false��ʧ��
	*���ܣ�
	*    ������p_pszProtocolName����<=CONST_MAXLENTH_PTZ_PROTOCOL_NAME������true�������浽m_szProtocolName;
	*	 ������p_pszProtocolNameΪnull�����䳤��>CONST_MAXLENTH_PTZ_PROTOCOL_NAME������false
	************************************************************************/
	bool setProtocolName(const char* p_pszProtocolName);

	/************************************************************************
	**������
	*		��ȡ��̨Э�������
    **���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��̨Э������ֵĵ�ַ
	**���ܣ�
	*		
	************************************************************************/
	const char* getProtocolName() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objPTZProtocol����̨Э��
	**�����
	*		��
	**����ֵ��
	*		��̨Э��
	**���ܣ�
	************************************************************************/
	PTZProtocol& operator =(const PTZProtocol& p_objPTZProtocol);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objPTZProtocol��PTZProtocol���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����PTZProtocol��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*		�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const PTZProtocol& p_objPTZProtocol);

private:
	
	int		m_nProtocolId;													//��̨Э���ID��
	
	char	m_szProtocolName[CONST_MAXLENTH_PTZ_PROTOCOL_NAME + 1];			//��̨Э�������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //__PTZPROTOCOL_H__

