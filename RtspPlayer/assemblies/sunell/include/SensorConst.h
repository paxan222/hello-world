#ifndef _SENSORCONST_H_
#define _SENSORCONST_H_
namespace SensorConst
{
	const int SensorConfigVersionId = 10000;
	const int SensorConfigVersionId2 = 10001;
	const int NonInfrared = 0;	//�Ǻ���
	const int Infrared = 1;		//����
	const int SmartInfrared = 2;//���ܺ���
	namespace SensorType
	{
		const int NULL_TYPE				= 0;		//δ֪���ͣ�����ʾ��֧��ǰ��ģ����ƹ��ܡ�
		const int SONY_HQ1				= 1;		//
		const int IT1					= 2;		//
		const int DPS					= 3;
		const int MT9P031				= 4;
		const int ICX274				= 5;
		const int MT9M033				= 6;
		const int HITACH				= 7;
		const int MT9V136				= 8;
		const int IT1ZoomModule			= 9;
		const int EFFIO					= 10;
		const int EH4300				= 11;
		const int SEAWOLF				= 12;
		const int EFFIO_960H			= 13;
		const int HitachCompat			= 14;
		const int ITN					= 15;
		const int CMD8100				= 16;
		const int NoSensorUI			= 17;
		const int CH3310				= 18;
		const int CV7500				= 19;
		const int DH1812				= 20;
		const int XARINA140				= 50;
		const int XARINA139				= 51;
		const int CMD7300				= 21;
		const int CMD7200				= 22;
		const int SC110N_C				= 23;
		const int CMD8100_Old			= 24;
		const int CMD8300				= 25;
		const int Hi351xSensor          = 60;
		const int ThermalBV3100			= 70;
		const int AmbaS2Sensor			= 80;
		const int EH6300				= 81;
		const int AmbaS2FBS8300			= 82;
		const int CMD7400				= 83;
		const int AmbaS2LSensor			= 84;
		const int EV7310				= 85;
		const int AmbaS2FBS8310			= 86;
		const int AmbaS2FBS9200			= 87;
		const int S2FisheyeSensor		= 88;
	};
	namespace Special_SensorID
	{
		const int Param_On_Off			= 500;
		const int Param_Start_Time_H	= 501;
		const int Param_Start_Time_M	= 502;
		const int Param_End_Time_H	= 503;
		const int Param_End_Time_M	= 504;
	};
	namespace Sensor_Return_ID
	{
		const int Param_Scheme_Bad_Parameter_1 = 505;//��ʼʱ�����ò�����
		const int Param_Scheme_Bad_Parameter_2 = 506;//����ʱ�����ò�����
		const int Param_Scheme_Bad_Parameter_3 = 507;//��ʼʱ����ڻ��ߵ��ڽ���ʱ��
		const int Param_Scheme_Bad_Parameter_4 = 508;//����ԭ���´���
	}
	namespace ThermalBV3100_SensorID
	{
		const int NoneColorMode			=	1;		//α��ģʽ
		const int ImagesMirror			=	2;		//ͼ��ת
		const int NRMode				=	3;		//2d����ģʽ
		const int DVEMode				=	4;		//DVE��ǿ�ȼ�
		const int AutoTime				=	5;		//�Զ�ʱ��

		const int Contrast				=	6;		//�Աȶ�
		const int ControlFFCMode		=	7;		//����ģʽ
		const int NR3DMode				=	8;		//3����ģʽ
		const int NR3DModeA0			=	9;		//3����ģʽA0
		const int NR3DModeTM			=	10;		//3����ģʽTM
		const int ImagesAdjust			=	11;		//����У��
		const int FOCUSINC				=	12;		//FOCUS+++
		const int FOCUSDEC				=	13;		//FOCUS---
		const int FOCUSINCSTART				=	14;		//FOCUS+++START
		const int FOCUSDECSTART				=	15;		//FOCUS---START
	};
	namespace SonyHQ1_SensorID
	{
		const int Mirror				=	1;		//����
		const int Brightness			=	2;		//����
		const int Sharpness				=	3;		//���
		const int RecRYGain				=	4;		//ɫ�ʵ���(R-Y Gain)
		const int RecBYGain				=	5;		//ɫ�ʵ���(B-Y Gain)
		const int ExposureMode			=	6;		//�ع�ģʽ
		const int ShutterSpeed			=	7;		//�����ٶ�
		const int IrisDriveMode			=	8;		//��Ȧģʽ
		const int DCLevel				=	9;		//��Ȧֵ(0-255) //todo IPISVCNT?
		const int WB_Mode				=	10;		//��ƽ��ģʽ
		const int AGCSetup				=	11;		//�Զ�������ƿ���
		const int BackLightSetup		=   12;		//���ⲹ������
		const int BackLightMode			=	13;		//���ⲹ��ģʽ
		const int BackLightArea1		=	14;		//���ⲹ������1(�ϲ�1/3����)�ع����(0-15)
		const int BackLightArea2		=	15;		//���ⲹ������2(�²�1/3����)�ع����(0-15)
		const int BackLightArea3		=	16;		//���ⲹ������3(�в�1/3������)�ع����(0-15)
		const int BackLightArea4		=	17;		//���ⲹ������4(�в�1/3������)�ع����(0-15)
		const int BackLightArea5		=	18;		//���ⲹ������5(��������)�ع����(0-15)
		const int CursoryGain			=	19;		//�ֵ���Χ(0-4)
		const int SmartGain				=	20;		//ϸ����Χ(1-1024)
		const int DayNightSetup			=	21;		//��ҹģʽ��ʽ
		const int DayToNightTransition	=	22;		//����ҹ��ģʽ���ٽ�ֵ(0 - 44)
		const int NightToDayTransition	=	23;		//�˳�ҹ��ģʽ���ٽ�ֵ(0 - 44)
		const int FlickerLessMode		=	24;		//����˸ģʽ
		const int NightColorMode		=	25;		//ҹ��ģʽʱ����ɫѡ��
	};

	namespace DPS_SensorID
	{
		const int BrightnessMode		=	1;		//����ģʽ
		const int Brightness			=	2;		//����(0-100)
		const int Sharpness				=	3;		//���(0-100)
		const int Saturation			=	4;		//���Ͷ�(0-100)
		const int VideoSystem			=	5;		//��Ƶ��ʽ
		const int Mirror				=	6;		//����
		const int AE_PREFs				=	7;		//�ع��Ż�
		const int AGCBias				=	8;		//�Զ�����ƫ��ֵ(-18 - 18)
		const int AGCLimit				=	9;		//�Զ���������ֵ(0 - 60)
		const int LowLight				=	10;		//���ն�ģʽ
		const int ShutterLimit			=	11;		//��������ֵ
		const int WDRBias				=	12;		//��̬��Χƫ��ֵ(-36 - 36)
		const int WDRLimit				=	13;		//��̬��Χ����ֵ(0 - 36)
		const int MeterMode				=	14;		//�����ع�ļ���ģʽ
		const int ExposalZone			=	15;		//ǰ��Ԥ��ģʽ���ع�����
		const int DayNightSetup			=	16;		//��ҹģʽ��ʽ
		const int NightColorMode		=	17;		//ҹ��ģʽʱ����ɫѡ��
		const int NightMaxAGC			=	18;		//ҹ��ģʽ�µ��������ֵ(0 - 44)
		const int DayToNightTransition	=	19;		//����ҹ��ģʽ���ٽ�ֵ(0 - 44)
		const int NightToDayTransition	=	20;		//�˳�ҹ��ģʽ���ٽ�ֵ(0 - 44)
		const int DayToNightDelay		=	21;		//����ҹ��ģʽ���ӳټ�����ʱ��(0 - 10)
		const int ShowFrame				=	22;
		const int Up					=	23;
		const int Down					=	24;
		const int Left					=	25;
		const int Right					=	26;
		const int Enter					=	27;
		const int HideFrame				=	28;
	};

	namespace IT1_SensorID
	{
		const int Brightness			=	1;		//����(0-100)
		const int Sharpness				=	2;		//���(0-100)
		const int Mirror				=	3;		//����
		const int DayNightSetup			=	4;		//��ҹģʽ��ʽ
		const int DayToNightTransition	=	5;		//����ҹ��ģʽ���ٽ�ֵ(0 - 255)
		const int NightToDayTransition	=	6;		//�˳�ҹ��ģʽ���ٽ�ֵ(0 - 255)
		const int VideoOutSetup			=	7;		//ģ���������
		const int MinShutter			=	8;		//��С����
		const int MaxGain				=	9;		//�������
		const int IrisDriveMode			=	10;		//�Զ���Ȧ
		const int MaxShutter			=	11;		//������ֵ
		const int GAMA					=	12;		//GAMA
		const int Chroma				=	13;		//ɫ��Ũ��
		const int WB_Mode				=	14;		//��ƽ��
		const int NightColor			=	15;		//ҹ��ɫ������
		const int IrisVoltage			=	16;		//�Զ���Ȧƫ�õ�ѹ
		const int IrisSpeed				=	17;		//��Ȧ�ٶ�
		const int FixedShutter			=	18;		//�̶�����
		const int ShutterMode			=	19;		//����ģʽ
		const int NF					=	20;		//����
		const int Strength				=	21;		//ǿ��
		const int Infrared				=   22;		//�����
	};

