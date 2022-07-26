#pragma once
#include <future>
#include <queue>

#include "events/JournalEventLib.h"
#include "../ThargoidKill.h"
#include "../KillCounter.h"

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

