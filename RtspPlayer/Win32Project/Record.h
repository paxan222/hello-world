extern "C" {
#include <libavcodec\avcodec.h>
#include <libavformat\avformat.h>
#include <libavformat\avio.h>
}
#pragma comment (lib, "avformat.lib")
#pragma comment (lib, "avcodec.lib")
#pragma comment (lib, "avutil.lib")


class CRecord{

	std::string					m_inputFilename;
	int							m_connectionTimeout{ 0 };
	unsigned long				m_timePrev{ 0 };
	bool						m_interruptFlag{ false };
	std::string					m_outputFilename;
	AVDictionary				*m_dictionary{ nullptr };
	AVFormatContext				*m_inputFmtCtx{ nullptr }, *m_outputFmtCtx{ nullptr };
	int							m_videoStreamIndex{ -1 }, m_audioStreamIndex{ -1 };
	AVPacket					m_packet;
	AVOutputFormat				*m_outputFmt{ nullptr };
	AVStream					*m_inputVideoStream{ nullptr }, *m_inputAudioStream{ nullptr }, *m_outputVideoStream{ nullptr }, *m_outputAudioStream{ nullptr };
	AVIOContext					*m_receivedCtx{ nullptr };
	const int					m_bufSize{ 32 * 1024 };
	BYTE						*m_buffer{ new BYTE[m_bufSize] };
	bool						m_stop{ false };

	AVCodecContext				*m_videoCodec{ nullptr };
	AVCodecContext				*m_audioCodec{ nullptr };
	
public:
	//Constructor for fileoutput
	//If outputFilename incorrect, than we get FALSE at guessing an outputFormat
	CRecord(PCHAR inputFilename, int connectionTimeout, PCHAR outputFilename){
		m_inputFilename = inputFilename;
		m_connectionTimeout = connectionTimeout;
		m_outputFilename = outputFilename;
	}
	//Constructor for bufferoutput
	CRecord(PCHAR inputFilename, int connectionTimeout){
		m_inputFilename = inputFilename;
		m_connectionTimeout = connectionTimeout;
	}

	~CRecord(){
		avformat_close_input(&m_inputFmtCtx);
		/*Constructor params*/
		m_inputFilename = "";
		m_outputFilename = "";
		/*Interrupt params*/
		m_connectionTimeout = 0;
		m_timePrev = 0;
		m_interruptFlag = false;
		/**/
		av_dict_free(&m_dictionary);
		avformat_free_context(m_inputFmtCtx);
		avformat_free_context(m_outputFmtCtx);
		m_videoStreamIndex = -1;
		m_audioStreamIndex = -1;
		av_free(m_outputFmt);
		av_free(m_inputVideoStream);
		av_free(m_inputAudioStream);
		av_free(m_outputVideoStream);
		av_free(m_outputAudioStream);
		av_free(m_receivedCtx);
		delete[] m_buffer;
		m_stop = false;
		avcodec_close(m_videoCodec);
		avcodec_close(m_audioCodec);
	}

	BOOL Open(); //Open stream or file
	BOOL StartRecord(); // start record thread
	BOOL StopRecord(); // stop record thread


private:
	BOOL Init(); //init input and output files
	void CreateStreams(); // Find and Create streams for output
	void RecalculateTimeStamps(AVPacket *packet, AVRational inputTimeBase, AVRational outputTimeBase); //Recalculate pts, dts and duration
	static int Interrupt_cb(void* opaque); // interrupt timeout callback
	static int ReceiveData_Cb(void* opaque, uint8_t *buf, int buf_size); //write packet to byte buffer callback

};