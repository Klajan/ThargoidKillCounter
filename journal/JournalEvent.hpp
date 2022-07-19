#pragma once
#include <chrono>
#include <string>
#include <sstream>

#include "../include/nlohmann/json.hpp"

namespace Journal
{
	class JournalEvent
	{
	protected:

		std::chrono::time_point<std::chrono::utc_clock> timestamp;

	public:
		
		JournalEvent(nlohmann::json& json)
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

		JournalEvent(std::string timestamp)
		{
			parseTimestamp(timestamp, this->timestamp);
		}

		std::chrono::time_point<std::chrono::utc_clock> time_point() const { return timestamp; }

		std::string getTimestamp()
		{
			std::stringstream ss;
			ss << std::format("%Y-%m-%dT%H:%M:%SZ") << timestamp;
			return ss.str();
		}
		static std::chrono::time_point<std::chrono::utc_clock> parseTimestamp(std::string stamp)
		{
			std::chrono::time_point<std::chrono::utc_clock> tp;
			JournalEvent::parseTimestamp(stamp, tp);
			return tp;
		}
		static void parseTimestamp(std::string stamp, std::chrono::time_point<std::chrono::utc_clock>& timepoint)
		{
			std::stringstream ss = std::stringstream(stamp);
			std::chrono::from_stream(ss, "%Y-%m-%dT%H:%M:%SZ", timepoint);
		}

		static nlohmann::json* parseJSON(){};
	};
}


