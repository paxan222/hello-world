#include "stdafx.h"
#include "add_buddy.h"

#include "../../../http_request.h"
#include "../../../tools/system.h"

using namespace core;
using namespace wim;

add_buddy::add_buddy(
	const wim_packet_params& _params,
	const std::string& _aimid,
	const std::string& _group,
	const std::string& _auth_message)

	:	wim_packet(_params),
		aimid_(_aimid),
		group_(_group),
		auth_message_(_auth_message)
{
}

add_buddy::~add_buddy()
{
}

int32_t add_buddy::init_request(std::shared_ptr<core::http_request_simple> _request)
{
	std::stringstream ss_url;

	ss_url << c_wim_host << "buddylist/addBuddy" <<
		"?f=json" <<
		"&aimsid=" << get_params().aimsid_ <<
        "&r=" <<  core::tools::system::generate_guid() <<
		"&buddy=" << escape_symbols(aimid_);

	if (!group_.empty())
		ss_url << "&group=" << escape_symbols(group_);
	
	ss_url << "&authorizationMsg=" << escape_symbols(auth_message_);
	ss_url << "&preAuthorized=1";
	
	_request->set_url(ss_url.str());
    _request->set_keep_alive();

	return 0;
}

int32_t add_buddy::parse_response_data(const rapidjson::Value& _data)
{
	return 0;
}
