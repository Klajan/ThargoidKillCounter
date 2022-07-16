#include <iostream>
#include "Functions.h"
#include "LogDirReader.h"
#include "LogReader.h"
#include "OutputHandler.h"

int main()
{
    std::wstring logfolder = getLogFolder();
    LogDirReader reader = LogDirReader(logfolder);
    LogReader parser = LogReader();
    KillCounter kills = KillCounter();
    reader.readDir();
    while (auto file = reader.getNextFile())
    {
        std::cout << "Reading:" << file.value().filename() << "..." << std::endl;
        parser.readFile(file.value(), kills);
    }
    std::cout << std::endl << std::endl;
    OutputHandler::killsToTable(kills);
}