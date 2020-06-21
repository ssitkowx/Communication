///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// INCLUDES /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include "Utils.h"
#include "LoggerMock.h"
#include "gmock/gmock.h"
#include "CommFixture.hxx"

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// FUNCTIONS ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

TEST_F (CommFixture, CheckThatSendOrReceiveCanBeChoosed)
{
    LOGW (MODULE, "CheckThatSendOrReceiveCanBeChoosed");

    EXPECT_CALL (CommMock, send    ()).Times (TWO);
    EXPECT_CALL (CommMock, receive ()).Times (TWO);

    for (uint8_t iterNum = ZERO; iterNum < FOUR; iterNum++)
    {
        CommMock.Process ();

        if ((iterNum == ZERO) || (iterNum == TWO))
        {
            LOGD              (MODULE, "Set communication state eSend");
            CommMock.SetState (Communication::EState::eSend);
        }
        else
        {
            LOGD              (MODULE, "Set communication state eReceive");
            CommMock.SetState (Communication::EState::eReceive);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// END OF FILE ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////