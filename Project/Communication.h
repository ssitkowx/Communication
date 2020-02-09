// General class for communication
// author sylsit
// 2020.02.09

#pragma once 

//////////////////////////////// INCLUDES /////////////////////////////////////

#include <stdint.h>

/////////////////////////// MACROS/DEFINITIONS ////////////////////////////////

//////////////////////////////// VARIABLES ////////////////////////////////////

class Communication
{
    public:
        enum class EState : uint8_t
        {
            eSend,
            eReceive
        };

        Communication          () { SetState (EState::eReceive); }
        virtual ~Communication () = default;

        void                  Process      (void);
        void                  SetState (Communication::EState v_eState) { eState = v_eState; }

    protected:
        virtual void          send         (void) = 0;
        virtual void          receive      (void) = 0;
        Communication::EState getState (void) { return eState; }

    private:
        EState eState;
};

//////////////////////////////// FUNCTIONS ////////////////////////////////////

/////////////////////////////// END OF FILE ///////////////////////////////////

