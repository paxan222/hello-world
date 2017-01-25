#ifdef RECORD_INTERFACE
#ifndef _LOCALPLAYBACK_H_
#define _LOCALPLAYBACK_H_

#include "RecordInfo.h"
#include "SNError.h"
#include "SNPlatOS.h"
#include "RecordDirInfo.h"
#include "RecordFileEx.h"
#include <vector>

class LocalRecordPlayer;

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

class SN_DLL_API LocalPlayback
{
public:
	LocalPlayback();
	~LocalPlayback(void);

public:
	/************************************************************************
	**������
	*		����¼��Ŀ¼
	**���룺
	*		p_RecordDirInfoList��¼��Ŀ¼�б�
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void setRecordDirInfoList(const std::vector<RecordDirInfo> &p_objRecordDirInfoList);

	/************************************************************************
	**������
	*		������Ƶ����ģʽ
	**���룺
	*		p_bStretchMode����Ƶ�Ƿ�����
	*		true��	������Ƶ����Ӧ��Ļ��С
	*		false��	��������Ƶ
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void setStretchMode(const bool p_bStretchMode);

	/************************************************************************
	**������
	*		������Ƶ�����Զ����ű�־��
	**���룺
	*		p_bAutoResizeFlag�������Զ����ű�־��
	**�����
	*		��
	**����ֵ��
	*		ִ�гɹ�����0������ʱ���ش����롣
	**���ܣ�
	*		��p_AutoResizeFlag = true����ʾ���ڿ����Զ����ţ�����Ƶ���ڵĴ�С�ı�ʱ����Ƶ������Զ�������С��
	*	��ʱ����resizeWindow����Ч����֮��p_AutoResizeFlag = false����ʾ���ڲ����Զ����ţ���ʱ���Ե���
	*	resizeWindow�ı䴰�ڴ�С��
	*		�˷����������ļ���ʽ����������ʽ���š�
	************************************************************************/
	void setAutoResizeFlag(bool p_bAutoResizeFlag = true);

	/************************************************************************
	**������
	*		���ý����¼��Ĵ��ھ������Ϣ���Զ��������
	**���룺
	*		p_hNotifyWnd��	ָ��������Ϣ�Ĵ��ھ����LocalPlayback��������Ϣ���þ��ָ���Ĵ��ڡ���ΪNULL���ʾ��������Ϣ��
	*		
	*		p_nMessage��	ָ��Windows������ϢID��LocalPlayback�����͸���Ϣ����p_hNotifyWndָ���Ĵ��ڡ����Windows������Ϣ���û��Զ��壬
	*						Windows	�µ�WM_USER�������԰����û�ΪWindows���ڶ���˽����Ϣ�����巽����WM_USER+X, X��һ������ֵ��
	*		
	*		p_pParam��		ָ��������Ϣʱ��Я������Ϣ����������Ϣ����������LocalPlayback�ı䣬LocalPlayback������Ϣʱֻ�Ǽ򵥵�
	*						������Ϣ�����ַ��ظ����ڡ�
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void setNotifyWindow(const unsigned int p_nNotifyWnd, const unsigned int p_nMessage, const void * p_pParam);

	/************************************************************************
	**������
	*		������Ƶ����ʾ���ڣ�λ�úʹ�С��
	**���룺
	*		p_hDisplayWnd��	��Ƶ��ʾ���ڵľ����
	*		x��				ָ���ڴ�������Ƶ��ʾλ�õ�x���꣬��λΪ���ء�
	*		y��				ָ���ڴ�������Ƶ��ʾλ�õ�y���꣬��λΪ���ء�
	*		width��			ָ���ڴ�������Ƶ��ʾ��С�Ŀ��ȣ���λΪ���ء�
	*		height��		ָ���ڴ�������Ƶ��ʾ��С�ĸ߶ȣ���λΪ���ء�
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void setVideoWindow(const unsigned int p_hDisplayWnd, const int x, const int y, const int width, const int height);
	void setVideoWindow(const unsigned int p_hDisplayWnd);
	

public:
	/************************************************************************
	**������
	*		��һ���ļ�������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��open�����ɹ�������SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	************************************************************************/
	int open(const RecordInfo & p_objRecordInfo);

