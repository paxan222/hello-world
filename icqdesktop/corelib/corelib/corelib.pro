#-------------------------------------------------
#
# Project created by QtCreator 2015-12-27T21:42:27
#
#-------------------------------------------------

TARGET = corelib
TEMPLATE = lib

QT -= gui core

DEFINES += CORELIB_LIBRARY RAPIDJSON_HAS_STDSTRING

CONFIG += precompile_header

PRECOMPILED_HEADER = ../../core/stdafx.h

SOURCES += \
    ../collection.cpp \
    ../collection_helper.cpp \
    ../core_instance.cpp \
    ../corelib.cpp \
    ../remote_proc.cpp \
    ../stdafx.cpp \
    ../../core/async_task.cpp \
    ../../core/core.cpp \
    ../../core/core_settings.cpp \
    ../../core/gui_settings.cpp \
    ../../core/main_thread.cpp \
    ../../core/scheduler.cpp \
    ../../core/utils.cpp \
    ../../core/archive/archive_index.cpp \
    ../../core/archive/contact_archive.cpp \
    ../../core/archive/dlg_state.cpp \
    ../../core/archive/history_message.cpp \
    ../../core/archive/local_history.cpp \
    ../../core/archive/messages_data.cpp \
    ../../core/archive/not_sent_messages.cpp \
    ../../core/archive/opened_dialog.cpp \
    ../../core/archive/storage.cpp \
    ../../core/configuration/app_config.cpp \
    ../../core/connections/base_im.cpp \
    ../../core/connections/contact_profile.cpp \
    ../../core/connections/im_container.cpp \
    ../../core/connections/login_info.cpp \
    ../../core/connections/search_contacts_params.cpp \
    ../../core/connections/wim/active_dialogs.cpp \
    ../../core/connections/wim/auth_parameters.cpp \
    ../../core/connections/wim/avatar_loader.cpp \
    ../../core/connections/wim/chat_info.cpp \
    ../../core/connections/wim/my_info.cpp \
    ../../core/connections/wim/robusto_packet.cpp \
    ../../core/connections/wim/wim_contactlist_cache.cpp \
    ../../core/connections/wim/wim_history.cpp \
    ../../core/connections/wim/wim_im.cpp \
    ../../core/connections/wim/wim_packet.cpp \
    ../../core/connections/wim/events/fetch_event_buddy_list.cpp \
    ../../core/connections/wim/events/fetch_event_diff.cpp \
    ../../core/connections/wim/events/fetch_event_dlg_state.cpp \
    ../../core/connections/wim/events/fetch_event_hidden_chat.cpp \
    ../../core/connections/wim/events/fetch_event_my_info.cpp \
    ../../core/connections/wim/events/fetch_event_presence.cpp \
    ../../core/connections/wim/events/fetch_event_user_added_to_buddy_list.cpp \
    ../../core/connections/wim/events/webrtc.cpp \
    ../../core/connections/wim/loader/download_task.cpp \
    ../../core/connections/wim/loader/loader.cpp \
    ../../core/connections/wim/loader/loader_handlers.cpp \
    ../../core/connections/wim/loader/loader_task.cpp \
    ../../core/connections/wim/loader/upload_task.cpp \
    ../../core/connections/wim/loader/web_file_info.cpp \
    ../../core/connections/wim/packets/add_buddy.cpp \
    ../../core/connections/wim/packets/add_chat.cpp \
    ../../core/connections/wim/packets/add_members.cpp \
    ../../core/connections/wim/packets/client_login.cpp \
    ../../core/connections/wim/packets/fetch.cpp \
    ../../core/connections/wim/packets/gen_robusto_token.cpp \
    ../../core/connections/wim/packets/get_chat_info.cpp \
    ../../core/connections/wim/packets/get_file_meta_info.cpp \
    ../../core/connections/wim/packets/get_gateway.cpp \
    ../../core/connections/wim/packets/get_history.cpp \
    ../../core/connections/wim/packets/get_sms_code.cpp \
    ../../core/connections/wim/packets/get_stickers_index.cpp \
    ../../core/connections/wim/packets/hide_chat.cpp \
    ../../core/connections/wim/packets/load_file.cpp \
    ../../core/connections/wim/packets/login_by_phone.cpp \
    ../../core/connections/wim/packets/modify_chat.cpp \
    ../../core/connections/wim/packets/mute_buddy.cpp \
    ../../core/connections/wim/packets/normalize_phone.cpp \
    ../../core/connections/wim/packets/remove_buddy.cpp \
    ../../core/connections/wim/packets/remove_members.cpp \
    ../../core/connections/wim/packets/request_avatar.cpp \
    ../../core/connections/wim/packets/robusto_add_client.cpp \
    ../../core/connections/wim/packets/search_contacts.cpp \
    ../../core/connections/wim/packets/send_file.cpp \
    ../../core/connections/wim/packets/send_imstat.cpp \
    ../../core/connections/wim/packets/send_message.cpp \
    ../../core/connections/wim/packets/set_dlg_state.cpp \
    ../../core/connections/wim/packets/set_permit_deny.cpp \
    ../../core/connections/wim/packets/set_state.cpp \
    ../../core/connections/wim/packets/spam_report.cpp \
    ../../core/connections/wim/packets/start_session.cpp \
    ../../core/connections/wim/packets/wim_webrtc.cpp \
    ../../core/connections/wim/stat/imstat.cpp \
    ../../core/log/log.cpp \
    ../../core/profiling/profiler.cpp \
    ../../core/stickers/stickers.cpp \
    ../../core/tools/binary_stream.cpp \
    ../../core/tools/binary_stream_reader.cpp \
    ../../core/tools/coretime.cpp \
    ../../core/tools/fast_binary_stream.cpp \
    ../../core/tools/hmac_sha_base64.cpp \
    ../../core/tools/md5.cpp \
    ../../core/tools/semaphore.cpp \
    ../../core/tools/settings.cpp \
    ../../core/tools/strings.cpp \
    ../../core/tools/threadpool.cpp \
    ../../core/tools/tlv.cpp \
    ../../core/updater/updater.cpp \
    ../../core/tools/system.linux.cpp \
    ../../core/connections/wim/events/fetch_event_typing.cpp \
    ../../core/connections/im_login.cpp \
    ../../core/connections/wim/search_contacts_response.cpp \
    ../../core/connections/wim/packets/end_session.cpp \
    ../../core/connections/wim/packets/search_contacts2.cpp \
    ../../core/connections/wim/packets/send_message_typing.cpp \
    ../../core/connections/wim/packets/send_feedback.cpp \
    ../../core/connections/wim/events/fetch_event_permit.cpp \
    ../../core/connections/wim/packets/get_permit_deny.cpp \
    ../../core/connections/wim/packets/speech_to_text.cpp \
    ../../core/connections/wim/permit_info.cpp \
    ../../core/crash_sender.cpp \
    ../../core/http_request.cpp \
    ../../core/statistics.cpp \
    ../../core/network_log.cpp \
    ../../core/tools/system_common.cpp \
    ../../core/themes/themes.cpp \
    ../../core/themes/theme_settings.cpp \
    ../../core/connections/wim/packets/get_themes_index.cpp \
    ../../core/connections/wim/favorites.cpp \
    ../../core/proxy_settings.cpp

