#ifndef  _RECORD_QUERY_RESULT_
#define _RECORD_QUERY_RESULT_


#include "RecordTimeSegment.h"
#include "SNPlatOS.h"
#include "DomainConst.h"

#include <vector>
using namespace std;

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

class SN_DLL_API RecordQueryResult
{
public:
	RecordQueryResult();
	RecordQueryResult(const char* p_pszDeviceID, const char* p_szDeviceIP, int p_nCameraID);
	~RecordQueryResult(void);

	RecordQueryResult(const RecordQueryResult &p_RecordQueryResult);

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
	bool setDeviceID(const char* p_pszDeviceId);

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
	const char* getDeviceID() const;


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
	*		p_nCameraId	 ���豸ͨ����
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setCameraID(int p_nCameraId);

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
	const int getCameraID() const;


	/************************************************************************
	**������
	*		��ȡ�豸¼����б���Ϣ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		¼����б���Ϣ
	************************************************************************/
	const vector<RecordTimeSegment>  &getRecordTimeSegment() const;

	/************************************************************************
	**������
	*		���Ӹ��豸��¼�����Ϣ
	**���룺
	*		p_objRecordTimeSegment	�豸¼�����Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void addRecordTimeSegment(const RecordTimeSegment &p_objRecordTimeSegment);
	void addNextDateSegmentList(const std::vector<RecordTimeSegment> &p_objRecordTimeSegmentList);
	
	void setRecordTimeSegment(const vector<RecordTimeSegment> &p_objRecordTimeSegmentList);

	
	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objRecordQueryResult ��¼���ѯ�����Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	RecordQueryResult& operator = (const RecordQueryResult &p_objRecordQueryResult);

private:
	char								m_szDeviceId[CONST_MAXLENGTH_DEVICEID + 1];				//�豸id
	char								m_szDeviceIp[CONST_MAXLENGTH_IP + 1];					//�豸IP��ַ
	int									m_nCameraID;											//��������
	vector<RecordTimeSegment>			m_objTimeSegmentList;									//ʱ����б�
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif  //_RECORD_QUERY_RESULT_
