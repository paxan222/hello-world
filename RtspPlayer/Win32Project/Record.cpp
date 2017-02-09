#include "stdafx.h"
#include "Record.h"

BOOL CRecord::Open(){

	av_register_all();
	avformat_network_init();
	if (m_inputFilename.find("rtsp://") != std::string::npos)
	{
		if (0 > av_dict_set(&m_dictionary, "rtsp_transport", "tcp", 0))
			return FALSE;
	}
	else
	{
		m_dictionary = nullptr;
	}

	if (Init() == FALSE){
		return FALSE;
	}
	return TRUE;
}

int CRecord::Interrupt_cb(void* opaque){
	CRecord* recorder = static_cast<CRecord*>(opaque);
	int time = GetTickCount();
	if ((time - recorder->m_timePrev) > recorder->m_connectionTimeout && !recorder->m_interruptFlag){
		return 1;
	}
	return 0;
}

FILE *outputFile;// = fopen("D:\\TestVideo\\record0.mkv", "wb");

int count = 0;
int64_t lastPts = 0;
void writeFile(uint8_t *buf, int buf_size, bool isHeaderData){
	if (isHeaderData){
		if (outputFile != nullptr)
			fclose(outputFile);
		_RPT0(0, "NewFile\n");
		auto filename = "D:\\TestVideo\\record" + std::to_string(count) + ".mkv";
		outputFile = fopen(filename.c_str(), "wb");
		count++;
	}
	fwrite(buf, 1, buf_size, outputFile);

	_RPT1(0, "BufSize:%i\n", buf_size);
	//_RPT1(0, "WriteCurrentPts: %i\n", currentPts);
}

