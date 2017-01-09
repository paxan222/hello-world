#ifndef _SENSORCONST_H_
#define _SENSORCONST_H_
namespace SensorConst
{
	const int SensorConfigVersionId = 10000;
	const int SensorConfigVersionId2 = 10001;
	const int NonInfrared = 0;	//非红外
	const int Infrared = 1;		//红外
	const int SmartInfrared = 2;//智能红外
	namespace SensorType
	{
		const int NULL_TYPE				= 0;		//未知类型，即表示不支持前端模组控制功能。
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
		const int Param_Scheme_Bad_Parameter_1 = 505;//开始时间设置不合理
		const int Param_Scheme_Bad_Parameter_2 = 506;//结束时间设置不合理
		const int Param_Scheme_Bad_Parameter_3 = 507;//开始时间大于或者等于结束时间
		const int Param_Scheme_Bad_Parameter_4 = 508;//其它原因导致错误
	}
	namespace ThermalBV3100_SensorID
	{
		const int NoneColorMode			=	1;		//伪彩模式
		const int ImagesMirror			=	2;		//图像翻转
		const int NRMode				=	3;		//2d降噪模式
		const int DVEMode				=	4;		//DVE增强等级
		const int AutoTime				=	5;		//自动时间

		const int Contrast				=	6;		//对比度
		const int ControlFFCMode		=	7;		//控制模式
		const int NR3DMode				=	8;		//3降噪模式
		const int NR3DModeA0			=	9;		//3降噪模式A0
		const int NR3DModeTM			=	10;		//3降噪模式TM
		const int ImagesAdjust			=	11;		//触发校正
		const int FOCUSINC				=	12;		//FOCUS+++
		const int FOCUSDEC				=	13;		//FOCUS---
		const int FOCUSINCSTART				=	14;		//FOCUS+++START
		const int FOCUSDECSTART				=	15;		//FOCUS---START
	};
	namespace SonyHQ1_SensorID
	{
		const int Mirror				=	1;		//镜像
		const int Brightness			=	2;		//亮度
		const int Sharpness				=	3;		//锐度
		const int RecRYGain				=	4;		//色彩调节(R-Y Gain)
		const int RecBYGain				=	5;		//色彩调节(B-Y Gain)
		const int ExposureMode			=	6;		//曝光模式
		const int ShutterSpeed			=	7;		//快门速度
		const int IrisDriveMode			=	8;		//光圈模式
		const int DCLevel				=	9;		//光圈值(0-255) //todo IPISVCNT?
		const int WB_Mode				=	10;		//白平衡模式
		const int AGCSetup				=	11;		//自动增益控制开关
		const int BackLightSetup		=   12;		//背光补偿设置
		const int BackLightMode			=	13;		//背光补偿模式
		const int BackLightArea1		=	14;		//背光补偿区域1(上部1/3区域)曝光比重(0-15)
		const int BackLightArea2		=	15;		//背光补偿区域2(下部1/3区域)曝光比重(0-15)
		const int BackLightArea3		=	16;		//背光补偿区域3(中部1/3左区域)曝光比重(0-15)
		const int BackLightArea4		=	17;		//背光补偿区域4(中部1/3右区域)曝光比重(0-15)
		const int BackLightArea5		=	18;		//背光补偿区域5(中央区域)曝光比重(0-15)
		const int CursoryGain			=	19;		//粗调范围(0-4)
		const int SmartGain				=	20;		//细调范围(1-1024)
		const int DayNightSetup			=	21;		//日夜模式方式
		const int DayToNightTransition	=	22;		//进入夜晚模式的临界值(0 - 44)
		const int NightToDayTransition	=	23;		//退出夜晚模式的临界值(0 - 44)
		const int FlickerLessMode		=	24;		//防闪烁模式
		const int NightColorMode		=	25;		//夜晚模式时的颜色选择
	};

	namespace DPS_SensorID
	{
		const int BrightnessMode		=	1;		//亮度模式
		const int Brightness			=	2;		//亮度(0-100)
		const int Sharpness				=	3;		//锐度(0-100)
		const int Saturation			=	4;		//饱和度(0-100)
		const int VideoSystem			=	5;		//视频制式
		const int Mirror				=	6;		//镜像
		const int AE_PREFs				=	7;		//曝光优化
		const int AGCBias				=	8;		//自动增益偏置值(-18 - 18)
		const int AGCLimit				=	9;		//自动增益限制值(0 - 60)
		const int LowLight				=	10;		//低照度模式
		const int ShutterLimit			=	11;		//快门限制值
		const int WDRBias				=	12;		//动态范围偏置值(-36 - 36)
		const int WDRLimit				=	13;		//动态范围限制值(0 - 36)
		const int MeterMode				=	14;		//区域曝光的计算模式
		const int ExposalZone			=	15;		//前景预置模式，曝光区域
		const int DayNightSetup			=	16;		//日夜模式方式
		const int NightColorMode		=	17;		//夜晚模式时的颜色选择
		const int NightMaxAGC			=	18;		//夜晚模式下的最大增益值(0 - 44)
		const int DayToNightTransition	=	19;		//进入夜晚模式的临界值(0 - 44)
		const int NightToDayTransition	=	20;		//退出夜晚模式的临界值(0 - 44)
		const int DayToNightDelay		=	21;		//进入夜晚模式的延迟及触发时间(0 - 10)
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
		const int Brightness			=	1;		//亮度(0-100)
		const int Sharpness				=	2;		//锐度(0-100)
		const int Mirror				=	3;		//镜像
		const int DayNightSetup			=	4;		//日夜模式方式
		const int DayToNightTransition	=	5;		//进入夜晚模式的临界值(0 - 255)
		const int NightToDayTransition	=	6;		//退出夜晚模式的临界值(0 - 255)
		const int VideoOutSetup			=	7;		//模拟输出开关
		const int MinShutter			=	8;		//最小快门
		const int MaxGain				=	9;		//最大增益
		const int IrisDriveMode			=	10;		//自动光圈
		const int MaxShutter			=	11;		//最大快门值
		const int GAMA					=	12;		//GAMA
		const int Chroma				=	13;		//色彩浓度
		const int WB_Mode				=	14;		//白平衡
		const int NightColor			=	15;		//夜晚色彩抑制
		const int IrisVoltage			=	16;		//自动光圈偏置电压
		const int IrisSpeed				=	17;		//光圈速度
		const int FixedShutter			=	18;		//固定快门
		const int ShutterMode			=	19;		//快门模式
		const int NF					=	20;		//降噪
		const int Strength				=	21;		//强度
		const int Infrared				=   22;		//红外灯
	};

