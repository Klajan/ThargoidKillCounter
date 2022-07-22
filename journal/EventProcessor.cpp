#include "EventProcessor.h"

EventProcessor::EventProcessor()
{
	this->counter = KillCounter();
}

EventProcessor::EventProcessor(KillCounter& counter)
{
	this->counter = counter;
}

void EventProcessor::processEventeQueue(std::unique_ptr<std::queue<std::unique_ptr<Journal::JournalEvent>>> queue)
{
	std::list<ThargoidKill> kills;
	std::shared_ptr<Journal::SupercruiseExit> lastDrop;
	std::shared_ptr<Journal::USSDrop> lastUss;
	unsigned int uss_before_drop = 0;
	if (!queue) return;
	std::unique_ptr<Journal::JournalEvent> eve;
	while (!queue->empty())
	{
		eve = std::move(queue->front());
		queue->pop();
		switch (eve->getEventType())
		{
		case Journal::EventType::USSDrop:
			lastUss = std::shared_ptr<Journal::USSDrop>(static_cast<Journal::USSDrop*>(eve.release()));
			uss_before_drop = 0x2;
			break;
		case Journal::EventType::SupercruiseExit:
			lastDrop = std::shared_ptr<Journal::SupercruiseExit>(static_cast<Journal::SupercruiseExit*>(eve.release()));
			uss_before_drop >>= 1;
			break;
		case Journal::EventType::KillBond:
		{
			std::shared_ptr<Journal::KillBond> bond(static_cast<Journal::KillBond*>(eve.release()));
			counter.addKill(bond->thargoid(), bond->reward());
			if (uss_before_drop)
			{
				kills.push_back(ThargoidKill(bond, lastDrop, lastUss));
			}
			else
			{
				kills.push_back(ThargoidKill(bond, lastDrop));
			}
		}
		break;
		default:
			break;
		}
	}
	std::scoped_lock lock(listMutex);
	counter.mergeList(kills);
}
