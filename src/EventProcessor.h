#pragma once
#include <future>
#include <queue>

#include "journal/JournalEventLib.h"
#include "statistic/ThargoidKill.h"
#include "statistic/KillCounter.h"

class EventProcessor
{
private:
	KillCounter counter;
	std::mutex listMutex;
public:
	EventProcessor();
	EventProcessor(KillCounter& counter);

	KillCounter& getKillCounter() { return counter; }

	void processEventeQueue(std::unique_ptr<std::queue<std::unique_ptr<Journal::JournalEvent>>>);
};

