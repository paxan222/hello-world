#ifndef  _RECORD_TIME_SEGMENT_
#define  _RECORD_TIME_SEGMENT_

#include "SNPlatOS.h"
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

class SN_DLL_API RecordTimeSegment
{
public:
	RecordTimeSegment(void);
	RecordTimeSegment(unsigned long p_nBeginTime,unsigned long p_nEndTime,bool p_bIsLock,unsigned long p_DataLength,bool p_IsAlarm);
	~RecordTimeSegment(void);

	RecordTimeSegment(const RecordTimeSegment &p_RecordTimeSegment);

public:

	/************************************************************************
	**������
	*		����¼��ʼʱ��
	**���룺
	*		p_nRecordBeginTime	�豸¼��ο�ʼʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setRecordBeginTime(unsigned long p_nRecordBeginTime);
	void setStructRecordBeginTime(const TimeStruct& p_objTime);

	/************************************************************************
	**������
	*		��ȡ¼��ʼʱ��
	**���룺
	*		��ȡ¼��ʼʱ��
	**�����
	*		��
	**����ֵ��
	*		¼��ʼʱ��
	************************************************************************/
	const unsigned long getRecordBeginTime() const;
	const TimeStruct& getStructRecordBeginTime() const;


	/************************************************************************
	**������
	*		����¼�����ʱ��
	**���룺
	*		p_nRecordEndTime	�豸¼��ν���ʱ��
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setRecordEndTime(unsigned long p_nRecordEndTime);
	void setStructRecordEndTime(const TimeStruct& p_objTime);

	/************************************************************************
	**������
	*		��ȡ¼��ν���ʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		¼�����ʱ��
	************************************************************************/
	const unsigned long getRecordEndTime() const;
	const TimeStruct& getStructRecordEndTime() const;


	/************************************************************************
	**������
	*		����¼�������
	**���룺
	*		p_isLock	��true �����ļ���false �����ļ�
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void   setRecordLockFlag(bool p_isLock);
	
	/************************************************************************
	**������
	*		��ȡ��ǰ¼���Ƿ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		true���ļ�����
	*		false���ļ�û�м���
	************************************************************************/
	const bool getRecordLockFlag() const;

	/************************************************************************
	**������
	*		����¼�񱨾����
	**���룺
	*		p_isAlarm	��true ������false ���Ǳ����ļ�
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void   setRecordAlarmFlag(bool p_isAlarm);

	/************************************************************************
	**������
	*		��ȡ��ǰ¼���Ƿ񱨾�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		true���ļ�����
	*		false���ļ�û�б���
	************************************************************************/
	const bool getRecordAlarmFlag() const;


	/************************************************************************
	**������
	*		����¼�����ݳ���
	**���룺
	*		p_nRecordDataLength	��¼�����ݳ���
	**�����
	*		��
	**����ֵ��
	*		��
	************************************************************************/
	void setRecordDataLength(unsigned long p_nRecordDataLength);

	/************************************************************************
	**������
	*		��ȡ¼�����ݳ���
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		¼�����ݳ���
	************************************************************************/
	const unsigned long getRecordDataLength() const;

	void setVideoEncoderType(int p_nVideoEncoderType);

	const int getVideoEncoderType() const;


	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objRecordTimeSegment ��¼��ʱ�����Ϣ
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*
	************************************************************************/
	RecordTimeSegment& operator = (const RecordTimeSegment &p_objRecordTimeSegment);

private:
	unsigned long					m_nBeginTime;				//��ʼʱ��
	TimeStruct						m_objRecordBeginTime;		//
	unsigned long					m_nEndTime;					//����ʱ��
	TimeStruct						m_objRecordEndTime;			//
	bool							m_bIsLock;					//�ļ��Ƿ����
	unsigned long					m_nRecordDataLength;		//��ʱ��������ݳ���
	bool							m_bIsAlarmRecordFlag;		//�Ƿ��Ǳ���¼��
	int								m_nVideoEncoderType;		//��Ƶ��������
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_RECORD_TIME_SEGMENT_
