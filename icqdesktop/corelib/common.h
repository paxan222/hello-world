#pragma once

#if !defined(InOut)
#define InOut
#endif

#if !defined(Out)
#define Out
#endif

// ----------------------------------------------
// fix for msvc++/clang compartibility

#if defined(_DEBUG) && !defined(DEBUG)
#define DEBUG
#endif

#if defined(DEBUG) && !defined(_DEBUG)
#define _DEBUG
#endif

// ----------------------------------------------

#if !defined(__FUNCTION__)
#define __FUNCTION__ ""
#endif

#define __DISABLE(x) {}

#define __STRA(x) _STRA(x)
#define _STRA(x) #x

#define __STRW(x) _STRW(x)
#define _STRW(x) L#x

#define __LINEA__ __STRA(__LINE__)
#define __LINEW__ __STRW(__LINE__)

#define __FUNCLINEA__ __FUNCTION__"(#"__LINEA__")"
#define __FUNCLINEW__ __FUNCTIONW__L"(#"__LINEW__L")"

#define __FILELINEA__ __FILE__"("__LINEA__")"
#define __FILELINEW__ __FILEW__L"("__LINEW__L")"

#define __TODOA__ __FILELINEA__": "
#define __TODOW__ __FILELINEW__L": "

#ifdef __APPLE__
#   undef __TODOA__
#   define __TODOA__ ""
#   undef __TODOW__
#   define __TODOW__ ""
#   undef __FILELINEA__
#   define __FILELINEA__ ""
#   undef __FILELINEW__
#   define __FILELINEW__ ""
#   undef __FUNCLINEA__
#   define __FUNCLINEA__ ""
#   undef __FUNCLINEW__
#   define __FUNCLINEW__ ""
#endif

namespace core
{
	typedef std::map<std::string, std::string> Str2StrMap;

	typedef std::set<int> IntSet;

	typedef std::set<std::string> StrSet;
}

namespace logutils
{

	inline const char* yn(const bool v) { return (v ? "yes" : "no"); }

	inline const char* tf(const bool v) { return (v ? "true" : "false"); }

}

namespace build
{
	inline bool is_debug()
	{
		#if defined(_DEBUG) || defined(DEBUG)
			return true;
		#else
			return false;
		#endif
	}

	inline bool is_release()
	{
		#if !defined(_DEBUG) && !defined(DEBUG)
			return true;
		#else
			return false;
		#endif
	}
}

namespace platform
{
	inline bool is_windows()
	{
		#if defined(_WIN32)
			return true;
		#else
			return false;
		#endif
	}

    inline bool is_windows_vista_or_late()
    {
        #if defined(_WIN32)
            OSVERSIONINFO os_version;
            os_version.dwOSVersionInfoSize = sizeof(os_version);
            ::GetVersionEx(&os_version);
            return (os_version.dwMajorVersion >= 6);
        #else
            return false;
        #endif
    }

	inline bool is_apple()
	{
		#if defined(__APPLE__)
			return true;
		#else
			return false;
		#endif
	}

	inline bool is_linux()
	{
		#if defined(__linux__)
			return true;
		#else
			return false;
		#endif
	}
}
namespace core
{
    namespace stats
    {
        typedef std::vector<std::pair<std::string, std:: string> > event_props_type;
        const int msg_pending_delay_s = 5;
    }
}

#ifdef _WIN32
namespace core
{
    namespace dump
    {
        inline bool is_crash_handle_enabled()
        {
            return true;
            return !build::is_debug();
        }
    }
}
#endif
