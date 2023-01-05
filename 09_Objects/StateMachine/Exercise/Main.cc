#include <iostream>

#include "AcStateMachine.h"
#include "AirConditioner.h"

int main()
{
    auto ac = AirConditioner{5};
    auto ac_state_machine = AcStateMachine{&ac};

    while (true)
    {
        const auto measured_temp = ac.measure();
        ac_state_machine.evaluation(measured_temp);
    }

    return 0;
}
