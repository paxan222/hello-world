#ifndef _DEVICEAVSTREAMPARAM_H_
#define _DEVICEAVSTREAMPARAM_H_

#include "SNPlatOS.h"
#include "DomainConst.h"
#include "AVStreamParam.h"
#include <vector>

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

class SN_DLL_API DeviceAVStreamParam
{
public:
	DeviceAVStreamParam(void);
	~DeviceAVStreamParam(void);

	DeviceAVStreamParam(const DeviceAVStreamParam &p_objDeviceAVStreamParam);

public:

	/************************************************************************
	**������
	*		����������Ƶ�豸��Ψһ��ʶ��
	**���룺
	*		p_pszDeviceId��������Ƶ�豸��Ψһ��ʶ��
	**�����
	*		��
	**����ֵ��
	*		true �����óɹ�
	*		false������ʧ��
	**���ܣ�
	*
	*************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);


	/************************************************************************
	**������
	*		��ȡ������Ƶ�豸��Ψһ��ʶ��
	**���룺
	*		��
	**��� ��
	*		��
	*����ֵ ��
	*		������Ƶ�豸��Ψһ��ʶ��
	**���ܣ�
	*    
	*************************************************************************/
	const char* getDeviceId() const;


	void setAVStreamParamList(const std::vector<AVStreamParam>& p_objAVStreamParamList);
	const std::vector<AVStreamParam>& getAVStreamParamList()const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objDeviceAVStreamParam ������������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	DeviceAVStreamParam& operator = (const DeviceAVStreamParam &p_objDeviceAVStreamParam);

private:
	char						m_szDeviceId[CONST_MAXLENGTH_UUID + 1];		
	std::vector<AVStreamParam>	m_objAVStreamParamList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_ENCODER_ABILITY_
