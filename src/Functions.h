#pragma once
#include <string>
#ifdef _WIN32
#include <Shlobj.h>
#include <Windows.h>
#elif __linux__
... // linux code goes here
#endif

std::wstring getLogFolder();
bool isAttachedConsole();