#pragma once
#include <string>
#ifdef _WIN32
#include <Shlobj.h>
#elif __linux__
... // linux code goes here
#endif

std::wstring getLogFolder();