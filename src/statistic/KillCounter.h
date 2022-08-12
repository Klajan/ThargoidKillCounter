#pragma once
#include "../Thargoid.hpp"
#include "../journal/JournalEventLib.h"
#include "ThargoidKill.h"
#include <memory>
#include <queue>

class KillCounter
{
	uint32_t Scout_ = 0;
	int64_t Scout_reward_ = 0;
	uint32_t Cyclops_ = 0;
	int64_t Cyclops_reward_ = 0;
	uint32_t Basilisk_ = 0;
	int64_t Basilisk_reward_ = 0;
	uint32_t Medusa_ = 0;
	int64_t Medusa_reward_ = 0;
	uint32_t Hydra_ = 0;
	int64_t Hydra_reward_ = 0;
	uint32_t Unknown_ = 0;
	int64_t Unknown_reward_ = 0;

	std::list<ThargoidKill> kill_list = std::list<ThargoidKill>();

public: 
	uint32_t Scout() const { return Scout_; }
	uint32_t Cyclops() const { return Cyclops_; }
	uint32_t Basilisk() const { return Basilisk_; }
	uint32_t Medusa() const { return Medusa_; }
	uint32_t Hydra() const { return Hydra_; }
	uint32_t Unknown() const { return Unknown_; }

	int64_t RewardScout() const { return Scout_reward_; }
	int64_t RewardCyclops() const { return Cyclops_reward_; }
	int64_t RewardBasilisk() const { return Basilisk_reward_; }
	int64_t RewardMedusa() const { return Medusa_reward_; }
	int64_t RewardHydra() const { return Hydra_reward_; }
	int64_t RewardUnknownd() const { return Unknown_reward_; }

	void addKill(Thargoid type);
	void addKill(Thargoid type, int32_t reward);

	void mergeList(std::list<ThargoidKill>&);
};

