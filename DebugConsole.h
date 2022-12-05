#pragma once
#include <windef.h>

#ifdef _DEBUG

#ifdef UNICODE
#define DebugConsolePrintf DebugConsolePrintfW
#else // UNICODE
#define DebugConsolePrintf DebugConsolePrintfA
#endif // UNICODE

int DebugConsolePrintfA(PCSTR format, ...);
int DebugConsolePrintfW(PCWSTR foramt, ...);

#else // _DEBUG

#define DebugConsolePrintf(...)
#define DebugConsolePrintfA(...)
#define DebugConsolePrintfW(...)

#endif // _DEBUG
