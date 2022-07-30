#include "USSDrop.h"

Journal::USSDrop::USSDrop(nlohmann::json& json) : JournalEvent(json)
{
	try
	{
		type_ = json.at("USSType");
		threat_ = json.at("USSThreat");
	}
	catch (const nlohmann::json::out_of_range&)
	{
		type_ = "Unknown";
		threat_ = -1;
	}
}

Journal::USSDrop::USSDrop(std::string timestamp, std::string type, int threat) : JournalEvent(timestamp)
{
	type_ = type; threat_ = threat;
}