	namespace IT1_ZoomModuleSensorID
	{
		const int Brightness			=	1;		//亮度(0-100)
		const int Sharpness				=	2;		//锐度(0-100)
		const int Mirror				=	3;		//镜像
		const int DayNightSetup			=	4;		//日夜模式方式
		const int DayToNightTransition	=	5;		//进入夜晚模式的临界值(0 - 255)
		const int NightToDayTransition	=	6;		//退出夜晚模式的临界值(0 - 255)
		const int VideoOutSetup			=	7;		//模拟输出开关
		const int MinShutter			=	8;		//最小快门
		const int MaxGain				=	9;		//最大增益
		const int IrisDriveMode			=	10;		//自动光圈
		const int MaxShutter			=	11;		//最大快门值
		const int GAMA					=	12;		//GAMA
		const int Chroma				=	13;		//色彩浓度
		const int WB_Mode				=	14;		//白平衡
		const int NightColor			=	15;		//夜晚色彩抑制
		const int IrisVoltage			=	16;		//自动光圈偏置电压
		const int IrisSpeed				=	17;		//光圈速度
		const int FixedShutter			=	18;		//固定快门
		const int ShutterMode			=	19;		//快门模式
		const int AutoFocus				=	20;		//自动聚焦
		const int FocusMode				=	21;		//聚焦模式
		const int AdjustLens			=	22;		//小工具矫正镜头，不用于界面
	};

	namespace ISP_SensorID
	{
		const int Brightness			=	1;		//亮度
		const int Saturation			=	2;		//饱和度
		const int Contrast				=	3;		//对比度
		const int GainMode				=	4;		//增益模式
		const int MaxGain				=	5;		//最大增益
		const int FixedGain				=	6;		//固定增益
		const int ShutterMode			=	7;		//曝光模式
		const int MaxShutterMode		=	8;		//最大曝光时间
		const int FixedShutterMode		=	9;		//固定曝光时间
		//const int MaxShutterMode_50HZ	=	8;		//最大曝光时间
		//const int FixShutterMode_50HZ	=	9;		//固定曝光时间
		const int DayNightSetup			=	10;		//日夜模式
		const int DayToNightTransition	=	11;		//进入夜晚临界值
		const int NightToDayTransition	=	12;		//进入白天临界值
		const int Sharpness				=	13;		//锐度
		const int CVBSOut				=	14;		//模拟输出
		const int NightColor			=	15;		//夜晚颜色
		const int IrisSpeed				=	16;		//光圈速度
		const int IrisVoltage			=	17;		//偏执电压
		const int AutoIris				=	18;		//自动光圈
		//const int IrisCloseSpeed		=	19;		//光圈关闭速度
		//const int PowerMode				=	20;		//电源模式
		//const int MaxShutterMode_60HZ	=	21;		//NTSC模式下的最大快门值
		//const int FixShutterMode_60HZ	=	22;		//NTSC模式下的固定快门值
		const int PowerFrequency		=	23;		//电源频率
		const int HighlightHold			=	24;		//强光抑制
		const int PhotometryArea		=	25;		//测光区域
		const int WBmode				=	26;		//白平衡模式
		const int WB_Manual				=	27;		//白平衡手动模式
		const int RedGain				=	28;		//红增益
		const int BlueGain				=	29;		//蓝增益
		const int Mirror				=	30;		//镜像
		const int ThreeDimensionalNR	=	31;
		const int HDR					=	32;		//宽动态模式
		const int RunMode				=	33;		//宽动态运行模式
		const int NR_2D					=	34;		//2D降噪
		const int KNF					=	35;		//空域
		const int NFAutoMax				=	36;		//空域最大强度
		const int TNF					=	37;		//时域
		const int Infrared				=	38;		//红外灯控制
		const int DoorMode				=	39;		//室内外模式
		const int DayNightDelay			=   57;
		const int DTNTime_H				=	58;
		const int DTNTime_M				=	59;
		const int NTDTime_H				=	60;
		const int NTDTime_M				=	61;
		const int TNFMode				=	62;		//3D降噪
	};

	namespace HITACH_SensorID
	{
		const int Brightness			=	1;		//亮度
		const int Sharpness				=	2;		//垂直锐度
		const int Saturation			=	3;		//饱和度
		const int NightColor			=	4;		//色彩抑制
		const int VideoOutSetup			=	5;		//模拟视频输出
		const int CameraMode			=	6;		//摄像机模式
		const int MainGain				=	7;		//最大增益
		const int WDR					=	8;		//宽动态
		const int DNSensitivity			=	9;		//日夜转换灵敏度
		const int FixShutter			=	10;		//固定快门
		const int BackLight				=	11;		//背光补偿	
		const int Mirror				=	12;		//镜像
		const int FocusDistance			=	13;		//聚焦距离
		const int FocusMode				=	14;		//聚焦模式
		const int PictureMode			=	15;		//图像模式
		const int Sharpness2			=	16;		//水平锐度
		const int NF					=	17;		//降噪
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
		const int Sharpness							=1;//锐度
		const int LowLightChromaSuppress			=2;//低照明下色度支持
		const int Gamma								=3;
		const int NoiseReduction					=4;//噪声衰减
		const int HR								=5;//高分辨率模式
		const int Mirror							=6;//镜像
		const int ThresholdLevel					=7;//夜转日灵敏度
		const int StillImage						=8;//冻结
		const int PictureEffect						=9;//普通/负片
		const int AEMode							=10;//曝光模式
		const int Shutter							=11;//快门调节
		const int Iri								=12;//光圈调节
		const int Bright							=13;//亮度调节
		const int Gain								=14;//增益调节
		const int GainLimit							=15;//最大增益值
		const int AutoSlowShutter					=16;//自动慢快门
		const int ExpComp							=17;//曝光补偿
		const int AE_Response						=18;//自动曝光响应时间
		const int SpotAE							=19;//点曝光设置
		const int SpotAE_X							=20;//点曝光X坐标
		const int SpotAE_Y							=21;//点曝光Y坐标
		const int BackLight							=22;//背光补偿
		const int WBMode							=23;//白平衡模式
		const int R_Gain							=24;//红增益
		const int B_Gain							=25;//蓝增益
		const int DNMode							=26;//日夜模式
		const int IRCorrection						=27;//聚焦感光
		const int WD								=28;//宽动态
		const int DZoom								=29;//数字变倍
		const int FocusMode							=30;//聚焦模式
		//const int FocusSpeed						=31;//聚焦速度
		const int FocusAutoMode						=32;//聚焦自动模式
		const int AF_Sensitivity					=33;//自动聚焦灵敏度
		const int FocusNearLimit					=34;//近焦最短距离 
		const int AutoFocusOnce						=37;//触发一次自动聚焦  按键
 
		//宽动态设置
		const int Display							=38;//Screen display
		const int Sens								=39;//Detection sensitivity
		const int B_intens							=40;//Blocked-up shadow correction level
		const int W_intens							=41;//Blown-out highlight correction level
		const int L_ExpSingalRatio					=42;//Long-exposure signal ratio
		const int S_ExpSingalRatio					=43;//Short-exposure signal ratio
		const int ShortTimeExp						=44;//Exposure ratio of short exposure
		//镜头设置
		const int Movement							=45;//移动时间
		const int Interval							=46;//间隔时间
		//ADD
		const int Saturation						=47;//色彩饱和度
		const int Hue								=48;//色调
		const int HighSensitivity					=49;//高灵敏度
		const int BrightRemoteSensor2				=50;//亮度，给RemoteSensor2使用
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

