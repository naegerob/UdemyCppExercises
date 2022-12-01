#include <cmath>
#include <cstdint>
#include <iostream>

#include "AdConstants.hpp"
#include "AdFunctions.hpp"

float kph_to_mps(const float kph)
{
    return kph / 3.6F;
}

void init_ego_vehicle(VehicleType &ego_vehicle)
{
    ego_vehicle.id = DEFAULT_ID;
    ego_vehicle.speed = kph_to_mps(135.0F);
    ego_vehicle.relDistance = 0.0F;
    ego_vehicle.lane = centerLane;
}

void init_vehicle(VehicleType &vehicle,
                  const std::int32_t id,
                  const float speed_kph,
                  const float distance_m,
                  const LaneType lane)
{
    vehicle.id = id;
    vehicle.speed = kph_to_mps(speed_kph);
    vehicle.relDistance = distance_m;
    vehicle.lane = lane;
}

void init_vehicles(NeighbourVehiclesType &vehicles)
{
    init_vehicle(vehicles.leftVehicle[0],
                 0,
                 240.0F,
                 80.0F,
                 leftLane);
    init_vehicle(vehicles.leftVehicle[1],
                 1,
                 80.0F,
                 -20.0F,
                 leftLane);
    init_vehicle(vehicles.centerVehicle[0],
                 2,
                 130.0F,
                 50.0F,
                 centerLane);
    init_vehicle(vehicles.centerVehicle[1],
                 3,
                 120.0F,
                 -50.0F,
                 centerLane);
    init_vehicle(vehicles.rightVehicle[0],
                 4,
                 110.0F,
                 30.0F,
                 rightLane);
    init_vehicle(vehicles.rightVehicle[1],
                 5,
                 150.0F,
                 -30.0F,
                 rightLane);
}

void print_vehicle(const VehicleType &vehicle)
{
    std::cout << "ID: " << vehicle.id << '\n';
    std::cout << "Speed (m/s): " << vehicle.speed << '\n';
    std::cout << "Distance (m): " << vehicle.relDistance << '\n';
    std::cout << "Lane: " << static_cast<std::int32_t>(vehicle.lane) << '\n';
}

void print_neighbor_vehicles(const NeighbourVehiclesType &vehicles)
{
    print_vehicle(vehicles.leftVehicle[0]);
    print_vehicle(vehicles.leftVehicle[1]);
    print_vehicle(vehicles.centerVehicle[0]);
    print_vehicle(vehicles.centerVehicle[1]);
    print_vehicle(vehicles.rightVehicle[0]);
    print_vehicle(vehicles.rightVehicle[1]);
}
/*
void compute_future_distance(VehicleType &vehicle,
                             const float ego_driven_distance,
                             const float seconds)
{
    const float driven_distance = vehicle.speed * seconds;

    vehicle.relDistance += (driven_distance - ego_driven_distance);
}

void compute_future_state(const VehicleType &ego_vehicle,
                          NeighbourVehiclesType &vehicles,
                          const float seconds)
{
    const float ego_driven_distance = ego_vehicle.speed * seconds;

    compute_future_distance(vehicles.leftVehicle[0],
                            ego_driven_distance,
                            seconds);
    compute_future_distance(vehicles.leftVehicle[1],
                            ego_driven_distance,
                            seconds);
    compute_future_distance(vehicles.centerVehicle[0],
                            ego_driven_distance,
                            seconds);
    compute_future_distance(vehicles.centerVehicle[1],
                            ego_driven_distance,
                            seconds);
    compute_future_distance(vehicles.rightVehicle[0],
                            ego_driven_distance,
                            seconds);
    compute_future_distance(vehicles.rightVehicle[1],
                            ego_driven_distance,
                            seconds);
}
*/