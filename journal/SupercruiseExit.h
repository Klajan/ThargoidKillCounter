#pragma once
#include "JournalEvent.hpp"

namespace Journal {
	class SupercruiseExit : public JournalEvent
	{
	private:
		std::string starsystem;
		std::string body;
	public:
		SupercruiseExit(nlohmann::json&);
		SupercruiseExit(std::string timestamp, std::string starsystem, std::string body);

		std::string starsystem() const { return starsystem; }
		std::string body() const { return body; }
	};
}