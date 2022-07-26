#include "SupercruiseExit.h"

Journal::SupercruiseExit::SupercruiseExit(nlohmann::json& json) : JournalEvent(json)
{
	try
	{
		starsystem_ = json.at("StarSystem");
		body_ = json.at("Body");
	}
	catch (const nlohmann::json::out_of_range&)
	{
		starsystem_ = "Unknown";
		body_ = "Unknown";
	}
}

Journal::SupercruiseExit::SupercruiseExit(std::string timestamp, std::string starsystem, std::string body) : JournalEvent(timestamp)
{
}