		const int MaskRegion						=	65;		//隐私遮蔽区域
		const int SetMask							=	66;		//隐私遮蔽设置
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
		const int Sharpness							=1;//锐度
		const int LowLightChromaSuppress			=2;//低照明下色度支持
		const int Gamma								=3;
		const int NoiseReduction					=4;//噪声衰减
		const int HR								=5;//高分辨率模式
		const int Mirror							=6;//镜像
		const int ThresholdLevel					=7;//夜转日灵敏度
		const int StillImage						=8;//冻结
		const int PictureEffect						=9;//普通/负片
		const int AEMode							=10;//曝光模式
		const int Shutter							=11;//快门调节
		const int Iri								=12;//光圈调节
		const int Bright							=13;//亮度调节
		const int Gain								=14;//增益调节
		const int GainLimit							=15;//最大增益值
		const int AutoSlowShutter					=16;//自动慢快门
		const int ExpComp							=17;//曝光补偿
		const int AE_Response						=18;//自动曝光响应时间
		const int SpotAE							=19;//点曝光设置
		const int SpotAE_X							=20;//点曝光X坐标
		const int SpotAE_Y							=21;//点曝光Y坐标
		const int BackLight							=22;//背光补偿
		const int WBMode							=23;//白平衡模式
		const int R_Gain							=24;//红增益
		const int B_Gain							=25;//蓝增益
		const int DNMode							=26;//日夜模式
		const int IRCorrection						=27;//聚焦感光
		const int WD								=28;//宽动态
		const int DZoom								=29;//数字变倍
		const int FocusMode							=30;//聚焦模式
		//const int FocusSpeed						=31;//聚焦速度
		const int FocusAutoMode						=32;//聚焦自动模式
		const int AF_Sensitivity					=33;//自动聚焦灵敏度
		const int FocusNearLimit					=34;//近焦最短距离 
		const int AutoFocusOnce						=37;//触发一次自动聚焦  按键

		//宽动态设置
		const int Display							=38;//Screen display
		const int Sens								=39;//Detection sensitivity
		const int B_intens							=40;//Blocked-up shadow correction level
		const int W_intens							=41;//Blown-out highlight correction level
		const int L_ExpSingalRatio					=42;//Long-exposure signal ratio
		const int S_ExpSingalRatio					=43;//Short-exposure signal ratio
		const int ShortTimeExp						=44;//Exposure ratio of short exposure
		//镜头设置
		const int Movement							=45;//移动时间
		const int Interval							=46;//间隔时间
		//ADD
		const int Saturation						=47;//色彩饱和度
		const int Hue								=48;//色调
		const int HighSensitivity					=49;//高灵敏度
		const int BrightRemoteSensor2				=50;//亮度，给RemoteSensor2使用
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
		const int Resolution							=1;//清晰度
		const int Sharpness								=2;//锐度
		const int Satulation							=3;//饱和度
		const int Gama									=4;
		const int NoiseReduction						=5;//噪声
		const int Bright								=6;//亮度
		const int Flip									=7;//镜像
		const int WDR									=20;//宽动态偏置值
		const int BLC									=9;//背光补偿
		const int Shutterlimit							=10;//慢快门
		const int EXPpreference							=11;//曝光区域预制
		const int Exposurearea							=12;//曝光区域
		const int WBmode								=13;//白平衡模式
		const int DNmode								=14;//日夜模式
		const int Colormode								=15;//夜晚模式
		const int DayToNightTransition					=16;//进入夜晚增益
		const int NightToDayTransition					=17;//转入白天增益
		const int MaxGain								=18;//最大增益
		const int GainBoost								=19;//增益提升
		const int Fluorescent							=8;//荧光模式
		const int VideoStandard							=21;//视频制式
		const int ShowFrame								=22;
		const int HideFrame								=23;
		const int Up									=24;
		const int Down									=25;
		const int Left									=26;
		const int Right									=27;
		const int Enter									=28;
		const int LensType								=29;//镜头类型
		const int NF									=30;//降噪
		const int Strength								=31;//强度
		const int Infrared								=32;//红外灯控制

		const int DayNightDelay							=   57;
		const int DTNTime_H								=	58;
		const int DTNTime_M								=	59;
		const int NTDTime_H								=	60;
		const int NTDTime_M								=	61;
	};

	namespace HitachCompat_SensorID
	{
		const int Brightness			=	1;		//亮度
		const int VerticalSharpness		=	2;		//垂直锐度
		const int Saturation			=	3;		//饱和度
		const int NightColor			=	4;		//色彩抑制
		//const int VideoOutSetup		=	5;		//模拟视频输出
		const int CameraMode			=	6;		//摄像机模式
		const int MainGain				=	7;		//最大增益
		//const int WDR					=	8;		//宽动态
		const int DNSensitivity			=	9;		//日夜转换灵敏度
		const int FixShutter			=	10;		//固定快门
		//const int BackLight			=	11;		//背光补偿	
		const int Mirror				=	12;		//镜像
		const int FocusDistance			=	13;		//聚焦距离
		const int FocusMode				=	14;		//聚焦模式
		//const int PictureMode			=	15;		//图像模式
		const int HoriSharpness			=	16;		//水平锐度
		const int AutoIris				=	17;		//自动光圈
		const int IrisVoltage			=	18;		//自动光圈偏置电压
		const int WBMode				=	19;		//白平衡模式
		const int AdjustLens			=	20;		//小工具矫正镜头，不用于界面
		const int NF					=	21;
		const int ManualTNF				=	22;

		const int FocusUp				=	54;
		const int FocusDown				=	55;
	};

	namespace ITN_SensorID
	{
		const int WDR						=1;//宽动态
		const int Brightness				=2;//亮度
		const int Sharpness					=3;//锐度
		const int Chroma					=4;//色彩浓度
		const int Mirror					=5;//镜像
		const int Shutter					=6;//快门设置
		const int FixShutter				=7;//固定快门
		const int MaxShutter				=8;//最大快门
		const int MinShutter				=9;//最小快门
		const int DNMode					=10;//日夜模式
		const int MaxGain					=11;//最大增益
		const int DayToNightTransition		=12;//转夜晚阈值
		const int NightToDayTransition		=13;//转白天阈值
		const int NightColor				=14;//夜晚色彩抑制
		const int WBMode					=15;//白平衡
		const int AutoIris					=16;//自动光圈
		const int Voltage					=17;//偏置电压
		const int IrisSpeed					=18;//光圈速度
		const int AE						=19;//测光模式
		const int PreventFlash				=20;//防闪
		const int Specific					=21;//白平衡特殊模式
		const int Surrounding				=22;//环绕块权重值
		const int SpotAE_X					=23;//点位置X
		const int SpotAE_Y					=24;//点位置Y
		const int NoiseReduction			=25;//降噪
		const int GAMA						=26;//GAMA
	};

	namespace CMD8100_SensorID
	{
		const int Brightness						=1;//亮度
		const int Sharpness							=2;//锐度
		const int Saturation						=3;//饱和度
		
