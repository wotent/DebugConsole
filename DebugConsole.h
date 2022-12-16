#pragma once
#include <windef.h>

#if defined(_DEBUG) || defined(DEBUGCONSOLE_RELEASE_ON)

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
