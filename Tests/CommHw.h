#pragma once 

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// INCLUDES /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include <gmock/gmock.h>
#include "Communication.h"

///////////////////////////////////////////////////////////////////////////////
/////////////////////////// CLASSES/STRUCTURES ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

class CommHw final : public Communication <CommHw>
{
    public:
        CommHw () = default;
       ~CommHw () = default;

        MOCK_METHOD0 (send   , void (void));
        MOCK_METHOD0 (receive, void (void));
};

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// END OF FILE ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////