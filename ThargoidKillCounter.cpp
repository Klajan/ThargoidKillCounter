#include <iostream>
#include <thread>
#include "Functions.h"
#include "journal/LogDirReader.h"
#include "journal/LogReader.h"
#include "OutputHandler.h"

int main()
{
    OutputHandler output;
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
    output.killsToTable(kills);

    //wait for intput to close window
    std::cout << std::endl << "press any key to exit" << std::endl;
    std::cin.get();
}