#pragma once

#include <cstdint>

#include "AdConstants.hpp"


enum LaneType
{
    unknownLane     = 0,
    leftLane        = 1,
    centerLane      = 2,
    rightLane       = 3
};


struct VehicleType
{
    std::int32_t    id;
    LaneType        lane;
    float           speed;
    float           relDistance;
};

struct NeighbourVehiclesType
{
    VehicleType     leftVehicle[NUM_VEHICLES];
    VehicleType     centerVehicle[NUM_VEHICLES];
    VehicleType     rightVehicle[NUM_VEHICLES];
};