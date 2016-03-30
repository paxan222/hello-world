#ifndef __STARTSESSION_H_
#define __STARTSESSION_H_

#pragma once

#include "../wim_packet.h"

namespace core
{
	namespace tools
	{
		class http_request_simple;
		class binary_stream;
	}
}

namespace core
{
	namespace wim
	{
		class send_imstat : public wim_packet
		{
			virtual int32_t init_request(std::shared_ptr<core::http_request_simple> _request) override;
			virtual int32_t execute_request(std::shared_ptr<core::http_request_simple> _request) override;
			
			std::string		data_;

		public:
			
			send_imstat(const wim_packet_params& _params, const std::string& _data);
			virtual ~send_imstat();
		};
	}
}

#endif //__STARTSESSION_H_