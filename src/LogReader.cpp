#include "LogReader.h"

using json = nlohmann::json;

std::optional<Thargoid> LogReader::parseLine(std::wstring& line)
{
	auto parsed = json::parse(line);
	if (auto ev = parsed.find("event"); ev != parsed.end() && ev.value() == "FactionKillBond") 
	{
		if(auto victim = parsed.find("VictimFaction"); victim != parsed.end() && victim.value() == "$faction_Thargoid;")
		{
			if (auto bond = parsed.find("Reward"); bond != parsed.end())
			{
				return (Thargoid)(int)bond.value();
			}
		}
	}
	return std::nullopt;
}

std::unique_ptr<Journal::JournalEvent> LogReader::parseLine_new(std::wstring& line)
{
	auto parsed = json::parse(line);
	try
	{
		std::string event_ = parsed.at("event");
		if (event_ == "FactionKillBond")
		{
			std::string victim = parsed.at("VictimFaction");
			if (victim == "$faction_Thargoid;") {
				return std::unique_ptr<Journal::JournalEvent>(new Journal::KillBond(parsed));
			}
			return std::unique_ptr<Journal::JournalEvent>();
		}
		else if (event_ == "USSDrop")
		{
			return std::unique_ptr<Journal::JournalEvent>(new Journal::USSDrop(parsed));
		}
		else if( event_ == "SupercruiseExit")
		{
			return std::unique_ptr<Journal::JournalEvent>(new Journal::SupercruiseExit(parsed));
		}
		else
		{
			return std::unique_ptr<Journal::JournalEvent>();
		}
	}
	catch (const nlohmann::json::out_of_range&)
	{
		return std::unique_ptr<Journal::JournalEvent>();
	}
}

void LogReader::readFile(std::filesystem::path filepath, KillCounter& counter)
{
	file.open(filepath);
	std::wstring line;
	while (std::getline(file, line)) {
		if (auto result = parseLine(line))
		{
			counter.addKill(result.value());
		}
	}
	file.close();
}

void LogReader::readFile(std::filesystem::path filepath, std::queue<std::unique_ptr<Journal::JournalEvent>>& queue)
{
	file.open(filepath);
	std::wstring line;
	while (std::getline(file, line)) {
		if (auto result = parseLine_new(line))
		{
			queue.push(std::move(result));
		}
	}
	file.close();
}
