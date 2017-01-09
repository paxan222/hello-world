#ifndef _FILEPLAYER_H_
#define _FILEPLAYER_H_

#include "IFilePlayer.h"
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

class SN_DLL_API FilePlayer
{
public:
	FilePlayer();
	~FilePlayer(void);

public:
	/************************************************************************
	������������Ƶ��ʾ������ģʽ
	���룺
		p_bStretchMode��trueΪ����ģʽ��falseΪ������ģʽ
	�����
		��
	����ֵ��
		��
	���ܣ�
		������Ƶ����ģʽ��������Ϊ����ģʽ��Ƶ������Ƶ��ʾ���ڵĴ�С������ʾ��������
		Ϊ������ģʽ������Ƶ��ԭʼ������ʾ
		ע������ģʽֻ����ʹ�ó�����Ⱦģʽʱ����Ч
	************************************************************************/
	void setStretchMode(const bool p_bStretchMode);

	/************************************************************************
	������������Ƶ��Ⱦģʽ
	���룺
	p_nRenderMode��ָ����Ƶ����Ⱦģʽ
	�����
		��
	����ֵ��
		��
	���ܣ�
		setRenderMode�����������ò�����Ƶʱ����Ƶ��Ⱦģʽ����ֵ��RenderMode�ĳ���ָ����
		����RENDER_MODE_GENERAL_RENDER��������Ⱦģʽ����RENDER_MODE_VMR7_RENDER��VMR7��Ⱦģʽ��
		��RENDER_MODE_VMR9_RENDER��VMR9��Ⱦģʽ����
		������Ⱦģʽ�ڲ�ͬ����ʾ�豸���磺�Կ������в�ͬ�����ܱ��֣�
		�û����Ը�����ʾ�豸������ѡ����ʵ���Ⱦģʽ��Ĭ��Ϊ������Ⱦģʽ
	************************************************************************/
	void setRenderMode(const int p_nRenderMode);

	/************************************************************************
	������������Ƶ����ʾ���ڣ�λ�úʹ�С
	���룺
		p_hDisplayWnd����Ƶ��ʾ���ڵľ����
		x��ָ���ڴ�������Ƶ��ʾλ�õ�x���꣬��λΪ���ء�
		y��ָ���ڴ�������Ƶ��ʾλ�õ�y���꣬��λΪ���ء�
		width:ָ���ڴ�������Ƶ��ʾ��С�Ŀ�ȣ���λΪ���ء�
		height:ָ���ڴ�������Ƶ��ʾ��С�ĸ߶ȣ���λΪ���ء�
	�����
		��
	����ֵ��
		��
	************************************************************************/
	void setVideoWindow(const unsigned int p_hDisplayWnd, const int x, const int y, const int width, const int height);
	void setVideoWindow(const unsigned int p_hDisplayWnd);
	/************************************************************************
	���������ý����¼��Ĵ��ھ������Ϣ���Զ������
	���룺
		p_hNotifyWnd��ָ��������Ϣ�Ĵ��ھ����Mpeg2PSPlayer��������Ϣ���þ��ָ���Ĵ��ڡ�
					  ��ΪNULL���ʾ��������Ϣ��
		p_nMessage��ָ��Windows������Ϣ��
					Mpeg2PSPlayer�����͸���Ϣ����p_hNotifyWndָ���Ĵ��ڡ�
					���Windows������Ϣ���û��Զ��壬
					Windows�µ�WM_USER�������԰����û�ΪWindows���ڶ���˽����Ϣ�����巽����WM_USER+X, X��һ������ֵ��
		p_pParam��ָ��������Ϣʱ��Я������Ϣ������
				  ����Ϣ����������Mpeg2PSPlayer�ı䣬Mpeg2PSPlayer������Ϣʱֻ�Ǽ򵥵ؽ�����Ϣ�����ַ��ظ����ڡ�
	�����
		��
	����ֵ��
		��
	************************************************************************/
	void setNotifyWindow(const unsigned int p_nNotifyWnd, const unsigned int p_nMessage, const void * p_pParam);
	void setNotifyWindowEX(const unsigned int p_nNotifyWnd, const unsigned int p_nMessage, long wparam, long param);

