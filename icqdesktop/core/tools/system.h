#pragma once

#define CORE_TOOLS_SYSTEM_NS_BEGIN namespace core { namespace tools { namespace system {
#define CORE_TOOLS_SYSTEM_NS_END } } }

CORE_TOOLS_SYSTEM_NS_BEGIN

bool is_dir_writable(const std::wstring &_dir_path_str);

bool move_file(const std::wstring& _old_file, const std::wstring& _new_file);

bool copy_file(const std::wstring& _old_file, const std::wstring& _new_file);

bool compare_dirs(const std::wstring& _dir1, const std::wstring& _dir2);

std::wstring get_file_directory(const std::wstring& file);

std::wstring get_file_name(const std::wstring& file);

std::wstring get_user_profile();

std::string generate_guid();

std::string generate_internal_id();

unsigned long get_current_thread_id();

std::wstring get_user_downloads_dir();

std::string to_upper(std::string str);

size_t get_memory_size_mb();

std::string get_os_version_string();

CORE_TOOLS_SYSTEM_NS_END