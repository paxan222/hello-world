#ifndef _SENSORABILITY_H_
#define _SENSORABILITY_H_
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

class SN_DLL_API SensorAbility
{
public:
	enum SensorControllerOpenType
	{
		SENSOR_CONTROLLER_OPEN_TYPE_NULL		=0,
		SENSOR_CONTROLLER_OPEN_TYPE_UI			=1,	//��UI�����ǰ������
		SENSOR_CONTROLLER_OPEN_TYPE_OSD_SN		=2, //��SN��OSD���͵�ǰ������
		SENSOR_CONTROLLER_OPEN_TYPE_OSD_ZTB10	=3 //�򿪵�OSDǰ�����ã����ZTB10���ͣ�95��Ԥ��λ����Ҫ�����������µ����˵���
	};
public:
	SensorAbility();
	~SensorAbility();
	/************************************************************************
	**����������ǰ�����ô�����
	*
	**���룺
	*		p_nSensorControllerOpenType   ǰ�����ô����ͣ��������SensorControllerOpenType
	**�����
	*		��
	**���ܣ�       
	*		����֧���ڵ���������
	************************************************************************/
	void setSensorControllerOpenType(const int &p_nSensorControllerOpenType);

	/************************************************************************
	**��������ȡǰ�����ô�����
	*
	**���룺
	*		��
	**���أ�
	*		ǰ�����ô�����
	**���ܣ�       
	*		��ȡǰ�����ô�����
	************************************************************************/
	const int getSensorControllerOpenType() const;
private:
	int m_nSensorControllerOpenType;	     //ǰ�����ô����ͣ��������SensorControllerOpenType
}_PACKED_1_;

/**********************************************************************/
#ifdef PRAGMA_PACK
 	#ifdef WIN32  
		#pragma pack(pop)
	#endif
 #endif
/**********************************************************************/


#endif // _SENSORABILITY_H_