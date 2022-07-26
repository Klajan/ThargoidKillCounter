#pragma once
#include <chrono>
#include <string>
#include <memory>
#include "../Thargoid.hpp"
#include "../journal/JournalEventLib.h"

class ThargoidKill
{
	std::shared_ptr<Journal::KillBond> killBond_ = nullptr;
	std::shared_ptr<Journal::SupercruiseExit> supercruiseExit_ = nullptr;
	std::shared_ptr<Journal::USSDrop> ussDrop_ = nullptr;

public:
	ThargoidKill();
	ThargoidKill(std::shared_ptr<Journal::KillBond>);
	ThargoidKill(std::shared_ptr<Journal::KillBond>, std::shared_ptr<Journal::SupercruiseExit>);
	ThargoidKill(std::shared_ptr<Journal::KillBond>, std::shared_ptr<Journal::SupercruiseExit>, std::shared_ptr<Journal::USSDrop>);

	Thargoid thargoid() const
	{
		return killBond_ ? killBond_->thargoid() : (Thargoid)Thargoid::Unknown;
	}
	int reward() const
	{
		return killBond_ ? killBond_->reward() : 0;
	}
	std::string system() const
	{
		return supercruiseExit_ ? supercruiseExit_->starsystem() : "Unknown";
	}
	std::string body() const
	{
		return supercruiseExit_ ? supercruiseExit_->body() : "Unknown";
	}
	std::chrono::time_point<std::chrono::utc_clock> time_point() const
	{
		return killBond_ ? killBond_->time_point() : std::chrono::time_point<std::chrono::utc_clock>();
	}
};