	namespace IT1_ZoomModuleSensorID
	{
		const int Brightness			=	1;		//����(0-100)
		const int Sharpness				=	2;		//���(0-100)
		const int Mirror				=	3;		//����
		const int DayNightSetup			=	4;		//��ҹģʽ��ʽ
		const int DayToNightTransition	=	5;		//����ҹ��ģʽ���ٽ�ֵ(0 - 255)
		const int NightToDayTransition	=	6;		//�˳�ҹ��ģʽ���ٽ�ֵ(0 - 255)
		const int VideoOutSetup			=	7;		//ģ���������
		const int MinShutter			=	8;		//��С����
		const int MaxGain				=	9;		//�������
		const int IrisDriveMode			=	10;		//�Զ���Ȧ
		const int MaxShutter			=	11;		//������ֵ
		const int GAMA					=	12;		//GAMA
		const int Chroma				=	13;		//ɫ��Ũ��
		const int WB_Mode				=	14;		//��ƽ��
		const int NightColor			=	15;		//ҹ��ɫ������
		const int IrisVoltage			=	16;		//�Զ���Ȧƫ�õ�ѹ
		const int IrisSpeed				=	17;		//��Ȧ�ٶ�
		const int FixedShutter			=	18;		//�̶�����
		const int ShutterMode			=	19;		//����ģʽ
		const int AutoFocus				=	20;		//�Զ��۽�
		const int FocusMode				=	21;		//�۽�ģʽ
		const int AdjustLens			=	22;		//С���߽�����ͷ�������ڽ���
	};

	namespace ISP_SensorID
	{
		const int Brightness			=	1;		//����
		const int Saturation			=	2;		//���Ͷ�
		const int Contrast				=	3;		//�Աȶ�
		const int GainMode				=	4;		//����ģʽ
		const int MaxGain				=	5;		//�������
		const int FixedGain				=	6;		//�̶�����
		const int ShutterMode			=	7;		//�ع�ģʽ
		const int MaxShutterMode		=	8;		//����ع�ʱ��
		const int FixedShutterMode		=	9;		//�̶��ع�ʱ��
		//const int MaxShutterMode_50HZ	=	8;		//����ع�ʱ��
		//const int FixShutterMode_50HZ	=	9;		//�̶��ع�ʱ��
		const int DayNightSetup			=	10;		//��ҹģʽ
		const int DayToNightTransition	=	11;		//����ҹ���ٽ�ֵ
		const int NightToDayTransition	=	12;		//��������ٽ�ֵ
		const int Sharpness				=	13;		//���
		const int CVBSOut				=	14;		//ģ�����
		const int NightColor			=	15;		//ҹ����ɫ
		const int IrisSpeed				=	16;		//��Ȧ�ٶ�
		const int IrisVoltage			=	17;		//ƫִ��ѹ
		const int AutoIris				=	18;		//�Զ���Ȧ
		//const int IrisCloseSpeed		=	19;		//��Ȧ�ر��ٶ�
		//const int PowerMode				=	20;		//��Դģʽ
		//const int MaxShutterMode_60HZ	=	21;		//NTSCģʽ�µ�������ֵ
		//const int FixShutterMode_60HZ	=	22;		//NTSCģʽ�µĹ̶�����ֵ
		const int PowerFrequency		=	23;		//��ԴƵ��
		const int HighlightHold			=	24;		//ǿ������
		const int PhotometryArea		=	25;		//�������
		const int WBmode				=	26;		//��ƽ��ģʽ
		const int WB_Manual				=	27;		//��ƽ���ֶ�ģʽ
		const int RedGain				=	28;		//������
		const int BlueGain				=	29;		//������
		const int Mirror				=	30;		//����
		const int ThreeDimensionalNR	=	31;
		const int HDR					=	32;		//��̬ģʽ
		const int RunMode				=	33;		//��̬����ģʽ
		const int NR_2D					=	34;		//2D����
		const int KNF					=	35;		//����
		const int NFAutoMax				=	36;		//�������ǿ��
		const int TNF					=	37;		//ʱ��
		const int Infrared				=	38;		//����ƿ���
		const int DoorMode				=	39;		//������ģʽ
		const int DayNightDelay			=   57;
		const int DTNTime_H				=	58;
		const int DTNTime_M				=	59;
		const int NTDTime_H				=	60;
		const int NTDTime_M				=	61;
		const int TNFMode				=	62;		//3D����
	};

	namespace HITACH_SensorID
	{
		const int Brightness			=	1;		//����
		const int Sharpness				=	2;		//��ֱ���
		const int Saturation			=	3;		//���Ͷ�
		const int NightColor			=	4;		//ɫ������
		const int VideoOutSetup			=	5;		//ģ����Ƶ���
		const int CameraMode			=	6;		//�����ģʽ
		const int MainGain				=	7;		//�������
		const int WDR					=	8;		//��̬
		const int DNSensitivity			=	9;		//��ҹת��������
		const int FixShutter			=	10;		//�̶�����
		const int BackLight				=	11;		//���ⲹ��	
		const int Mirror				=	12;		//����
		const int FocusDistance			=	13;		//�۽�����
		const int FocusMode				=	14;		//�۽�ģʽ
		const int PictureMode			=	15;		//ͼ��ģʽ
		const int Sharpness2			=	16;		//ˮƽ���
		const int NF					=	17;		//����
	};

	namespace EFFIO_SensorID
	{
		const int Brightness			=	1;
		const int Sharpness				=	2;
		const int Mirror				=	3;	
		const int AutoExposalMode		=	4;
		const int WB					=	5;
		const int R_Gain				=	6;
		const int B_Gain				=	7;
		const int DayNightMode			=	8;
		const int DayToNightTransition	=	9;
		const int NightToDayTransition	=	10;
		//const int AGCValue				=	11;
		const int ExposalMode			=	12;
		const int Shutter_Speed			=	13;
		const int NR2_FILMODE			=	14;
		const int BackLight				=	15;
		const int BackLightLevel		=	16;
		const int ATR					=	17;
		const int AGCMode				=	18;
		const int MaxAGC				=	19;
		const int MirisCtrl				=	20;
		const int NF					=	21;
		const int Strength				=	22;
		const int Infrared				=	23;
		const int DayNightDelay			=   57;
		const int DTNTime_H				=	58;
		const int DTNTime_M				=	59;
		const int NTDTime_H				=	60;
		const int NTDTime_M				=	61;
	};

	namespace SONYEH4300_SensorID
	{
		const int Sharpness							=1;//���
		const int LowLightChromaSuppress			=2;//��������ɫ��֧��
		const int Gamma								=3;
		const int NoiseReduction					=4;//����˥��
		const int HR								=5;//�߷ֱ���ģʽ
		const int Mirror							=6;//����
		const int ThresholdLevel					=7;//ҹת��������
		const int StillImage						=8;//����
		const int PictureEffect						=9;//��ͨ/��Ƭ
		const int AEMode							=10;//�ع�ģʽ
		const int Shutter							=11;//���ŵ���
		const int Iri								=12;//��Ȧ����
		const int Bright							=13;//���ȵ���
		const int Gain								=14;//�������
		const int GainLimit							=15;//�������ֵ
		const int AutoSlowShutter					=16;//�Զ�������
		const int ExpComp							=17;//�عⲹ��
		const int AE_Response						=18;//�Զ��ع���Ӧʱ��
		const int SpotAE							=19;//���ع�����
		const int SpotAE_X							=20;//���ع�X����
		const int SpotAE_Y							=21;//���ع�Y����
		const int BackLight							=22;//���ⲹ��
		const int WBMode							=23;//��ƽ��ģʽ
		const int R_Gain							=24;//������
		const int B_Gain							=25;//������
		const int DNMode							=26;//��ҹģʽ
		const int IRCorrection						=27;//�۽��й�
		const int WD								=28;//��̬
		const int DZoom								=29;//���ֱ䱶
		const int FocusMode							=30;//�۽�ģʽ
		//const int FocusSpeed						=31;//�۽��ٶ�
		const int FocusAutoMode						=32;//�۽��Զ�ģʽ
		const int AF_Sensitivity					=33;//�Զ��۽�������
		const int FocusNearLimit					=34;//������̾��� 
		const int AutoFocusOnce						=37;//����һ���Զ��۽�  ����
 
		//��̬����
		const int Display							=38;//Screen display
		const int Sens								=39;//Detection sensitivity
		const int B_intens							=40;//Blocked-up shadow correction level
		const int W_intens							=41;//Blown-out highlight correction level
		const int L_ExpSingalRatio					=42;//Long-exposure signal ratio
		const int S_ExpSingalRatio					=43;//Short-exposure signal ratio
		const int ShortTimeExp						=44;//Exposure ratio of short exposure
		//��ͷ����
		const int Movement							=45;//�ƶ�ʱ��
		const int Interval							=46;//���ʱ��
		//ADD
		const int Saturation						=47;//ɫ�ʱ��Ͷ�
		const int Hue								=48;//ɫ��
		const int HighSensitivity					=49;//��������
		const int BrightRemoteSensor2				=50;//���ȣ���RemoteSensor2ʹ��
		const int NF								=51;
		const int IrisUp							=52;
		const int IrisDown							=53;
		const int FocusUp							=54;
		const int FocusDown							=55;

