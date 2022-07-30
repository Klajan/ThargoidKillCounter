#include "KillBond.h"

Journal::KillBond::KillBond(nlohmann::json& json) : JournalEvent(json)
{
	try
	{
		reward_ = json.at("Reward");
	}
	catch (const nlohmann::json::out_of_range&)
	{
		reward_ = 0;
	}
	thargoid_ = reward_;
}

Journal::KillBond::KillBond(std::string timestamp, int reward) : JournalEvent(timestamp)
{
	reward_ = reward; thargoid_ = reward;
}

Journal::KillBond::KillBond(std::string timestamp, int reward, Thargoid thargoid) : JournalEvent(timestamp)
{
	reward_ = reward; thargoid_ = thargoid;
}