		const int Mirror							=4;//镜像

		
		const int Iris								=5;//光圈调节
		const int Photometry						=6;//测光模式
		const int Shutter							=7;//快门调节
		const int AEMode							=0;//曝光模式
		

		const int WDR								=9;//宽动态
		const int DeFog								=10;//去雾
		const int NoiseReduction					=11;//噪声衰减

		const int DNMode							=12;//日夜模式
		const int ThresholdLevel					=13;//灵敏度
		const int MaxGain							=14;//自动最大增益

		const int FocusMode							=15;//聚焦模式
		const int FocusNearLimit					=16;//聚焦距离 
		const int Sensitivity						=17;//灵敏度
		
		const int NF								=18;//降噪
		const int WBMode							=19;//白平衡
		const int ShutDownLimit						=20;//最低快门速度
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

		const int MaskRegion						=	65;		//隐私遮蔽区域
		const int SetMask							=	66;		//隐私遮蔽设置
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
		const int Brightness						=1;//亮度
		const int Sharpness							=2;//锐度
		const int Saturation						=3;//饱和度

		const int Mirror							=4;//镜像


		const int Iris								=5;//光圈调节
		const int Photometry						=6;//测光模式
		const int Shutter							=7;//快门调节
		const int AEMode							=0;//曝光模式


		const int WDR								=9;//宽动态
		const int DeFog								=10;//去雾
		const int NoiseReduction					=11;//噪声衰减

		const int DNMode							=12;//日夜模式
		const int ThresholdLevel					=13;//灵敏度
		const int MaxGain							=14;//自动最大增益

		const int FocusMode							=15;//聚焦模式
		const int FocusNearLimit					=16;//聚焦距离 
		const int Sensitivity						=17;//灵敏度

		const int NF								=18;//降噪
		const int WBMode							=19;//白平衡
		const int ShutDownLimit						=20;//最低快门速度
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
		const int Sharpness							=1;//锐度
		const int LowLightChromaSuppress			=2;//低照明下色度支持
		const int Gamma								=3;
		const int NoiseReduction					=4;//噪声衰减
		const int HR								=5;//高分辨率模式
		const int Mirror							=6;//镜像
		const int ThresholdLevel					=7;//夜转日灵敏度
		const int StillImage						=8;//冻结
		//const int PictureEffect						=9;//普通/负片
		const int AEMode							=10;//曝光模式
		const int Shutter							=11;//快门调节
		const int Iri								=12;//光圈调节
		const int Bright							=13;//亮度调节
		const int Gain								=14;//增益调节
		const int GainLimit							=15;//最大增益值
		const int AutoSlowShutter					=16;//自动慢快门
		const int ExpComp							=17;//曝光补偿
		const int AE_Response						=18;//自动曝光响应时间
		const int SpotAE							=19;//点曝光设置
		const int SpotAE_X							=20;//点曝光X坐标
		const int SpotAE_Y							=21;//点曝光Y坐标
		const int BackLight							=22;//背光补偿
		const int WBMode							=23;//白平衡模式
		const int R_Gain							=24;//红增益
		const int B_Gain							=25;//蓝增益
		const int DNMode							=26;//日夜模式
		const int IRCorrection						=27;//聚焦感光
		const int WD								=28;//宽动态
		const int DZoom								=29;//数字变倍
		const int FocusMode							=30;//聚焦模式
		//const int FocusSpeed						=31;//聚焦速度
		const int FocusAutoMode						=32;//聚焦自动模式
		const int AF_Sensitivity					=33;//自动聚焦灵敏度
		const int FocusNearLimit					=34;//近焦最短距离 
		const int AutoFocusOnce						=37;//触发一次自动聚焦  按键

		//宽动态设置
		const int CompensLevel						=39;//
		const int BrightCompens						=40;//
		const int BrightLevel						=44;//Exposure ratio of short exposure
		//镜头设置
		const int Movement							=45;//移动时间
		const int Interval							=46;//间隔时间
		//ADD
		const int Saturation						=47;//色彩饱和度
		const int Hue								=48;//色调
		const int HighSensitivity					=49;//高灵敏度
		const int BrightRemoteSensor2				=50;//亮度，给RemoteSensor2使用
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
		const int Brightness			=	1;		//亮度
		const int Sharpness				=	2;		//锐度
		const int Mirror				=	3;		//镜像
		const int DayNightMode			=	4;		//日夜模式
		const int ShutterMode			=   5;		//快门模式
		const int FixShutter			=	6;		//固定快门
		const int FocusMode				=	7;		//聚焦模式
		const int FocusNearLimit		=	8;		//聚焦距离
		const int WBMode				=	9;		//白平衡模式
		const int NF					=	10;

	}

	namespace SC110N_C_SensorID
	{
		const int Brightness			=	1;		//亮度
		const int Sharpness				=	2;		//垂直锐度
		const int Saturation			=	3;		//饱和度
		const int NightColor			=	4;		//色彩抑制
		const int VideoOutSetup			=	5;		//模拟视频输出
		const int CameraMode			=	6;		//摄像机模式
		const int MainGain				=	7;		//最大增益
		const int WDR					=	8;		//宽动态
		const int DNSensitivity			=	9;		//日夜转换灵敏度
		const int FixShutter			=	10;		//固定快门
		const int BackLight				=	11;		//背光补偿	
		const int Mirror				=	12;		//镜像
		const int FocusDistance			=	13;		//聚焦距离
		const int FocusMode				=	14;		//聚焦模式
		const int PictureMode			=	15;		//图像模式
		const int Sharpness2			=	16;		//水平锐度
		const int NR					=	17;		//降噪
		const int ManualNR				=   18;		//手动降噪强度

		const int MaskRegion			=	19;		//隐私遮蔽区域
		const int SetMask				=	20;		//隐私遮蔽设置
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
		const int DoorMode							=30;//室内外模式
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
		const int DoorMode							=30;//室内外模式
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
		const int Brightness			=	1;		//亮度
		const int Saturation			=	2;		//饱和度
		const int Contrast				=	3;		//对比度
		const int Sharpness				=	4;		//锐度

		const int ShutterMode			=	5;		//快门模式
		const int MaxShutter			=	6;		//最大快门
		const int FixShutter			=	7;		//固定快门

		const int GainMode	 			=	8;		//增益
		const int MaxGain				=	9;		//最大增益
		const int FixGain				=	10;		//固定增益			

		const int DNMode				=	11;		//日夜
		const int DayToNightThreshold	=	12;
		const int NightToDayThreshold	=	13;

		const int IrisMode				=	14;		//光圈
		const int IrisSpeed				=	15;
		const int RoomIntOrOutMode		=	16;		//室内外


		const int WDRMode				=	17;		//宽动态
		const int WDRContrast			=	18;		//宽动态强度

		const int Photometry			=	19;		//测光模式

		const int Mirror				=	20;		//镜像
		const int BeAway				=	21;		//走廊模式

