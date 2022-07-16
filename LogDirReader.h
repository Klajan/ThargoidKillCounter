#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <regex>
#include <queue>

class LogDirReader
{
private:
	std::wstring logdir;
	const static std::wregex logfileFormat;
	std::queue<std::filesystem::path> logQueue;

	bool isLogFile(std::filesystem::path);
	static std::wstring getFileName(std::wstring path);
public:
	LogDirReader(std::wstring);
	void readDir();
	void readDir(std::wstring path);
	std::optional<std::filesystem::path> getNextFile();
};

