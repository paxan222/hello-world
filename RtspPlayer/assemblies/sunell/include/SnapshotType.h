#ifndef _SNAPSHOTTYPE_
#define _SNAPSHOTTYPE_
namespace SnapshotType
{
	enum SnapshotType
	{	
		Schedule				= 0x01,	//用第一位表示计划抓拍
		Alarm					= 0x02,	//用第二位表示报警抓拍
		Manual					= 0x04	//用第三位表示手动抓拍
	};//若Snapshot的值为0x07，则表示同时有这三种抓拍在进行
	
};
#endif
