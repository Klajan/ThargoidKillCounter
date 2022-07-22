#include "KillCounter.h"

void KillCounter::addKill(Thargoid type)
{
	addKill(type, type);
}

void KillCounter::addKill(Thargoid type, int reward)
{
	switch (type)
	{
	case Thargoid::Scout:
		Scout_++;
		Scout_reward += reward;
		break;
	case Thargoid::Cyclops:
		Cyclops_++;
		Cyclops_reward += reward;
		break;
	case Thargoid::Basilisk:
		Basilisk_++;
		Basilisk_reward += reward;
		break;
	case Thargoid::Medusa:
		Medusa_++;
		Medusa_reward += reward;
		break;
	case Thargoid::Hydra:
		Hydra_++;
		Hydra_reward += reward;
		break;
	default:
		Unknown_++;
		Unknown_reward += reward;
		break;
	}
}

void KillCounter::mergeList(std::list<ThargoidKill>& list)
{
	if (list.empty()) return;
	auto sorter = [](ThargoidKill& first, ThargoidKill& second) {
		return first.time_point() <= second.time_point();
	};
	if (kill_list.empty()) {
		kill_list.splice(std::end(kill_list), list);
		kill_list.sort(sorter);
	}
	else
	{
		kill_list.merge(list, sorter);
	}	
}