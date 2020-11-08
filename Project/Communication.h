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
            eSend,
            eReceive
        };

        ~Communication () = default;

        void Process (void)
        {
            EState eState = getState ();
            switch (eState)
            {
                case EState::eReceive:
                {
                    receive ();
                    break;
                }
                case EState::eSend:
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

        void                  SetState (Communication::EState v_eState) { eState = v_eState; }

    protected:
        void                  send     (void) { derivedType.send    (); }
        void                  receive  (void) { derivedType.receive (); }
        Communication::EState getState (void) { return eState;          }

    private:
        EState eState;
        Communication () { SetState (EState::eReceive); }
};

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// END OF FILE ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