		const int NR2D					=	22;		//降噪
		const int MaxNR2D				=	23;
		const int ManualNR2D			=   24;		//手动降噪强度
		const int NR3D					=	25;		//降噪
		const int MaxNR3D				=	26;
		const int ManualNR3D			=   27;		//手动降噪强度

		const int DTNTime_H				=	28;
		const int DTNTime_M				=	29;
		const int NTDTime_H				=	30;
		const int NTDTime_M				=	31;

		const int InfraredDayToNightThreshold		=32;
		const int InfraredNightToDayThreshold		=33;
		const int DayNightDelay						=34;
		const int SmartInfraredMode_Auto			=35;
		const int SmartInfraredManualValue			=36;
		const int HLCMode				=37;  //强光抑制 HLC
		const int HLCContrastValue		=38;  //强光抑制的强度
		const int BLCMode				=39;  //背光补偿 BLC
		const int AntiFogMode			=40;  //透雾模式
		const int AntiFogValue			=41;  //透雾强度
		const int BHLCMode				= 42;
		const int PictureControlUp		= 43; //图像控制上
		const int PictureControlDown		= 44; //图像控制下
		const int PictureControlLeft		= 45; //图像控制左
		const int PictureControlRight		= 46; //图像控制右
		const int PictureControlValue   = 47; //步长


	};

	namespace AmbaS2_SensorID
	{
		const int Brightness			=	1;		//亮度
		const int Saturation			=	2;		//饱和度
		const int Contrast				=	3;		//对比度
		const int Sharpness				=	4;		//锐度
		const int ShutterMode			=	5;		//快门模式
		const int MaxShutter			=	6;		//最大快门
		const int FixShutter			=	7;		//固定快门
		const int GainMode	 			=	8;		//增益
		const int MaxGain				=	9;		//最大增益
		const int FixGain				=	10;		//固定增益			
		const int DNMode				=	11;		//日夜
		const int DayToNightThreshold	=	12;
		const int NightToDayThreshold	=	13;
		const int IrisMode				=	14;		//光圈
		const int IrisSpeed				=	15;
		const int RoomIntOrOutMode		=	16;		//室内外
		const int WDRMode				=	17;		//宽动态
		const int WDRContrast			=	18;		//宽动态强度
		const int Photometry			=	19;		//测光模式
		const int Mirror				=	20;		//镜像
		const int BeAway				=	21;		//走廊模式
		const int NR2D					=	22;		//降噪
		const int MaxNR2D				=	23;
		const int ManualNR2D			=   24;		//手动降噪强度
		const int NR3D					=	25;		//降噪
		const int MaxNR3D				=	26;
		const int ManualNR3D			=   27;		//手动降噪强度
		const int DTNTime_H				=	28;
		const int DTNTime_M				=	29;
		const int NTDTime_H				=	30;
		const int NTDTime_M				=	31;
		const int InfraredDayToNightThreshold		=32;
		const int InfraredNightToDayThreshold		=33;
		const int DayNightDelay						=34;
		const int SmartInfraredMode_Auto			=35;
		const int SmartInfraredManualValue			=36;
		const int StrongInhibitionMode				=37;  //强光抑制 HLC
		const int StrongInhibitionManualValue		=38;
		const int BacklightCompensationMode			=39;  //背光补偿 BLC
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
		const int Brightness			=	1;		//亮度
		const int Saturation			=	2;		//饱和度
		const int Contrast				=	3;		//对比度
		const int Sharpness				=	4;		//锐度
		const int ShutterMode			=	5;		//快门模式
		const int MaxShutter			=	6;		//最大快门
		const int FixShutter			=	7;		//固定快门
		const int GainMode	 			=	8;		//增益
		const int MaxGain				=	9;		//最大增益
		const int FixGain				=	10;		//固定增益			
		const int DNMode				=	11;		//日夜
		const int DayToNightThreshold	=	12;
		const int NightToDayThreshold	=	13;
		const int IrisMode				=	14;		//光圈
		const int IrisSpeed				=	15;
		const int RoomIntOrOutMode		=	16;		//室内外
		const int WDRMode				=	17;		//宽动态
		const int WDRContrast			=	18;		//宽动态强度
		const int Photometry			=	19;		//测光模式
		const int Mirror				=	20;		//镜像
		const int BeAway				=	21;		//走廊模式
		const int NR2D					=	22;		//降噪
		const int MaxNR2D				=	23;
		const int ManualNR2D			=   24;		//手动降噪强度
		const int NR3D					=	25;		//降噪
		const int MaxNR3D				=	26;
		const int ManualNR3D			=   27;		//手动降噪强度
		const int DTNTime_H				=	28;
		const int DTNTime_M				=	29;
		const int NTDTime_H				=	30;
		const int NTDTime_M				=	31;
		const int InfraredDayToNightThreshold		=32;
		const int InfraredNightToDayThreshold		=33;
		const int DayNightDelay						=34;
		const int SmartInfraredMode_Auto			=35;
		const int SmartInfraredManualValue			=36;
		const int StrongInhibitionMode				=37;  //强光抑制 HLC
		const int StrongInhibitionManualValue		=38;
		const int BacklightCompensationMode			=39;  //背光补偿 BLC
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
		const int Brightness			=	1;		//亮度
		const int Saturation			=	2;		//饱和度
		const int Contrast				=	3;		//对比度
		const int Sharpness				=	4;		//锐度
		const int ShutterMode			=	5;		//快门模式
		const int MaxShutter			=	6;		//最大快门
		const int FixShutter			=	7;		//固定快门
		const int GainMode	 			=	8;		//增益
		const int MaxGain				=	9;		//最大增益
		const int FixGain				=	10;		//固定增益			
		const int DNMode				=	11;		//日夜
		const int DayToNightThreshold	=	12;
		const int NightToDayThreshold	=	13;
		const int IrisMode				=	14;		//光圈
		const int IrisSpeed				=	15;
		const int RoomIntOrOutMode		=	16;		//室内外
		const int WDRMode				=	17;		//宽动态
		const int WDRContrast			=	18;		//宽动态强度
		const int Photometry			=	19;		//测光模式
		const int Mirror				=	20;		//镜像
		const int BeAway				=	21;		//走廊模式
		const int NR2D					=	22;		//降噪
		const int MaxNR2D				=	23;
		const int ManualNR2D			=   24;		//手动降噪强度
		const int NR3D					=	25;		//降噪
		const int MaxNR3D				=	26;
		const int ManualNR3D			=   27;		//手动降噪强度
		const int DTNTime_H				=	28;
		const int DTNTime_M				=	29;
		const int NTDTime_H				=	30;
		const int NTDTime_M				=	31;
		const int InfraredDayToNightThreshold		=32;
		const int InfraredNightToDayThreshold		=33;
		const int DayNightDelay						=34;
		const int SmartInfraredMode_Auto			=35;
		const int SmartInfraredManualValue			=36;
		const int StrongInhibitionMode				=37;  //强光抑制 HLC
		const int StrongInhibitionManualValue		=38;
		const int BacklightCompensationMode			=39;  //背光补偿 BLC
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
		const int Saturation						=	1;		//饱和度
		const int Contrast							=	2;		//对比度
		const int Sharpness							=   3;		//锐度
		const int Gamma								=	4;
		const int NoiseReductionMode				=	5;		//噪声衰减模式
		const int NR_2D								=	6;		//2D降噪
		const int DeFog								=	7;		//去雾
		const int Mirror							=	8;		//镜像
		const int StillImage						=	9;		//冻结
		const int AEMode							=	10;		//曝光模式
		const int Shutter							=	11;		//快门调节
		const int Iri								=	12;		//光圈调节
		const int Bright							=	13;		//亮度调节
		const int Gain								=	14;		//增益调节
		const int MaxGain							=	15;		//最大增益
		const int AutoSlowShutter					=	16;		//自动慢快门
		const int BackLight							=	17;		//背光补偿
		const int WBMode							=	18;		//白平衡
		const int RedGain							=	19;		//红增益
		const int BlueGain							=	20;		//蓝增益
		const int Infrared							=   21;		//红外灯
		const int DNMode							=	22;		//日夜模式
		const int WDR								=	23;		//宽动态
		const int HighlightHold						=	24;		//高亮抑制
		const int Brightness						=	25;		//亮度值
		const int DZoom								=	26;		//数字变倍
		const int FocusMode							=	27;		//聚焦模式
		const int AutoFocusOnce						=	28;		//触发一次自动聚焦  按键
		const int AF_Sensitivity					=	29;		//自动聚焦灵敏度
		const int FocusNearLimit					=	30;		//近焦最短距离 
		const int NtoDSensitivity					=	31;		//夜转日灵敏度（黑转彩阈值）
		const int DtoNSensitivity					=	32;		//日转夜灵敏度（彩转黑阈值）
		const int NearLight							=	57;
		const int MiddleLight						=	58;
		const int FarLight							=	59;
		const int DTNTime_H							=	60;		//定时时间
		const int DTNTime_M							=	61;
		const int NTDTime_H							=	62;
		const int NTDTime_M							=	63;
		const int PowerMode							=	64;
		const int NoiseReduction					=	65;		//自动噪声衰减
		const int ManualNoiseReduction				=	66;		//手动噪声衰减 
	}
	namespace AmbaS2FBS8300_SensorID
	{
		const int Saturation						=	1;		//饱和度
		const int Contrast							=	2;		//对比度
		const int Sharpness							=   3;		//锐度
		const int Gamma								=	4;
		const int NoiseReduction					=	5;		//噪声衰减
		const int NR_2D								=	6;		//2D降噪
		const int DeFog								=	7;		//去雾

