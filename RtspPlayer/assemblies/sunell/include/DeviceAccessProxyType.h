#ifndef _DEVICEACCESSPROXYTYPE_H_
#define _DEVICEACCESSPROXYTYPE_H_

namespace DeviceAccessProxyType
{
	enum DeviceAccessProxyType
	{
		NO_PROXY = 0,
		ROUTER_MAPPING = 0x1,		//路由映射
		TRANSPOND	= 0x2			//转发
	};
} ;

#endif
