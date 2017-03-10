namespace RVI.NativePlayerWrap
{
    /// <summary>
    /// Размер изображения
    /// </summary>
    public class FrameSize
    {
        #region <Fields>

        private readonly uint _width;
        private readonly uint _height;

        #endregion </Fields>

        #region <Ctors>

        /// <summary>
        /// 
        /// </summary>
        /// <param name="width">Горизонтальное разрешение в пикс</param>
        /// <param name="height">Вертикальное разрешение в пикс</param>
        public FrameSize(uint width, uint height)
        {
            _width = width;
            _height = height;
        }

        #endregion </Ctors>

        #region <Actions>

        #endregion </Actions>

        #region <Properties>

        /// <summary>
        /// Вертикальное разрешение в пикс
        /// </summary>
        public uint Height
        {
            get { return _height; }
        }


        /// <summary>
        /// Горизонтальное разрешение в пикс
        /// </summary>
        public uint Width
        {
            get { return _width; }
        }

        /// <summary>
        /// Значение соотношения сторон 
        /// </summary>
        public double AspectRatio
        {
            get { return (double)Width / Height; }
        }

        #endregion </Properties>

        #region <Helpers>

        #endregion </Helpers>


    }
}