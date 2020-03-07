#ifndef ASSERT_HH
#define ASSERT_HH

#pragma once

//==================================================================
// PROJECT:     SimulationLib
// FILENAME:    Assert.h
// DATE:        1-Oct-2001
// AUTHOR(S):   Avi Bueno
//===================================================================

bool simAssertFunc( bool failed, char* testExpr, char* file, int line );

#define SIM_ASSERT_FUNC(testExpr) \
    do \
    { \
        if (!(testExpr) && simAssertFunc( !(testExpr), #testExpr,  __FILE__, __LINE__)) \
            __asm { int 3 }; \
    } while (0) \
    

#define SIM_NULL_ASSERT_FUNC(testExpr)  ((void)0)

// Assert() macro definition
#ifdef _DEBUG
    #define Assert  SIM_ASSERT_FUNC
#else
    #define Assert  SIM_NULL_ASSERT_FUNC
#endif


#endif // ASSERT_HH //
