#ifndef _EXTERNDEVICEABILITY_H_
#define _EXTERNDEVICEABILITY_H_

#include <vector>
#include <string>
#include "ExternComInfo.h"
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
/*********************************************************************
�ⲿ�����������豸֧�ִ��������Ϣ
**********************************************************************/

class SN_DLL_API ExternDeviceAbility
{
public:
	ExternDeviceAbility(void);
	~ExternDeviceAbility(void);
	
	/****************************************************************************
	**������
	*		�����ⲿ������Ϣ�б�
	**���룺
	*		p_vecExternComInfoList���ⲿ������Ϣ�б�
	**�����
	*		��
	**����ֵ��
	*		�� 
	**���ܣ�
	*		
	*******************************************************************************/
	void setExternComInfoList(const std::vector<ExternComInfo>& p_vecExternComInfoList);

	/****************************************************************************
	**������
	*		��ȡ�ⲿ������Ϣ�б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�ⲿ������Ϣ�б�
	**���ܣ�
	*		
	*******************************************************************************/
	const std::vector<ExternComInfo>& getExternComInfoList() const;

	/****************************************************************************
	**������
	*		���ò������б�
	**���룺
	*		p_vecBaudRateList���������б�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*******************************************************************************/
	void setBaudRateList(const std::vector<int>& p_vecBaudRateList);

	/****************************************************************************
	**������
	*		��ȡ�������б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������б�
	**���ܣ�
	*		
	*******************************************************************************/
	const std::vector<int>& getBaudRateList() const;

	/****************************************************************************
	**������
	*		��������λ�б�
	**���룺
	*		p_vecDataBitsList������λ�б�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*******************************************************************************/
	void setDataBitsList(const std::vector<int>& p_vecDataBitsList);

	/****************************************************************************
	**������
	*		��ȡ����λ�б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����λ�б�
	**���ܣ�
	*		
	*******************************************************************************/
	const std::vector<int>& getDataBitsList() const;

	/****************************************************************************
	**������
	*		����ֹͣλ�б�
	**���룺
	*		p_vecStopBitsList��ֹͣλ�б�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*******************************************************************************/
	void setStopBitsList(const std::vector<std::string>& p_vecStopBitsList);

	/****************************************************************************
	**������
	*		��ȡֹͣλ�б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ֹͣλ�б�
	**���ܣ�
	*		
	*******************************************************************************/
	const std::vector<std::string>& getStopBitsList() const;

	/****************************************************************************
	**������
	*		������żУ��λ�б�
	**���룺
	*		p_vecParityList����żУ��λ�б�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*******************************************************************************/
	void setParityList(const std::vector<std::string>& p_vecParityList);

	/****************************************************************************
	**������
	*		��ȡ��żУ��λ�б�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��żУ��λ�б�
	**���ܣ�
	*		
	*******************************************************************************/
	const std::vector<std::string>& getParityList() const;

	ExternDeviceAbility& operator =(const ExternDeviceAbility& p_objExternDeviceAbility);
private:
	std::vector<ExternComInfo>	m_objExternComInfoList;
	std::vector<int>			m_vecBaudRateList;
	std::vector<int>			m_vecDataBitsList;
	std::vector<std::string>	m_vecStopBitsList;
	std::vector<std::string>	m_vecParityList;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
	#ifdef WIN32  
	#pragma pack(pop)
	#endif
#endif
/**********************************************************************/

#endif //_DEVICETYPE_H_
