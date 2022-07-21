#pragma once
#include <future>
#include <thread>
#include <queue>

#include "../WorkQueue.hpp"
#include "LogDirReader.h"
#include "LogReader.h"

class JournalProcessor
{
	const int max_threads;
	const int read_threads;
	const int process_treads;

	bool run = true;

	LogDirReader dirReader;

	std::vector<std::thread> thread_pool;
	WorkQueue<std::queue<std::unique_ptr<Journal::JournalEvent>>> _workQueue;

	void readLogThread();
	void processLogThread();


public:
	JournalProcessor();

	void addJournalLocation(std::wstring path);

	std::promise<void> start();
	std::promise<void> stop();
};

