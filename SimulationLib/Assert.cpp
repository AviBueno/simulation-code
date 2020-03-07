//==================================================================
// PROJECT:     SimulationLib
// FILENAME:    Assert.cpp
// DATE:        1-Oct-2001
// AUTHOR(S):   Avi Bueno
//===================================================================

#include "Assert.h"
#include <windows.h>
#include <stdio.h>

bool simAssertFunc( bool failed, char* testExpr, char* file, int line )
{
    bool retVal = true;
    char buf[1000];
    char* pFilename = strrchr(file, '\\') + 1;
    sprintf(buf, "Debug Assertion Failed\n%s (%d)\nExpr: \"%s\"", pFilename, line, testExpr );
    int userChoice = ::MessageBox(NULL, buf, "Assertion Failed", MB_ABORTRETRYIGNORE | MB_ICONERROR );
    switch ( userChoice )
    {
        case IDRETRY:   retVal = true; break;
        case IDIGNORE:  retVal = false; break;
        case IDABORT:   _exit(123); // Special exit code
    }

    return retVal; // boolean = need to issue a break point?
}
