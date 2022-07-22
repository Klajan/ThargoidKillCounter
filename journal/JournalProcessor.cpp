#include "JournalProcessor.h"

JournalProcessor::JournalProcessor() : max_threads(std::thread::hardware_concurrency()), read_threads(std::max((int)(max_threads * 0.75), 3)), process_treads(std::max((int)(max_threads * 0.25), 1))
{
	thread_pool_read = std::vector<std::thread>(read_threads);
	thread_pool_proc = std::vector<std::thread>(process_treads);
}

void JournalProcessor::readLogThread()
{
	static std::mutex dirReadMutex;
	{
		std::optional<std::filesystem::path> file;
		std::queue<std::unique_ptr<Journal::JournalEvent>>* eventQueue;
		LogReader reader;
		while (run)
		{
			{
				const std::scoped_lock<std::mutex> lock(dirReadMutex);
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
				return;
			}
		}
	}
}

void JournalProcessor::processLogThread()
{
	while (run)
	{
		auto result = _workQueue.pop_wait();
		eventProcessor.processEventeQueue(std::move(result));
	}
}

void JournalProcessor::addJournalLocation(std::wstring path)
{
	dirReader.readDir(path);
}

void JournalProcessor::start()
{
	for (int i = 0; i < read_threads; i++)
	{
		thread_pool_read[i] = std::thread(&JournalProcessor::readLogThread, this);
	}
	for (int i = 0; i < process_treads; i++)
	{
		thread_pool_proc[i] = std::thread(&JournalProcessor::processLogThread, this);
	}
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