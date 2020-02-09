// Starts tests
// author sylsit
// 2020.02.09

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// INCLUDES /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include "CommMock.hxx"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "Communication.h"

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// FUNCTIONS ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

int main (int v_argc, char ** v_argv)
{
    ::testing::InitGoogleMock (&v_argc, v_argv);
    return RUN_ALL_TESTS();
}

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// END OF FILE ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////