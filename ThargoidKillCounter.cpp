#include <iostream>
#include <thread>
#include "Functions.h"
#include "journal/LogDirReader.h"
#include "journal/LogReader.h"
#include "OutputHandler.h"
#include "journal/JournalProcessor.h"
#include "journal/EventProcessor.h"

int main()
{
    OutputHandler output;
    std::wstring logfolder = getLogFolder();
    LogDirReader reader = LogDirReader(logfolder);
    LogReader parser = LogReader();
    KillCounter kills = KillCounter();
    EventProcessor proc = EventProcessor(kills);
    std::future<void> waitToDone;
    JournalProcessor processor;

    processor.addJournalLocation(logfolder);
    waitToDone = processor.start();
    waitToDone.wait();
    processor.stop();
    /*
    reader.readDir();
    while (auto file = reader.getNextFile())
    {
        std::queue<std::unique_ptr<Journal::JournalEvent>> *qu = new std::queue<std::unique_ptr<Journal::JournalEvent>>();
        std::cout << "Reading:" << file.value().filename() << "..." << std::endl;
        //parser.readFile(file.value(), kills);
        //parser.readFile(file.value(), *qu);
        //proc.processEventeQueue(std::unique_ptr<std::queue<std::unique_ptr<Journal::JournalEvent>>>(qu));

    }
    */
    std::cout << std::endl << std::endl;
    kills = processor.getKillCounter();
    output.killsToTable(kills);

    //wait for intput to close window
    std::cout << std::endl << "press any key to exit" << std::endl;
    std::cin.get();
}