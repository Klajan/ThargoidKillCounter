#pragma once
#include <future>
#include <thread>
#include <queue>

#include "../WorkQueue.hpp"
#include "LogDirReader.h"
#include "LogReader.h"
#include "EventProcessor.h"

class JournalProcessor
{
	const int max_threads;
	const int process_treads;
	const int read_threads;
	

	std::promise<void> done;
	bool run = false;

	LogDirReader dirReader;
	EventProcessor eventProcessor;

	std::vector<std::thread> thread_pool_read;
	std::vector<std::thread> thread_pool_proc;
	WorkQueue<std::queue<std::unique_ptr<Journal::JournalEvent>>> _workQueue;

	std::mutex readLogMutex;
	bool waiting = false;

	void readLogThread();
	void processLogThread();
	void waitUntilDone();

public:
	JournalProcessor();

	bool addJournalLocation(std::wstring path);

	std::future<void> start();
	void stop();

	KillCounter& getKillCounter() { return eventProcessor.getKillCounter(); }
};

