#include <iostream>

#include "AirConditioner.h"


AirConditioner::AirConditioner(float curr_temp_)
: curr_temp(curr_temp_), target_temp(20.0F) {}

bool AirConditioner::heat(int duration)
{

}
bool AirConditioner::cool(int duration)
{

}

float AirConditioner::measure()
{
    curr_temp = static_cast<float>(-20 + std::rand() % 65);
}
int AirConditioner::activate(int curr_temp_)
{
    curr_temp = curr_temp_;
    if(curr_temp < -20 || curr_temp > 45)
    {
        return -1;
    }
    if(curr_temp < target_temp)
    {
        AirConditioner::heat((target_temp - curr_temp) * 2);
        return static_cast<int>((target_temp - curr_temp) * 2);
    }
    else if(curr_temp_ > target_temp)
    {
        AirConditioner::cool(curr_temp - target_temp);
        return static_cast<int>(curr_temp - target_temp);
    }
}
