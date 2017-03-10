#pragma once
#include <queue>

namespace Queue
{
	class terminate final :
		public std::exception
	{
	public:
		terminate() = default;

		~terminate() = default;

		const char *what() const override
		{
			return "queue is terminated, can't modify it";
		}
	};

	class abort final :
		public std::exception
	{
	public:
		abort() = default;

		~abort() = default;

		const char *what() const override
		{
			return "blocking queue operation is aborted";
		}
	};


	template<typename T>
	class ThreadSafe final :
		private std::queue < T >
	{
		std::size_t m_maxQueueSize{0};

		mutable std::mutex m_mut;
		mutable std::condition_variable m_valid;

		bool m_terminated{ false };
		bool m_aborted{ false };

		void throw_state()
		{
			if (m_terminated)
				throw terminate();
			else if (m_aborted)
			{
				m_aborted = false;
				throw abort();
			}
		}

	public:

		ThreadSafe() = default;

		~ThreadSafe() = default;

		ThreadSafe(std::size_t size_limit)
			: m_maxQueueSize{ size_limit }
		{
		}

		ThreadSafe(const ThreadSafe&) = delete;

		ThreadSafe& operator=(const ThreadSafe&) = delete;

		ThreadSafe& operator=(ThreadSafe&&) = delete;

		ThreadSafe(ThreadSafe&&) = delete;

		void Push(T&& item)
		{
			std::unique_lock<decltype(m_mut)> lk(m_mut);

			m_valid.wait(lk, [this]
			{
				throw_state();
				return !size() || size() < m_maxQueueSize;
			});

			emplace(std::forward<T>(item));

			//if (size() == 1)
				m_valid.notify_one();
		}

		T Pop()
		{
			std::unique_lock<decltype(m_mut)> lk(m_mut);

			m_valid.wait(lk, [this] {
				throw_state();
				return !empty();
			});

			T ret = std::move(front());
			pop();

			//if (size() == m_maxQueueSize - 1)
				m_valid.notify_one();

			return ret;
		}

		const_reference Front() const
		{
			std::lock_guard<decltype(m_mut)> lk(m_mut);

			return front();
		}

		void Eat()
		{
			std::lock_guard<decltype(m_mut)> lk(m_mut);

			pop();

			//if (size() == m_maxQueueSize - 1)
				m_valid.notify_one();
		}

		size_type Size() const
		{
			std::lock_guard<decltype(m_mut)> lk(m_mut);

			return size();
		}

		void SetCapacity(std::size_t size)
		{
			std::lock_guard<decltype(m_mut)> lk(m_mut);

			m_maxQueueSize = size;
		}

		bool Empty() const
		{
			std::lock_guard<decltype(m_mut)> lk(m_mut);

			return empty();
		}

		void Clear()
		{
			std::unique_lock<decltype(m_mut)> lk(m_mut);

			while (!empty())
				pop();

			// get rid of pending pushes
			lk.unlock();
			m_valid.notify_one();

			lk.lock();
			while (!empty())
				pop();
		}

		void Wait()
		{
			std::unique_lock<decltype(m_mut)> lk(m_mut);

			m_valid.wait(lk, [this] {
				//throw_state();
				return !empty();
			});
		}

		bool Wait(int ms) const
		{
			std::unique_lock<decltype(m_mut)> lk(m_mut);

			return m_valid.wait_for(lk, std::chrono::milliseconds(ms), [this] {
				//throw_state();
				return !empty();
			});
		}

		void Terminate()
		{
			std::lock_guard<decltype(m_mut)> lk(m_mut);

			m_terminated = true;
			m_valid.notify_all();
		}

		void Abort()
		{
			std::lock_guard<decltype(m_mut)> lk(m_mut);

			m_aborted = true;
			m_valid.notify_all();
		}
	};
}

