// General class for communication
// author sylsit
// 2020.02.09

#pragma once 

//////////////////////////////// INCLUDES /////////////////////////////////////

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "Communication.h"

/////////////////////////// MACROS/DEFINITIONS ////////////////////////////////

//////////////////////////////// VARIABLES ////////////////////////////////////

using ::testing::AtLeast;
using ::testing::Return;

class CommMock : public Communication, public ::testing::Test
{
    public:
        void TestBody () override {}
        void SetUp    () override {}
        void TearDown () override {}

        MOCK_METHOD0 (send, void (void));
        MOCK_METHOD0 (receive, void (void));
};

TEST_F (CommMock, ChecksSwitchingBetweenSendAndReceive) 
{
    CommMock commMock;
    EXPECT_CALL (commMock, send    ()).Times (2);
    EXPECT_CALL (commMock, receive ()).Times (2);

    for (uint8_t iteration = 0; iteration < 4; iteration++)
    {
        commMock.Process ();

        if ((iteration == 0) || (iteration == 2))
        {
            commMock.SetState (Communication::EState::eSend);
        }
        else
        {
            commMock.SetState (Communication::EState::eReceive);
        }
    }
}