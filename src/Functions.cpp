#include "Functions.h"

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
#endif