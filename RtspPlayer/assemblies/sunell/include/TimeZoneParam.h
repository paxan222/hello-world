#ifndef _TIMEZONEPARAM_H_
#define _TIMEZONEPARAM_H_

#include "DomainConst.h"
#include "SNPlatOS.h"

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

class SN_DLL_API TimeZoneParam
{
public:
	TimeZoneParam(void);
	~TimeZoneParam(void);

	TimeZoneParam(const TimeZoneParam& p_objTimeZoneParam);

public:

	/************************************************************************
	**������
	*		����ʱ��
	**���룺
	*		p_nTimeZone ��ʱ��ID������IDֵ��鿴�ļ�ĩβ�Ķ�Ӧ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	void setTimeZone(const int p_nTimeZone);

	/************************************************************************
	**������
	*		��ȡʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		ʱ��
	**���ܣ�       
	*		
	************************************************************************/
	const int getTimeZone() const;


	/************************************************************************
	**������
	*		�����Ƿ���������ʱ��־
	**���룺
	*		p_bDSTOpenFlag ����������ʱ��־
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	void setDSTOpenFlag(const bool p_bDSTOpenFlag);

	/************************************************************************
	**������
	*		��ȡ��������ʱ��־
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��������ʱ��־
	**���ܣ�       
	*		
	************************************************************************/
	const bool getDSTOpenFlag() const;


	/************************************************************************
	**������
	*		��������ʱƫ�ƣ��˽ӿ�Ԥ�����ݲ�֧�֣�
	**���룺
	*		p_nDSTOffset ������ʱƫ��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	void setDSTOffset(const int p_nDSTOffset);

	/************************************************************************
	**������
	*		��ȡ����ʱƫ�ƣ��˽ӿ�Ԥ�����ݲ�֧�֣�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ʱƫ��
	**���ܣ�       
	*		
	************************************************************************/
	const int getDSTOffset() const;


	/************************************************************************
	**������
	*		��������ʱ��ʼ�·�
	**���룺
	*		p_nBeginMonth ������ʱ��ʼ�·�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	void setBeginMonth(const int p_nBeginMonth);

	/************************************************************************
	**������
	*		��ȡ����ʱ��ʼ�·�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ʱ��ʼ�·�
	**���ܣ�       
	*		
	************************************************************************/
	const int getBeginMonth() const;


	/************************************************************************
	**������
	*		��������ʱ��ʼ��
	**���룺
	*		p_nBeginWeekly ������ʱ��ʼ�ܣ�һ���еĵڼ��ܣ�5Ϊ���һ�ܣ�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	void setBeginWeekly(const int p_nBeginWeekly);

	/************************************************************************
	**������
	*		��ȡ����ʱ��ʼ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ʱ��ʼ�ܣ�һ���еĵڼ��ܣ�5Ϊ���һ�ܣ�
	**���ܣ�       
	*		
	************************************************************************/
	const int getBeginWeekly() const;


	/************************************************************************
	**������
	*		��������ʱ��ʼ���ڼ�
	**���룺
	*		p_nBeginWeekDays ������ʱ��ʼ���ڼ���0-6,0Ϊ���գ�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	void setBeginWeekDays(const int p_nBeginWeekDays);

	/************************************************************************
	**������
	*		��ȡ����ʱ��ʼ���ڼ�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ʱ��ʼ���ڼ���0-6,0Ϊ���գ�
	**���ܣ�       
	*		
	************************************************************************/
	const int getBeginWeekDays() const;


	/************************************************************************
	**������
	*		��������ʱ��ʼʱ��
	**���룺
	*		p_nBeginTime ������ʱ��ʼʱ�䣬��00:00��ʼ����ǰʱ��ķ���������10:30Ϊ630,��λ����(m)
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	void setBeginTime(const unsigned int p_nBeginTime);

	/************************************************************************
	**������
	*		��ȡ����ʱ��ʼʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ʱ��ʼʱ�䣬��00:00��ʼ����ǰʱ��ķ���������10:30Ϊ630,��λ����(m)
	**���ܣ�       
	*		
	************************************************************************/
	const unsigned int getBeginTime() const;


