#include "stdafx.h"
#include "BaseOperation.h"
#include <atlimage.h>
#include <fstream>

/*-----------------Public----------------------------------------*/
//Constructor
CBaseOperation::CBaseOperation()
{

}

//Destructor
CBaseOperation::~CBaseOperation()
{
	avformat_close_input(&m_inputFmtCtx);
}

/*
* Return media file duration or return NULL if couldn't open file
*/
int CBaseOperation::GetFileDuration(PCHAR filename){
	av_register_all();
	AVFormatContext *fmtCtx = avformat_alloc_context();
	if (avformat_open_input(&fmtCtx, filename, nullptr, nullptr) != 0){
		return NULL;
	}
	auto duration = fmtCtx->duration * CONVERT_TIME_TO_MS / AV_TIME_BASE;
	avformat_close_input(&fmtCtx);
	return duration;
}

int CBaseOperation::GetJpeg(PCHAR inputFilename, char* strBuf, int strBufSize, int width, int height, int64_t timestamp) {
	av_register_all();
	int error = 0;
	AVFormatContext *fmtCtx = avformat_alloc_context();
	SwsContext *imgconvertCtx{ nullptr };
	AVFrame *frame = av_frame_alloc();
	AVPacket packet;
	av_init_packet(&packet);
	AVFrame *frame_rgb = av_frame_alloc();
	int gotFrame;
	if (avformat_open_input(&fmtCtx, inputFilename, nullptr, nullptr) != 0){
		goto cleanUp;
	}
	avformat_find_stream_info(fmtCtx, nullptr);
	auto videoStreamIndex = av_find_best_stream(fmtCtx, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);

	auto codecCtx = fmtCtx->streams[videoStreamIndex]->codec;
	avcodec_open2(codecCtx, avcodec_find_decoder(codecCtx->codec_id), nullptr);
	auto numBytes = avpicture_get_size(AV_PIX_FMT_RGB32, codecCtx->width, codecCtx->height);
	auto buffer = (uint8_t *)av_malloc(numBytes*sizeof(uint8_t));
	imgconvertCtx = sws_getContext(codecCtx->width, codecCtx->height, codecCtx->pix_fmt, width, height, AV_PIX_FMT_RGB32, SWS_BICUBIC, NULL, NULL, NULL);
	avpicture_fill((AVPicture *)frame_rgb, buffer, AV_PIX_FMT_RGB32, width, height);
	if (timestamp > fmtCtx->duration / AV_TIME_BASE*1000)
		goto cleanUp;
	av_seek_frame(fmtCtx, videoStreamIndex, timestamp, AVSEEK_FLAG_FRAME);

	av_read_frame(fmtCtx, &packet);
	if (0 > avcodec_decode_video2(codecCtx, frame, &gotFrame, &packet)){
		goto cleanUp;
	};
	if (gotFrame){
		sws_scale(imgconvertCtx, (const uint8_t* const*)frame->data, frame->linesize, 0, codecCtx->height, frame_rgb->data, frame_rgb->linesize);
		error = saveToJpeg(frame_rgb, width, height, strBuf, strBufSize);
		goto cleanUp;
	}
cleanUp:
	av_packet_unref(&packet);
	av_free_packet(&packet);
	av_free(buffer);
	avcodec_close(codecCtx);
	if (imgconvertCtx)
		sws_freeContext(imgconvertCtx);
	av_frame_free(&frame);
	av_frame_free(&frame_rgb);
	avformat_close_input(&fmtCtx);
	avformat_free_context(fmtCtx);
	return error;
}

void CBaseOperation::saveFrame(AVFrame *pFrame, PCHAR outputFilename, int width, int height){

	FILE *pFile;
	pFile = fopen("tmp.bmp", "wb");
	if (!pFile)
	{
		return;
	}
	fprintf(pFile, "P6\n%d %d\n255\n", width, height);
	fwrite(pFrame->data[0], width*height * 3, 1, pFile);
	fclose(pFile);
}

