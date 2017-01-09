#ifndef _GENERALERROR_H_
#define _GENERALERROR_H_

#define SN_SUCCESS				0

//-1 ~ -100
#define SN_ERROR_GENERAL_BEGIN			(0)


//#define SN_ERROR_GENERAL_ERROR			(SN_ERROR_GENERAL_BEGIN - 1)

//内存不足
#define SN_ERROR_NOT_ENOUGH_MEMORY      (SN_ERROR_GENERAL_BEGIN - 2)

//无效句柄
#define SN_ERROR_INVALID_HANDLE			(SN_ERROR_GENERAL_BEGIN - 3)

//空指针
#define SN_ERROR_NULL_POINTER			(SN_ERROR_GENERAL_BEGIN - 4)

//函数调用无效
#define SN_ERROR_INVALID_FUNCTION		(SN_ERROR_GENERAL_BEGIN - 5)

//系统环境错误
#define SN_ERROR_BAD_ENVIRONMENT        (SN_ERROR_GENERAL_BEGIN - 6)

//加载程序时，格式错误
#define SN_ERROR_BAD_FORMAT				(SN_ERROR_GENERAL_BEGIN - 7)

////加载程序时，参数错误
#define SN_ERROR_BAD_PARAMETER			(SN_ERROR_GENERAL_BEGIN - 8)

//设备或数据未准备好
#define SN_ERROR_NOT_READY              (SN_ERROR_GENERAL_BEGIN - 9)

//数据长度错误
#define SN_ERROR_BAD_LENGTH             (SN_ERROR_GENERAL_BEGIN - 10)

//线程已运行
#define SN_ERROR_THREAD_RUNING			(SN_ERROR_GENERAL_BEGIN - 11)

//线程启动失败
#define SN_ERROR_THREAD_START_FAILED	(SN_ERROR_GENERAL_BEGIN - 12)

//队列已满
#define SN_ERROR_QUEUE_FULL				(SN_ERROR_GENERAL_BEGIN - 13)

//队列为空
#define SN_ERROR_QUEUE_EMPTY			(SN_ERROR_GENERAL_BEGIN - 14)

//系统超时
#define SN_ERROR_SYSTEM_TIMEOUT			(SN_ERROR_GENERAL_BEGIN - 15)

//未找到
#define SN_ERROR_NOT_FIND				(SN_ERROR_GENERAL_BEGIN - 16)

//不需要进行SSL加密
#define SN_ERROR_NO_SSL					(SN_ERROR_GENERAL_BEGIN - 17)

//需要进行SSL加密
#define SN_ERROR_NEED_SSL				(SN_ERROR_GENERAL_BEGIN - 18)

//ssl accpect超时
#define SN_ERROR_SSL_ACCECTP_FAILED		(SN_ERROR_GENERAL_BEGIN - 19)

//ssl connect超时
#define SN_ERROR_SSL_CONNECT_FAILED		(SN_ERROR_GENERAL_BEGIN - 20)

// 添加的设备已经存在
#define SN_ERROR_ADD_DEVICE_EXIST		(SN_ERROR_GENERAL_BEGIN - 21)

#endif // _AVOBSERVER_H_