		const int Mirror							=	8;		//镜像
		const int StillImage						=	9;		//冻结

		const int AEMode							=	10;		//曝光模式
		const int Shutter							=	11;		//快门调节
		const int Iri								=	12;		//光圈调节
		const int Bright							=	13;		//亮度调节
		const int Gain								=	14;		//增益调节
		const int MaxGain							=	15;		//最大增益
		const int AutoSlowShutter					=	16;		//自动慢快门
		const int BackLight							=	17;		//背光补偿

		const int WBMode							=	18;		//白平衡
		const int RedGain							=	19;		//红增益
		const int BlueGain							=	20;		//蓝增益

		const int Infrared							=   21;		//红外灯
		const int DNMode							=	22;		//日夜模式

		const int WDR								=	23;		//宽动态
		const int HighlightHold						=	24;		//高亮抑制
		const int Brightness						=	25;		//亮度值

		const int DZoom								=	26;		//数字变倍
		const int FocusMode							=	27;		//聚焦模式
		const int AutoFocusOnce						=	28;		//触发一次自动聚焦  按键
		const int AF_Sensitivity					=	29;		//自动聚焦灵敏度
		const int FocusNearLimit					=	30;		//近焦最短距离 

		const int DtoNSensitivity					=	31;		//日转夜灵敏度（彩转黑阈值）
		const int NtoDSensitivity					=	32;		//夜转日灵敏度（黑转彩阈值）
		//const int Delay								=	33;		//延迟

		const int ZoomUp							=	41;
		const int ZoomDown							=	42;
		const int IrisUp							=	43;
		const int IrisDown							=	44;
		const int FocusUp							=	45;
		const int FocusDown							=	46;

		const int NearLight							=	57;
		const int MiddleLight						=	58;
		const int FarLight							=	59;
		const int DTNTime_H							=	60;		//定时时间
		const int DTNTime_M							=	61;
		const int NTDTime_H							=	62;
		const int NTDTime_M							=	63;
		const int PowerMode							=	64;
		
		const int AutoNoiseReduction				=	65;		//自动噪声衰减
		const int ManualNoiseReduction				=	66;		//手动噪声衰减 
		const int NoiseReductionMode				=	67;		//噪声衰减模式

		const int ChromaSuppress					=	68;		//色度抑制
	};

	namespace AmbaS2FBS8310_SensorID
	{
		const int Saturation						=	1;		//饱和度
		const int Contrast							=	2;		//对比度
		const int Sharpness							=   3;		//锐度
		const int Gamma								=	4;
		const int NoiseReduction					=	5;		//噪声衰减
		const int NR_2D								=	6;		//2D降噪
		const int DeFog								=	7;		//去雾

		const int Mirror							=	8;		//镜像
		const int StillImage						=	9;		//冻结

		const int AEMode							=	10;		//曝光模式
		const int Shutter							=	11;		//快门调节
		const int Iri								=	12;		//光圈调节
		const int Bright							=	13;		//亮度调节
		const int Gain								=	14;		//增益调节
		const int MaxGain							=	15;		//最大增益
		const int AutoSlowShutter					=	16;		//自动慢快门
		const int BackLight							=	17;		//背光补偿

		const int WBMode							=	18;		//白平衡
		const int RedGain							=	19;		//红增益
		const int BlueGain							=	20;		//蓝增益

		const int Infrared							=   21;		//红外灯
		const int DNMode							=	22;		//日夜模式

		const int WDR								=	23;		//宽动态
		const int HighlightHold						=	24;		//高亮抑制
		const int Brightness						=	25;		//亮度值

		const int DZoom								=	26;		//数字变倍
		const int FocusMode							=	27;		//聚焦模式
		const int AutoFocusOnce						=	28;		//触发一次自动聚焦  按键
		const int AF_Sensitivity					=	29;		//自动聚焦灵敏度
		const int FocusNearLimit					=	30;		//近焦最短距离 

		const int NtoDSensitivity					=	31;		//夜转日灵敏度（黑转彩阈值）
		const int DtoNSensitivity					=	32;		//日转夜灵敏度（彩转黑阈值）
		//const int Delay								=	33;		//延迟

		const int ZoomUp							=	41;
		const int ZoomDown							=	42;
		const int IrisUp							=	43;
		const int IrisDown							=	44;
		const int FocusUp							=	45;
		const int FocusDown							=	46;

		const int NearLight							=	57;
		const int MiddleLight						=	58;
		const int FarLight							=	59;
		const int DTNTime_H							=	60;		//定时时间
		const int DTNTime_M							=	61;
		const int NTDTime_H							=	62;
		const int NTDTime_M							=	63;
		const int PowerMode							=	64;

