#include "JournalProcessor.h"

JournalProcessor::JournalProcessor() : max_threads(std::thread::hardware_concurrency()), process_treads(std::max((int)(max_threads * 0.25), 1)), read_threads(std::max((int)(max_threads - process_treads), 3))
{
	thread_pool_read = std::vector<std::thread>(read_threads);
	thread_pool_proc = std::vector<std::thread>(process_treads);
}

void JournalProcessor::readLogThread()
{
	std::optional<std::filesystem::path> file;
	std::queue<std::unique_ptr<Journal::JournalEvent>>* eventQueue;
	LogReader reader;
	while (run)
	{
		{
			const std::scoped_lock<std::mutex> lock(readLogMutex);
			file = dirReader.getNextFile();
		}
		eventQueue = new std::queue<std::unique_ptr<Journal::JournalEvent>>();
		if (file) {
			reader.readFile(file.value(), *eventQueue);
			_workQueue.push(eventQueue);
		}
		else
		{
			delete eventQueue;
			waitUntilDone();
			return;
		}
	}
}

void JournalProcessor::processLogThread()
{
	while (run)
	{
		auto result = _workQueue.pop_wait();
		if (result)
		{
			eventProcessor.processEventeQueue(std::move(result));
		}
	}
}

bool JournalProcessor::addJournalLocation(std::wstring path)
{
	if (!run)
	{
		dirReader.readDir(path);
		return true;
	}
	return false;
}

void JournalProcessor::waitUntilDone()
{
	if (waiting) return;
	waiting = true;
	std::future<void> empty = _workQueue.notifyOnEmpty();
	_workQueue.notifyAll();
	empty.wait();
	done.set_value();
}

std::future<void> JournalProcessor::start()
{
	run = true;
	for (int i = 0; i < read_threads; i++)
	{
		thread_pool_read[i] = std::thread(&JournalProcessor::readLogThread, this);
	}
	for (int i = 0; i < process_treads; i++)
	{
		thread_pool_proc[i] = std::thread(&JournalProcessor::processLogThread, this);
	}
	return done.get_future();
}

void JournalProcessor::stop()
{
	run = false;
	_workQueue.notifyAll();
	for (std::thread& thread : thread_pool_read)
	{
		thread.join();
	}
	for (std::thread& thread : thread_pool_proc)
	{
		thread.join();
	}
	return;
}