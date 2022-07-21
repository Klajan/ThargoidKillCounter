#include "JournalProcessor.h"

JournalProcessor::JournalProcessor() : max_threads(std::thread::hardware_concurrency()), read_threads(std::max((int)(max_threads * 0.75), 3)), process_treads(std::max((int)(max_threads * 0.25), 1))
{
	
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

	}
}

void JournalProcessor::addJournalLocation(std::wstring path)
{
	dirReader.readDir(path);
}

std::promise<void> JournalProcessor::start()
{

}

std::promise<void> JournalProcessor::stop()
{
	run = false;
	_workQueue.notifyAll();
}