HRESULT CBaseOperation::GetGdiplusEncoderClsid(__in LPCWSTR pwszFormat, __out GUID *pGUID)
{
	HRESULT hr = E_FAIL;
	UINT  nEncoders = 0;          // number of image encoders
	UINT  nSize = 0;              // size of the image encoder array in bytes
	CAutoVectorPtr<BYTE> spData;
	Gdiplus::ImageCodecInfo* pImageCodecInfo = NULL;
	Gdiplus::Status status;
	bool fFound = false;

	// param check

	if ((pwszFormat == NULL) || (pwszFormat[0] == 0) || (pGUID == NULL))
	{
		return E_POINTER;
	}

	*pGUID = GUID_NULL;
	status = Gdiplus::GetImageEncodersSize(&nEncoders, &nSize);

	if ((status != Gdiplus::Ok) || (nSize == 0))
	{
		return E_FAIL;
	}

	spData.Allocate(nSize);

	if (spData == NULL)
	{
		return E_FAIL;
	}

	pImageCodecInfo = (Gdiplus::ImageCodecInfo*)(BYTE*)spData;

	status = Gdiplus::GetImageEncoders(nEncoders, nSize, pImageCodecInfo);

	if (status != Gdiplus::Ok)
	{
		return E_FAIL;
	}

	for (UINT j = 0; j < nEncoders; ++j)
	{
		if (wcscmp(pImageCodecInfo[j].MimeType, pwszFormat) == 0)
		{
			*pGUID = pImageCodecInfo[j].Clsid;
			fFound = true;
			break;
		}
	}

	hr = fFound ? S_OK : E_FAIL;

	return hr;
}

struct GdiplusInit {
	GdiplusInit() {
		Gdiplus::GdiplusStartupInput inp;
		GdiplusStartup(&token_, &inp, NULL);
	}
	~GdiplusInit() {
		Gdiplus::GdiplusShutdown(token_);
	}
private:
	ULONG_PTR token_;
};

int CBaseOperation::saveToJpeg(AVFrame *pFrame, int width, int height, char *buffer, int bufSize){
	GdiplusInit gdiplusinit;
	CLSID imgClsid;
	int encoderClsid = GetGdiplusEncoderClsid(L"image/jpeg", &imgClsid);
	Gdiplus::Image *image = new Gdiplus::Bitmap(width, height, pFrame->linesize[0], PixelFormat32bppRGB, pFrame->data[0]);
	if (encoderClsid != -1)
	{
		IStream *stream;
		CreateStreamOnHGlobal(nullptr, TRUE, static_cast<LPSTREAM*>(&stream));
		if (image->Save(stream, &imgClsid) != Gdiplus::Ok){
			printf("err");
		}
		delete image;
		STATSTG sts;
		stream->Stat(&sts, STATFLAG_DEFAULT);
		ULARGE_INTEGER ulargeSize = sts.cbSize;
		unsigned int int64Size = ulargeSize.QuadPart;
		LARGE_INTEGER zero;
		zero.QuadPart = 0;
		stream->Seek(zero, STREAM_SEEK_SET, nullptr);
		if (bufSize >= int64Size){
			stream->Read(buffer, int64Size, nullptr);
			stream->Release();				
		}
		else
		{
			return int64Size;
		}
	}
	return 0;
}

