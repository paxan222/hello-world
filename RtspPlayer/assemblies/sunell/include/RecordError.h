#ifndef _RECORDERROR_H_
#define _RECORDERROR_H_

//磁盘没有剩余空间
#define	SN_RECORD_NO_FREE_SPACE									-701

//打开录像文件失败
#define	SN_RECORD_OPEN_RECORDFILE_FAILED						-702

//写入录像文件失败
#define	SN_RECORD_WRITE_RECORDFILE_FAILED						-703	

//写入索引文件失败
#define	SN_RECORD_WRITE_INDEXFILE_FAILED						-704

//打开索引文件失败
#define	SN_RECORD_OPEN_INDEXFILE_FAILED							-705

//读取索引文件内容失败
#define	SN_RECORD_READ_INDEXFILE_FAILED							-706

//已经写满一个录像文件片大小
#define	SN_RECORD_RECORDFILE_ISMAXSIZE							-707

//没有设置磁盘目录
#define	SN_RECORD_NO_SET_ROOT_DIR								-708

//获取最早录像文件失败
#define	SN_RECORD_GET_EARLIEST_FILE_FAILED						-709

//替换文件失败
#define	SN_RECORD_REPLACE_FILE_FAILED							-710

//获取录像文件长度失败
#define	SN_RECORD_GET_FILE_LENGTH_FAILED						-711

//读取录像文件失败
#define	SN_RECORD_READ_RECORDFILE_FAILED						-712

//没有磁盘目录可写入录像
#define	SN_RECORD_NO_DIR_WRITE									-713

//磁盘空间写满
#define	SN_RECORD_FULL_STOP										-714

//录像查询结果为空
#define	SN_RECORD_RETRIEVER_QUERY_EMPTY_LIST					-715

//录像读取超过查询的时间范围
#define	SN_RECORD_RETRIVER_OUT_TIME_RANGE						-716

#define SN_RECORD_PARSE_ERROR									-717
#define SN_RECORD_PARSE_EMPTY									-718
#define SN_RECORD_PARSE_NO_IFRAM								-719
#define	SN_RECORD_QUERY_FAILED									-720

//录像文件没有打开
#define	SN_RECORD_NOT_OPEN										-721

//未知的磁盘类型
#define	SN_RECORD_UNKNOWN_DISKTYPE								-722

//定位开始位置失败
#define	SN_RECORD_LOCATE_BEGINPOS_FAILED						-723

//定位结束位置失败
#define	SN_RECORD_LOCATE_ENDPOS_FAILED							-724

//文件seek失败
#define	SN_RECORD_SEEK_ERROR									-725

//录像读取结束
#define	SN_RECORD_READ_END										-726

//
#define	SN_RECORD_FRAMEID_ERROR									-727

//没有录像数据
#define SN_RECORD_NO_RECORD_DATA								-728

//获取文件长度失败
#define	SN_RECORD_GET_LENGTH_FAILED							    -729

//没有可用空间
#define	SN_RECORD_NO_ENOUGH_SIZE								-730

//查找I帧失败
#define	SN_RECORD_NO_IFRAME										-731

#define	SN_RECORD_NO_FRAME										-732

//获取文件列表失败
#define	SN_RECORD_GET_FILELIST_FAILED							-733

//错误设备信息
#define SN_RECORD_INVALID_DEVICEINFO							-734

//获取设备列表失败
#define SN_RECORD_GET_DEVICELIST_FAILED							-735

//获取日期列表失败
#define SN_RECORD_GET_DATELIST_FAILED							-736

//录像数据时间戳回滚
#define SN_RECORD_TIME_ADJUST									-737

//录像数据日期切换
#define SN_RECORD_DATE_SWITCH									-738

//IO错误
#define SN_RECORD_IO_ERROR										-739

//录像目录更新
#define SN_RECORD_DIR_UPDATE									-740

//未知的磁盘文件系统格式
#define SN_RECORD_UNKNOWN_DISK_FORMAT							-741

#define SN_SNAPSHOT_OPENFILE_FAILED								-742

#define SN_SNAPSHOT_READFILE_FAILED								-743

#define SN_SNAPSHOT_FILE_NO_EXIST								-744

#define SN_SNAPSHOT_QUERY_FAILED								-745

#define SN_SNAPSHOT_CREATE_FILE_FAILED							-746

#define SN_RECORD_INVALID_FILE_NAME								-747


#define SN_RECORD_VIDEO_TYPE_CHANGED							-748

#define SN_RECORD_AUDIO_TYPE_CHANGED							-749
//分辨率改变
#define SN_RECORD_VIDEO_IMAGE_CHANGED							-750

//没有配置设备策略
#define	SN_RECORD_NO_FIND_DEVICEPOLICY							-751

//文件seek失败
#define	SN_RECORD_SEEK_BEGIN		 							-752

#define SN_RECORD_INVALID_DATE									-753

//TSFrameQueue更新时间时间戳，TS流格式错误
#define DATA_FARMAT_ERROR										-754

//没有发现该磁盘组
#define SN_RECORD_NO_FIND_GROUP									-755

//清理空间失败
#define  SN_RECORD_CLEAR_SPACE_FAILED							-756

//录像100个文件名用完
#define  SN_RECORD_NAME_OVER									-757

//移动回收站文件失败
#define SN_RECORD_MOVE_RECYCLEBIN_FILE_FAILED					-758

//移动空文件夹文件失败
#define SN_RECORD_MOVE_EMPTY_FILE_FAILED				    	-759

//没有可以使用的目录
#define SN_RECORD_NOT_FIND_DIR									-760

//没有磁盘可以使用，等一下别的磁盘
#define SN_RECORD_WAIT_DISK										-761

#define SN_RECORD_DISCARD_FRAME									-762

//超过上锁文件占总空间25%的阀值
#define SN_0VER_LOCKFILE_THRESHOLD								-763

#define SN_LOCK_FILE_FAILD										-764
#define SN_UNLOCK_FILE_FAILD									-765

//add by lmg 2014-09-09
//存储目录不可用                                            
#define SN_RECORD_DIR_NOT_USEABLE                               -766

//创建索引文件失败
#define SN_RECORD_CREATE_INDEXFILE_FAIL                         -767
//没有找到可用目录
#define SN_RECORD_NO_USEABLE_DIR                                -768
//创建录像文件名失败
#define SN_RECORD_CREATE_RECORDFILENAME_FAIL                    -769
//创建录像目录失败
#define SN_RECORD_CREATE_RECORDDIR_FAIL                         -770
//创建录像文件失败
#define SN_RECORD_CREATE_RECORDFILE_FAIL                        -771

#include "SNError.h"
#endif //_RECORDERROR_H_
