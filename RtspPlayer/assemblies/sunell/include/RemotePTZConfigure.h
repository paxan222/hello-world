#ifndef _REMOTE_PTZ_CONFIGURE_H_
#define _REMOTE_PTZ_CONFIGURE_H_

#include "DeviceInfoEx.h"
#include <vector>
#include "PTZPreset.h"
#include "PTZTourPoint.h"
#include "PTZTourEx.h"
#include "PTZScan.h"
#include "PTZTrack.h"

class RemoteUserDefineParamConfigure;

//�������UserDefineParamConfigure.xml�ļ����еĲ������û��Զ����ļ������ļ������������/mnt/mtd/code/code_configure����


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

class SN_DLL_API RemotePTZConfigure
{
public:
	RemotePTZConfigure(void);
	~RemotePTZConfigure(void);

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
	void	setDeviceInfo(const DeviceInfo &p_objDeviceInfo);

	void	setDeviceInfo(const DeviceInfoEx &p_objDeviceInfoEx);

	/************************************************************************
	**������
	*		����Ҫ�򿪵���̨��Ӧ���������
	**���룺
	*		p_nCameraID �������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		���ò��������Ĺ��캯��������ʱ����open֮ǰ������ø÷���
	*************************************************************************/
	void	setCameraID(const int p_nCameraID);

public:
	/************************************************************************
	**������
	*		����RemotePTZ2��������Ƶ�豸֮������紫��Э��
	**���룺
	*		p_nTransferProtocol��ָ�����紫���Э��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		
	*************************************************************************/
	void setTransferProtocol(const int p_nTransferProtocol);

	/************************************************************************
	**������
	*		����̨�豸����������������Ƶ�豸֮��Ĵ���Ự
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int open();

	/************************************************************************
	**������
	*		�ر�RemotePTZ2��������Ƶ�豸֮��Ĵ���Ự��
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	*************************************************************************/
	void close();


	//Ԥ�õ�������
	/************************************************************************
	**������
	*		����Ԥ�õ����ơ�
	**���룺
	*		p_nPresetID�� Ԥ�õ���
	*		p_pszPresetName��Ԥ�õ�����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	*************************************************************************/
	int setPTZPresetName(int p_nPresetID, const char* p_pszPresetName,const int p_nPTZid=1);

	/************************************************************************
	**������
	*		��ȡԤ�õ�
	**���룺
	*		p_nPresetID�� Ԥ�õ���
	**�����
	*		p_objPTZPreset��Ԥ�õ�
	**����ֵ��
	*		��
	**���ܣ�
	*	
	*************************************************************************/
	int getPTZPreset(int p_nPresetID, PTZPreset& p_objPTZPreset,const int p_nPTZid=1);

	/************************************************************************
	**������
	*		��ȡ����Ԥ�õ�
	**���룺
	*		��
	**�����
	*		p_objPTZPreset��Ԥ�õ�
	**����ֵ��
	*		��
	**���ܣ�
	*	
	*************************************************************************/
	int getAllPTZPreset(std::vector<PTZPreset>& p_objPTZPresetList,const int p_nPTZid=1);

	/************************************************************************
	**������
	*		ɾ��Ԥ�õ�
	**���룺
	*		p_nPresetID�� Ԥ�õ���
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	*************************************************************************/
	int deletePTZPreset(int p_nPresetID,const int p_nPTZid=1);

