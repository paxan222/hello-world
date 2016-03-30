#ifndef __NETWORKLOG_H__
#define __NETWORKLOG_H__

#pragma once

namespace core
{
    class async_executer;

    struct log_file_context
    {
        const boost::filesystem::wpath logs_directory_;
        int64_t file_index_; 

        std::unique_ptr<boost::filesystem::ofstream> file_stream_;

        log_file_context(const boost::filesystem::wpath& _logs_directory)
            :   logs_directory_(_logs_directory),
                file_index_(-1)
        {
        }

        virtual ~log_file_context()
        {
            if (file_stream_)
                file_stream_->close();
        }
    };

    class network_log
    {
        std::unique_ptr<async_executer> write_thread_;
        
        std::shared_ptr<log_file_context> file_context_;
        
        std::pair<std::wstring, std::wstring> file_names_history_; // previous and current

    public:

        network_log(const boost::filesystem::wpath& _logs_directory);
        virtual ~network_log();

        void write_data(const tools::binary_stream& _data);
        
        const std::pair<std::wstring, std::wstring> &file_names_history() const { return file_names_history_; }
    };
    
}

#endif // __NETWORKLOG_H__