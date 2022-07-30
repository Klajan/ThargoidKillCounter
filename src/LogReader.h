#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <optional>
#include <filesystem>
#include <queue>
#include <memory>
#include <nlohmann/json.hpp>

#include "Thargoid.hpp"
#include "statistic/KillCounter.h"
#include "journal/JournalEventLib.h"


class LogReader
{
private:
	std::wifstream file;
	
	std::optional<Thargoid> parseLine(std::wstring& line);
	std::unique_ptr<Journal::JournalEvent> parseLine_new(std::wstring& line);
public:
	void readFile(std::filesystem::path, KillCounter&);
	void readFile(std::filesystem::path path, std::queue<std::unique_ptr<Journal::JournalEvent>>& queue);
};