		const int Brightness						=56;
		const int NearLight							=57;
		const int MiddleLight						=58;
		const int FarLight							=59;

		const int DTNTime_H							=	60;
		const int DTNTime_M							=	61;
		const int NTDTime_H							=	62;
		const int NTDTime_M							=	63;
		const int PowerMode							=	64;

		const int MaskRegion						=	65;		//��˽�ڱ�����
		const int SetMask							=	66;		//��˽�ڱ�����
		const int Show								=	67;
		const int Hide								=	68;
		const int Clear								=	69;
		const int ClearAll							=	70;
		const int IncreaseWidth						=	71;
		const int DecreaseWidth						=	72;
		const int IncreaseHight						=	73;
		const int DecreaseHight						=	74;
	};

	namespace SONYCH3310_SensorID
	{
		const int Sharpness							=1;//���
		const int LowLightChromaSuppress			=2;//��������ɫ��֧��
		const int Gamma								=3;
		const int NoiseReduction					=4;//����˥��
		const int HR								=5;//�߷ֱ���ģʽ
		const int Mirror							=6;//����
		const int ThresholdLevel					=7;//ҹת��������
		const int StillImage						=8;//����
		const int PictureEffect						=9;//��ͨ/��Ƭ
		const int AEMode							=10;//�ع�ģʽ
		const int Shutter							=11;//���ŵ���
		const int Iri								=12;//��Ȧ����
		const int Bright							=13;//���ȵ���
		const int Gain								=14;//�������
		const int GainLimit							=15;//�������ֵ
		const int AutoSlowShutter					=16;//�Զ�������
		const int ExpComp							=17;//�عⲹ��
		const int AE_Response						=18;//�Զ��ع���Ӧʱ��
		const int SpotAE							=19;//���ع�����
		const int SpotAE_X							=20;//���ع�X����
		const int SpotAE_Y							=21;//���ع�Y����
		const int BackLight							=22;//���ⲹ��
		const int WBMode							=23;//��ƽ��ģʽ
		const int R_Gain							=24;//������
		const int B_Gain							=25;//������
		const int DNMode							=26;//��ҹģʽ
		const int IRCorrection						=27;//�۽��й�
		const int WD								=28;//��̬
		const int DZoom								=29;//���ֱ䱶
		const int FocusMode							=30;//�۽�ģʽ
		//const int FocusSpeed						=31;//�۽��ٶ�
		const int FocusAutoMode						=32;//�۽��Զ�ģʽ
		const int AF_Sensitivity					=33;//�Զ��۽�������
		const int FocusNearLimit					=34;//������̾��� 
		const int AutoFocusOnce						=37;//����һ���Զ��۽�  ����

		//��̬����
		const int Display							=38;//Screen display
		const int Sens								=39;//Detection sensitivity
		const int B_intens							=40;//Blocked-up shadow correction level
		const int W_intens							=41;//Blown-out highlight correction level
		const int L_ExpSingalRatio					=42;//Long-exposure signal ratio
		const int S_ExpSingalRatio					=43;//Short-exposure signal ratio
		const int ShortTimeExp						=44;//Exposure ratio of short exposure
		//��ͷ����
		const int Movement							=45;//�ƶ�ʱ��
		const int Interval							=46;//���ʱ��
		//ADD
		const int Saturation						=47;//ɫ�ʱ��Ͷ�
		const int Hue								=48;//ɫ��
		const int HighSensitivity					=49;//��������
		const int BrightRemoteSensor2				=50;//���ȣ���RemoteSensor2ʹ��
		const int NF								=51;
		const int Brightness						=52;

		const int PowerMode							=56;
		const int NearLight							=57;
		const int MiddleLight						=58;
		const int FarLight							=59;

		const int DTNTime_H							=	60;
		const int DTNTime_M							=	61;
		const int NTDTime_H							=	62;
		const int NTDTime_M							=	63;
	};

	namespace Seawolf_SensorID
	{
		const int Resolution							=1;//������
		const int Sharpness								=2;//���
		const int Satulation							=3;//���Ͷ�
		const int Gama									=4;
		const int NoiseReduction						=5;//����
		const int Bright								=6;//����
		const int Flip									=7;//����
		const int WDR									=20;//��̬ƫ��ֵ
		const int BLC									=9;//���ⲹ��
		const int Shutterlimit							=10;//������
		const int EXPpreference							=11;//�ع�����Ԥ��
		const int Exposurearea							=12;//�ع�����
		const int WBmode								=13;//��ƽ��ģʽ
		const int DNmode								=14;//��ҹģʽ
		const int Colormode								=15;//ҹ��ģʽ
		const int DayToNightTransition					=16;//����ҹ������
		const int NightToDayTransition					=17;//ת���������
		const int MaxGain								=18;//�������
		const int GainBoost								=19;//��������
		const int Fluorescent							=8;//ӫ��ģʽ
		const int VideoStandard							=21;//��Ƶ��ʽ
		const int ShowFrame								=22;
		const int HideFrame								=23;
		const int Up									=24;
		const int Down									=25;
		const int Left									=26;
		const int Right									=27;
		const int Enter									=28;
		const int LensType								=29;//��ͷ����
		const int NF									=30;//����
		const int Strength								=31;//ǿ��
		const int Infrared								=32;//����ƿ���

		const int DayNightDelay							=   57;
		const int DTNTime_H								=	58;
		const int DTNTime_M								=	59;
		const int NTDTime_H								=	60;
		const int NTDTime_M								=	61;
	};

	namespace HitachCompat_SensorID
	{
		const int Brightness			=	1;		//����
		const int VerticalSharpness		=	2;		//��ֱ���
		const int Saturation			=	3;		//���Ͷ�
		const int NightColor			=	4;		//ɫ������
		//const int VideoOutSetup		=	5;		//ģ����Ƶ���
		const int CameraMode			=	6;		//�����ģʽ
		const int MainGain				=	7;		//�������
		//const int WDR					=	8;		//��̬
		const int DNSensitivity			=	9;		//��ҹת��������
		const int FixShutter			=	10;		//�̶�����
		//const int BackLight			=	11;		//���ⲹ��	
		const int Mirror				=	12;		//����
		const int FocusDistance			=	13;		//�۽�����
		const int FocusMode				=	14;		//�۽�ģʽ
		//const int PictureMode			=	15;		//ͼ��ģʽ
		const int HoriSharpness			=	16;		//ˮƽ���
		const int AutoIris				=	17;		//�Զ���Ȧ
		const int IrisVoltage			=	18;		//�Զ���Ȧƫ�õ�ѹ
		const int WBMode				=	19;		//��ƽ��ģʽ
		const int AdjustLens			=	20;		//С���߽�����ͷ�������ڽ���
		const int NF					=	21;
		const int ManualTNF				=	22;

		const int FocusUp				=	54;
		const int FocusDown				=	55;
	};

	namespace ITN_SensorID
	{
		const int WDR						=1;//��̬
		const int Brightness				=2;//����
		const int Sharpness					=3;//���
		const int Chroma					=4;//ɫ��Ũ��
		const int Mirror					=5;//����
		const int Shutter					=6;//��������
		const int FixShutter				=7;//�̶�����
		const int MaxShutter				=8;//������
		const int MinShutter				=9;//��С����
		const int DNMode					=10;//��ҹģʽ
		const int MaxGain					=11;//�������
		const int DayToNightTransition		=12;//תҹ����ֵ
		const int NightToDayTransition		=13;//ת������ֵ
		const int NightColor				=14;//ҹ��ɫ������
		const int WBMode					=15;//��ƽ��
		const int AutoIris					=16;//�Զ���Ȧ
		const int Voltage					=17;//ƫ�õ�ѹ
		const int IrisSpeed					=18;//��Ȧ�ٶ�
		const int AE						=19;//���ģʽ
		const int PreventFlash				=20;//����
		const int Specific					=21;//��ƽ������ģʽ
		const int Surrounding				=22;//���ƿ�Ȩ��ֵ
		const int SpotAE_X					=23;//��λ��X
		const int SpotAE_Y					=24;//��λ��Y
		const int NoiseReduction			=25;//����
		const int GAMA						=26;//GAMA
	};

	namespace CMD8100_SensorID
	{
		const int Brightness						=1;//����
		const int Sharpness							=2;//���
		const int Saturation						=3;//���Ͷ�
		
		const int Mirror							=4;//����

		
		const int Iris								=5;//��Ȧ����
		const int Photometry						=6;//���ģʽ
		const int Shutter							=7;//���ŵ���
		const int AEMode							=0;//�ع�ģʽ
		

		const int WDR								=9;//��̬
		const int DeFog								=10;//ȥ��
		const int NoiseReduction					=11;//����˥��

		const int DNMode							=12;//��ҹģʽ
		const int ThresholdLevel					=13;//������
		const int MaxGain							=14;//�Զ��������

		const int FocusMode							=15;//�۽�ģʽ
		const int FocusNearLimit					=16;//�۽����� 
		const int Sensitivity						=17;//������
		
