#ifdef _DEBUG

#include <windows.h>
#include <stdio.h>
#include <stdarg.h>

#pragma warning (disable: 4996)
#pragma warning (disable: 6031)

class DebugConsole
{
public:
    DebugConsole();
    ~DebugConsole();
};

DebugConsole::DebugConsole()
{
    AllocConsole();
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONERR$", "w", stderr);
}
DebugConsole::~DebugConsole()
{
    FreeConsole();
}

DebugConsole debug_console;

int DebugConsolePrintfA(PCSTR format, ...)
{
    va_list ap;

    va_start(ap, format);
    int len = vsnprintf(NULL, 0, format, ap);
    CHAR* buffer = (CHAR*)malloc((len + 1) * sizeof(CHAR));

    va_start(ap, format);
    vsnprintf(buffer, len + 1, format, ap);

    HANDLE h_console_stdout = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD number_of_chars_written = 0;
    WriteConsoleA(h_console_stdout, buffer, len, &number_of_chars_written, NULL);

    free(buffer);
    va_end(ap);
    return number_of_chars_written;
}

int DebugConsolePrintfW(PCWSTR format, ...)
{
    va_list ap;

    va_start(ap, format);
    int len = _vsnwprintf(NULL, 0, format, ap);
    WCHAR* buffer = (WCHAR*)malloc((len + 1) * sizeof(WCHAR));

    va_start(ap, format);
    _vsnwprintf(buffer, len + 1, format, ap);

    HANDLE h_console_stdout = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD number_of_chars_written = 0;
    WriteConsoleW(h_console_stdout, buffer, len, &number_of_chars_written, NULL);
    free(buffer);
    va_end(ap);
    return number_of_chars_written;
}

#endif
