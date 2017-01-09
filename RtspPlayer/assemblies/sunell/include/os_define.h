#ifndef _OS_DEFINE_H_
#define _OS_DEFINE_H_


#if (defined(WIN32) || defined(_WIN32_WCE))
	#ifdef _WIN32_WCE
		 //#include <process.h>
	#else
		 #include <process.h>
	#endif
	
	#include <winsock2.h>
	#include <ws2tcpip.h> 
	#include <errno.h>
	#define SOCKETHANDLE							SOCKET		
	#define SOCKERR									INVALID_SOCKET
	#define CLOSESOCKET(x)							closesocket(x)
	#define SOCKLENTYPE								int
	#define RTPIOCTL								ioctlsocket
	typedef  void THREADTYPE;	
	#define getLastError()							GetLastError()
	#define setLastError(x)							SetLastError(x)

	#define MSG_FLAG								0

	typedef __int64									INT64;
	typedef unsigned __int64						UINT64;
#else // not Win32
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <sys/ioctl.h>
	#include <net/if.h>
	#include <string.h>
	#include <netdb.h>
	#include <unistd.h>
	#include <sys/time.h>
	#include <sys/select.h>
	#include <signal.h>
	#include <errno.h>

	#define SOCKETHANDLE							int		
	#define SOCKERR									-1
	#define RTPCLOSE(x)								close(x)
    #define CLOSESOCKET(x)							close(x)

	typedef  struct addrinfo						ADDRINFO;
	typedef  struct sockaddr_storage				SOCKADDR_STORAGE;
	typedef struct sockaddr_in						SOCKADDR_IN;

	#define getLastError()							errno
	#define setLastError(x)							errno=x

	#ifdef SOCKLENTYPE_UINT
		#define SOCKLENTYPE							unsigned int
	#else
		#define SOCKLENTYPE							socklen_t //int
	#endif // SOCKLENTYPE_UINT
	
	#define MSG_FLAG								MSG_NOSIGNAL	


	#define IOCTLSOCKET								ioctl
	typedef  void* THREADTYPE;	

	typedef long long								INT64;
	typedef unsigned long long                      UINT64;
#endif // WIN32

#endif
