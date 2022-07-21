#pragma once
#include <queue>
#include <future>

template <class T>
class WorkQueue
{
	std::deque<std::unique_ptr<T>> _workQueue;
	std::mutex _workMutex;
	std::condition_variable _workReady;

	std::unique_ptr<T> _pop()
	{
		if (_workQueue.empty())
		{
			return nullptr;
		}
		auto ptr = std::move(_workQueue.back());
		_workQueue.pop_front();
		return ptr;
	}

public:

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

