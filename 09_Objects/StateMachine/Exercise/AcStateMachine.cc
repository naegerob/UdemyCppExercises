#include "AcStateMachine.h"



void AcStateMachine::eval_transition(const float temp)
{
    switch (state)
    {
        case Idle:
        {
            if(ac->get_target_temp_cel() > temp)
            {
                state = Cooling;
                return;
            }
            else if(ac->get_target_temp_cel() <= temp)
            {
                state = Heating;
                return;
            }
        }
        break;
        case Cooling:
        {
            if(ac->get_target_temp_cel() > temp)
            {
                state = Heating;
                return;
            }
        }
        break;
        case Heating:
        {
            if(ac->get_target_temp_cel() <= temp)
            {
                state = Cooling;
                return;
            }
        }
        break;
        default:
        break;
    }
}

void AcStateMachine::eval_state(float temp) const
{

    ac->activate(temp);
}

void AcStateMachine::evaluation(float temp)
{
    eval_state(temp);

    eval_transition(temp);
}

AcStates AcStateMachine::get_state() const
{
    return state;
}