		const int NF								=18;//����
		const int WBMode							=19;//��ƽ��
		const int ShutDownLimit						=20;//��Ϳ����ٶ�
		const int IrisUp							=52;
		const int IrisDown							=53;
		const int FocusUp							=54;
		const int FocusDown							=55;
		const int PowerMode							=56;
		const int NearLight							=57;
		const int MiddleLight						=58;
		const int FarLight							=59;

		const int DTNTime_H							=	60;
		const int DTNTime_M							=	61;
		const int NTDTime_H							=	62;
		const int NTDTime_M							=	63;
		const int OnePushTrigger					=	64;

		const int MaskRegion						=	65;		//��˽�ڱ�����
		const int SetMask							=	66;		//��˽�ڱ�����
		const int Show								=	67;
		const int Hide								=	68;
		const int Clear								=	69;
		const int ClearAll							=	70;
		const int IncreaseWidth						=	71;
		const int DecreaseWidth						=	72;
		const int IncreaseHight						=	73;
		const int DecreaseHight						=	74;

	};

	namespace CMD7300_SensorID
	{
		const int Brightness						=1;//����
		const int Sharpness							=2;//���
		const int Saturation						=3;//���Ͷ�

		const int Mirror							=4;//����


		const int Iris								=5;//��Ȧ����
		const int Photometry						=6;//���ģʽ
		const int Shutter							=7;//���ŵ���
		const int AEMode							=0;//�ع�ģʽ


		const int WDR								=9;//��̬
		const int DeFog								=10;//ȥ��
		const int NoiseReduction					=11;//����˥��

		const int DNMode							=12;//��ҹģʽ
		const int ThresholdLevel					=13;//������
		const int MaxGain							=14;//�Զ��������

		const int FocusMode							=15;//�۽�ģʽ
		const int FocusNearLimit					=16;//�۽����� 
		const int Sensitivity						=17;//������

		const int NF								=18;//����
		const int WBMode							=19;//��ƽ��
		const int ShutDownLimit						=20;//��Ϳ����ٶ�
		const int IrisUp							=52;
		const int IrisDown							=53;
		const int FocusUp							=54;
		const int FocusDown							=55;
		const int PowerMode							=56;
		const int NearLight							=57;
		const int MiddleLight						=58;
		const int FarLight							=59;
		const int DTNTime_H							=60;
		const int DTNTime_M							=61;
		const int NTDTime_H							=62;
		const int NTDTime_M							=63;
		const int OnePushTrigger					=64;

	};

	namespace SONYCV7500_SensorID
	{
		const int Sharpness							=1;//���
		const int LowLightChromaSuppress			=2;//��������ɫ��֧��
		const int Gamma								=3;
		const int NoiseReduction					=4;//����˥��
		const int HR								=5;//�߷ֱ���ģʽ
		const int Mirror							=6;//����
		const int ThresholdLevel					=7;//ҹת��������
		const int StillImage						=8;//����
		//const int PictureEffect						=9;//��ͨ/��Ƭ
		const int AEMode							=10;//�ع�ģʽ
		const int Shutter							=11;//���ŵ���
		const int Iri								=12;//��Ȧ����
		const int Bright							=13;//���ȵ���
		const int Gain								=14;//�������
		const int GainLimit							=15;//�������ֵ
		const int AutoSlowShutter					=16;//�Զ�������
		const int ExpComp							=17;//�عⲹ��
		const int AE_Response						=18;//�Զ��ع���Ӧʱ��
		const int SpotAE							=19;//���ع�����
		const int SpotAE_X							=20;//���ع�X����
		const int SpotAE_Y							=21;//���ع�Y����
		const int BackLight							=22;//���ⲹ��
		const int WBMode							=23;//��ƽ��ģʽ
		const int R_Gain							=24;//������
		const int B_Gain							=25;//������
		const int DNMode							=26;//��ҹģʽ
		const int IRCorrection						=27;//�۽��й�
		const int WD								=28;//��̬
		const int DZoom								=29;//���ֱ䱶
		const int FocusMode							=30;//�۽�ģʽ
		//const int FocusSpeed						=31;//�۽��ٶ�
		const int FocusAutoMode						=32;//�۽��Զ�ģʽ
		const int AF_Sensitivity					=33;//�Զ��۽�������
		const int FocusNearLimit					=34;//������̾��� 
		const int AutoFocusOnce						=37;//����һ���Զ��۽�  ����

		//��̬����
		const int CompensLevel						=39;//
		const int BrightCompens						=40;//
		const int BrightLevel						=44;//Exposure ratio of short exposure
		//��ͷ����
		const int Movement							=45;//�ƶ�ʱ��
		const int Interval							=46;//���ʱ��
		//ADD
		const int Saturation						=47;//ɫ�ʱ��Ͷ�
		const int Hue								=48;//ɫ��
		const int HighSensitivity					=49;//��������
		const int BrightRemoteSensor2				=50;//���ȣ���RemoteSensor2ʹ��
		const int NF								=51;
		const int IrisUp							=52;
		const int IrisDown							=53;
		const int FocusUp							=54;
		const int FocusDown							=55;
		const int Stabilizer						=56;
		const int Defog								=57;
		const int Brightness						=58;
		const int NearLight							=59;
		const int MiddleLight						=60;
		const int FarLight							=61;

		const int NTDTime_H							=62;
		const int NTDTime_M							=63;
		const int DTNTime_H							=64;
		const int DTNTime_M							=65;
		const int PowerMode							=66;

		const int OpenPointLightFocus				=67;
		const int ClosePointLightFocus				=68;
	};

	namespace CMD7200_SensorID
	{
		const int Brightness			=	1;		//����
		const int Sharpness				=	2;		//���
		const int Mirror				=	3;		//����
		const int DayNightMode			=	4;		//��ҹģʽ
		const int ShutterMode			=   5;		//����ģʽ
		const int FixShutter			=	6;		//�̶�����
		const int FocusMode				=	7;		//�۽�ģʽ
		const int FocusNearLimit		=	8;		//�۽�����
		const int WBMode				=	9;		//��ƽ��ģʽ
		const int NF					=	10;

	}

	namespace SC110N_C_SensorID
	{
		const int Brightness			=	1;		//����
		const int Sharpness				=	2;		//��ֱ���
		const int Saturation			=	3;		//���Ͷ�
		const int NightColor			=	4;		//ɫ������
		const int VideoOutSetup			=	5;		//ģ����Ƶ���
		const int CameraMode			=	6;		//�����ģʽ
		const int MainGain				=	7;		//�������
		const int WDR					=	8;		//��̬
		const int DNSensitivity			=	9;		//��ҹת��������
		const int FixShutter			=	10;		//�̶�����
		const int BackLight				=	11;		//���ⲹ��	
		const int Mirror				=	12;		//����
		const int FocusDistance			=	13;		//�۽�����
		const int FocusMode				=	14;		//�۽�ģʽ
		const int PictureMode			=	15;		//ͼ��ģʽ
		const int Sharpness2			=	16;		//ˮƽ���
		const int NR					=	17;		//����
		const int ManualNR				=   18;		//�ֶ�����ǿ��

		const int MaskRegion			=	19;		//��˽�ڱ�����
		const int SetMask				=	20;		//��˽�ڱ�����
		//const int Cancel				=	21;
		const int Show					=	22;
		const int Hide					=	23;
		const int Clear					=	24;
		const int ClearAll				=	25;
		const int IncreaseWidth			=	26;
		const int DecreaseWidth			=	27;
		const int IncreaseHight			=	28;
		const int DecreaseHight			=	29;
		//const int Confirm				=   30;

	}

	namespace XARINA_SensorID
	{
		const int Brightness						=1;
		const int Saturation						=2;
		const int Contrast							=3;
		const int Sharpness							=4;
		const int Gamma								=5;
		const int ShutterMode						=7;
		const int FixShutter						=6;
 		const int GainMode	 						=8;
		const int MaxGain							=9;
		const int Photometry						=10;
		const int DNMode							=11;
		const int DayToNightThreshold				=12;
		const int NightToDayThreshold				=13;
		const int WBMode							=14;
		const int ATWMode							=15;
		const int ManualWB							=16;
		const int RedGain							=17;
		const int BlueGain							=18;
		const int IrisMode							=19;
		const int IrisSpeed							=20;
		const int WDRMode							=21;
 		const int FixGain							=22;
		const int WDRContrast						=23;
		const int NRMode							=24;
		const int NRStrengthLimit					=25;
		const int Mirror							=26;
		const int Infrared							=27;
		const int MaxShutter						=28;
		const int FlickerLess						=29;
		const int DoorMode							=30;//������ģʽ
		const int InfraredDayToNightThreshold		=31;
		const int InfraredNightToDayThreshold		=32;
		const int DayNightDelay						=33;
		const int DTNTime_H							=34;
		const int DTNTime_M							=35;
		const int NTDTime_H							=36;
		const int NTDTime_M							=37;	
	}
	namespace XARINA139_SensorID
	{
		const int Brightness						=1;
		const int Saturation						=2;
		const int Contrast							=3;
		const int Sharpness							=4;
		const int Gamma								=5;
		//const int ShutterMode						=7;
		//const int FixShutter						=6;
		const int GainMode	 						=8;
		const int MaxGain							=9;
		const int Photometry						=10;
		const int DNMode							=11;
		const int DayToNightThreshold				=12;
		const int NightToDayThreshold				=13;
		const int WBMode							=14;
		const int ATWMode							=15;
		const int ManualWB							=16;
		const int RedGain							=17;
		const int BlueGain							=18;
		const int IrisMode							=19;
		const int IrisSpeed							=20;
		const int WDRMode							=21;
		const int FixGain							=22;
		const int WDRContrast						=23;
		const int NRMode							=24;
		const int NRStrengthLimit					=25;
		const int Mirror							=26;
		const int Infrared							=27;
		//const int MaxShutter						=28;
		//const int FlickerLess						=29;
		const int DoorMode							=30;//������ģʽ
		const int InfraredDayToNightThreshold		=31;
		const int InfraredNightToDayThreshold		=32;
		const int DayNightDelay						=33;
		const int DTNTime_H							=34;
		const int DTNTime_M							=35;
		const int NTDTime_H							=36;
		const int NTDTime_M							=37;					
	}

