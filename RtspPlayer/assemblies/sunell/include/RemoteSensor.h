#ifndef _REMOTESENSOR_H_
#define _REMOTESENSOR_H_

#include "DeviceInfoEx.h"

#include "SNPlatOS.h"

class ITransfer;

#ifndef byte
typedef unsigned char byte;
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

class SN_DLL_API RemoteSensor
{
public:
	RemoteSensor();

	RemoteSensor(const DeviceInfo &p_objDeviceInfo);

	RemoteSensor(const DeviceInfoEx &p_objDeviceInfoEx);

	~RemoteSensor(void);
public:
	/************************************************************************
	**������
	*		����DeviceInfo
	**���룺
	*		DeviceInfo �豸��Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		���ò��������Ĺ��캯��������ʱ����open֮ǰ������ø÷���
	*************************************************************************/
	void setDeviceInfo(const DeviceInfo &p_objDeviceInfo);

	void setDeviceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

public:
	/************************************************************************
	**������
	*		������������Ƶ�豸֮������紫��ĳ�ʱʱ��
	**���룺
	*		p_nTimeout����ʱʱ�䣬�Ժ��루ms��Ϊ��λ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setTimeout(const int p_nTimeout);

	/************************************************************************
	**������
	*		������������Ƶ�豸֮���Զ�̴��ڻỰ
	**���룺
	*		p_nReopenTimes    ������ʧ���ظ����ӣ�p_nReopenTimesΪ�����ӵ��ܴ���
	**�����
	*		��
	**����ֵ��
	*		��open�����ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int open(int p_nReopenTimes=1);

	/************************************************************************
	**������
	*		��ȡǰ��ģ������
	**���룺
	*		��
	**�����
	*		p_SensorType			ǰ��ģ������
	**����ֵ��
	*		���ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		1.����ȡ��ģ������ΪNULL_TYPE�����ʾ���豸��֧�ֿ��ƹ��ܡ�
	*************************************************************************/
	int getSensorType(int &p_SensorType);

	/************************************************************************
	**������
	*		��ȡ�����ʼ�����ַ���
	**���룺
	*		p_UIInitConfigBuffer	���ջ���
	*		p_BufferLength			���ջ����С
	**�����
	*		p_UIInitConfigBuffer	ʵ�ʷ��ص����ݽ��´�����û�����
	*		p_DataLength			ʵ�ʷ��ص����ݳ���
	**����ֵ��
	*		���ɹ�����SN_SUCCESS;
	*		�������С���㣬�򷵻�SN_ERROR_NOT_ENOUGH_MEMORY,p_DataLength��ʾʵ�ʴ�С;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		1.������Ҫʹ���ṩ�Ľ������ɽӿڣ���ýӿڿ��Բ������á�
	*		2.ʹ�ø÷�����p_UIInitConfigBuffer�ڴ��ɵ������Լ����䡣
	*************************************************************************/
	int getUIInitConfig(char *p_UIInitConfigBuffer,int p_BufferLength,int &p_DataLength);

	int getUIStyleConfig(char *p_UIInitConfigBuffer,int p_BufferLength,int &p_DataLength);
	int getUICommonConfig(int p_nLanguageId,char *p_UIInitConfigBuffer,int p_BufferLength,int &p_DataLength);
	int getUILanguageConfig(int p_nLanguageId,char *p_UIInitConfigBuffer,int p_BufferLength,int &p_DataLength);

