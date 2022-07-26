#include "Functions.h"

#ifdef _WIN32
std::wstring getLogFolder()
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
    HWND consoleWnd = GetConsoleWindow();
    DWORD dwProcessId;
    GetWindowThreadProcessId(consoleWnd, &dwProcessId);
    if (GetCurrentProcessId() == dwProcessId)
    {
        return false;
    }
    else
    {
        return false;
    }
}
#endif