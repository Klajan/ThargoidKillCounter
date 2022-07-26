#pragma once
#include "../Thargoid.hpp"
#include "../journal/JournalEventLib.h"
#include "ThargoidKill.h"
#include <memory>
#include <queue>

class KillCounter
{
	int Scout_ = 0;
	long Scout_reward = 0;
	int Cyclops_ = 0;
	long Cyclops_reward = 0;
	int Basilisk_ = 0;
	long Basilisk_reward = 0;
	int Medusa_ = 0;
	long Medusa_reward = 0;
	int Hydra_ = 0;
	long Hydra_reward = 0;
	int Unknown_ = 0;
	long Unknown_reward = 0;

	std::list<ThargoidKill> kill_list = std::list<ThargoidKill>();

public: 
	int Scout() const { return Scout_; }
	int Cyclops() const { return Cyclops_; }
	int Basilisk() const { return Basilisk_; }
	int Medusa() const { return Medusa_; }
	int Hydra() const { return Hydra_; }
	int Unknown() const { return Unknown_; }

	void addKill(Thargoid type);
	void addKill(Thargoid type, int reward);

	void mergeList(std::list<ThargoidKill>&);
};