void CBaseOperation::saveFrameToBmp(AVFrame *pFrame, PCHAR outputFilename, int width, int height){
	BITMAPFILEHEADER bmpheader;
	BITMAPINFO bmpinfo;
	int y = 0;
	FILE *pFile;

	unsigned char *y_buf = pFrame->data[0];
	pFile = fopen(outputFilename, "wb");

	bmpheader.bfType = 0x4d42;
	bmpheader.bfReserved1 = 0;
	bmpheader.bfReserved2 = 0;
	bmpheader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	bmpheader.bfSize = bmpheader.bfOffBits + width*height * 24 / 8;

	bmpinfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmpinfo.bmiHeader.biWidth = width;
	bmpinfo.bmiHeader.biHeight = -height;
	bmpinfo.bmiHeader.biPlanes = 1;
	bmpinfo.bmiHeader.biBitCount = 24;
	bmpinfo.bmiHeader.biCompression = BI_RGB;
	bmpinfo.bmiHeader.biSizeImage = 0;
	bmpinfo.bmiHeader.biXPelsPerMeter = 100;
	bmpinfo.bmiHeader.biYPelsPerMeter = 100;
	bmpinfo.bmiHeader.biClrUsed = 0;
	bmpinfo.bmiHeader.biClrImportant = 0;

	fwrite(&bmpheader, sizeof(BITMAPFILEHEADER), 1, pFile);
	fwrite(&bmpinfo.bmiHeader, sizeof(BITMAPINFOHEADER), 1, pFile);

	fwrite(pFrame->data[0], width*height * 24 / 8, 1, pFile);

	fclose(pFile);
}
//Cancel task
BOOL CBaseOperation::CancelTask(){
	return m_cancel = true;
}

/*-----------------Protected-------------------------------------*/

//Open input file
BOOL CBaseOperation::OpenInputFile(AVFormatContext *&fmtCtx, PCHAR filename){
	fmtCtx = avformat_alloc_context();
	if (avformat_open_input(&fmtCtx, filename, nullptr, nullptr) != 0){
		//m_errorCode = ErrorCode::OpenInputFileError;
		return FALSE;
	}
	//Find stream info
	avformat_find_stream_info(fmtCtx, nullptr);
	return TRUE;
}

//Guess output format
BOOL CBaseOperation::GuessOutputFormat(AVFormatContext *outputFmtCtx, PCHAR outputFilename){
	/*
	*Return the output format in the list of registered output formats
	*which best matches the provided parameters, or return NULL if
	* there is no match.
	*/
	AVOutputFormat *outputFmt{ nullptr };
	if ((outputFmt = av_guess_format(nullptr, outputFilename, nullptr)) == nullptr) {
		//m_errorCode = ErrorCode::OutputFormatNotMatchFormat;
		return FALSE;
	}
	//Alloc OutputFormatContext
	m_outputFmtCtx = avformat_alloc_context();
	m_outputFmtCtx->oformat = outputFmt;
	//Copy outputfilename to outputCtx
	strcpy_s(m_outputFmtCtx->filename, sizeof(m_outputFmtCtx->filename), outputFilename);

	if (m_outputFmtCtx->oformat->flags & AVFMT_GLOBALHEADER)
	{
		m_outputFmtCtx->flags |= CODEC_FLAG_GLOBAL_HEADER;
	}
	return TRUE;
}

BOOL CBaseOperation::OpenOutputFile(PCHAR outputFilename)
{
	if (!GuessOutputFormat(m_outputFmtCtx, outputFilename))
		return FALSE;

	CreateOutputStreams(m_outputFmtCtx);

	//Open outputfile, if return "<0" exit
	if (avio_open(&m_outputFmtCtx->pb, outputFilename, AVIO_FLAG_WRITE) < 0){
		//m_errorCode = ErrorCode::OpenOutputFileError;
		return FALSE;
	}
	//Write header of output file
	avformat_write_header(m_outputFmtCtx, nullptr);

	return TRUE;
}

//CreateOutputStream
int CBaseOperation::CreateStream(AVCodecID codecId, AVStream *inputStream){
	auto tmpCodec = avcodec_find_encoder(codecId);
	auto outputStream = avformat_new_stream(m_outputFmtCtx, tmpCodec);
	avcodec_copy_context(outputStream->codec, inputStream->codec);
	return outputStream->index;
}

//Recalculate timestamps of the packet using timebase of input and output streams and offset if it necessary
void CBaseOperation::RecalculateTimeStamps(AVPacket *packet, AVRational inputTimeBase, AVRational outputTimeBase, int offset){
	packet->pts = av_rescale_q(packet->pts, inputTimeBase, outputTimeBase) + offset;
	packet->dts = packet->pts;
	packet->duration = av_rescale_q(packet->duration, inputTimeBase, outputTimeBase);
}