HEADERS += \
    ../collection.h \
    ../collection_helper.h \
    ../common.h \
    ../core_face.h \
    ../core_instance.h \
    ../cp_afxres.h \
    ../enumerations.h \
    ../ibase.h \
    ../ifptr.h \
    ../iserializable.h \
    ../ivalue.h \
    ../namespaces.h \
    ../remote_proc.h \
    ../stdafx.h \
    ../targetver.h \
    ../../core/async_task.h \
    ../../core/core.h \
    ../../core/core_settings.h \
    ../../core/gui_settings.h \
    ../../core/main_thread.h \
    ../../core/scheduler.h \
    ../../core/targetver.h \
    ../../core/utils.h \
    ../../core/archive/archive_index.h \
    ../../core/archive/contact_archive.h \
    ../../core/archive/dlg_state.h \
    ../../core/archive/errors.h \
    ../../core/archive/history_message.h \
    ../../core/archive/local_history.h \
    ../../core/archive/message_flags.h \
    ../../core/archive/messages_data.h \
    ../../core/archive/not_sent_messages.h \
    ../../core/archive/opened_dialog.h \
    ../../core/archive/options.h \
    ../../core/archive/storage.h \
    ../../core/stdafx.h \
    ../../core/configuration/app_config.h \
    ../../core/connections/base_im.h \
    ../../core/connections/contact_profile.h \
    ../../core/connections/im_container.h \
    ../../core/connections/login_info.h \
    ../../core/connections/search_contacts_params.h \
    ../../core/connections/wim/active_dialogs.h \
    ../../core/connections/wim/auth_parameters.h \
    ../../core/connections/wim/avatar_loader.h \
    ../../core/connections/wim/chat_info.h \
    ../../core/connections/wim/my_info.h \
    ../../core/connections/wim/robusto_packet.h \
    ../../core/connections/wim/wim_contactlist_cache.h \
    ../../core/connections/wim/wim_history.h \
    ../../core/connections/wim/wim_im.h \
    ../../core/connections/wim/wim_packet.h \
    ../../core/connections/wim/events/fetch_event.h \
    ../../core/connections/wim/events/fetch_event_buddy_list.h \
    ../../core/connections/wim/events/fetch_event_diff.h \
    ../../core/connections/wim/events/fetch_event_dlg_state.h \
    ../../core/connections/wim/events/fetch_event_hidden_chat.h \
    ../../core/connections/wim/events/fetch_event_my_info.h \
    ../../core/connections/wim/events/fetch_event_presence.h \
    ../../core/connections/wim/events/fetch_event_user_added_to_buddy_list.h \
    ../../core/connections/wim/events/webrtc.h \
    ../../core/connections/wim/loader/download_task.h \
    ../../core/connections/wim/loader/loader.h \
    ../../core/connections/wim/loader/loader_errors.h \
    ../../core/connections/wim/loader/loader_handlers.h \
    ../../core/connections/wim/loader/loader_task.h \
    ../../core/connections/wim/loader/upload_task.h \
    ../../core/connections/wim/loader/web_file_info.h \
    ../../core/connections/wim/packets/add_buddy.h \
    ../../core/connections/wim/packets/add_chat.h \
    ../../core/connections/wim/packets/add_members.h \
    ../../core/connections/wim/packets/client_login.h \
    ../../core/connections/wim/packets/fetch.h \
    ../../core/connections/wim/packets/gen_robusto_token.h \
    ../../core/connections/wim/packets/get_chat_info.h \
    ../../core/connections/wim/packets/get_file_meta_info.h \
    ../../core/connections/wim/packets/get_gateway.h \
    ../../core/connections/wim/packets/get_history.h \
    ../../core/connections/wim/packets/get_sms_code.h \
    ../../core/connections/wim/packets/get_stickers_index.h \
    ../../core/connections/wim/packets/hide_chat.h \
    ../../core/connections/wim/packets/load_file.h \
    ../../core/connections/wim/packets/login_by_phone.h \
    ../../core/connections/wim/packets/modify_chat.h \
    ../../core/connections/wim/packets/mute_buddy.h \
    ../../core/connections/wim/packets/normalize_phone.h \
    ../../core/connections/wim/packets/remove_buddy.h \
    ../../core/connections/wim/packets/remove_members.h \
    ../../core/connections/wim/packets/request_avatar.h \
    ../../core/connections/wim/packets/robusto_add_client.h \
    ../../core/connections/wim/packets/search_contacts.h \
    ../../core/connections/wim/packets/send_file.h \
    ../../core/connections/wim/packets/send_imstat.h \
    ../../core/connections/wim/packets/send_message.h \
    ../../core/connections/wim/packets/set_dlg_state.h \
    ../../core/connections/wim/packets/set_permit_deny.h \
    ../../core/connections/wim/packets/set_state.h \
    ../../core/connections/wim/packets/spam_report.h \
    ../../core/connections/wim/packets/start_session.h \
    ../../core/connections/wim/packets/wim_webrtc.h \
    ../../core/connections/wim/stat/imstat.h \
    ../../core/log/log.h \
    ../../core/profiling/profiler.h \
    ../../core/stickers/stickers.h \
    ../../core/tools/binary_stream.h \
    ../../core/tools/binary_stream_reader.h \
    ../../core/tools/coretime.h \
    ../../core/tools/fast_binary_stream.h \
    ../../core/tools/hmac_sha_base64.h \
    ../../core/tools/md5.h \
    ../../core/tools/scope.h \
    ../../core/tools/semaphore.h \
    ../../core/tools/settings.h \
    ../../core/tools/strings.h \
    ../../core/tools/system.h \
    ../../core/tools/threadpool.h \
    ../../core/tools/tlv.h \
    ../../core/updater/updater.h \
    ../../core/Voip/sound_call_end.h \
    ../../core/Voip/sound_call_incoming.h \
    ../../core/Voip/sound_call_outgoing.h \
    ../../core/Voip/VoipManager.h \
    ../../core/Voip/VoipManagerDefines.h \
    ../../core/Voip/VoipSerialization.h \
    ../../core/connections/wim/events/fetch_event_typing.h \
    ../../core/connections/im_login.h \
    ../../core/namespaces.h \
    ../../core/connections/wim/dialog_holes.h \
    ../../core/connections/wim/search_contacts_response.h \
    ../../core/connections/wim/packets/end_session.h \
    ../../core/connections/wim/packets/search_contacts2.h \
    ../../core/connections/wim/packets/send_message_typing.h \
    ../../core/Voip/call_busy.h \
    ../../core/Voip/call_connected.h \
    ../../core/Voip/call_dial.h \
    ../../core/Voip/call_end.h \
    ../../core/Voip/call_hold.h \
    ../../core/Voip/call_incoming.h \
    ../../core/Voip/call_start.h \
    ../../core/connections/wim/packets/send_feedback.h \
    ../../core/tools/statistics.h \
    ../../core/connections/wim/events/fetch_event_permit.h \
    ../../core/connections/wim/packets/get_permit_deny.h \
    ../../core/connections/wim/packets/speech_to_text.h \
    ../../core/connections/wim/permit_info.h \
    ../../core/http_request.h \
    ../../core/statistics.h \
    ../../core/network_log.h \
    ../../core/themes/themes.h \
    ../../core/themes/theme_settings.h \
    ../../core/connections/wim/packets/get_themes_index.h \
    ../../common.shared/version_info_constants.h \
    ../../common.shared/version_info.h \
    ../../core/connections/wim/favorites.h \
    ../../core/proxy_settings.h

DEFINES += STRIP_VOIP

QMAKE_CXXFLAGS += -std=c++0x

QMAKE_LFLAGS += -static-libgcc -static-libstdc++

INCLUDEPATH += ../../core ../../external/rapidjson-master/include
