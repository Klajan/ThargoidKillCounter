#pragma once
#include <chrono>
#include <string>
#include <sstream>

#include "../external/nlohmann/json.hpp"

namespace Journal
{
	enum class EventType
	{
		USSDrop, SupercruiseExit, KillBond
	};

	class JournalEvent
	{
	protected:

		std::chrono::time_point<std::chrono::utc_clock> timestamp;

	public:

		virtual EventType getEventType() const = 0;
		
		JournalEvent(nlohmann::json& json);

		JournalEvent(std::string timestamp);

		std::chrono::time_point<std::chrono::utc_clock> time_point() const { return timestamp; }

		std::string getTimestamp();

		static std::chrono::time_point<std::chrono::utc_clock> parseTimestamp(std::string stamp);
		static void parseTimestamp(std::string stamp, std::chrono::time_point<std::chrono::utc_clock>& timepoint);
	};
}


