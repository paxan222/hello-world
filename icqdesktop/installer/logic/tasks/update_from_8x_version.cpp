#include "stdafx.h"
#include "update_from_8x_version.h"
#include "../exported_data.h"
#include "../tools.h"

namespace installer
{
    namespace logic
    {

        const std::wstring main_window_classname = L"MraICQWClass";
        const std::wstring rwa_mra_shutdown = L"MraICQ shutdown";

        BOOL CALLBACK enum_windows_callback(HWND hwnd, LPARAM l_param)
        {
            HWND* out_hwnd = (HWND*) l_param;

            const int class_name_length = 4096;
            wchar_t class_name[class_name_length];

            ::GetClassName(hwnd, class_name, (class_name_length - 1));

            if (main_window_classname == class_name)
            {
                *out_hwnd = hwnd;
            }

            return TRUE;
        }


        installer::error shutdown_8x()
        {
            const int app_version = 1000000000; //infinite version
            const unsigned int shutdown_message = ::RegisterWindowMessage(rwa_mra_shutdown.c_str());

            HWND hwnd = 0;
            if (::EnumWindows(enum_windows_callback, (LPARAM) &hwnd))
            {
                if (hwnd != 0)
                {
                    unsigned long process_id = 0;
                    if (::GetWindowThreadProcessId(hwnd, &process_id))
                    {
                        CHandle icq_process(::OpenProcess(SYNCHRONIZE, FALSE, process_id));

                        ::SendNotifyMessage(hwnd, shutdown_message, app_version + 1, 0);

                        if (icq_process.m_h)
                        {
                            if (::WaitForSingleObject(icq_process.m_h, 10000) != WAIT_OBJECT_0)
                            {
                                icq_process.Close();

                                icq_process.Attach(::OpenProcess(PROCESS_TERMINATE | SYNCHRONIZE, FALSE, process_id));

                                if (icq_process.m_h)
                                {
                                    ::TerminateProcess(icq_process.m_h, 1);
                                    ::WaitForSingleObject(icq_process.m_h, 30000);
                                }
                            }
                        }
                    }
                }
            }

            return installer::error();
        }


        bool is_new_accounts_exist()
        {
            QString folder_name = get_exported_account_folder();

            QString auth_file = get_exported_account_folder() + "/" + auth_file_name;

            return QFileInfo::exists(auth_file);
        }

        bool is_new_settings_exits()
        {
            QString folder_name = get_exported_account_folder();

            QString auth_file = get_exported_account_folder() + "/" + gui_settings_file_name;

            return QFileInfo::exists(auth_file);
        }

        installer::error export_from_8x()
        {
            shutdown_8x();

            get_exported_data().read(
                !is_new_accounts_exist(), 
                !is_new_settings_exits());

            return installer::error();
        }

        installer::error uninstall_8x_from_executable()
        {
            CRegKey key_path;
            if (key_path.Open(HKEY_CURRENT_USER, L"Software\\ICQ\\ICQ", KEY_READ) == ERROR_SUCCESS)
            {
                wchar_t buffer_path[1025];
                ULONG len = 1024;

                if (key_path.QueryStringValue(L"InstallPath", buffer_path, &len) == ERROR_SUCCESS)
                {
                    CRegKey key_uninstall;
                    if (key_uninstall.Open(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\ICQ", KEY_READ) == ERROR_SUCCESS)
                    {
                        wchar_t buffer_uninstall_command[1025];
                        len = 1024;

                        if (key_uninstall.QueryStringValue(L"UninstallString", buffer_uninstall_command, &len) == ERROR_SUCCESS)
                        {
                            CAtlString registry_command = CAtlString(L"\"") + buffer_uninstall_command;
                            registry_command.Replace(L".exe ", L".exe\" ");

                            QString uninstall_command = QString::fromUtf16((const ushort*)(LPCWSTR) registry_command) + " -uninstallsilent";

                            QProcess::execute(uninstall_command);
                        }
                    }
                }
            }

            return installer::error();
        }

        installer::error store_exported_account()
        {
            QString folder_name = get_exported_account_folder();

            QDir dir;
            if (!dir.mkpath(folder_name))
                return installer::error(errorcode::create_exported_account_folder, QString("create folder: ") + folder_name);

            get_exported_data().store_exported_account(folder_name + "/" + auth_export_file_name);

            return installer::error();
        }

        installer::error store_exported_settings()
        {
            QString folder_name = get_exported_settings_folder();

            QDir dir;
            if (!dir.mkpath(folder_name))
                return installer::error(errorcode::create_exported_settings_folder, QString("create folder: ") + folder_name);

            get_exported_data().store_exported_settings(folder_name + "/" + settings_export_file_name);

            return installer::error();
        }


    }
}