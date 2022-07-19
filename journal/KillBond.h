#pragma once
#include "JournalEvent.hpp"
#include "../Thargoid.h"

namespace Journal
{
	class KillBond : public JournalEvent
	{
	private:
		Thargoid thargoid;
		int reward;
	public:
		KillBond(nlohmann::json&);
		KillBond(std::string timestamp, int reward);
		KillBond(std::string timestamp, int reward, Thargoid thargoid);

		Thargoid thargoid() const { return thargoid; }
		int reward() const { return reward; }
	};
}