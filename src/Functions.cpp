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
#endif