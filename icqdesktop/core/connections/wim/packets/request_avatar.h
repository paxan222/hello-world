#ifndef __REQUEST_AVATAR_H_
#define __REQUEST_AVATAR_H_

#pragma once

#include "../wim_packet.h"

namespace core
{
	namespace tools
	{
		class http_request_simple;
	}
}

namespace core
{
	namespace wim
	{
		class request_avatar : public wim_packet
		{
			const std::string	avatar_type_;
			const std::string	contact_;
			std::shared_ptr<core::tools::binary_stream>	data_;	
			time_t				write_time_;

			virtual int32_t init_request(std::shared_ptr<core::http_request_simple> _request) override;
			virtual int32_t parse_response(std::shared_ptr<core::tools::binary_stream> _response) override;
			
		public:

			std::shared_ptr<core::tools::binary_stream> get_data();

			request_avatar(
				const wim_packet_params& params, 
				const std::string& _contact, 
				const std::string& _avatar_type,
				time_t _write_time = 0);
			virtual ~request_avatar();
		};
	}
}


#endif //__REQUEST_AVATAR_H_