
#if (defined(WIN32) || defined(_WIN32_WCE))
	#pragma warning(disable:4251)
	//disable warnings on 255 char debug symbols
	#pragma warning (disable : 4786)
	//disable warnings on extern before template instantiation
	#pragma warning (disable : 4231)

	#ifdef SN_DLL_EXPORTS
		#define SN_DLL_API __declspec(dllexport)
		#define SN_EXTERN
	#else
		#ifdef NO_SN_DLL_EXPORTS
			#define SN_DLL_API 
			#define SN_EXTERN
		#else
			#define SN_DLL_API __declspec(dllimport)
			#define SN_EXTERN extern
		#endif
	#endif

	#ifdef SN_C_EXPORTS
		#define SN_C_API __declspec(dllexport)
	#else
		#define SN_C_API __declspec(dllimport)
	#endif

#else
	#define SN_DLL_API 
	#define SN_C_API 
#endif

#if (!defined(WIN32) && !defined(_WIN32_WCE))
	#define CALLBACK
	typedef long long			INT64;
#else
	typedef __int64				INT64;
#endif

#ifndef byte
	typedef unsigned char byte;
#endif

//�����ֽڶ��룬���PRAGMA_PACK�����壬��Ĭ���ֽڶ���
#define  PRAGMA_PACK_DEFINE		10000 //�˶���Ϊ�˷�ֹ����PRAGMA_PACK�ĵط�û�а���SNPlatOS.h�ļ�������PRAGMA_PACK����Ⱦ
#define  PRAGMA_PACK
#define  PRAGMA_PACK_CHAR		1

