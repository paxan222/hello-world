#include "stdafx.h"
#include "remove_members.h"

#include "../../../http_request.h"
#include "../../../tools/system.h"

using namespace core;
using namespace wim;

remove_members::remove_members(
	const wim_packet_params& _params,
	const std::string& _aimid,
	const std::string& _m_chat_members_to_remove)
	:	wim_packet(_params),
	aimid_(_aimid),
	m_chat_members_to_remove(_m_chat_members_to_remove)
{
}

remove_members::~remove_members()
{
}

int32_t remove_members::init_request(std::shared_ptr<core::http_request_simple> _request)
{
	std::stringstream ss_url;

	ss_url << c_wim_host << "mchat/DelMembers" <<
		"?f=json" <<
		"&chat_id=" <<  aimid_ <<
		"&aimsid=" << get_params().aimsid_ <<
        "&r=" << core::tools::system::generate_guid() <<
        "&members=" << m_chat_members_to_remove;

	_request->set_url(ss_url.str());
    _request->set_keep_alive();

	return 0;
}

int32_t remove_members::parse_response_data(const rapidjson::Value& _data)
{
	return 0;
}