	void setFileEndCallback(long hHandle, void(CALLBACK *FileEndCallback)(long hHandle, void *pUser), void * User);
	
	void setDecodeCallBack( long hHandle, void* fDecodeCallBack, void * pUser);

	void setDrawFuncForRender(long hHandle, void * fDrawCallFunc, void* pUser, bool p_bUseDestResolution );


	/************************************************************************
	�������ı�һ���ļ�����������ʾ����
	���룺
	p_hDisplayWnd,		��ǰ��ʾ�Ĵ���
	�����
	��
	����ֵ��
	true,		����ʧ��
	false,		�����ɹ�
	���ܣ�
	�ı�һ���ļ�����������ʾ����
	************************************************************************/
	bool changeWindow(const unsigned int p_hDisplayWnd);

	/************************************************************************
	�������ı�һ���ļ�����������ʾ���ڵĴ�С
	���룺
	p_objRect,		�ı��Ĵ��ڵĴ�С
	�����
	��
	����ֵ��
	false,		����ʧ��
	true,		�����ɹ�
	���ܣ�
	�ı�һ���ļ�����������ʾ���ڵĴ�С
	************************************************************************/
	void resizeWindow(const int x, const int y, const int width, const int height);

	//ˢ����ʾ����
	void refresh();

	void resizeWindowToClient();

public:
	/************************************************************************
	��������һ���ļ�������
	���룺
	p_pszFileName,		�ļ���·�����ļ���
	p_hParentWnd,		�����ھ��
	p_hDisplayWnd,		��ʾ���ھ��
	�����
	��
	����ֵ��
	true,		�����ļ��ɹ�	
	false,		�����ļ�ʧ��
	���ܣ�
	��һ������Ƶ�ļ�,����ʼ����
	************************************************************************/
	int open(const char * p_pszFileName);

	/************************************************************************
	�������ر�һ���ļ�������
	���룺
	��
	�����
	��
	����ֵ��
	��
	���ܣ�
	�ر�һ���ļ�������
	************************************************************************/
	void close();

public:
	/************************************************************************
	��������ʼ����
	���룺
	�ļ����Ŵ���ֹͣ״̬����ͣ״̬
	�����
	�ļ����Ŵ��ڲ���״̬
	����ֵ��
	��
	���ܣ�
	��ʼ����һ������Ƶ�ļ�
	************************************************************************/
	int play();

	/************************************************************************
	��������ͣ�ļ�����
	���룺
	�ļ����Ŵ��ڲ���״̬
	�����
	�ļ����Ŵ�����ͣ״̬
	����ֵ��
	��
	���ܣ�
	��ͣ����һ������Ƶ�ļ�
	************************************************************************/
	int pause();

	/************************************************************************
	������ֹͣ�ļ�����
	���룺
	�ļ����Ŵ��ڲ���״̬����ͣ״̬
	�����
	�ļ����Ŵ���ֹͣ״̬
	����ֵ��
	��
	���ܣ�
	ֹͣ����һ������Ƶ�ļ�
	************************************************************************/
	int stop();

	int getPlayStatus();

	int	playNextFrame();

	int	playPreviousFrame();

public:
	/************************************************************************
	������ȡ���ļ��ĳ���(��λ:��)
	���룺
	��
	�����
	p_pdblDuration,		�����ļ���ʱ�䳤��
	����ֵ��
	true,		��ȡ�ɹ�
	false,		��ȡʧ��
	���ܣ�
	ȡ���ļ���ʱ�䳤��(��λ:��)
	************************************************************************/
	int getDuration(long & p_nDuration);
	int getDuration(float & p_nDuration);

	/************************************************************************
	������ȡ�õ�ǰ�Ĳ���λ��(��λ:��)
	���룺
	��
	�����
	p_pdblPosition,		���ص�ǰ�Ĳ���λ��
	����ֵ��
	true,		��ȡ�ɹ�
	false,		��ȡʧ��
	���ܣ�
	ȡ�õ�ǰ�Ĳ���λ��(��λ:��)
	************************************************************************/
	int getPlayPosByTime(long & p_nPosition);
	int getPlayPosByTime(float & p_nPosition);

