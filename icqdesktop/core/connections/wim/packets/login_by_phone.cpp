#include "stdafx.h"

#include "login_by_phone.h"
#include "../../../http_request.h"
#include "../../login_info.h"
#include "../../../tools/system.h"

using namespace core;
using namespace wim;

phone_login::phone_login(
	const wim_packet_params& params,
	const phone_info& _info)
	:	
	wim_packet(params),
	info_(new phone_info(_info))
{
}


phone_login::~phone_login()
{
}



int32_t phone_login::init_request(std::shared_ptr<core::http_request_simple> _request)
{
	std::stringstream ss_url;
	ss_url << "https://www.icq.com:443/smsreg/loginWithPhoneNumber.php?" << 
		"&msisdn=" << info_->get_phone() <<
		"&trans_id=" << info_->get_trans_id() <<
		"&k=" << params_.dev_id_ <<
        "&r=" << core::tools::system::generate_guid() << 
		"&f=json" <<
		"&sms_code=" << info_->get_sms_code() <<
		"&create_account=1";
			
	_request->set_url(ss_url.str());
    _request->set_keep_alive();
	return 0;
}

int32_t core::wim::phone_login::on_response_error_code()
{
	return wpie_phone_not_verified;
	
}

int32_t core::wim::phone_login::parse_response_data(const rapidjson::Value& _data)
{
	int32_t err = wpie_http_parse_response;

	try
	{
		auto iter_phone_verified = _data.FindMember("phone_verified");
		if (iter_phone_verified == _data.MemberEnd() || !iter_phone_verified->value.IsBool())
			return wpie_http_parse_response;

		if (!iter_phone_verified->value.GetBool())
			return wpie_phone_not_verified;

		auto iter_session_key = _data.FindMember("sessionKey");
		if (iter_session_key == _data.MemberEnd() || !iter_session_key->value.IsString())
			return wpie_http_parse_response;

		session_key_ = iter_session_key->value.GetString();

		auto iter_host_time = _data.FindMember("hostTime");
		if (iter_host_time == _data.MemberEnd() || !iter_host_time->value.IsUint())
			return wpie_http_parse_response;

		host_time_ = iter_host_time->value.GetUint();

		auto iter_token = _data.FindMember("token");
		if (iter_token == _data.MemberEnd() || !iter_token->value.IsObject())
			return wpie_http_parse_response;
        
		auto iter_expired_in = iter_token->value.FindMember("expiresIn");
		auto iter_a = iter_token->value.FindMember("a");
		if (iter_expired_in == iter_token->value.MemberEnd() || iter_a == iter_token->value.MemberEnd() ||
			!iter_expired_in->value.IsUint() || !iter_a->value.IsString())
			return wpie_http_parse_response;

		expired_in_ = iter_expired_in->value.GetUint();
		a_token_ = iter_a->value.GetString();

		time_offset_ = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) - host_time_;

		err = 0;
	}
	catch (const std::exception&)
	{
		
	}
	
	
	return err;
}

int32_t core::wim::phone_login::on_http_client_error()
{
	switch (http_code_)
	{
		case 401:
		case 463:
		case 466: 
		case 468:
		case 469:
			return wpie_wrong_login;
	}

	return wpie_client_http_error;
}