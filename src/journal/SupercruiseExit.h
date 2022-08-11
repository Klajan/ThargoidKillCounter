#pragma once
#include "JournalEvent.h"

namespace Journal {
	class SupercruiseExit : public JournalEvent
	{
	private:
		std::string starsystem_;
		std::string body_;
	public:
		SupercruiseExit(nlohmann::json& json);
		SupercruiseExit(std::string timestamp, std::string starsystem, std::string body);

		EventType getEventType() const noexcept { return EventType::SupercruiseExit; }
		std::string starsystem() const noexcept { return starsystem_; }
		std::string body() const noexcept { return body_; }
	};
}