#pragma once
#include <queue>
#include <future>

template <class T>
class WorkQueue
{
	std::deque<std::unique_ptr<T>> _workQueue;
	std::mutex _workMutex;
	std::condition_variable _workReady;
	std::promise<void> _empty;
	int _notify = 0;

	std::unique_ptr<T> _pop()
	{
		if (_workQueue.empty())
		{
			if (_notify == 1)
			{
				_notify = 2;
				_empty.set_value();
			}
			return nullptr;
		}
		auto ptr = std::move(_workQueue.front());
		_workQueue.pop_front();
		return ptr;
	}

public:

	std::future<void> notifyOnEmpty()
	{
		if (_notify == 0) _notify = 1;
		return _empty.get_future();
	}

	void push(T* work)
	{
		{
			std::scoped_lock<std::mutex> lock(_workMutex);
			_workQueue.push_back(std::unique_ptr<T>(work));
		}
		_workReady.notify_one();
	}

	std::unique_ptr<T> pop()
	{
		std::scoped_lock<std::mutex> lock(_workMutex);
		return _pop();
		
	}
	std::unique_ptr<T> pop_wait()
	{
		std::unique_lock lock(_workMutex);
		_workReady.wait(lock);
		auto out = std::move(_pop());
		lock.unlock();
		return out;

	}
	std::condition_variable& subscribe()
	{
		return _workReady;
	}
	void notifyAll() { _workReady.notify_all(); }
};