	/***********************************************************************
	**������
	*		��ftp¼���ļ���
	**���룺
	*		p_RecordFile:ftp¼���ļ���Ϣ
	**�����
	*		��
	**����ֵ��
	*		SN_SCUESS:	�򿪳ɹ�
	*		<0:			��ʧ��
	**����������
	*		����p_RecordFile��ftp¼���ļ�������ֵ����0��򿪳ɹ��������ʧ�ܡ�
	*		�ļ��򿪳ɹ�����read��ͣ�Ķ�ȡ��Ƶ���ݡ�
	************************************************************************/
	int open(const RecordFileEx &p_RecordFile);

	/************************************************************************
	**������
	*		�ر�һ���ļ�������
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�ر�һ���ļ�������
	************************************************************************/
	void close();

public:
	/************************************************************************
	**������
	*		��ʼ����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��open�����ɹ�������SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*
	************************************************************************/
	int play();

	/************************************************************************
	**������
	*		��ͣ�ļ�����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��open�����ɹ�������SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*
	************************************************************************/
	int pause();

	/************************************************************************
	**������
	*		ֹͣ�ļ�����
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��open�����ɹ�������SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*
	************************************************************************/
	int stop();

	/************************************************************************
	**������
	*		��ȡ��ǰ��������״̬
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��ǰ��������״̬
	**���ܣ�
	*
	************************************************************************/
	int getPlayStatus();

	/************************************************************************
	**������
	*		������һ֡��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int	playNextFrame();

	/************************************************************************
	**������
	*		������һ֡��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int	playPreviousFrame();

public:
	/************************************************************************
	**������
	*		������Ƶ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int	playSound();


	/************************************************************************
	**������
	*		ֹͣ������Ƶ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int stopSound();

	/************************************************************************
	**������
	*		�Ƿ����ڲ�����Ƶ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�����ڲ�����Ƶ������true;
	*		��ֹͣ������Ƶ������false;
	*************************************************************************/
	bool isOnSound();


	/************************************************************************
	**������
	*		����������
	**���룺
	*		p_nVolume������
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setVolume(const long p_nVolume);


	/************************************************************************
	**������
	*		��ȡ������
	**���룺
	*		��
	**�����
	*		p_nVolume������
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getVolume(long & p_nVolume);

public:
	/************************************************************************
	**������
	*		����������Ƶ�ڵ�ǰ���ڵ���ʾλ�úʹ�С��
	**���룺
	*		x��		�ڴ�������Ƶ��ʾλ�õ�x���꣬��λΪ���ء�
	*		y��		�ڴ�������Ƶ��ʾλ�õ�y���꣬��λΪ���ء�
	*		width��	�ڴ�������Ƶ��ʾ��С�Ŀ��ȣ���λΪ���ء�
	*		height���ڴ�������Ƶ��ʾ��С�ĸ߶ȣ���λΪ���ء�
	**�����
	*		��
	**����ֵ��
	*		��
	*************************************************************************/
	void resizeWindow(const int x, const int y, const int width, const int height);

	/************************************************************************
	**������
	*		ˢ����ʾ����
	**���룺
	*		�ޡ�
	**�����
	*		�ޡ�
	**����ֵ��
	*		SN_SUCCESS���ɹ�
	*		������		ʧ��
	**���ܣ�
	*		ˢ����ʾ���򡣵����Ŵ�����ͣ״̬ʱ����������˴����л�����ʹ��Ƶ��ʾ�����ң�
	*		���ô˽ӿ�ʹ������ػ沥������������ɫЧ����
	************************************************************************/
	int refresh( );

public:
	/************************************************************************
	**������
	*		ȡ�õ�ǰ�Ĳ���ʱ��λ��(��λ:��)
	**���룺
	*		��
	**�����
	*		p_pdblPosition,		���ص�ǰ�Ĳ���λ��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*
	**************************************************************************/
	int getPlayPosByTime(unsigned long & p_nPosition);

