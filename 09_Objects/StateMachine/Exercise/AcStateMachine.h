#pragma once

#include "AirConditioner.h"


enum AcStates
{
    Idle = 0,
    Heating,
    Cooling
};


class AcStateMachine{

private:
    AirConditioner ac;
    AcStates state = Idle;
    void eval_transition(float temp);
    void eval_state(float temp) const;

public:
    AcStateMachine(AirConditioner &ac_) : ac(ac_) {};
    ~AcStateMachine() noexcept = default;

    void evaluation(float temp);
    AcStates get_state() const;
};