	/************************************************************************
	**������
	*		���ò���ǰ��ģ�����
	**���룺
	*		p_pszParameter���������ݣ���ʽΪ(id1,value1)(id2,value2)����
	*		p_nDateLen    ����������
	**�����
	*		��
	**����ֵ��
	*		���ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setParameters(const char* p_pszParameter, const int p_nDataLen);

	/************************************************************************
	**������
	*		��ȡǰ��ģ��ָ������ֵ
	**���룺
	*		p_pszParameterIdList	��������б���ʽΪ(id1,id2,����)
	*		p_nDataLen				��������б���
	*		p_ParameterBuffer		���ڽ��ղ����Ļ���(�������10K���ϵ��ڴ�ռ�)
	*		p_ParameterBufferLen	���ڽ��ղ����Ļ����С
	**�����
	*		p_ParameterBuffer		�������ݣ���ʽΪ(id1,value1)(id2,value2)����
	*		p_OutDataLen			�������ݳ���(�ֽ���)
	**����ֵ��
	*		���ɹ�����SN_SUCCESS;
	*		�������С���㣬�򷵻�SN_ERROR_NOT_ENOUGH_MEMORY,p_OutDataLen��ʾʵ�ʴ�С;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getParameters(const char* p_pszParameterIdList, const int p_nInDataLen,char *p_ParameterBuffer,int p_ParameterBufferLen,int &p_OutDataLen);

	/************************************************************************
	**������
	*		��ȡ����ǰ��ģ�����
	**���룺
	*		p_ParameterBuffer		���ڽ��ղ����Ļ���(�������10K���ϵ��ڴ�ռ�)
	*		p_ParameterBufferLen	���ڽ��ղ����Ļ����С
	**�����
	*		p_ParameterBuffer		�������ݣ���ʽΪ(id1,value1)(id2,value2)����
	*		p_OutDataLen			�������ݳ���(�ֽ���)
	**����ֵ��
	*		���ɹ�����SN_SUCCESS;
	*		�������С���㣬�򷵻�SN_ERROR_NOT_ENOUGH_MEMORY,p_OutDataLen��ʾʵ�ʴ�С;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int getAllParameters(char *p_ParameterBuffer,int p_ParameterBufferLen,int &p_OutDataLen);

	/************************************************************************
	**������
	*		�������ָ�����������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int resetParameters();

	/************************************************************************
	**������
	*		�������ָ������һ�α�������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int resetToLastParameters();

	/************************************************************************
	**������
	*		�����������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		���ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int save();

	/************************************************************************
	**������
	*		������˽����
	**���룺
	*		p_pszSecretArea���������ݣ���ʽΪ(x,y,width,hight)(x,y,width,hight)����
	*		p_nDateLen    ����������
	**�����
	*		��
	**����ֵ��
	*		���ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	*************************************************************************/
	int setSecretArea(const char* p_pszSecretArea, const int p_nDataLen);

	/************************************************************************
	**������
	*		�ر���������Ƶ�豸�����ûỰ�����رմ򿪵�Զ�̴���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�ر���������Ƶ�豸�����ûỰ
	*************************************************************************/
	void close();

	/************************************************************************
	**������
	*		����ǰ�����ò�������
	**���룺
	*		p_nScheme ����ID
	**�����
	*		��
	**����ֵ��
	*		���ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		ѡ��ǰ�����ò�������
	*************************************************************************/
	int setParamScheme(const int p_nScheme);

	/************************************************************************
	**������
	*		��ȡ��ǰ��ǰ�����ò�������
	**���룺
	*		��
	**�����
	*		p_nScheme ��ȡ���ķ���ID
	**����ֵ��
	*		���ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ��ǰ��ǰ�����ò�������
	*************************************************************************/
	int getParamScheme(int &p_nScheme);

	/************************************************************************
	**������
	*		����ǰ�����ò���ģʽ
	**���룺
	*		p_nMode ���ò���ģʽ
	**�����
	*		��
	**����ֵ��
	*		���ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����ǰ�����ò���ģʽ
	*************************************************************************/
	int setParamMode(const int p_nMode);

	/************************************************************************
	**������
	*		��ȡ��ǰ��ǰ�����ò���ģʽ
	**���룺
	*		��
	**�����
	*		p_nMode ��ȡ�������ò���ģʽ
	**����ֵ��
	*		���ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		��ȡ��ǰ��ǰ�����ò���ģʽ
	*************************************************************************/
	int getParamMode(int &p_nMode);
private:
	/************************************************************************
	**������
	*		��ȡǰ��ģ������
	**���룺
	*		��
	**�����
	*		p_SupportFlag			true��ʾ֧�֣�flase��ʾ��֧��
	**����ֵ��
	*		���ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		1.����ȡ��ģ������ΪNULL_TYPE�����ʾ���豸��֧�ֿ��ƹ��ܡ�
	*************************************************************************/
	int getSupportFlag(bool &p_SupportFlag);

	//�������캯��
	RemoteSensor(const RemoteSensor& p_objObject)
	{
	}

	//��ֵ����
	RemoteSensor& operator = (const RemoteSensor& p_objObject)
	{
		return *this;
	}
private:

	DeviceInfoEx	m_objDeviceInfoEx;			//�豸��Ϣ

	ITransfer *		m_pobjTransfer;				//������

	InetAddr		m_objServerAddr;			//��ַ

	int				m_nTimeout;					//��ʱʱ�䣬�Ժ���Ϊ��λ��ms��

	int				m_nTransferProtocol;		//����Э��

	int				m_nSessionId;

	bool			m_bSupportFlag;				//�Ƿ�֧�֣�true��ʾ֧�֣�false��ʾ��֧��

	bool			m_bIsOpen;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_REMOTESENSOR_H_
