#ifndef  _RECORD_FILE_EX_
#define  _RECORD_FILE_EX_

#include "RecordDirInfo.h"
#include "SNPlatOS.h"
#include "DomainConst.h"
#include "TimeStruct.h"

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

class SN_DLL_API RecordFileEx
{
public:
	RecordFileEx(void);
	~RecordFileEx(void);

	RecordFileEx(const RecordFileEx &p_RecordFile);

public:
	/***********************************************************************
	**������
	*		�����豸Id��
	**���룺
	*		p_pszDeviceId���豸Id
	**�����
	*		��
	**����ֵ��
	*		true	�����óɹ�
	*		false   ������ʧ��
	**���ܣ�
	************************************************************************/
	bool setDeviceId(const char* p_pszDeviceId);

	/************************************************************************
	**������
	*		��ȡ�豸Id
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�豸ID
	**���ܣ�
	*
	***************************************************************************/
	const char* getDeviceId() const;


	/***********************************************************************
	**������
	*		�����豸IP��ַ
	**���룺
	*		p_strDeviceIP���豸IP��ַ
	**�����
	*		��
	**����ֵ��
	*		true	�����óɹ�
	*		false   ������ʧ��
	**���ܣ�
	************************************************************************/
	bool setDeviceIP(const char* p_pszDeviceIP);

	/***********************************************************************
	**������
	*		��ȡ�豸IP��ַ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�豸IP��ַ
	**���ܣ�
	************************************************************************/
	const char* getDeviceIP() const;


	/************************************************************************
	**������
	*		�����豸ͨ����
	**���룺
	*		p_nCameraId	�豸ͨ����
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setCameraId(int p_nCameraId);

	/************************************************************************
	**������
	*		��ȡ�豸ͨ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�豸ͨ����
	************************************************************************/
	const int getCameraId() const;


	/************************************************************************
	**������
	*		��ȡ¼���ļ���ʼʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		¼���ļ���ʼʱ�䣬��λ��s
	************************************************************************/
	const unsigned long getRecordFileBeginTime() const;
	const TimeStruct& getStructRecordFileBeginTime() const;

	/************************************************************************
	**������
	*		����¼���ļ���ʼʱ��
	**���룺
	*		p_nRecordFileBeginTime :¼���ļ���ʼʱ�䣬��λ��s
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setRecordFileBeginTime(unsigned long p_nRecordFileBeginTime);
	void setStructRecordFileBeginTime(const TimeStruct& p_objTime);

	/************************************************************************
	**������
	*		����¼���ļ���
	**���룺
	*		p_RecordFileName��¼���ļ���
	**�����
	*		��
	**����ֵ��
	*		
	************************************************************************/
	bool setRecordFileName(const char *p_RecordFileName);

	/************************************************************************
	**������
	*		��ȡ¼���ļ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		¼���ļ���
	************************************************************************/
	const char * getRecordFileName() const;


	/************************************************************************
	**������
	*		����¼���ļ�Ŀ¼��Ϣ
	**���룺
	*		p_RecordDirInfo	¼���ļ�Ŀ¼��Ϣ
	**�����
	*		��
	**����ֵ��
	*		
	************************************************************************/
	void setRecordDirInfo(const RecordDirInfo & p_RecordDirInfo);

	/************************************************************************
	**������
	*		��ȡ¼���ļ�Ŀ¼��Ϣ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		¼���ļ�Ŀ¼��Ϣ
	************************************************************************/
	const RecordDirInfo& getRecordDirInfo() const;


	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objRecordFile ��¼���ļ���Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	RecordFileEx& operator = (const RecordFileEx& p_objRecordFile);

private:
	char				m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];					//�豸id
	char				m_szDeviceIp[CONST_MAXLENGTH_IP + 1];						//�豸IP��ַ
	int					m_nCameraId;												//�豸ͨ����
	unsigned long		m_nRecordFileBeginTime;										//¼��ʼʱ�䣬��λS
	TimeStruct			m_objRecordFileBeginTime;									//
	char				m_szRecordFileName[CONST_MAXLENGTH_FILE_NAME+1];			//�ļ���
	RecordDirInfo		m_objRecordDirInfo;											//¼���ļ�Ŀ¼��Ϣ
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/
#endif  //_RECORD_FILE_EX_