	/************************************************************************
	**������
	*		����ʱ�����õ�ǰ�Ĳ���λ��(��λ:��)
	**���룺
	*		��
	**�����
	*		p_dblPosition,		����λ��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*
	**************************************************************************/
	int setPlayPosByTime(const unsigned long p_nPosition );

	/************************************************************************
	**������
	*		���õ�ǰ�Ĳ�������
	**���룺
	*		p_pdRate����ǰ�Ĳ������ʣ�1.0Ϊ�������ٶȲ���
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	************************************************************************/
	int setRate (const float p_nRate );

	/************************************************************************
	**������
	*		��ȡ��ǰ�Ĳ�������
	**���룺
	*		��
	**�����
	*		p_pdRate,		��ǰ�Ĳ�������
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*
	************************************************************************/
	int getRate(float& p_nRate );

public:
	/************************************************************************
	**������
	*		��ȡ��ǰ��Ƶ��ʾ�����ȡ�
	**���룺
	*		��
	**�����
	*		p_nValue����ȡ������Ƶ��ʾ����ֵ����ΧΪ0��100(����0��100)��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setVideoBrightness(const int p_nValue);

	/************************************************************************
	**������
	*		��ȡ��ǰ��Ƶ��ʾ�����ȡ�
	**���룺
	*		��
	**�����
	*		p_nValue����ȡ������Ƶ��ʾ����ֵ����ΧΪ0��100(����0��100)��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getVideoBrightness(int & p_nValue);

	/************************************************************************
	**������
	*		���õ�ǰ��Ƶ��ʾ�ĶԱȶȡ�
	**���룺
	*		p_nValue��Ҫ���õ���Ƶ��ʾ�ĶԱȶ�ֵ
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setVideoContrast(const int p_nValue);

	/************************************************************************
	**������
	*		��ȡ��ǰ��Ƶ��ʾ�ĶԱȶȡ�
	**���룺
	*		��
	**�����
	*		p_nValue����ȡ������Ƶ��ʾ�Աȶ�ֵ����ΧΪ0��100(����0��100)
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getVideoContrast(int & p_nValue);

	/************************************************************************
	**������
	*		���õ�ǰ��Ƶ��ʾ��ɫ����
	**���룺
	*		p_nValue��Ҫ���õ���Ƶ��ʾ��ɫ��ֵ
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setVideoHue(const int p_nValue);

	/************************************************************************
	**������
	*		��ȡ��ǰ��Ƶ��ʾ��ɫ������
	**���룺
	*		��
	**�����
	*		p_nValue����ȡ������Ƶ��ʾ��ɫ��ֵ����ΧΪ0��100(����0��100)��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getVideoHue(int & p_nValue);

	
	/************************************************************************
	**������
	*		���õ�ǰ��Ƶ��ʾ�ı��Ͷȡ�
	**���룺
	*		p_nValue��Ҫ���õ���Ƶ��ʾ�ı��Ͷ�ֵ��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setVideoSaturation(const int p_nValue);

	/************************************************************************
	**������
	*		��ȡ��ǰ��Ƶ��ʾ�ı��Ͷȡ�
	**���룺
	*		��
	**�����
	*		p_nValue����ȡ������Ƶ��ʾ�ı��Ͷ�ֵ����ΧΪ0��100(����0��100)��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getVideoSaturation(int & p_nValue);

	/***********************************************************************
	**������
	*		�����ȡ��Աȶȡ����ͶȺ�ɫ������ΪĬ��ֵ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	************************************************************************/
	int resetPictureAdjustFilter();

