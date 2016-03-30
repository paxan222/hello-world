#include "stdafx.h"
#include "normalize_phone.h"

#include "../../../http_request.h"
#include "../../../tools/system.h"



using namespace core;
using namespace wim;



normalize_phone::normalize_phone(const wim_packet_params& _params, const std::string& _country, const std::string& _phone)
	:	wim_packet(_params), 
		country_(_country), 
		phone_(_phone), 
		sms_enabled_(false)
{
}


normalize_phone::~normalize_phone()
{
}

int32_t normalize_phone::init_request(std::shared_ptr<core::http_request_simple> _request)
{
	std::stringstream ss_url;
	ss_url << "https://www.icq.com:443/smsreg/normalizePhoneNumber.php?" << 
		"countryCode=" << escape_symbols(country_) <<
		"&phoneNumber=" << phone_ <<
		"&k=" << params_.dev_id_ <<
        "&r=" << core::tools::system::generate_guid();

	_request->set_url(ss_url.str());
    _request->set_keep_alive();
	return 0;
}


int32_t core::wim::normalize_phone::parse_response_data(const rapidjson::Value& _data)
{
	auto iter_msisdn = _data.FindMember("msisdn");
	if (iter_msisdn == _data.MemberEnd() || !iter_msisdn->value.IsString())
		return wpie_http_parse_response;

	normalized_phone_ = iter_msisdn->value.GetString();

	auto iter_sms_enabled = _data.FindMember("smsEnabled");
	if (iter_sms_enabled != _data.MemberEnd() && iter_sms_enabled->value.IsBool())
		sms_enabled_ = iter_sms_enabled->value.GetBool();

	return 0;
}

int32_t core::wim::normalize_phone::on_http_client_error()
{
	switch (http_code_)
	{
	case 462:
	case 464:
	case 465:
		return wpie_invalid_phone_number;
	}
	return wpie_client_http_error;
}