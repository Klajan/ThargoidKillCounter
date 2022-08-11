#include <iostream>
#include <thread>
#include <locale>
#include "Functions.h"
#include "LogDirReader.h"
#include "LogReader.h"
#include "output/OutputHandler.h"
#include "JournalProcessor.h"
#include "EventProcessor.h"

int main(int argc, const char* argv[])
{
    setupConsole();

    Output::OutputHandler output;
    std::wstring logfolder = getDefaultLogFolder();
    std::future<void> waitToDone;
    JournalProcessor processor;

    processor.addJournalLocation(logfolder);
    waitToDone = processor.start();
    waitToDone.wait();
    processor.stop();

    KillCounter kills = processor.getKillCounter();
    output.killsToTable(kills);

    //wait for intput to close window
    if (!isAttachedConsole()) {
        std::wcout << std::endl << "press any key to exit" << std::endl;
        std::wcin.get();
    }
}