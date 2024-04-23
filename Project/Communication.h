#pragma once 

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// INCLUDES /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
/////////////////////////// CLASSES/STRUCTURES ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template <class DERIVED_TYPE>
class Communication
{
    friend DERIVED_TYPE;
    DERIVED_TYPE & derivedType = static_cast <DERIVED_TYPE &>(*this);

    public:
        enum class EState : uint8_t
        {
            Send,
            Receive
        };

        EState State;

        ~Communication () = default;

        void Process (void)
        {
            switch (State)
            {
                case EState::Receive:
                {
                    receive ();
                    break;
                }
                case EState::Send:
                {
                    send ();
                    break;
                }
                default:
                {
                    break;
                }
            }
        }

    protected:
        void send    (void) { derivedType.send    (); }
        void receive (void) { derivedType.receive (); }

    private:
        constexpr Communication () { State = EState::Receive; }
};

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// END OF FILE ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