	/************************************************************************
	**������
	*		��������ʱ������
	**���룺
	*		p_nEndMonth ������ʱ������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	void setEndMonth(const int p_nEndMonth);

	/************************************************************************
	**������
	*		��ȡ����ʱ������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ʱ������
	**���ܣ�       
	*		
	************************************************************************/
	const int getEndMonth() const;


	/************************************************************************
	**������
	*		��������ʱ������
	**���룺
	*		p_nEndWeekly ������ʱ�����ܣ�һ���еĵڼ��ܣ�5Ϊ���һ�ܣ�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	void setEndWeekly(const int p_nEndWeekly);

	/************************************************************************
	**������
	*		��ȡ����ʱ������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ʱ�����ܣ�һ���еĵڼ��ܣ�5Ϊ���һ�ܣ�
	**���ܣ�       
	*		
	************************************************************************/
	const int getEndWeekly() const;


	/************************************************************************
	**������
	*		��������ʱ�������ڼ�
	**���룺
	*		p_nEndWeekDays ������ʱ�������ڼ���0-6,0Ϊ���գ�
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	void setEndWeekDays(const int p_nEndWeekDays);

	/************************************************************************
	**������
	*		��ȡ����ʱ�������ڼ�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ʱ�������ڼ���0-6,0Ϊ���գ�
	**���ܣ�       
	*		
	************************************************************************/
	const int getEndWeekDays() const;


	/************************************************************************
	**������
	*		��������ʱ����ʱ��
	**���룺
	*		p_nEndTime������ʱ����ʱ�䣬��00:00��ʼ����ǰʱ��ķ���������10:30Ϊ630,��λ����(m)
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�       
	*		
	************************************************************************/
	void setEndTime(const unsigned int p_nEndTime);

	/************************************************************************
	**������
	*		��ȡ����ʱ����ʱ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		����ʱ����ʱ�䣬��00:00��ʼ����ǰʱ��ķ���������10:30Ϊ630,��λ����(m)
	**���ܣ�       
	*		
	************************************************************************/
	const unsigned int getEndTime() const;


	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objTimeZoneParam���豸����������Ϣ
	**�����
	*		��
	**����ֵ��
	*		�豸����������Ϣ
	**���ܣ�
	************************************************************************/
	TimeZoneParam& operator =(const TimeZoneParam& p_objTimeZoneParam);

	static float getTimeZoneOffset(const int p_nTimeZoneID);

private:
	
	int				m_nTimeZone;												//ʱ��

	bool			m_bDSTOpenFlag;												//����ʱ������־

	int				m_nDSTOffset;												//����ʱƫ�ƣ�����Ϊ��λ

	int				m_nBeginMonth;												//����ʱ��ʼ�·�
	int				m_nBeginWeekly;												//����ʱ��ʼ�ܣ�һ���еĵڼ��ܣ�5Ϊ���һ�ܣ�
	int				m_nBeginWeekDays;											//���ڼ�(0-6),0Ϊ����
	unsigned int	m_nBeginTime;												//��ʼʱ�䣬��00:00��ʼ����ǰʱ��ķ���������01:30Ϊ90,��λ����(m)
	
