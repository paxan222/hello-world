#ifndef __ROBUSTO_PACKET_H_
#define __ROBUSTO_PACKET_H_

#pragma once

#include "wim_packet.h"

namespace core
{
	namespace tools
	{
		class binary_stream;
		class http_request_simple;
	}
}


namespace core
{
	namespace wim
	{
		class robusto_packet : public core::wim::wim_packet
		{
		protected:

			robusto_packet_params	robusto_params_;

			virtual int32_t parse_response(std::shared_ptr<core::tools::binary_stream> _response) override;
			virtual int32_t on_response_error_code() override;
			virtual int32_t execute_request(std::shared_ptr<core::http_request_simple> _request) override;

			virtual int32_t parse_results(const rapidjson::Value& _node_results);
			const std::string get_req_id() const;
			
		
		public:
					
			robusto_packet(const wim_packet_params& _params);
			virtual ~robusto_packet();

			void set_robusto_params(const robusto_packet_params& _params);
		};

	}
}



#endif //__ROBUSTO_PACKET_H_