	namespace Hi351x_SensorID
	{
		const int Brightness			=	1;		//����
		const int Saturation			=	2;		//���Ͷ�
		const int Contrast				=	3;		//�Աȶ�
		const int Sharpness				=	4;		//���

		const int ShutterMode			=	5;		//����ģʽ
		const int MaxShutter			=	6;		//������
		const int FixShutter			=	7;		//�̶�����

		const int GainMode	 			=	8;		//����
		const int MaxGain				=	9;		//�������
		const int FixGain				=	10;		//�̶�����			

		const int DNMode				=	11;		//��ҹ
		const int DayToNightThreshold	=	12;
		const int NightToDayThreshold	=	13;

		const int IrisMode				=	14;		//��Ȧ
		const int IrisSpeed				=	15;
		const int RoomIntOrOutMode		=	16;		//������


		const int WDRMode				=	17;		//��̬
		const int WDRContrast			=	18;		//��̬ǿ��

		const int Photometry			=	19;		//���ģʽ

		const int Mirror				=	20;		//����
		const int BeAway				=	21;		//����ģʽ

		const int NR2D					=	22;		//����
		const int MaxNR2D				=	23;
		const int ManualNR2D			=   24;		//�ֶ�����ǿ��
		const int NR3D					=	25;		//����
		const int MaxNR3D				=	26;
		const int ManualNR3D			=   27;		//�ֶ�����ǿ��

		const int DTNTime_H				=	28;
		const int DTNTime_M				=	29;
		const int NTDTime_H				=	30;
		const int NTDTime_M				=	31;

		const int InfraredDayToNightThreshold		=32;
		const int InfraredNightToDayThreshold		=33;
		const int DayNightDelay						=34;
		const int SmartInfraredMode_Auto			=35;
		const int SmartInfraredManualValue			=36;
		const int HLCMode				=37;  //ǿ������ HLC
		const int HLCContrastValue		=38;  //ǿ�����Ƶ�ǿ��
		const int BLCMode				=39;  //���ⲹ�� BLC
		const int AntiFogMode			=40;  //͸��ģʽ
		const int AntiFogValue			=41;  //͸��ǿ��
		const int BHLCMode				= 42;
		const int PictureControlUp		= 43; //ͼ�������
		const int PictureControlDown		= 44; //ͼ�������
		const int PictureControlLeft		= 45; //ͼ�������
		const int PictureControlRight		= 46; //ͼ�������
		const int PictureControlValue   = 47; //����


	};

	namespace AmbaS2_SensorID
	{
		const int Brightness			=	1;		//����
		const int Saturation			=	2;		//���Ͷ�
		const int Contrast				=	3;		//�Աȶ�
		const int Sharpness				=	4;		//���
		const int ShutterMode			=	5;		//����ģʽ
		const int MaxShutter			=	6;		//������
		const int FixShutter			=	7;		//�̶�����
		const int GainMode	 			=	8;		//����
		const int MaxGain				=	9;		//�������
		const int FixGain				=	10;		//�̶�����			
		const int DNMode				=	11;		//��ҹ
		const int DayToNightThreshold	=	12;
		const int NightToDayThreshold	=	13;
		const int IrisMode				=	14;		//��Ȧ
		const int IrisSpeed				=	15;
		const int RoomIntOrOutMode		=	16;		//������
		const int WDRMode				=	17;		//��̬
		const int WDRContrast			=	18;		//��̬ǿ��
		const int Photometry			=	19;		//���ģʽ
		const int Mirror				=	20;		//����
		const int BeAway				=	21;		//����ģʽ
		const int NR2D					=	22;		//����
		const int MaxNR2D				=	23;
		const int ManualNR2D			=   24;		//�ֶ�����ǿ��
		const int NR3D					=	25;		//����
		const int MaxNR3D				=	26;
		const int ManualNR3D			=   27;		//�ֶ�����ǿ��
		const int DTNTime_H				=	28;
		const int DTNTime_M				=	29;
		const int NTDTime_H				=	30;
		const int NTDTime_M				=	31;
		const int InfraredDayToNightThreshold		=32;
		const int InfraredNightToDayThreshold		=33;
		const int DayNightDelay						=34;
		const int SmartInfraredMode_Auto			=35;
		const int SmartInfraredManualValue			=36;
		const int StrongInhibitionMode				=37;  //ǿ������ HLC
		const int StrongInhibitionManualValue		=38;
		const int BacklightCompensationMode			=39;  //���ⲹ�� BLC
		const int ZoomInterval						=40;
		const int FocusInterval						=41;
		const int ZoomPosition						=42;
		const int ZoomWideSlow							=43;//
		const int ZoomTeleSlow							=44;//
		const int FocusPosition						=45;
		const int FocusFarSlow							=46;//
		const int FocusNearSlow							=47;//
		const int ZoomWideFast							=48;
		const int ZoomTeleFast							=49;
		const int FocusFarFast							=50;
		const int FocusNearFast							=51;
		const int RunAutoFocus							=52;
		const int ResetZoomFocus						=53;
		const int DeFog									=54;
		const int DeFogStrength							=55;
		const int AntiShake								=56;
	};

