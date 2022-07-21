#include "JournalEvent.h"

Journal::JournalEvent::JournalEvent(nlohmann::json& json)
{
	try
	{
		parseTimestamp(json.at("timestamp"), this->timestamp);
	}
	catch (const nlohmann::json::out_of_range&)
	{
		this->timestamp = std::chrono::time_point<std::chrono::utc_clock>();
	}
}

Journal::JournalEvent::JournalEvent(std::string timestamp)
{
	parseTimestamp(timestamp, this->timestamp);
}

std::string Journal::JournalEvent::getTimestamp()
{
	std::stringstream ss;
	ss << std::format("%Y-%m-%dT%H:%M:%SZ") << timestamp;
	return ss.str();
}

std::chrono::time_point<std::chrono::utc_clock> Journal::JournalEvent::parseTimestamp(std::string stamp)
{
	std::chrono::time_point<std::chrono::utc_clock> tp;
	JournalEvent::parseTimestamp(stamp, tp);
	return tp;
}

void Journal::JournalEvent::parseTimestamp(std::string stamp, std::chrono::time_point<std::chrono::utc_clock>& timepoint)
{
	std::stringstream ss = std::stringstream(stamp);
	std::chrono::from_stream(ss, "%Y-%m-%dT%H:%M:%SZ", timepoint);
}
