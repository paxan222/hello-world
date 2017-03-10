#ifdef RTSPRECORDER_EXPORTS
#define RTSPRECORDER_API __declspec(dllexport) 
#else
#define RTSPRECORDER_API __declspec(dllimport) 
#endif
#include <map>

template<typename Tkey, typename Tvalue>
class Container
{
	std::recursive_mutex _lock;
	std::map<Tkey, Tvalue> _map;
public:
	Container(std::map<Tkey, Tvalue> map){
		_map = map;
	}
	~Container(){}

	bool add(Tkey key, Tvalue value)
	{
		std::lock_guard<std::recursive_mutex> locker(_lock);
		if (hasItem(key))
			return false;
		_map.insert(std::make_pair(key, value));
		return true;
	}

	Tvalue getItem(Tkey key)
	{
		std::lock_guard<std::recursive_mutex> locker(_lock);
		auto it = _map.find(key);
		if (it != _map.end())
			return it->second;
		return nullptr;
	}
	void remove(Tkey key)
	{
		std::lock_guard<std::recursive_mutex> locker(_lock);
		auto it = _map.find(key);
		if (it != _map.end())
			_map.erase(it);
	}

	bool hasItem(Tkey key)
	{
		std::lock_guard<std::recursive_mutex> locker(_lock);
		auto it = _map.find(key);
		return it != _map.end();
	}
};

enum class ErrorCode :INT{
	UnknownError = -1,				// Unknow error
	Disconnect,						// Disconnected from rtsp source
	OpenInputFileError,				// Error occured while opening input file
	OpenOutputFileError,			// Error occured while opening output file
	EmptyFilename,					// Filename is empty
	RecievedCallbackIsNull,			// Recive data callback is null
	AllocCallbackError,				// Error occured while allocating callback to ouput
	OutputFormatNotMatchFormat,		// Output format is no match in the list of registered output formats	
	VideoStreamNotExist				// Error occured while checking for input video stream

};

#ifdef __cplusplus
extern "C"
{
#endif
	//Тип функии для обратного вызова при окончании пакетов
	typedef void (CALLBACK *FErrorCallback)(ErrorCode errorCode);
	//Тип функции для обратного вызова при записи в буфер данных
	typedef void(CALLBACK *FFRecieveDataCallback)(uint8_t *buf, int buf_size, bool isHeaderData);
	//Тип функции для обратного вызова при записи в буфер
	typedef void(CALLBACK *FFRecieveHeaderCallback)(uint8_t *buf, int buf_size);
	//Получить указатель
	RTSPRECORDER_API PVOID WINAPI StartFileRecord(PCHAR pchRtspPath, PCHAR pchOutputFilename, int timeout, FErrorCallback fEofCallback);
	RTSPRECORDER_API BOOL WINAPI StartCallbackRecord(PCHAR pchRtspPath, int timeout, FFRecieveDataCallback fReceiveDataCallback, FFRecieveHeaderCallback fReceiveHeaderCallback, FErrorCallback fEofCallback);
	RTSPRECORDER_API void WINAPI Stop(PCHAR pchRtspPath);
	RTSPRECORDER_API BOOL WINAPI WriteHeader(PCHAR pchRtspPath);
	RTSPRECORDER_API BOOL WINAPI SendHeader(PCHAR pchRtspPath);
#ifdef __cplusplus
}
#endif