	/************************************************************************
	���������õ�ǰ�Ĳ���λ��(��λ:��)
	���룺
	��
	�����
	p_dblPosition,		����λ��
	����ֵ��
	true,		���óɹ�
	false,		����ʧ��
	���ܣ�
	���õ�ǰ�Ĳ���λ��(��λ:��)
	************************************************************************/
	int setPlayPosByTime(const long p_nPosition );
	int setPlayPosByTime(const float p_nPosition );

	/************************************************************************
	������ȡ�õ�ǰ�Ĳ���λ��(�ٷֱ�)��Ϊ0-100֮�������
	���룺
	��
	�����
	p_pdblPosition,		���ص�ǰ�Ĳ���λ��
	����ֵ��
	true,		��ȡ�ɹ�
	false,		��ȡʧ��
	���ܣ�
	ȡ�õ�ǰ�Ĳ���λ��(��λ:��)
	************************************************************************/
	int getPlayPosByPercent(long & p_nPosition);

	/************************************************************************
	���������õ�ǰ�Ĳ���λ��(�ٷֱ�)��Ϊ0-100֮�������
	���룺
	��
	�����
	p_dblPosition,		����λ��
	����ֵ��
	true,		���óɹ�
	false,		����ʧ��
	���ܣ�
	���õ�ǰ�Ĳ���λ��(��λ:��)
	************************************************************************/
	int setPlayPosByPercent(const long p_nPosition );

	/************************************************************************
	��������ȡ��ǰ�Ĳ�������
	���룺
	��
	�����
	p_pdRate,		��ǰ�Ĳ�������
	����ֵ��
	true,		��ȡ�ɹ�
	false,		��ȡʧ��
	���ܣ�
	��ȡ��ǰ�Ĳ�������
	************************************************************************/
	int getRate(float & p_nRate );

	/************************************************************************
	���������õ�ǰ�Ĳ�������
	���룺
	p_pdRate,		��ǰ�Ĳ������ʣ�1.0Ϊ�������ٶȲ���
	�����
	��
	����ֵ��
	true,		���óɹ�
	false,		����ʧ��
	���ܣ�
	���õ�ǰ�Ĳ�������
	************************************************************************/
	int setRate (const float p_nRate );

	int getFileTotalFrames(long & p_nFrames);

	int	getPlayedFrames(long & p_nFrames);

	int	setCurrentFrameNum(const long nFrameNum);
public:

	/***********************************************************************
	**������
	*	�Ӳ��ŵ����л�ȡ��Ƶ��֡��
	**���룺
	*	��
	**�����
	*	p_nValue������.
	*����ֵ��
	*	SN_SUCCESS:�ɹ���
	*	������ʧ�ܡ�
	*���ܣ�
	*	
	************************************************************************/
	int getVideoFrameRate(int & p_nValue);

	/***********************************************************************
	**������
	*	�Ӳ��ŵ����л�ȡ��Ƶ�Ĳɼ�����
	**���룺
	*	��
	**�����
	*	p_nValue������.
	*����ֵ��
	*	SN_SUCCESS:�ɹ���
	*	������ʧ�ܡ�
	*���ܣ�
	*	
	************************************************************************/
	int getVideoBitRate(int & p_nValue);

	
	int getPictureSize(int & p_nWidth, int &p_nHeight);

public:
	//����
	int setVideoBrightness(const int p_nValue);
	int getVideoBrightness(int & p_nValue);

	//�Աȶ�
	int setVideoContrast(const int p_nValue);
	int getVideoContrast(int & p_nValue);

	//ɫ��
	int setVideoHue(const int p_nValue);
	int getVideoHue(int & p_nValue);

	//���Ͷ�
	int setVideoSaturation(const int p_nValue);
	int getVideoSaturation(int & p_nValue);

	int resetPictureAdjustFilter();

public:
	/************************************************************************
	��������������
	���룺
	��
	�����
	��
	����ֵ��
	************************************************************************/
	int	playSound();

	/************************************************************************
	�������ر�����
	���룺
	��
	�����
	��
	����ֵ��
	************************************************************************/
	int stopSound();

