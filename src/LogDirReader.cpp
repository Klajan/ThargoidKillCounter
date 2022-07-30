#include "LogDirReader.h"

const std::wregex LogDirReader::logfileFormat{ L"Journal\\.[0-9]{2,4}-?[0-9]{2}-?[0-9]{2}T?[0-9]{6}\\.[0-9]{2}\\.log" };

bool LogDirReader::isLogFile(std::filesystem::path path)
{
	std::wstring name = path.filename().wstring();
	return std::regex_match(name, logfileFormat);
}

void LogDirReader::readDir()
{
	readDir(this->logdir);
}

void LogDirReader::readDir(std::wstring path)
{
	logdir = path;
	for (const auto& entry : std::filesystem::directory_iterator(path)) {
		if (entry.is_regular_file() && isLogFile(entry.path())) {
			logQueue.push(entry.path());
		}
	}
}

LogDirReader::LogDirReader(std::wstring logdir)
{
	this->logdir = logdir;
}

std::optional<std::filesystem::path> LogDirReader::getNextFile()
{
	if (logQueue.empty()) {
		return std::nullopt;
	}
	std::filesystem::path out = logQueue.front();
	logQueue.pop();
	return out;
}