	namespace AmbaS2L_SensorID
	{
		const int Brightness			=	1;		//����
		const int Saturation			=	2;		//���Ͷ�
		const int Contrast				=	3;		//�Աȶ�
		const int Sharpness				=	4;		//���
		const int ShutterMode			=	5;		//����ģʽ
		const int MaxShutter			=	6;		//������
		const int FixShutter			=	7;		//�̶�����
		const int GainMode	 			=	8;		//����
		const int MaxGain				=	9;		//�������
		const int FixGain				=	10;		//�̶�����			
		const int DNMode				=	11;		//��ҹ
		const int DayToNightThreshold	=	12;
		const int NightToDayThreshold	=	13;
		const int IrisMode				=	14;		//��Ȧ
		const int IrisSpeed				=	15;
		const int RoomIntOrOutMode		=	16;		//������
		const int WDRMode				=	17;		//��̬
		const int WDRContrast			=	18;		//��̬ǿ��
		const int Photometry			=	19;		//���ģʽ
		const int Mirror				=	20;		//����
		const int BeAway				=	21;		//����ģʽ
		const int NR2D					=	22;		//����
		const int MaxNR2D				=	23;
		const int ManualNR2D			=   24;		//�ֶ�����ǿ��
		const int NR3D					=	25;		//����
		const int MaxNR3D				=	26;
		const int ManualNR3D			=   27;		//�ֶ�����ǿ��
		const int DTNTime_H				=	28;
		const int DTNTime_M				=	29;
		const int NTDTime_H				=	30;
		const int NTDTime_M				=	31;
		const int InfraredDayToNightThreshold		=32;
		const int InfraredNightToDayThreshold		=33;
		const int DayNightDelay						=34;
		const int SmartInfraredMode_Auto			=35;
		const int SmartInfraredManualValue			=36;
		const int StrongInhibitionMode				=37;  //ǿ������ HLC
		const int StrongInhibitionManualValue		=38;
		const int BacklightCompensationMode			=39;  //���ⲹ�� BLC
		const int ZoomInterval						=40;
		const int FocusInterval						=41;
		const int ZoomPosition						=42;
		const int ZoomWideSlow							=43;//
		const int ZoomTeleSlow							=44;//
		const int FocusPosition						=45;
		const int FocusFarSlow							=46;//
		const int FocusNearSlow							=47;//
		const int ZoomWideFast							=48;
		const int ZoomTeleFast							=49;
		const int FocusFarFast							=50;
		const int FocusNearFast							=51;
		const int RunAutoFocus							=52;
		const int ResetZoomFocus						=53;
		const int DeFog									=54;
		const int DeFogStrength							=55;
		const int AntiShake								=56;
	};
	namespace S2Fisheye_SensorID
	{
		const int Brightness			=	1;		//����
		const int Saturation			=	2;		//���Ͷ�
		const int Contrast				=	3;		//�Աȶ�
		const int Sharpness				=	4;		//���
		const int ShutterMode			=	5;		//����ģʽ
		const int MaxShutter			=	6;		//������
		const int FixShutter			=	7;		//�̶�����
		const int GainMode	 			=	8;		//����
		const int MaxGain				=	9;		//�������
		const int FixGain				=	10;		//�̶�����			
		const int DNMode				=	11;		//��ҹ
		const int DayToNightThreshold	=	12;
		const int NightToDayThreshold	=	13;
		const int IrisMode				=	14;		//��Ȧ
		const int IrisSpeed				=	15;
		const int RoomIntOrOutMode		=	16;		//������
		const int WDRMode				=	17;		//��̬
		const int WDRContrast			=	18;		//��̬ǿ��
		const int Photometry			=	19;		//���ģʽ
		const int Mirror				=	20;		//����
		const int BeAway				=	21;		//����ģʽ
		const int NR2D					=	22;		//����
		const int MaxNR2D				=	23;
		const int ManualNR2D			=   24;		//�ֶ�����ǿ��
		const int NR3D					=	25;		//����
		const int MaxNR3D				=	26;
		const int ManualNR3D			=   27;		//�ֶ�����ǿ��
		const int DTNTime_H				=	28;
		const int DTNTime_M				=	29;
		const int NTDTime_H				=	30;
		const int NTDTime_M				=	31;
		const int InfraredDayToNightThreshold		=32;
		const int InfraredNightToDayThreshold		=33;
		const int DayNightDelay						=34;
		const int SmartInfraredMode_Auto			=35;
		const int SmartInfraredManualValue			=36;
		const int StrongInhibitionMode				=37;  //ǿ������ HLC
		const int StrongInhibitionManualValue		=38;
		const int BacklightCompensationMode			=39;  //���ⲹ�� BLC
		const int ZoomInterval						=40;
		const int FocusInterval						=41;
		const int ZoomPosition						=42;
		const int ZoomWideSlow							=43;//
		const int ZoomTeleSlow							=44;//
		const int FocusPosition						=45;
		const int FocusFarSlow							=46;//
		const int FocusNearSlow							=47;//
		const int ZoomWideFast							=48;
		const int ZoomTeleFast							=49;
		const int FocusFarFast							=50;
		const int FocusNearFast							=51;
		const int RunAutoFocus							=52;
		const int ResetZoomFocus						=53;
		const int DeFog									=54;
		const int DeFogStrength							=55;
		const int AntiShake								=56;
	};	
	namespace CMD8300_SensorID
	{
		const int Saturation						=	1;		//���Ͷ�
		const int Contrast							=	2;		//�Աȶ�
		const int Sharpness							=   3;		//���
		const int Gamma								=	4;
		const int NoiseReductionMode				=	5;		//����˥��ģʽ
		const int NR_2D								=	6;		//2D����
		const int DeFog								=	7;		//ȥ��
		const int Mirror							=	8;		//����
		const int StillImage						=	9;		//����
		const int AEMode							=	10;		//�ع�ģʽ
		const int Shutter							=	11;		//���ŵ���
		const int Iri								=	12;		//��Ȧ����
		const int Bright							=	13;		//���ȵ���
		const int Gain								=	14;		//�������
		const int MaxGain							=	15;		//�������
		const int AutoSlowShutter					=	16;		//�Զ�������
		const int BackLight							=	17;		//���ⲹ��
		const int WBMode							=	18;		//��ƽ��
		const int RedGain							=	19;		//������
		const int BlueGain							=	20;		//������
		const int Infrared							=   21;		//�����
		const int DNMode							=	22;		//��ҹģʽ
		const int WDR								=	23;		//��̬
		const int HighlightHold						=	24;		//��������
		const int Brightness						=	25;		//����ֵ
		const int DZoom								=	26;		//���ֱ䱶
		const int FocusMode							=	27;		//�۽�ģʽ
		const int AutoFocusOnce						=	28;		//����һ���Զ��۽�  ����
		const int AF_Sensitivity					=	29;		//�Զ��۽�������
		const int FocusNearLimit					=	30;		//������̾��� 
		const int NtoDSensitivity					=	31;		//ҹת�������ȣ���ת����ֵ��
		const int DtoNSensitivity					=	32;		//��תҹ�����ȣ���ת����ֵ��
		const int NearLight							=	57;
		const int MiddleLight						=	58;
		const int FarLight							=	59;
		const int DTNTime_H							=	60;		//��ʱʱ��
		const int DTNTime_M							=	61;
		const int NTDTime_H							=	62;
		const int NTDTime_M							=	63;
		const int PowerMode							=	64;
		const int NoiseReduction					=	65;		//�Զ�����˥��
		const int ManualNoiseReduction				=	66;		//�ֶ�����˥�� 
	}
	namespace AmbaS2FBS8300_SensorID
	{
		const int Saturation						=	1;		//���Ͷ�
		const int Contrast							=	2;		//�Աȶ�
		const int Sharpness							=   3;		//���
		const int Gamma								=	4;
		const int NoiseReduction					=	5;		//����˥��
		const int NR_2D								=	6;		//2D����
		const int DeFog								=	7;		//ȥ��

		const int Mirror							=	8;		//����
		const int StillImage						=	9;		//����

		const int AEMode							=	10;		//�ع�ģʽ
		const int Shutter							=	11;		//���ŵ���
		const int Iri								=	12;		//��Ȧ����
		const int Bright							=	13;		//���ȵ���
		const int Gain								=	14;		//�������
		const int MaxGain							=	15;		//�������
		const int AutoSlowShutter					=	16;		//�Զ�������
		const int BackLight							=	17;		//���ⲹ��

		const int WBMode							=	18;		//��ƽ��
		const int RedGain							=	19;		//������
		const int BlueGain							=	20;		//������

		const int Infrared							=   21;		//�����
		const int DNMode							=	22;		//��ҹģʽ

		const int WDR								=	23;		//��̬
		const int HighlightHold						=	24;		//��������
		const int Brightness						=	25;		//����ֵ

		const int DZoom								=	26;		//���ֱ䱶
		const int FocusMode							=	27;		//�۽�ģʽ
		const int AutoFocusOnce						=	28;		//����һ���Զ��۽�  ����
		const int AF_Sensitivity					=	29;		//�Զ��۽�������
		const int FocusNearLimit					=	30;		//������̾��� 

		const int DtoNSensitivity					=	31;		//��תҹ�����ȣ���ת����ֵ��
		const int NtoDSensitivity					=	32;		//ҹת�������ȣ���ת����ֵ��
		//const int Delay								=	33;		//�ӳ�

		const int ZoomUp							=	41;
		const int ZoomDown							=	42;
		const int IrisUp							=	43;
		const int IrisDown							=	44;
		const int FocusUp							=	45;
		const int FocusDown							=	46;

		const int NearLight							=	57;
		const int MiddleLight						=	58;
		const int FarLight							=	59;
		const int DTNTime_H							=	60;		//��ʱʱ��
		const int DTNTime_M							=	61;
		const int NTDTime_H							=	62;
		const int NTDTime_M							=	63;
		const int PowerMode							=	64;
		
		const int AutoNoiseReduction				=	65;		//�Զ�����˥��
		const int ManualNoiseReduction				=	66;		//�ֶ�����˥�� 
		const int NoiseReductionMode				=	67;		//����˥��ģʽ

		const int ChromaSuppress					=	68;		//ɫ������
	};

	namespace AmbaS2FBS8310_SensorID
	{
		const int Saturation						=	1;		//���Ͷ�
		const int Contrast							=	2;		//�Աȶ�
		const int Sharpness							=   3;		//���
		const int Gamma								=	4;
		const int NoiseReduction					=	5;		//����˥��
		const int NR_2D								=	6;		//2D����
		const int DeFog								=	7;		//ȥ��

		const int Mirror							=	8;		//����
		const int StillImage						=	9;		//����

		const int AEMode							=	10;		//�ع�ģʽ
		const int Shutter							=	11;		//���ŵ���
		const int Iri								=	12;		//��Ȧ����
		const int Bright							=	13;		//���ȵ���
		const int Gain								=	14;		//�������
		const int MaxGain							=	15;		//�������
		const int AutoSlowShutter					=	16;		//�Զ�������
		const int BackLight							=	17;		//���ⲹ��

		const int WBMode							=	18;		//��ƽ��
		const int RedGain							=	19;		//������
		const int BlueGain							=	20;		//������

		const int Infrared							=   21;		//�����
		const int DNMode							=	22;		//��ҹģʽ

		const int WDR								=	23;		//��̬
		const int HighlightHold						=	24;		//��������
		const int Brightness						=	25;		//����ֵ

		const int DZoom								=	26;		//���ֱ䱶
		const int FocusMode							=	27;		//�۽�ģʽ
		const int AutoFocusOnce						=	28;		//����һ���Զ��۽�  ����
		const int AF_Sensitivity					=	29;		//�Զ��۽�������
		const int FocusNearLimit					=	30;		//������̾��� 

		const int NtoDSensitivity					=	31;		//ҹת�������ȣ���ת����ֵ��
		const int DtoNSensitivity					=	32;		//��תҹ�����ȣ���ת����ֵ��
		//const int Delay								=	33;		//�ӳ�

