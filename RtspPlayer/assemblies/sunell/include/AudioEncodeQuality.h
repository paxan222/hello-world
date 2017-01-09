#ifndef _AUDIOENCODEQUALITY_H_
#define _AUDIOENCODEQUALITY_H_

#include "DomainConst.h"
#include <string>
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

class SN_DLL_API AudioEncodeQuality
{
public:

	AudioEncodeQuality(void);

	~AudioEncodeQuality(void);

	//�������캯��
	AudioEncodeQuality(const AudioEncodeQuality& p_objAudioEncodeQuality);

public:

	//���ø�ʽ���
	void setFormatTag(const unsigned short p_nFormatTag);
	//��ȡ��ʽ���
	const unsigned short getFormatTag() const;

	//��������ͨ������������
	void setChannels(const unsigned short p_nChannels);
	//��ȡ����ͨ������������
	const unsigned short getChannels() const;

	//����ÿ�������
	void setSamplesPerSec(const unsigned long p_nSamplesPerSec);
	//��ȡÿ�������
	const unsigned long getSamplesPerSec() const;

	void setAvgBytesPerSec(const unsigned long p_nAvgBytesPerSec);
	const unsigned long getAvgBytesPerSec() const;

	void setBlockAlign(const unsigned short p_nBlockAlign);
	const unsigned short getBlockAligns() const;

	//����ÿ�β����Ĵ�С
	void setBitsPerSample(const unsigned short p_nBitsPerSample);
	//��ȡÿ�β����Ĵ�С
	const unsigned short getBitsPerSample() const;

	//����׷�����ݳ���
	void setCBSize(const unsigned short p_nCBSize);
	//��ȡ׷�����ݳ���
	const unsigned short getCBSize() const;

	//���ñ����ʽ
	void setEncodeType(const int p_nCompression);
	//��ȡ�����ʽ
	const int getEncodeType() const;

	/************************************************************************
	**������
	*		��ֵ����
	**���룺
	*		p_objAudioEncodeQuality����Ƶ������������
	**�����
	*		��
	**����ֵ��
	*		��ֵ�����Ƶ������������
	**���ܣ�       
	*
	************************************************************************/
	AudioEncodeQuality& operator =(const AudioEncodeQuality &p_objAudioEncodeQuality);

	/****************************************************************************
	**������
	*		���塰���ڡ�������
	**���룺
	*		p_objAudioEncodeQuality��AudioEncodeQuality���һ����������á�
	**�����
	*		��
	**����ֵ��
	*		true:���
	*		false�������
	**���ܣ�
	*		����AudioEncodeQuality��Ķ����������Ծ���ȣ���˵��������������ȣ�����true
	*�����һ�����Բ��ȣ��򷵻�false��
	*****************************************************************************/
	bool operator == (const AudioEncodeQuality& p_objAudioEncodeQuality) const;

	bool operator < (const AudioEncodeQuality& p_objAudioEncodeQuality) const;

private:

	unsigned short		m_nFormatTag;					//��ʽ���

	unsigned short		m_nChannels;					//����ͨ������������

	unsigned long		m_nSamplesPerSec;				//ÿ�������

	unsigned long		m_nAvgBytesPerSec;				//

	unsigned short		m_nBlockAlign;					//

	unsigned short		m_nBitsPerSample;				//ÿ�β����Ĵ�С

	unsigned short		m_nCBSize;						//����׷�����ݳ���

	int					m_nEncodeType;					//�����ʽ


}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif //_AUDIOENCODEQUALITY_H_
