#pragma once

namespace core
{
	class async_executer;

	namespace update
	{
		class updater
		{
			uint32_t			timer_id_;

			std::atomic<bool>	stop_;

			std::chrono::system_clock::time_point	last_check_time_;

			std::unique_ptr<core::async_executer>	thread_;

		public:

			bool is_stoped();

			updater();
			virtual ~updater();
						
			void check_if_need();
		};

	}
}
