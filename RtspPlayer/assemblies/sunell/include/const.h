#ifndef _CONST_H_

#define _CONST_H_

#define CONST_VIDEO_RECV_BUFFER_SIZE			4096 * 1024

//TCP/UDPһ�����ݰ�ͷ
#define CONST_LENGTH_PACKET_HEAD				24		//��ͷ����
#define CONST_LENGTH_PACKET_RESERVE				3		//��ͷ����λ����

#define CONST_MAXLENGTH_NETWORK_MTU				1400	//MTU����
#define CONST_MAXLENGTH_PACKET					(CONST_MAXLENGTH_NETWORK_MTU)
#define CONST_MAXLENGTH_PACKET_PAYLOAD			(CONST_MAXLENGTH_PACKET - CONST_LENGTH_PACKET_HEAD)		//����󳤶�

//��Ƶ��ʽר�ð���ʽ����
#define CONST_LENGTH_AV_PACKET_HEAD				20
#define CONST_LENGTH_AV_PACKET_RESERVE			2


#define CONST_MAXLENGTH_COMMAND					(CONST_MAXLENGTH_PACKET - CONST_LENGTH_PACKET_HEAD)		//������󳤶�
#define CONST_LENGTH_COMMAND_HEAD				76		//����ͷ����
#define CONST_MAXLENGTH_COMMAND_PAYLOAD			(CONST_MAXLENGTH_COMMAND - CONST_LENGTH_COMMAND_HEAD)	//
#define CONST_LENGTH_COMMAND_SOURCEID			32
#define CONST_LENGTH_COMMAND_DESTID				32
#define CONST_LENGTH_COMMAND_RESERVE			2
#define CONST_LENGTH_FRAMEHEAD					16 //25

#define CONST_COMMAND_VERSION_V1				1
#define CONST_COMMAND_VERSION_V2				2

#define CONST_DEFAULTSIZE_CAPTUREVECTOR			100			//CaptureManagerĬ�ϵĶ������ֵ


#define MAX_LEN_SPLIT_DATA							((1024 - CONST_LENGTH_COMMAND_HEAD)*15)   //�ְ�������󳤶�

#define	CONST_MAXLENGTH_RESPONSEINFO				512		//Ӧ����Ϣ��󳤶�
#define	CONST_LENGTH_RESPONSE_HEAD					12		//Ӧ������ͷ����


#define CONST_LENGTH_DATANAME						256
#define CONST_LENGTH_SUBCOMMAND_PAYLOAD    			(CONST_MAXLENGTH_COMMAND_PAYLOAD - sizeof(int) - sizeof(unsigned int) )


#define CONST_INTERVAL_CAPTUREFREE					30			//	captureFree�߳�ɨ����ʱ��
#define CONST_INTERVAL_MUX							15			//����Ƶ�����������ݵļ��ʱ�䣨��λ���룩
 
#define CONST_MAXLENGTH_VIDEO_FRAME					(1920 * 1080) //��Ƶ֡��󳤶�

#define CONST_MAXLENGTH_AUDIO_FRAME					(1024 * 6)		//��Ƶ֡��󳤶�

#define CONST_MPEG2TS_PACKET_LENGTH					188

#define RTPEXTENDHEADID								100			//RTP��չͷ�ı�ʶ�ţ���չͷ�б�����֡����

#define CONST_SIZE_RTP_FRAME_MAP					20			//rtp�ְ�֡����Ĭ�ϴ�С
#define CONST_SIZE_RTP_PACKET_MAP					100			//rtp�ְ�ÿ֡����Ĭ�ϴ�С
#define CONST_MAXSIZE_RTPFRAME_MAP					100			//rtp�ְ�֡�����������

#define CONST_RTP_EXTENDHEAD_LENGTH					72			//rtp��չͷ����

#define CONST_MAXLENGTH_IP							48			//�ַ���IP����

#define CONST_SESSION_SUCCESS						0
#define CONST_SESSION_FAILED						-1
#define CONST_SESSION_EXIT							-2

#define CONST_TRANSFER_CONNECT_TIMEOUT				3000

//�û�����TCP���ӣ���Ƶ������������޶�ֵ
#define CONST_MAX_TCP_CONNECTION_NUM				128				//����TCP��������
#define CONST_MAX_AV_CONNECTION_NUM					64				//��������Ƶ������	
#define CONST_MAX_SESSIONID							65535				//�����û���
#define CONST_MAX_FILE_TRANSFER_NUM					16				//�����ļ�������


#define CONST_MAX_DISK_GROUP_ID_COUNT				8				//�����ID������

#define CONST_DIRECT_IO_BLOCK_SIZE					(4*1024)		//DirectIO��д���С

#endif //_CONST_H_

