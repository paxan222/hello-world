#pragma once

#ifdef _WIN32

#define WINVER 0x0500
#define _WIN32_WINDOWS 0x0500
#define _WIN32_WINNT 0x0600

#define _CRT_SECURE_NO_WARNINGS
#define _WIN32_LEAN_AND_MEAN

#include "targetver.h"
#include <Windows.h>
#include <Shlobj.h>
#include <atlbase.h>
#include <atlstr.h>
#endif //WIN32

#include <algorithm>
#include <atomic>
#include <cassert>
#include <ctime>
#include <codecvt>
#include <condition_variable>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <future>
#include <iomanip>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <mutex>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>
#include <utility>
#include <vector>
#include <assert.h>

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/locale.hpp>
#include <boost/locale/generator.hpp>
#include <boost/noncopyable.hpp>
#include <boost/system/config.hpp>
#include <boost/thread/thread.hpp>
#include <boost/xpressive/xpressive.hpp>
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.
#include <boost/thread.hpp>
#include <boost/intrusive_ptr.hpp>
#include <boost/filesystem/fstream.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include "../corelib/common.h"

#include "tools/tlv.h"
#include "tools/binary_stream.h"
#include "tools/binary_stream_reader.h"
#include "tools/scope.h"
#include "tools/strings.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "../common.shared/constants.h"

typedef rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> rapidjson_allocator;

#undef min
#undef max
#undef small

#ifndef _WIN32
#   define assert(e) { if (!(e)) puts("ASSERT: " #e); }
#endif // _WIN32

#ifdef __APPLE__
#   if defined(DEBUG) || defined(_DEBUG)
//#       define DEBUG__OUTPUT_NET_PACKETS
#   endif // defined(DEBUG) || defined(_DEBUG)
#endif // __APPLE__