	/************************************************************************
	**������
	*		ɾ������Ԥ�õ�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*	
	*************************************************************************/
	int deleteAllPTZPreset();

	
	//����λ���
	/************************************************************************
	**������
	*		���ÿ���λ
	**���룺
	*		p_nTypeValue��ִ�п���λ�����ͣ�1��Ԥ��λ��2��ɨ�裬3����ѧϰ��4��Ѳ�Σ���
			p_nIdValue����Ӧ��p_nTypeValue���͵ı�š�
			p_nTimeValue��ִ�п���λʱ�䣬����̨���һ��ִ�в�����p_nTimeValueʱ���ִ�п���λ����
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setPTZKeeper(int p_nKeeperType, int p_nPresetID, int p_nKeepTime);

	/************************************************************************
	**������
	*		��ȡ����λ
	**���룺
	*		��
	**�����
	*		p_nTypeValue��ִ�п���λ�����ͣ�1��Ԥ��λ��2��ɨ�裬3����ѧϰ��4��Ѳ�Σ���
			p_nIdValue����Ӧ��p_nTypeValue���͵ı�š�
			p_nTimeValue��ִ�п���λʱ�䣬����̨���һ��ִ�в�����p_nTimeValueʱ���ִ�п���λ����
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getPTZKeeper(int& p_nPresetType, int& p_nPresetID, int& p_nKeeperTime);

	/************************************************************************
	**������
	*		ɾ������λ
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int deletePTZKeeper();

	
	/************************************************************************
	**������
	*		���ÿ���λ״̬
	*		����ֵ��Ĭ��Ϊ�ر�״̬��2����ʾ������O����ʾ�ر�
	**���룺
	*		p_nKeeperState������λ״̬
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setPTZKeeperState(int p_nKeeperState);

	/************************************************************************
	**������
	*		��ȡ����λ״̬
	*		����ֵ��Ĭ��Ϊ�ر�״̬��2����ʾ������O����ʾ�ر�
	**���룺
	*		��
	**�����
	*		p_nKeeperState������λ״̬
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getPTZKeeperState(int& p_nKeeperState);

	/************************************************************************
	**������
	*		ɾ������λ״̬
	*		����ֵ��Ĭ��Ϊ�ر�״̬��2����ʾ������O����ʾ�ر�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int deleteKeeperState();

	/************************************************************************
	**������
	*		����Ѳ��
	**���룺
	*		p_nTourID��Ѳ�α��
	*		p_pszTourName��Ѳ������
	**�����
	*		p_objPTZTourPointList��Ѳ����Ϣ
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setPTZTour(const int p_nTourID, const char* p_pszTourName, const std::vector<PTZTourPoint>& p_objPTZTourPointList);

	/************************************************************************
	**������
	*		��ȡѲ��
	**���룺
	*		p_nTourID��Ѳ�α��
	**�����
	*		p_objPTZTourEx��Ѳ��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getPTZTour(int p_nTourID, PTZTourEx& p_objPTZTourEx);

	/************************************************************************
	**������
	*		��ȡ����Ѳ��
	**���룺
	*		��
	**�����
	*		p_objPTZTourList��Ѳ���б�
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getPTZAllTour(std::vector<PTZTourEx>& p_objPTZTourList);

	/************************************************************************
	**������
	*		Ѳ��ɾ��
	**���룺
	*		p_nValue��Ѳ�α�ţ�0-7��
	**�����
	*		��
	**����ֵ��
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int deletePTZTour(const int p_nTourID);

	//
	/************************************************************************
	**������
	*		����ɨ��
	**���룺
	*		p_nPresetID��ɨ����
			p_pszScanName��ɨ������
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setPTZScan(const int p_nScanID, const char* p_pszScanName);

	/************************************************************************
	**������
	*		��ȡɨ��
	**���룺
	*		p_nPresetID��ɨ����
	**�����
	*		p_objPTZScan��ɨ��
	**����ֵ��
	*		��
	**���ܣ�
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getPTZScan(const int p_nScanID, PTZScan& p_objPTZScan);

	/************************************************************************
	**������
	*		��ȡ����ɨ��
	**���룺
	*		��
	**�����
	*		p_objPTZScanList��ɨ���б�
	**����ֵ��
	*		��
	**���ܣ�
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAllPTZScan(std::vector<PTZScan>& p_objPTZScanList);

	/************************************************************************
	**������
	*		ɾ��ɨ��
	**���룺
	*		p_nPresetID��ɨ����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int deletePTZScan(const int p_nScanID);

	//�켣
	/************************************************************************
	**������
	*		���ù켣����
	**���룺
	*		p_nTrackID���켣���
	*		p_pszTrackName���켣����
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int setPTZTrack(const int p_nTrackID, const char* p_pszTrackName);

	/************************************************************************
	**������
	*		��ȡ�켣
	**���룺
	*		p_nTrackID���켣���
	**�����
	*		p_objPTZTrack���켣
	**����ֵ��
	*		��
	**���ܣ�
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��	
	*************************************************************************/
	int getPTZTrack(const int p_nTrackID, PTZTrack& p_objPTZTrack);

	/************************************************************************
	**������
	*		��ȡ���й켣
	**���룺
	*		p_nTrackID���켣���
	**�����
	*		p_objPTZTrack���켣
	**����ֵ��
	*		��
	**���ܣ�
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int getAllPTZTrack(std::vector<PTZTrack>& p_objPTZTrackList);

	/************************************************************************
	**������
	*		ɾ���켣
	**���룺
	*		p_nTrackID���켣���
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int deletePTZTrack(const int p_nTrackID);

	/************************************************************************
	**������
	*		��ȡ���PTZ�����ļ�
	**���룺
	*		��
	**�����
	*		��
	**����ֵ��
	*		��
	**���ܣ�
	*		�������ɹ�������SN_SUCCESS��
	*		������ʧ���򷵻�С��0��ֵ������ͨ��ErrorInfo::formatMessage����ȡ������Ϣ��
	*************************************************************************/
	int deleteAllParam();

	////////////////////////////////////////////////////////////


private:
	DeviceInfoEx		m_objDeviceInfoEx;			//�豸��Ϣ
	int					m_nCameraID;				//��̨��Ӧ����������
	int					m_nTransferProtocol;

	RemoteUserDefineParamConfigure*  m_pobjRemoteUserDefineParamConfigure;
	
}_PACKED_1_;

	/**********************************************************************/
	#ifdef PRAGMA_PACK
		#ifdef WIN32  
			#pragma pack(pop)
		#endif
	#endif
	/**********************************************************************/

#endif //_RemotePTZEx_H_


