///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// INCLUDES /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include "Utils.h"
#include "LoggerHw.h"
#include "gmock/gmock.h"
#include "CommFixture.hxx"

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// FUNCTIONS ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

TEST_F (CommFixture, CheckThatSendOrReceiveCanBeChoosed)
{
    LOGW (MODULE, "CheckThatSendOrReceiveCanBeChoosed");

    EXPECT_CALL (CommHw, send    ()).Times (TWO);
    EXPECT_CALL (CommHw, receive ()).Times (TWO);

    for (uint8_t iterNum = ZERO; iterNum < FOUR; iterNum++)
    {
        CommHw.Process ();

        if ((iterNum == ZERO) || (iterNum == TWO))
        {
            LOGD              (MODULE, "Set communication state eSend");
            CommHw.SetState (Communication <decltype (CommHw)>::EState::eSend);
        }
        else
        {
            LOGD              (MODULE, "Set communication state eReceive");
            CommHw.SetState (Communication <decltype (CommHw)>::EState::eReceive);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// END OF FILE ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////