	/************************************************************************
	**������
	*		���������ԭʼͼ���С��
	**���룺
	*		�ޡ�
	**�����
	*		p_nWidth ��ԭʼͼ�������λ�����ء�
	*		p_nHeight��ԭʼͼ��ߣ���λ�����ء�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo:: formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		
	************************************************************************/
	int getPictureSize(int& p_nWidth, int& p_nHeight);

public:
	/************************************************************************
	**������
	*		���յ�ǰ���ŵ���Ƶ�����洢Ϊһ��BMP��ʽ��ͼ���ļ���
	**���룺
	*		p_szFileName���洢ͼ���ļ����ļ����������洢������·�����磺��C:\image\sample.bmp����
	**�����
	*		��
	**����ֵ��
	*		true�� ���ճɹ���������ͼ���ļ��ɹ���
	*		fales������ʧ�ܡ�
	*************************************************************************/
	int snapShot(const char* p_szFileName);

//ʵʱ¼��
	/************************************************************************
	**������
	*		����¼���ļ���
	**���룺
	*		p_pszFileName:¼����
	**�����
	*		��
	**����ֵ��
	*		
	*************************************************************************/
	void setRecordFile(const char* p_pszFileName);
	
	/************************************************************************
	**������
	*		����¼���ʽ
	**���룺
	*		p_nFileFormat:¼���ʽ����1��TS����4��PS��,����ɲ鿴RecorderParam.h���壩
	**�����
	*		��
	**����ֵ��
	*		
	*************************************************************************/
	void setRecordFileFormat(const int p_nFileFormat);

	/************************************************************************
	**������
	*		��������¼��ͷ
	**���룺
	*		p_pszRecordFileHead:¼��ͷ
	*		p_nRecordFileLength:¼��ͷ����
	**�����
	*		��
	**����ֵ��
	*		
	*************************************************************************/
	void setRecordFileHead(const char* p_pszRecordFileHead, const int p_nRecordFileLength);

	/************************************************************************
	**������
	*		��ʼ¼��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		
	*************************************************************************/
	int startRecord();

	/************************************************************************
	**������
	*		ֹͣ¼��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		
	*************************************************************************/
	void stopRecord();

	/************************************************************************
	**������
	*		��ȡ¼��״̬��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��ǰ����Ƶ¼�Ƶ�״̬
	**���ܣ�
	*		
	*************************************************************************/
	int getRecordStatus();

public:
	/************************************************************************
	**������
	*		�Ŵ���ʾ��Ƶͼ��
	**���룺
	*		x����Ҫ�Ŵ���ʾ�������x���꣬������Ϊ����ڵ�ǰ��ʾ��Ƶ���ڵ����ꡣ
	*		y����Ҫ�Ŵ���ʾ�������y���꣬������Ϊ����ڵ�ǰ��ʾ��Ƶ���ڵ����ꡣ
	*		width����Ҫ�Ŵ���ʾ������Ŀ��ȡ�
	*		height����Ҫ�Ŵ���ʾ������ĸ߶ȡ�
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		���û���������Ŵ���ʾ
	************************************************************************/
	int zoomInVideo(const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height);

	/************************************************************************
	**������
	*		�Ŵ�ǰ��ʾ��Ƶͼ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����һ���ı��ʷŴ�ǰ��ʾ����Ƶͼ��
	************************************************************************/
	int zoomInVideo();

	/************************************************************************
	**������
	*		��С��ǰ��ʾ��Ƶͼ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�����SN_SUCCESS;
	*		��ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	**���ܣ�
	*		����һ���ı�����С��ǰ��ʾ����Ƶͼ��
	************************************************************************/
	int zoomOutVideo();

	/************************************************************************
	**������
	*		�ָ���������Ƶͼ����ʾ��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	************************************************************************/
	void restoreVideo();

private:
	//�������캯��
	LocalPlayback(const LocalPlayback& p_objObject)
	{
	}

	//��ֵ����
	LocalPlayback& operator = (const LocalPlayback& p_objObject)
	{
		return *this;
	}

private:
	LocalRecordPlayer* 		m_pobjLocalRecordPlayer;
	bool					m_bIsOpen;
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif
#endif