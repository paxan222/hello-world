#ifndef __BINARYSTREAM_H_
#define __BINARYSTREAM_H_

#pragma once

#include "scope.h"

namespace core
{
	namespace tools
	{
		class binary_stream
		{
			typedef std::vector<char>	data_buffer;

			mutable data_buffer		buffer_;
			mutable uint32_t		input_cursor_;
			mutable uint32_t		output_cursor_;

		public:

			binary_stream()
				:	input_cursor_(0),
				output_cursor_(0)
			{
			}

			binary_stream(const binary_stream& _stream)
			{
				copy(_stream);
			}

			binary_stream& operator=( const binary_stream& _stream)
			{
				copy(_stream);
				return *this;
			}

			void copy(const binary_stream& _stream)
			{
				input_cursor_ = _stream.input_cursor_;
				output_cursor_ = _stream.output_cursor_;
				buffer_ = _stream.buffer_;
			}

			void swap(binary_stream& _stream)
			{
				int32_t input_cursor = input_cursor_;
				int32_t output_cursor = output_cursor_;

				input_cursor_ = _stream.input_cursor_;
				output_cursor_ = _stream.output_cursor_;

				_stream.input_cursor_ = input_cursor;
				_stream.output_cursor_ = output_cursor;

				_stream.buffer_.swap(buffer_);
			}

			uint32_t available() const
			{
				return (input_cursor_ - output_cursor_);
			}

			void reserve(uint32_t _size)
			{
				if (buffer_.size() < _size)
					buffer_.resize(_size);
			}

			void reset()
			{
				input_cursor_ = 0;
				output_cursor_ = 0;
			}

			void reset_out()
			{
				output_cursor_ = 0;
			}

			char* alloc_buffer(uint32_t _size)
			{
				uint32_t size_need = input_cursor_ + _size;
				if (size_need > buffer_.size())
					buffer_.resize(size_need*2);

				char* out = &buffer_[input_cursor_];

				input_cursor_ += _size;

				return out;
			}

            template <class t_> void write(const t_& _val)
            {
                write((const char*) &_val, sizeof(t_));
            }

			void write(const char* _data, uint32_t _size)
			{
				uint32_t size_need = input_cursor_ + _size;
				if (size_need > buffer_.size())
					buffer_.resize(size_need*2);

				memcpy(&buffer_[input_cursor_], _data, _size);
				input_cursor_ += _size;
			}

			char* read(uint32_t _size) const
			{
				if (_size == 0)
				{
					assert(!"read from stream size = 0");
					return 0;
				}

				if (available() < _size)
				{
					assert(!"read from invalid size");
					return 0;
				}

				char* out = &buffer_[output_cursor_];

				output_cursor_ += _size;

				return out;
			}

			char* read_available()
			{
				uint32_t available_size = available();

				if (available_size == 0)
				{
					assert(false);
					return nullptr;
				}


				char* out = &buffer_[output_cursor_];

				output_cursor_ += available_size;

				return out;
			}

			template <class t_>
			t_ read() const
			{
				return  *((t_*) read(sizeof(t_)));
			}

			bool save_2_file(const std::wstring& _file_name) const;
			bool load_from_file(const std::wstring& _file_name);
		};

        template <> void core::tools::binary_stream::write<std::string>(const std::string& _val);

        template <> std::string core::tools::binary_stream::read<std::string>() const;
	}

}

#endif //__BINARYSTREAM_H_