		const int AutoNoiseReduction				=	65;		//自动噪声衰减
		const int ManualNoiseReduction				=	66;		//手动噪声衰减 
		const int NoiseReductionMode				=	67;		//噪声衰减模式

		const int ChromaSuppress					=	68;		//色度抑制
	};

	namespace AmbaS2FBS9200_SensorID
	{
		const int Saturation						=	1;		//饱和度
		const int Contrast							=	2;		//对比度
		const int Sharpness							=   3;		//锐度
		const int Gamma								=	4;
		const int NoiseReduction					=	5;		//噪声衰减
		const int NR_2D								=	6;		//2D降噪
		const int DeFog								=	7;		//去雾

		const int Mirror							=	8;		//镜像
		const int StillImage						=	9;		//冻结

		const int AEMode							=	10;		//曝光模式
		const int Shutter							=	11;		//快门调节
		const int Iri								=	12;		//光圈调节
		const int Bright							=	13;		//亮度调节
		const int Gain								=	14;		//增益调节
		const int MaxGain							=	15;		//最大增益
		const int AutoSlowShutter					=	16;		//自动慢快门
		const int BackLight							=	17;		//背光补偿

		const int WBMode							=	18;		//白平衡
		const int RedGain							=	19;		//红增益
		const int BlueGain							=	20;		//蓝增益

		const int Infrared							=   21;		//红外灯
		const int DNMode							=	22;		//日夜模式

		const int WDR								=	23;		//宽动态
		const int HighlightHold						=	24;		//高亮抑制
		const int Brightness						=	25;		//亮度值

		const int DZoom								=	26;		//数字变倍
		const int FocusMode							=	27;		//聚焦模式
		const int AutoFocusOnce						=	28;		//触发一次自动聚焦  按键
		const int AF_Sensitivity					=	29;		//自动聚焦灵敏度
		const int FocusNearLimit					=	30;		//近焦最短距离 

		const int NtoDSensitivity					=	31;		//夜转日灵敏度（黑转彩阈值）
		const int DtoNSensitivity					=	32;		//日转夜灵敏度（彩转黑阈值）
		//const int Delay								=	33;		//延迟

		const int ZoomUp							=	41;
		const int ZoomDown							=	42;
		const int IrisUp							=	43;
		const int IrisDown							=	44;
		const int FocusUp							=	45;
		const int FocusDown							=	46;

		const int NearLight							=	57;
		const int MiddleLight						=	58;
		const int FarLight							=	59;
		const int DTNTime_H							=	60;		//定时时间
		const int DTNTime_M							=	61;
		const int NTDTime_H							=	62;
		const int NTDTime_M							=	63;
		const int PowerMode							=	64;

		const int AutoNoiseReduction				=	65;		//自动噪声衰减
		const int ManualNoiseReduction				=	66;		//手动噪声衰减 
		const int NoiseReductionMode				=	67;		//噪声衰减模式

		const int ChromaSuppress					=	68;		//色度抑制

		const int OpenMenu							=	70;
		const int Up								=   71;
		const int Down								=	72;
		const int Left								=	73;
		const int Right								=   74;

		const int Sharpness2A						=	76;		//2A库锐度调节（仅调试用）
		const int Nr2A								=	77;		//2A库降噪调节（仅调试用）
		const int AutoNoiseReduction2A				=	78;		//2A自动噪声衰减
		const int ManualNoiseReduction2A			=	79;		//2A手动噪声衰减 
		const int NoiseReductionMode2A				=	80;		//2A噪声衰减模式

	};

	namespace CMD7400_SensorID
	{
		const int Saturation						=	1;		//饱和度
		const int Contrast							=	2;		//对比度
		const int Sharpness							=   3;		//锐度
		const int Gamma								=	4;
		const int NoiseReduction					=	5;		//噪声衰减
		const int NR_2D								=	6;		//2D降噪
		const int DeFog								=	7;		//去雾

		const int Mirror							=	8;		//镜像
		const int StillImage						=	9;		//冻结

		const int AEMode							=	10;		//曝光模式
		const int Shutter							=	11;		//快门调节
		const int Iri								=	12;		//光圈调节
		const int Bright							=	13;		//亮度调节
		const int Gain								=	14;		//增益调节
		const int MaxGain							=	15;		//最大增益
		const int AutoSlowShutter					=	16;		//自动慢快门
		const int BackLight							=	17;		//背光补偿

		const int WBMode							=	18;		//白平衡
		const int RedGain							=	19;		//红增益
		const int BlueGain							=	20;		//蓝增益

		const int Infrared							=   21;		//红外灯
		const int DNMode							=	22;		//日夜模式

		const int WDR								=	23;		//宽动态
		const int HighlightHold						=	24;		//高亮抑制
		const int Brightness						=	25;		//亮度值

		const int DZoom								=	26;		//数字变倍
		const int FocusMode							=	27;		//聚焦模式
		const int AutoFocusOnce						=	28;		//触发一次自动聚焦  按键
		const int AF_Sensitivity					=	29;		//自动聚焦灵敏度
		const int FocusNearLimit					=	30;		//近焦最短距离 

		const int NtoDSensitivity					=	31;		//夜转日灵敏度（黑转彩阈值）
		const int DtoNSensitivity					=	32;		//日转夜灵敏度（彩转黑阈值）
		//const int Delay								=	33;		//延迟

		const int ZoomUp							=	41;
		const int ZoomDown							=	42;
		const int IrisUp							=	43;
		const int IrisDown							=	44;
		const int FocusUp							=	45;
		const int FocusDown							=	46;

		const int NearLight							=	57;
		const int MiddleLight						=	58;
		const int FarLight							=	59;
		const int DTNTime_H							=	60;		//定时时间
		const int DTNTime_M							=	61;
		const int NTDTime_H							=	62;
		const int NTDTime_M							=	63;
		const int PowerMode							=	64;

		const int AutoNoiseReduction				=	65;		//自动噪声衰减
		const int ManualNoiseReduction				=	66;		//手动噪声衰减 
		const int NoiseReductionMode				=	67;		//噪声衰减模式

		const int ChromaSuppress					=	68;		//色度抑制


		const int OpenMenu							=	69;
		const int CloseMenu							=   70;
		const int Up								=   71;
		const int Down								=	72;
		const int Left								=	73;
		const int Right								=   74;

		//const int ZoomSpeed							=   75;		//变倍速度

		const int Sharpness2A						=	76;		//2A库锐度调节（仅调试用）
		const int Nr2A								=	77;		//2A库降噪调节（仅调试用）
	};

