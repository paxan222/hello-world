using System;
using System.Runtime.InteropServices;

namespace RVI.NativePlayerWrap
{
    /// <summary>
    /// Содержит информацию о формате потока
    /// </summary>
    [StructLayout(LayoutKind.Sequential)]
    public class StreamInfo
    {
        #region <Fields>
        private UInt32 _msNaturalDuration; // длительность в мс
        private UInt32 _frameWidth; // гор. разрешение кадра
        private UInt32 _frameHeight; // верт. разрешение кадра
        private uint _bitrate; // kbps
        private int _fps;
        private BitrateType _bitrateType; // постоянный / переменный битрейт
        private CodecType _codecType; // тип кодека

        #endregion </Fields>

        #region <Ctors>

        public StreamInfo()
        {
            HasAudio = false;
            HasVideo = false;
            ContainerType = ContainerType.Unknown;
            _msNaturalDuration = 0;
            _frameWidth = 0;
            _frameHeight = 0;
            Bitrate = 0;
            _bitrateType = BitrateType.Unknown;
            _codecType = CodecType.Unknown;
            Fps = 0;
        }

        #endregion</Ctors>


        #region <Properties>

        /// <summary>
        /// бит в сек
        /// </summary>
        public uint Bitrate
        {
            get { return _bitrate; }
            set { _bitrate = value; }
        }

        /// <summary>
        /// постоянный битрейт/переменный битрейт
        /// </summary>
        public BitrateType BitrateType
        {
            get { return _bitrateType; }
            private set { _bitrateType = value; }
        }

        /// <summary>
        /// тип кодека (h264/h263/mjpeg ....)
        /// </summary>
        public CodecType CodecType
        {
            get { return _codecType; }
            private set { _codecType = value; }
        }

        /// <summary>
        /// тип контейнера (mkv, avi ....)
        /// </summary>
        public ContainerType ContainerType
        {
            get;
            private set;
        }

        /// <summary>
        /// размер кадра
        /// </summary>
        public FrameSize FrameSize
        {
            get { return new FrameSize(_frameWidth, _frameHeight); }
            set
            {
                _frameWidth = value.Width;
                _frameHeight = value.Height;
            }
        }


        /// <summary>
        /// true - поток содержит видео дорожку, false - обратное
        /// </summary>
        public bool HasVideo
        {
            get;
            private set;
        }

        /// <summary>
        /// true - поток содержит звуковую дорожку, false - обратное
        /// </summary>
        public bool HasAudio
        {
            get;
            private set;
        }

        /// <summary>
        /// Длительность источника
        /// </summary>
        public TimeSpan NaturalDuration
        {
            get { return TimeSpan.FromMilliseconds(_msNaturalDuration); }
        }

        /// <summary>
        /// Frames per second
        /// </summary>
        public int Fps
        {
            get { return _fps; }
            set { _fps = value; }
        }

        #endregion </Properties>

        #region <Ctors>

        /// <summary>
        /// Содержит свединия о формате потока
        /// </summary>
        /// <param name="farmeWidth">Горизонтальное разрешение кадра (пикс)</param>
        /// <param name="frameHeight">Вертикальное разрешение кадра (пикс)</param>
        /// <param name="bitrate">бит в сек</param>
        /// <param name="bitrateType">постоянный битрейт/переменный битрейт</param>
        /// <param name="codecType">тип кодека (h264/h263/mjpeg ....)</param>
        /// <param name="containerType">тип контейнера (mkv, avi ....)</param>
        /// <param name="hasVideo">true - поток содержит видео дорожку</param>
        /// <param name="hasAudio">поток содержит звуковую дорожку</param>
        /// <param name="msNaturalDuration">Длительность в милисекундах</param>
        /// <param name="fps"></param>
        public StreamInfo(UInt32 farmeWidth, UInt32 frameHeight, UInt32 bitrate, BitrateType bitrateType, CodecType codecType, ContainerType containerType, bool hasVideo, bool hasAudio, uint msNaturalDuration, int fps)
        {
            _frameWidth = farmeWidth;
            _frameHeight = frameHeight;
            HasAudio = hasAudio;
            HasVideo = hasVideo;
            Bitrate = bitrate;
            BitrateType = bitrateType;
            CodecType = codecType;
            _msNaturalDuration = msNaturalDuration;
            Fps = fps;
            ContainerType = containerType;
            HasVideo = hasVideo;
            HasAudio = hasAudio;
        }

        #endregion </Ctors>

        #region <Actions>

        #endregion </Actions>

        #region <Helpers>

        #endregion </Helpers>
    }
}