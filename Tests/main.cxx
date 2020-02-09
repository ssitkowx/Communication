
//////////////////////////////// INCLUDES /////////////////////////////////////

#include "CommMock.hxx"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "Communication.h"

/////////////////////////// MACROS/DEFINITIONS ////////////////////////////////

//////////////////////////////// VARIABLES ////////////////////////////////////

using ::testing::AtLeast;
using ::testing::Return;

int main (int v_argc, char ** v_argv)
{
	::testing::InitGoogleMock (&v_argc, v_argv);
	return RUN_ALL_TESTS();
}