		const int ZoomUp							=	41;
		const int ZoomDown							=	42;
		const int IrisUp							=	43;
		const int IrisDown							=	44;
		const int FocusUp							=	45;
		const int FocusDown							=	46;

		const int NearLight							=	57;
		const int MiddleLight						=	58;
		const int FarLight							=	59;
		const int DTNTime_H							=	60;		//��ʱʱ��
		const int DTNTime_M							=	61;
		const int NTDTime_H							=	62;
		const int NTDTime_M							=	63;
		const int PowerMode							=	64;

		const int AutoNoiseReduction				=	65;		//�Զ�����˥��
		const int ManualNoiseReduction				=	66;		//�ֶ�����˥�� 
		const int NoiseReductionMode				=	67;		//����˥��ģʽ

		const int ChromaSuppress					=	68;		//ɫ������
	};

	namespace AmbaS2FBS9200_SensorID
	{
		const int Saturation						=	1;		//���Ͷ�
		const int Contrast							=	2;		//�Աȶ�
		const int Sharpness							=   3;		//���
		const int Gamma								=	4;
		const int NoiseReduction					=	5;		//����˥��
		const int NR_2D								=	6;		//2D����
		const int DeFog								=	7;		//ȥ��

		const int Mirror							=	8;		//����
		const int StillImage						=	9;		//����

		const int AEMode							=	10;		//�ع�ģʽ
		const int Shutter							=	11;		//���ŵ���
		const int Iri								=	12;		//��Ȧ����
		const int Bright							=	13;		//���ȵ���
		const int Gain								=	14;		//�������
		const int MaxGain							=	15;		//�������
		const int AutoSlowShutter					=	16;		//�Զ�������
		const int BackLight							=	17;		//���ⲹ��

		const int WBMode							=	18;		//��ƽ��
		const int RedGain							=	19;		//������
		const int BlueGain							=	20;		//������

		const int Infrared							=   21;		//�����
		const int DNMode							=	22;		//��ҹģʽ

		const int WDR								=	23;		//��̬
		const int HighlightHold						=	24;		//��������
		const int Brightness						=	25;		//����ֵ

		const int DZoom								=	26;		//���ֱ䱶
		const int FocusMode							=	27;		//�۽�ģʽ
		const int AutoFocusOnce						=	28;		//����һ���Զ��۽�  ����
		const int AF_Sensitivity					=	29;		//�Զ��۽�������
		const int FocusNearLimit					=	30;		//������̾��� 

		const int NtoDSensitivity					=	31;		//ҹת�������ȣ���ת����ֵ��
		const int DtoNSensitivity					=	32;		//��תҹ�����ȣ���ת����ֵ��
		//const int Delay								=	33;		//�ӳ�

		const int ZoomUp							=	41;
		const int ZoomDown							=	42;
		const int IrisUp							=	43;
		const int IrisDown							=	44;
		const int FocusUp							=	45;
		const int FocusDown							=	46;

		const int NearLight							=	57;
		const int MiddleLight						=	58;
		const int FarLight							=	59;
		const int DTNTime_H							=	60;		//��ʱʱ��
		const int DTNTime_M							=	61;
		const int NTDTime_H							=	62;
		const int NTDTime_M							=	63;
		const int PowerMode							=	64;

		const int AutoNoiseReduction				=	65;		//�Զ�����˥��
		const int ManualNoiseReduction				=	66;		//�ֶ�����˥�� 
		const int NoiseReductionMode				=	67;		//����˥��ģʽ

		const int ChromaSuppress					=	68;		//ɫ������

		const int OpenMenu							=	70;
		const int Up								=   71;
		const int Down								=	72;
		const int Left								=	73;
		const int Right								=   74;

		const int Sharpness2A						=	76;		//2A����ȵ��ڣ��������ã�
		const int Nr2A								=	77;		//2A�⽵����ڣ��������ã�
		const int AutoNoiseReduction2A				=	78;		//2A�Զ�����˥��
		const int ManualNoiseReduction2A			=	79;		//2A�ֶ�����˥�� 
		const int NoiseReductionMode2A				=	80;		//2A����˥��ģʽ

	};

	namespace CMD7400_SensorID
	{
		const int Saturation						=	1;		//���Ͷ�
		const int Contrast							=	2;		//�Աȶ�
		const int Sharpness							=   3;		//���
		const int Gamma								=	4;
		const int NoiseReduction					=	5;		//����˥��
		const int NR_2D								=	6;		//2D����
		const int DeFog								=	7;		//ȥ��

		const int Mirror							=	8;		//����
		const int StillImage						=	9;		//����

		const int AEMode							=	10;		//�ع�ģʽ
		const int Shutter							=	11;		//���ŵ���
		const int Iri								=	12;		//��Ȧ����
		const int Bright							=	13;		//���ȵ���
		const int Gain								=	14;		//�������
		const int MaxGain							=	15;		//�������
		const int AutoSlowShutter					=	16;		//�Զ�������
		const int BackLight							=	17;		//���ⲹ��

		const int WBMode							=	18;		//��ƽ��
		const int RedGain							=	19;		//������
		const int BlueGain							=	20;		//������

		const int Infrared							=   21;		//�����
		const int DNMode							=	22;		//��ҹģʽ

		const int WDR								=	23;		//��̬
		const int HighlightHold						=	24;		//��������
		const int Brightness						=	25;		//����ֵ

		const int DZoom								=	26;		//���ֱ䱶
		const int FocusMode							=	27;		//�۽�ģʽ
		const int AutoFocusOnce						=	28;		//����һ���Զ��۽�  ����
		const int AF_Sensitivity					=	29;		//�Զ��۽�������
		const int FocusNearLimit					=	30;		//������̾��� 

		const int NtoDSensitivity					=	31;		//ҹת�������ȣ���ת����ֵ��
		const int DtoNSensitivity					=	32;		//��תҹ�����ȣ���ת����ֵ��
		//const int Delay								=	33;		//�ӳ�

		const int ZoomUp							=	41;
		const int ZoomDown							=	42;
		const int IrisUp							=	43;
		const int IrisDown							=	44;
		const int FocusUp							=	45;
		const int FocusDown							=	46;

		const int NearLight							=	57;
		const int MiddleLight						=	58;
		const int FarLight							=	59;
		const int DTNTime_H							=	60;		//��ʱʱ��
		const int DTNTime_M							=	61;
		const int NTDTime_H							=	62;
		const int NTDTime_M							=	63;
		const int PowerMode							=	64;

		const int AutoNoiseReduction				=	65;		//�Զ�����˥��
		const int ManualNoiseReduction				=	66;		//�ֶ�����˥�� 
		const int NoiseReductionMode				=	67;		//����˥��ģʽ

		const int ChromaSuppress					=	68;		//ɫ������


		const int OpenMenu							=	69;
		const int CloseMenu							=   70;
		const int Up								=   71;
		const int Down								=	72;
		const int Left								=	73;
		const int Right								=   74;

		//const int ZoomSpeed							=   75;		//�䱶�ٶ�

		const int Sharpness2A						=	76;		//2A����ȵ��ڣ��������ã�
		const int Nr2A								=	77;		//2A�⽵����ڣ��������ã�
	};

	namespace FCBEV7310_SensorID
	{
		const int Sharpness							=1;//���
		const int LowLightChromaSuppress			=2;//��������ɫ��֧��
		const int Gamma								=3;
		const int NoiseReduction					=4;//����˥��
		const int HR								=5;//�߷ֱ���ģʽ
		const int Mirror							=6;//����
		const int ThresholdLevel					=7;//ҹת��������
		const int StillImage						=8;//����
		const int PictureEffect						=9;//��ͨ/��Ƭ
		const int AEMode							=10;//�ع�ģʽ
		const int Shutter							=11;//���ŵ���
		const int Iri								=12;//��Ȧ����
		const int Bright							=13;//���ȵ���
		const int Gain								=14;//�������
		const int GainLimit							=15;//�������ֵ
		const int AutoSlowShutter					=16;//�Զ�������
		const int ExpComp							=17;//�عⲹ��
		const int AE_Response						=18;//�Զ��ع���Ӧʱ��
		const int SpotAE							=19;//���ع�����
		const int SpotAE_X							=20;//���ع�X����
		const int SpotAE_Y							=21;//���ع�Y����
		const int BackLight							=22;//���ⲹ��
		const int WBMode							=23;//��ƽ��ģʽ
		const int R_Gain							=24;//������
		const int B_Gain							=25;//������
		const int DNMode							=26;//��ҹģʽ
		const int IRCorrection						=27;//�۽��й�
		const int WD								=28;//��̬
		const int DZoom								=29;//���ֱ䱶
		const int FocusMode							=30;//�۽�ģʽ
		//const int FocusSpeed						=31;//�۽��ٶ�
		const int FocusAutoMode						=32;//�۽��Զ�ģʽ
		const int AF_Sensitivity					=33;//�Զ��۽�������
		const int FocusNearLimit					=34;//������̾��� 
		const int AutoFocusOnce						=37;//����һ���Զ��۽�  ����

		//��̬����
		const int Display							=38;//Screen display
		const int Sens								=39;//Detection sensitivity
		const int B_intens							=40;//Blocked-up shadow correction level
		const int W_intens							=41;//Blown-out highlight correction level
		const int L_ExpSingalRatio					=42;//Long-exposure signal ratio
		const int S_ExpSingalRatio					=43;//Short-exposure signal ratio
		const int ShortTimeExp						=44;//Exposure ratio of short exposure
		//��ͷ����
		const int Movement							=45;//�ƶ�ʱ��
		const int Interval							=46;//���ʱ��
		//ADD
		const int Saturation						=47;//ɫ�ʱ��Ͷ�
		const int Hue								=48;//ɫ��
		const int HighSensitivity					=49;//��������
		const int BrightRemoteSensor2				=50;//���ȣ���RemoteSensor2ʹ��
		const int NF								=51;
		const int IrisUp							=52;
		const int IrisDown							=53;
		const int FocusUp							=54;
		const int FocusDown							=55;

		const int Brightness						=56;
		const int NearLight							=57;
		const int MiddleLight						=58;
		const int FarLight							=59;

		const int DTNTime_H							= 60;
		const int DTNTime_M							= 61;
		const int NTDTime_H							= 62;
		const int NTDTime_M							= 63;
		const int PowerMode							= 64;

		const int Defog								= 65;
		const int HLC_Lv							= 66;
		const int HLC_MaskLv						= 67;
		const int HLC								= 68;
	};

	namespace Power_Mode
	{
		const int _50HZ					=	0;
		const int _60HZ					=	1;
	}

	namespace ON_OFF_MODE
	{
		const int CLOSE					=	0;
		const int OPEN					=	1;
	}

	namespace A_M_MODE
	{
		const int Auto					=	0;
		const int Manual				=	1;
	}

	namespace PIC_MODE
	{
		const int MODE1					=	0;
		const int MODE2					=	1;
	}

	namespace Sensitivity
	{
		const int Low					=	1;
		const int Mid					=	2;
		const int High					=	3;
	}

	namespace CameraMode
	{
		const int Color					=	0;
		const int Color_DSS				=	1;
		const int Color_DN				=	2;
		const int Color_DSS_DN			=	3;
		const int FixShutter			=	4;
	}

	namespace IrisSpeed
	{
		const int Speed1				=	1;		
		const int Speed2				=	2;		
		const int Speed3				=	3;		
		const int Speed4				=	4;		
		const int Speed5				=	5;		
		const int Speed6				=	6;		
	}

	//�۽�ģʽ
	namespace FocusMode
	{
		const int AUTO					=	1;
		const int PUSH					=	2;
	}

	//�Զ��۽�
	namespace AutoFocus
	{
		const int DISTANCE5CM			=	1;		//5cm
		const int DISTANCE1M			=	2;		//1m
		const int DISTANCE1P5M			=	3;		//1.5m
		const int DISTANCE3M			=	4;		//3m
	}

	//����ģʽ
	namespace GainMode
	{
		const int AutoGain				=	0;		//�Զ�����
		const int FixedGain				=	1;		//�̶�����
	}

	//�ع�ģʽ
	namespace ShutterMode
	{
		const int AutoShutter			=	0;		//�Զ��ع�
		const int FixedShutter			=	1;		//�̶��ع�
	}

	//�ع�ʱ��
	namespace ShutterTime
	{
		const int Time1_5				=	1;
		const int Time1_10				=	2;
		const int Time1_15				=	3;
		const int Time1_20				=	4;
		const int Time1_25				=	5;
		const int Time1_50				=	6;
		const int Time1_100				=	7;
		const int Time1_200				=	8;
		const int Time1_500				=	9;
		const int Time1_1000			=	10;
		const int Time1_2000			=	11;
		const int Time1_5000			=	12;
		const int Time1_10000			=	13;
	}

	//����ģʽ
	namespace BrightnessMode
	{
		const int Auto					=	0;		//�Զ�
		const int Manual				=	1;		//�ֶ�
	};

	//��Ƶ��ʽ
 	namespace VideoSystem
 	{
 		const int NTSC					=	0;
 		const int PAL					=	1;
 	};

	//����
	namespace Mirror
	{
		const int Off					=	0;		//�ر�
		const int Horizontal			=	1;		//ˮƽ����
		const int Vertical				=	2;		//��ֱ����
		const int Horizontal_Vertical	=	3;		//ˮƽ+��ֱ����
	};

	//�ع��Ż�
	namespace AE_PREFs
	{
		const int Shadow				=	0;		//��Ӱ
		const int HighLight				=	1;		//����
	};

	//���ն�ģʽ
	namespace LowLight	
	{
		const int Gain					=	0;		//����ģʽ
		const int SlowShutter			=	1;		//������ģʽ
	};

	namespace LowShutterSetup
	{
		const int On					=	1;		//��
		const int Off					=	0;		//�ر�
	};

	//��������ֵ
	namespace ShutterLimit
	{
		const int X2					=	1;		//2X
		const int X4					=	2;		//4X
		const int X8					=	3;		//8X
		const int X16					=	4;		//16X
		const int X32					=	5;		//32X
	};

	//�����ع�ļ���ģʽ
	namespace MeterMode
	{
		const int ForGroud				=	1;		//ǰ��ģʽ
		const int BackGround			=	2;		//����ģʽ
	};

	//ǰ��Ԥ��ģʽ�µ��ع�����
	namespace ExposalZone
	{
		const int Most					=	1;		//�󲿷���Ļ����
		const int Center				=	2;		//��������
		const int Bottom				=	3;		//�²�1/3����
		const int All					=	4;		//ȫ��Ļ����
	};

	//��ҹģʽ��ʽ
	namespace DayNightMode
	{
		const int Auto					=	0;
		const int DayMode				=	1;
		const int NightMode				=	2;
		const int Timing				=	3;
		const int Auto_Sensor			=	4;		//ǰ��/��о�Զ�����ȫ��ǰ��/��о���Զ��л���ҹ
	};

	//��ҹ״̬
	namespace DayNightStatus
	{
		const int Night					=	0;
		const int Day					=	1;
		//const int Auto					=	2;
	};

	//ҹ��ģʽʱ����ɫѡ��
	namespace NightColorMode
	{
		const int Color					=	0;		//��ɫģʽ
		const int BlackWhit				=	1;		//�ڰ�ģʽ
	};

	//��ƽ��ģʽ
	namespace WB_Mode
	{
		const int ATW					=	1;		//
		const int Push					=	2;		//
		const int InDoor				=	3;		//
		const int FluorescenceLight		=	4;		//
		const int OutDoor				=	5;		//
		const int Hold					=	6;		//
	};

	//��Ȧ����ģʽ
	namespace IrisDriveMode
	{
		const int Auto					=	0;		//�Զ�
		const int Manual				=	1;		//�ֶ�
	};

	//�ع�ģʽ
	namespace ExposureMode
	{
		const int Auto					=	0;		//�Զ�
		const int Manual				=	1;		//�ֶ�
	};

	//�����ٶ�
	namespace ShutterSpeed
	{
		const int Normal				=	1;		//Normal
		const int FlickerLess			=	2;		//FlickerLess
		const int X250					=	3;		//1/250
		const int X500					=	4;		//1/500
		const int X1k					=	5;		//1/1k
		const int X2k					=	6;		//1/2k
		const int X4k					=	7;		//1/10k
		const int X10k					=	8;		//1/40k
		const int X100k					=	9;		//1/100k
	};

	//�Զ���ƽ������
	namespace AGCSetup
	{
		const int ON                 =   1;
		const int OFF                =   2;
	};

	//���ⲹ������
	namespace BLCSetup
	{
		const int ON                 =   1;
		const int OFF                =   2;
	};

	//���ⲹ��
	namespace BackLightSetup
	{
		const int OPEN               =   1;
		const int CLOSE              =   0;
	};

	//���ⲹ��ģʽ
	namespace BackLightMode
	{
		const int Area              =   1;
		const int CursoryGain       =   2;
		const int SmartGain         =   3;
	};

	//���
	namespace Sharpness
	{
		const int OFF               =    1;
		const int Low               =    2;
		const int Mid               =    3;
		const int High              =    4;
	};

	//����˸ģʽ
	namespace FlickerLessMode
	{
		const int OFF				= 0;
		const int NORMAL			= 1;
		const int LLFL				= 2;
		const int FIXS				= 3;
	};

	//ģ���������
	namespace VideoOutSetup
	{
		const int OPEN				= 1;
		const int CLOSE             = 0;
	};

	//�˵���ʽ
	namespace MenuType
	{
		const int Show			=  1;
		const int UnShow		=  2;
	};

	namespace WDRSetup
	{
		const int OPEN               =   1;
		const int CLOSE              =   0;
	};
	namespace SmartInfraredMode
	{
		const int CLOSE				=0; 
		const int AUTO				=1;
		const int MANUAL			=2;
	};
	namespace MotorStepMode
	{
		const int MICRO				=0;
		const int SMALL				=1;
		const int MIDDLE			=2;
		const int LARGE				=3;
		const int LARGEST			=4;
	};
	namespace DefogLevel
	{
		const int OFF				=0;
		const int LOW				=1;
		const int MID				=2;
		const int HIGH				=3;
	}
};
#endif //_SENSORCONST_H_