	namespace FCBEV7310_SensorID
	{
		const int Sharpness							=1;//锐度
		const int LowLightChromaSuppress			=2;//低照明下色度支持
		const int Gamma								=3;
		const int NoiseReduction					=4;//噪声衰减
		const int HR								=5;//高分辨率模式
		const int Mirror							=6;//镜像
		const int ThresholdLevel					=7;//夜转日灵敏度
		const int StillImage						=8;//冻结
		const int PictureEffect						=9;//普通/负片
		const int AEMode							=10;//曝光模式
		const int Shutter							=11;//快门调节
		const int Iri								=12;//光圈调节
		const int Bright							=13;//亮度调节
		const int Gain								=14;//增益调节
		const int GainLimit							=15;//最大增益值
		const int AutoSlowShutter					=16;//自动慢快门
		const int ExpComp							=17;//曝光补偿
		const int AE_Response						=18;//自动曝光响应时间
		const int SpotAE							=19;//点曝光设置
		const int SpotAE_X							=20;//点曝光X坐标
		const int SpotAE_Y							=21;//点曝光Y坐标
		const int BackLight							=22;//背光补偿
		const int WBMode							=23;//白平衡模式
		const int R_Gain							=24;//红增益
		const int B_Gain							=25;//蓝增益
		const int DNMode							=26;//日夜模式
		const int IRCorrection						=27;//聚焦感光
		const int WD								=28;//宽动态
		const int DZoom								=29;//数字变倍
		const int FocusMode							=30;//聚焦模式
		//const int FocusSpeed						=31;//聚焦速度
		const int FocusAutoMode						=32;//聚焦自动模式
		const int AF_Sensitivity					=33;//自动聚焦灵敏度
		const int FocusNearLimit					=34;//近焦最短距离 
		const int AutoFocusOnce						=37;//触发一次自动聚焦  按键

		//宽动态设置
		const int Display							=38;//Screen display
		const int Sens								=39;//Detection sensitivity
		const int B_intens							=40;//Blocked-up shadow correction level
		const int W_intens							=41;//Blown-out highlight correction level
		const int L_ExpSingalRatio					=42;//Long-exposure signal ratio
		const int S_ExpSingalRatio					=43;//Short-exposure signal ratio
		const int ShortTimeExp						=44;//Exposure ratio of short exposure
		//镜头设置
		const int Movement							=45;//移动时间
		const int Interval							=46;//间隔时间
		//ADD
		const int Saturation						=47;//色彩饱和度
		const int Hue								=48;//色调
		const int HighSensitivity					=49;//高灵敏度
		const int BrightRemoteSensor2				=50;//亮度，给RemoteSensor2使用
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

	//聚焦模式
	namespace FocusMode
	{
		const int AUTO					=	1;
		const int PUSH					=	2;
	}

	//自动聚焦
	namespace AutoFocus
	{
		const int DISTANCE5CM			=	1;		//5cm
		const int DISTANCE1M			=	2;		//1m
		const int DISTANCE1P5M			=	3;		//1.5m
		const int DISTANCE3M			=	4;		//3m
	}

	//增益模式
	namespace GainMode
	{
		const int AutoGain				=	0;		//自动增益
		const int FixedGain				=	1;		//固定增益
	}

	//曝光模式
	namespace ShutterMode
	{
		const int AutoShutter			=	0;		//自动曝光
		const int FixedShutter			=	1;		//固定曝光
	}

	//曝光时间
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

	//亮度模式
	namespace BrightnessMode
	{
		const int Auto					=	0;		//自动
		const int Manual				=	1;		//手动
	};

	//视频制式
 	namespace VideoSystem
 	{
 		const int NTSC					=	0;
 		const int PAL					=	1;
 	};

	//镜像
	namespace Mirror
	{
		const int Off					=	0;		//关闭
		const int Horizontal			=	1;		//水平镜像
		const int Vertical				=	2;		//垂直镜像
		const int Horizontal_Vertical	=	3;		//水平+垂直镜像
	};

	//曝光优化
	namespace AE_PREFs
	{
		const int Shadow				=	0;		//阴影
		const int HighLight				=	1;		//高亮
	};

	//低照度模式
	namespace LowLight	
	{
		const int Gain					=	0;		//增益模式
		const int SlowShutter			=	1;		//慢快门模式
	};

	namespace LowShutterSetup
	{
		const int On					=	1;		//打开
		const int Off					=	0;		//关闭
	};

	//快门限制值
	namespace ShutterLimit
	{
		const int X2					=	1;		//2X
		const int X4					=	2;		//4X
		const int X8					=	3;		//8X
		const int X16					=	4;		//16X
		const int X32					=	5;		//32X
	};

	//区域曝光的计算模式
	namespace MeterMode
	{
		const int ForGroud				=	1;		//前景模式
		const int BackGround			=	2;		//背景模式
	};

	//前景预置模式下的曝光区域
	namespace ExposalZone
	{
		const int Most					=	1;		//大部分屏幕区域
		const int Center				=	2;		//中央区域
		const int Bottom				=	3;		//下部1/3区域
		const int All					=	4;		//全屏幕区域
	};

	//日夜模式方式
	namespace DayNightMode
	{
		const int Auto					=	0;
		const int DayMode				=	1;
		const int NightMode				=	2;
		const int Timing				=	3;
		const int Auto_Sensor			=	4;		//前端/机芯自动，完全由前端/机芯来自动切换日夜
	};

	//日夜状态
	namespace DayNightStatus
	{
		const int Night					=	0;
		const int Day					=	1;
		//const int Auto					=	2;
	};

	//夜晚模式时的颜色选择
	namespace NightColorMode
	{
		const int Color					=	0;		//彩色模式
		const int BlackWhit				=	1;		//黑白模式
	};

	//白平衡模式
	namespace WB_Mode
	{
		const int ATW					=	1;		//
		const int Push					=	2;		//
		const int InDoor				=	3;		//
		const int FluorescenceLight		=	4;		//
		const int OutDoor				=	5;		//
		const int Hold					=	6;		//
	};

	//光圈驱动模式
	namespace IrisDriveMode
	{
		const int Auto					=	0;		//自动
		const int Manual				=	1;		//手动
	};

	//曝光模式
	namespace ExposureMode
	{
		const int Auto					=	0;		//自动
		const int Manual				=	1;		//手动
	};

	//快门速度
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

	//自动白平衡设置
	namespace AGCSetup
	{
		const int ON                 =   1;
		const int OFF                =   2;
	};

	//背光补偿设置
	namespace BLCSetup
	{
		const int ON                 =   1;
		const int OFF                =   2;
	};

	//背光补偿
	namespace BackLightSetup
	{
		const int OPEN               =   1;
		const int CLOSE              =   0;
	};

	//背光补偿模式
	namespace BackLightMode
	{
		const int Area              =   1;
		const int CursoryGain       =   2;
		const int SmartGain         =   3;
	};

	//锐度
	namespace Sharpness
	{
		const int OFF               =    1;
		const int Low               =    2;
		const int Mid               =    3;
		const int High              =    4;
	};

	//防闪烁模式
	namespace FlickerLessMode
	{
		const int OFF				= 0;
		const int NORMAL			= 1;
		const int LLFL				= 2;
		const int FIXS				= 3;
	};

	//模拟输出开关
	namespace VideoOutSetup
	{
		const int OPEN				= 1;
		const int CLOSE             = 0;
	};

	//菜单形式
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