	/************************************************************************
	��������ǰ�����Ƿ��
	���룺
	��
	�����
	��
	����ֵ��
	true,		��ǰ�����Ѵ�
	false,		��ǰ�����ѹر�
	���ܣ�
	���ص�ǰ�����Ƿ��Ѵ򿪵�״̬
	************************************************************************/
	bool isOnSound();

	int setVolume(const long p_nVolume);

	int getVolume(long & p_nVolume);

	/************************************************************************
	**������
	*		������Ƶ��ʾ�ı�־��
	**���룺
	*		p_bDrawFlag����Ƶ��ʾ��־��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		������Ƶ��ʾ�ı�־��TRUE ���벢��ʾ��FALSE ֻ���벻��ʾ��
	************************************************************************/
	void setDrawVideoFlag(bool p_bDrawFlag);

	void setAutoResizeFlag(bool p_bAutoResizeFlag);

public:
	/***********************************************************************
	**������
	*		��ȡ��ǰ����ͼƬ
	**���룺
	*		p_szSaveFileName���ļ���
	*		p_pszFormat: ץͼ��ͼƬ��ʽ��֧�֡�JPG���͡�BMP��
	*�����
	*		��ָ��·�������浱ǰ���������ŵĽ�ͼ
	**����ֵ��
	*		SN_SUCCESS ����ȡ�ɹ�
	*		SN_ERROR_BAD_ENVIRONMENT����ȡʧ��
	************************************************************************/
	int snapShot(const char* p_szSaveFileName , const char * p_pszFormat = "JPG");

public:
	/************************************************************************
	������������ʱϵͳ���ص���Ϣ
	���룺
	��
	�����
	��
	����ֵ��
	��
	���ܣ�
	������ʱϵͳ���ص���Ϣ
	************************************************************************/
	const bool isPlayComplete();

	const char * getFileName();

public:
	/************************************************************************
	**������
	*		�Ŵ���ʾ��Ƶͼ��
	**���룺
	*		x����Ҫ�Ŵ���ʾ�������x���꣬������Ϊ����ڵ�ǰ��ʾ��Ƶ���ڵ����ꡣ
	*		y����Ҫ�Ŵ���ʾ�������y���꣬������Ϊ����ڵ�ǰ��ʾ��Ƶ���ڵ����ꡣ
	*		width����Ҫ�Ŵ���ʾ������Ŀ�ȡ�
	*		height����Ҫ�Ŵ���ʾ������ĸ߶ȡ�
	**�����
	*		��
	**����ֵ��
	*		SN_SUCCESS���ɹ���
	*		< 0��		ʧ�ܡ�
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
	*		SN_SUCCESS���ɹ���
	*		< 0��		ʧ�ܡ�
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
	*		SN_SUCCESS���ɹ���
	*		< 0��		ʧ�ܡ�
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

public:
	//ʵʱ¼��
	void setRecordFile(const char * p_pszFileName);

	//����¼���ʽ
	void setRecordFileFormat(const int p_nFileFormat);

	//����¼��ͷ
	void setRecordFileHead(const char* p_pszRecordFileHead, const int p_nRecordFileLength);

	//��ʼ¼��
	int startRecord();

	//ֹͣ¼��
	int stopRecord();

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

	//������ʾģʽ
	void setDrawVideoMode(const int p_nDrawMode);

private:
	//�����ļ�������
	int createFilePlayer(const char * p_pszFileName, IFilePlayer*& p_pobjFilePlayer);

private:
	IFilePlayer * m_pobjFilePlayer;

private:
	bool	m_bDrawVideoFlag;
	bool	m_bAutoResizeFlag;
	bool	m_bStretchMode;
	int		m_nRenderMode;
	int		m_nDrawVideoMode;

	unsigned int m_hDisplayWnd;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
private:
	unsigned int m_nNotifyWnd;
	unsigned int m_nMessage;
	void * m_pParam;
	long		m_nWparam;
	long		m_nLparam;

	long				  m_hFileEndCallbackHandle;
	func_FileEndCallback  m_fFileEndCallback;
	void * m_pUser;

private:

}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/

#endif