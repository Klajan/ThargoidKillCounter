#pragma once
#include "JournalEvent.h"
#include "../Thargoid.hpp"

namespace Journal
{
	class KillBond : public JournalEvent
	{
	private:
		Thargoid thargoid_;
		int reward_;
	public:
		KillBond(nlohmann::json& json);
		KillBond(std::string timestamp, int reward);
		KillBond(std::string timestamp, int reward, Thargoid thargoid);

		EventType getEventType() const noexcept override { return EventType::KillBond; }
		Thargoid thargoid() const noexcept { return thargoid_; }
		int reward() const noexcept { return reward_; }
	};
}