	int				m_nEndMonth;												//����ʱ�����·�
	int				m_nEndWeekly;												//����ʱ�����ܣ�һ���еĵڼ��ܣ�5Ϊ���һ�ܣ�
	int				m_nEndWeekDays;												//���ڼ�(0-6),0Ϊ����
	unsigned int	m_nEndTime;													//����ʱ�䣬��00:00��ʼ����ǰʱ��ķ���������10:30Ϊ630,��λ����(m)

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_TIMEZONEPARAM_H_

/* setTimeZone()����ζ�Ӧ��,TimeZoneId=""Ϊ�����p_nTimeZoneֵ

<ConfigItem TimeZoneId="0" name="(GMT-12:00)�������ڱ������"/>
<ConfigItem TimeZoneId="1" name="(GMT-11:00) ��;������Ħ��Ⱥ��"/>
<ConfigItem TimeZoneId="2" name="(GMT-10:00) ������"/>
<ConfigItem TimeZoneId="3" name="(GMT-09:00) ����˹��"/>
<ConfigItem TimeZoneId="4" name="(GMT-08:00) ̫ƽ��ʱ��(�����ͼ��ô�)"/>
<ConfigItem TimeZoneId="5" name="(GMT-08:00) �¼�����������"/>
<ConfigItem TimeZoneId="10" name="(GMT-07:00) ɽ��ʱ��(�����ͼ��ô�)"/>
<ConfigItem TimeZoneId="13" name="(GMT-07:00)�����ߣ�����˹����������"/>
<ConfigItem TimeZoneId="15" name="(GMT-07:00) ����ɣ��"/>
<ConfigItem TimeZoneId="20" name="(GMT-06:00) �в�ʱ��(�����ͼ��ô�)"/>
<ConfigItem TimeZoneId="25" name="(GMT-06:00) ��˹������"/>
<ConfigItem TimeZoneId="30" name="(GMT-06:00)�ϴ���������ī����ǣ�������"/>
<ConfigItem TimeZoneId="33" name="(GMT-06:00) ������"/>
<ConfigItem TimeZoneId="35" name="(GMT-05:00) ����ʱ��(�����ͼ��ô�)"/>
<ConfigItem TimeZoneId="40" name="(GMT-05:00) ӡ�ذ�����(����)"/>
<ConfigItem TimeZoneId="45" name="(GMT-05:00) �������������"/>
<ConfigItem TimeZoneId="50" name="(GMT-04:00) ������ʱ��(���ô�)"/>
<ConfigItem TimeZoneId="55" name="(GMT-04:30) ������˹"/>
<ConfigItem TimeZoneId="56" name="(GMT-04:00) ʥ���Ǹ�"/>
<ConfigItem TimeZoneId="60" name="(GMT-03:30) Ŧ����"/>
<ConfigItem TimeZoneId="65" name="(GMT-03:00) ��������"/>
<ConfigItem TimeZoneId="70" name="(GMT-03:00) ����ŵ˹����˹"/>
<ConfigItem TimeZoneId="73" name="(GMT-03:00) ������"/>
<ConfigItem TimeZoneId="75" name="(GMT-02:00) �д�����"/>
<ConfigItem TimeZoneId="80" name="(GMT-01:00) ���ٶ�Ⱥ��"/>
<ConfigItem TimeZoneId="83" name="(GMT-01:00) ��ý�Ⱥ��"/>
<ConfigItem TimeZoneId="85" name="(GMT) �������α�׼ʱ��: ������, ������, �׶�, ��˹��"/>
<ConfigItem TimeZoneId="90" name="(GMT) ����������������ά��"/>
<ConfigItem TimeZoneId="95" name="(GMT+01:00) ���������£�������˹������������˹��¬�������ǣ�������"/>
<ConfigItem TimeZoneId="100" name="(GMT+01:00) �������ѣ�˹�������ɳ�������ղ�"/>
<ConfigItem TimeZoneId="105" name="(GMT+01:00) ��³�������籾��������������"/>
<ConfigItem TimeZoneId="110" name="(GMT+01:00) ��ķ˹�ص������֣������ᣬ����˹�¸��Ħ��άҲ��"/>
<ConfigItem TimeZoneId="113" name="(GMT+01:00) �з�����"/>
<ConfigItem TimeZoneId="115" name="(GMT+02:00) ������˹��"/>
<ConfigItem TimeZoneId="120" name="(GMT+02:00) ����"/>
<ConfigItem TimeZoneId="125" name="(GMT+02:00) �ն���������������ӣ������ǣ����֣�ά��Ŧ˹"/>
<ConfigItem TimeZoneId="130" name="(GMT+02:00) �ŵ䣬��³�أ���˹̹��������˹��"/>
<ConfigItem TimeZoneId="135" name="(GMT+02:00) Ү·����"/>
<ConfigItem TimeZoneId="140" name="(GMT+02:00) �����ף�����������"/>
<ConfigItem TimeZoneId="145" name="(GMT+04:00) Ī˹�ƣ�ʥ�˵ñ�, �����Ӹ���"/>
<ConfigItem TimeZoneId="150" name="(GMT+03:00) �����أ����ŵ�"/>
<ConfigItem TimeZoneId="155" name="(GMT+03:00) ���ޱ�"/>
<ConfigItem TimeZoneId="158" name="(GMT+03:00) �͸��"/>
<ConfigItem TimeZoneId="160" name="(GMT+03:30) �º���"/>
<ConfigItem TimeZoneId="165" name="(GMT+04:00) �������ȣ���˹����"/>
<ConfigItem TimeZoneId="170" name="(GMT+04:00) �Ϳ⣬�ڱ���˹��������"/>
<ConfigItem TimeZoneId="175" name="(GMT+04:30) ������"/>
<ConfigItem TimeZoneId="180" name="(GMT+06:00) Ҷ�����ձ�"/>
<ConfigItem TimeZoneId="185" name="(GMT+05:00) ��˹�����������棬��ʲ��"/>
<ConfigItem TimeZoneId="190" name="(GMT+05:30) ���Σ��Ӷ����������µ���"/>
<ConfigItem TimeZoneId="193" name="(GMT+05:45) �ӵ�����"/>
<ConfigItem TimeZoneId="195" name="(GMT+06:00) ��˹���ɣ��￨"/>
<ConfigItem TimeZoneId="200" name="(GMT+05:30) ˹������׵�����"/>
<ConfigItem TimeZoneId="201" name="(GMT+08:00) ����������"/>
<ConfigItem TimeZoneId="203" name="(GMT+06:30) ����"/>
<ConfigItem TimeZoneId="205" name="(GMT+07:00) ���ȣ����ڣ��żӴ�"/>
<ConfigItem TimeZoneId="207" name="(GMT+07:00) ����˹ŵ�Ƕ�˹��"/>
<ConfigItem TimeZoneId="210" name="(GMT+08:00) ���������죬����ر�����������³ľ��"/>
<ConfigItem TimeZoneId="215" name="(GMT+08:00) ��¡�£��¼���"/>
<ConfigItem TimeZoneId="220" name="(GMT+08:00) ̨��"/>
<ConfigItem TimeZoneId="225" name="(GMT+08:00) ��˹"/>
<ConfigItem TimeZoneId="227" name="(GMT+09:00) ������Ŀ�"/>
<ConfigItem TimeZoneId="230" name="(GMT+09:00) ����"/>
<ConfigItem TimeZoneId="235" name="(GMT+09:00) ���࣬���ϣ�����"/>
<ConfigItem TimeZoneId="240" name="(GMT+09:00) �ſ�Ŀ�"/>
<ConfigItem TimeZoneId="245" name="(GMT+09:30) �����"/>
<ConfigItem TimeZoneId="250" name="(GMT+09:30) ��������"/>
<ConfigItem TimeZoneId="255" name="(GMT+10:00) ��������ī������Ϥ��"/>
<ConfigItem TimeZoneId="260" name="(GMT+10:00) ����˹��"/>
<ConfigItem TimeZoneId="265" name="(GMT+10:00) ������"/>
<ConfigItem TimeZoneId="270" name="(GMT+11:00) ��������˹�п�"/>
<ConfigItem TimeZoneId="275" name="(GMT+10:00) �ص���Ī���ȱȸ�"/>
<ConfigItem TimeZoneId="280" name="(GMT+11:00) ������Ⱥ�����¿��������"/>
<ConfigItem TimeZoneId="285" name="(GMT+12:00) 쳼ã�����Ӱ뵺�����ܶ�Ⱥ��"/>
<ConfigItem TimeZoneId="290" name="(GMT+12:00) �¿����������"/>
<ConfigItem TimeZoneId="300" name="(GMT+13:00) Ŭ�Ⱒ�巨"/>
*/