int CRecord::ReceiveData_Cb(void* opaque, uint8_t *buf, int buf_size){
	CRecord* recorder = static_cast<CRecord*>(opaque);

	writeFile(buf, buf_size, recorder->m_isHeaderData);
	//int lastpts = 0;
	//recorder->m_RcvDtCb(buf, buf_size,  recorder->m_lastPts );
	return 0;
}
BOOL CRecord::Init(){
	m_inputFmtCtx = avformat_alloc_context();

	//Connection with interrupt callback
	if (m_connectionTimeout != 0){
		m_inputFmtCtx->interrupt_callback.callback = Interrupt_cb;
		m_inputFmtCtx->interrupt_callback.opaque = this;
		m_timePrev = GetTickCount();
	}

	if (avformat_open_input(&m_inputFmtCtx, m_inputFilename.c_str(), nullptr, &m_dictionary) != 0){
		return FALSE;
	}
	//m_interruptFlag = true;

	//Find stream info
	avformat_find_stream_info(m_inputFmtCtx, nullptr);

	//If constructor with callback, else constructor with filename
	// m_RcvDtCb == nullptr means write in file
	if ((m_outputFilename == "") /*&& (m_RcvDtCb != nullptr)*/){ // запись через callback
		//Guess outputformat
		//if ((m_outputFmt = av_guess_format("matroska", nullptr, nullptr)) == nullptr)
		//{
		//	return FALSE;
		//}
		////Alloc OutputFormatContext
		//m_outputFmtCtx = avformat_alloc_context();
		//m_outputFmtCtx->oformat = m_outputFmt;
		////WriteCallback for AvioContext
		//m_receivedCtx = avio_alloc_context(m_buffer, m_bufSize, 1, this, nullptr, ReceiveData_Cb, nullptr);
		//m_outputFmtCtx->pb = m_receivedCtx;
		//m_outputFmtCtx->flags = AVFMT_FLAG_CUSTOM_IO;

		//if (m_outputFmtCtx->oformat->flags & AVFMT_GLOBALHEADER)
		//{
		//	m_outputFmtCtx->flags |= CODEC_FLAG_GLOBAL_HEADER;
		//}

		//CreateStreams();
	}
	else{// запись напрямую в файл
		//Guess outputformat
		if ((m_outputFmt = av_guess_format(nullptr, m_outputFilename.c_str(), nullptr)) == nullptr) {
			return FALSE;
		}
		//Alloc OutputFormatContext
		m_outputFmtCtx = avformat_alloc_context();
		m_outputFmtCtx->oformat = m_outputFmt;
		//Copy outputfilename to outputCtx
		strcpy_s(m_outputFmtCtx->filename, sizeof(m_outputFmtCtx->filename), m_outputFilename.c_str());

		if (m_outputFmtCtx->oformat->flags & AVFMT_GLOBALHEADER)
		{
			m_outputFmtCtx->flags |= CODEC_FLAG_GLOBAL_HEADER;
		}

		CreateStreams();

		//Open outputfile, if return "<0" exit
		if (avio_open(&m_outputFmtCtx->pb, m_outputFilename.c_str(), AVIO_FLAG_WRITE) < 0){
			return FALSE;
		}
	}


	return TRUE;
}
void CRecord::WriteHeaderWithCallback(AVFormatContext *&outputFmtCtx){
	delete[] m_buffer;
	m_buffer = new BYTE[m_bufSize];

	if (m_outputFmt = av_guess_format("matroska", nullptr, nullptr)){

	}

	outputFmtCtx = avformat_alloc_context();
	outputFmtCtx->oformat = m_outputFmt;

	m_receivedCtx = avio_alloc_context(m_buffer, m_bufSize, 1, this, nullptr, ReceiveData_Cb, nullptr);
	outputFmtCtx->pb = m_receivedCtx;

	outputFmtCtx->flags = AVFMT_FLAG_CUSTOM_IO;

	if (outputFmtCtx->oformat->flags & AVFMT_GLOBALHEADER)
	{
		outputFmtCtx->flags |= CODEC_FLAG_GLOBAL_HEADER;
	}

	CreateStreams();

	m_isHeaderData = true;
	avformat_write_header(outputFmtCtx, nullptr);
	m_isHeaderData = false;
}
void CRecord::CreateStreams(){
	//Finding inputStreams and creating outPutStreams
	//Video
	m_videoStreamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
	if (m_videoStreamIndex >= 0){
		m_inputVideoStream = m_inputFmtCtx->streams[m_videoStreamIndex];
		m_videoCodec = m_inputVideoStream->codec;
		auto codec = avcodec_find_encoder(m_outputFmt->video_codec);
		m_outputVideoStream = avformat_new_stream(m_outputFmtCtx, codec);
		avcodec_copy_context(m_outputVideoStream->codec, m_videoCodec);
	}
	//Audio
	m_audioStreamIndex = av_find_best_stream(m_inputFmtCtx, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
	if (m_audioStreamIndex >= 0){
		m_inputAudioStream = m_inputFmtCtx->streams[m_audioStreamIndex];
		m_audioCodec = m_inputAudioStream->codec;
		auto codec = avcodec_find_encoder(m_outputFmt->video_codec);
		m_outputAudioStream = avformat_new_stream(m_outputFmtCtx, codec);
		avcodec_copy_context(m_outputAudioStream->codec, m_audioCodec);
	}
}

void CRecord::RecalculateTimeStamps(AVPacket *packet, AVRational inputTimeBase, AVRational outputTimeBase){
	packet->pts = av_rescale_q(packet->pts, inputTimeBase, outputTimeBase);
	packet->dts = packet->pts;
	packet->duration = av_rescale_q(packet->duration, inputTimeBase, outputTimeBase);
}

void CRecord::WritePacket(AVPacket packet, AVFormatContext *&outputFmtCtx, AVStream *inputStream, int outputStreamIndex){
	RecalculateTimeStamps(&packet, inputStream->time_base, outputFmtCtx->streams[outputStreamIndex]->time_base);
	packet.stream_index = outputFmtCtx->streams[outputStreamIndex]->index;
	av_write_frame(outputFmtCtx, &packet);
}

BOOL CRecord::StartRecord(){
	std::thread([this]{
		//Write header of outputFile
		//m_askHeader = true;
		while (!m_stop){
			av_init_packet(&m_packet);
			if (av_read_frame(m_inputFmtCtx, &m_packet)){
				//End of packets
				/*if (m_EofCb != nullptr)
					std::thread([this]{m_EofCb(); }).detach();*/
				break;
			}
			if (m_writeHeader && (m_packet.flags == AV_PKT_FLAG_KEY ||
				m_packet.flags == AV_PKT_FLAG_KEY + AV_PKT_FLAG_CORRUPT ||
				m_packet.flags == AV_PKT_FLAG_KEY + AV_PKT_FLAG_DISCARD ||
				m_packet.flags == AV_PKT_FLAG_KEY + AV_PKT_FLAG_CORRUPT + AV_PKT_FLAG_DISCARD)){

				m_writeHeader = false;

				WriteHeaderWithCallback(m_outputFmtCtx);
			}
			//Init packet
			/*if (m_StartRecCb != nullptr)
				std::thread([this]{m_StartRecCb(); }).detach();*/
			//Recalculate pts, dts and duration
			if (m_packet.stream_index == m_inputVideoStream->index){
				WritePacket(m_packet, m_outputFmtCtx, m_inputVideoStream, m_outputVideoStream->index);
			}
			else{
				if (m_packet.stream_index == m_inputAudioStream->index){
					WritePacket(m_packet, m_outputFmtCtx, m_inputAudioStream, m_outputAudioStream->index);
				}
				else{
					//Free packet
					av_free_packet(&m_packet);
				}
			}
		}
		//Write trailer of outputFile and close input and output
		av_write_trailer(m_outputFmtCtx);
		if ((m_outputFilename != "")/* && (m_RcvDtCb == nullptr)*/){
			avio_close(m_outputFmtCtx->pb);
		}
		if (outputFile != nullptr)
			fclose(outputFile);
	}).detach();
	return TRUE;
}

BOOL CRecord::StopRecord(){
	return m_stop = true;
}

void CRecord::RefreshHeader(){
	m_writeHeader = true;
}
