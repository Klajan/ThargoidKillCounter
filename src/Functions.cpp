#include "Functions.h"
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Shlobj.h>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#elif __linux__
... // linux code goes here
#endif

#ifdef _WIN32
std::wstring getDefaultLogFolder()
{
    WCHAR path[MAX_PATH];
    std::wstring logpath;
    if (SUCCEEDED(SHGetFolderPathW(NULL, CSIDL_PROFILE, NULL, 0, path))) {
        logpath.append(path);
        logpath.append(L"\\Saved Games\\Frontier Developments\\Elite Dangerous");
    }
    return logpath;
}

bool isAttachedConsole()
{
    static bool attached = true;
    static HWND consoleWnd = GetConsoleWindow();
    static DWORD dwProcessId = 0;

    if (dwProcessId != 0) return attached;

    GetWindowThreadProcessId(consoleWnd, &dwProcessId);
    attached = !(GetCurrentProcessId() == dwProcessId);
    return attached;
}
void setupConsole()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_WTEXT);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE)
    {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode))
        {
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
        }
    }
}
#endif