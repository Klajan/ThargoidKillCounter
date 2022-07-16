#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <optional>
#include <filesystem>
#include "nlohmann/json.hpp"

#include "Thargoid.h"
#include "KillCounter.h"

class LogReader
{
private:
	std::wifstream file;

	std::optional<Thargoid> parseLine(std::wstring& line);
public:
	void readFile(std::filesystem::path, KillCounter&);
};

