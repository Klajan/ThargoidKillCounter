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

void LogReader::readFile(std::filesystem::path filepath, KillCounter& counter)
{
	int l = 0;
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
