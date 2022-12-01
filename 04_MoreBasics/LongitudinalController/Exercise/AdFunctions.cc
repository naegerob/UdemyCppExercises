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
    ego_vehicle.id = EGO_VEHICLE_ID;
    ego_vehicle.speed_mps = kph_to_mps(135.0F);
    ego_vehicle.distance_m = 0.0F;
    ego_vehicle.lane = LaneAssociationType::CENTER;
}

void init_vehicle(VehicleType &vehicle,
                  const std::int32_t id,
                  const float speed_kph,
                  const float distance_m,
                  const LaneAssociationType lane)
{
    vehicle.id = id;
    vehicle.speed_mps = kph_to_mps(speed_kph);
    vehicle.distance_m = distance_m;
    vehicle.lane = lane;
}

void init_vehicles(NeighborVehiclesType &vehicles)
{
    init_vehicle(vehicles.vehicles_left_lane[0],
                 0,
                 130.0F,
                 80.0F,
                 LaneAssociationType::LEFT);
    init_vehicle(vehicles.vehicles_left_lane[1],
                 1,
                 80.0F,
                 -20.0F,
                 LaneAssociationType::LEFT);
    init_vehicle(vehicles.vehicles_center_lane[0],
                 2,
                 80.0F,
                 50.0F,
                 LaneAssociationType::CENTER);
    init_vehicle(vehicles.vehicles_center_lane[1],
                 3,
                 120.0F,
                 -50.0F,
                 LaneAssociationType::CENTER);
    init_vehicle(vehicles.vehicles_right_lane[0],
                 4,
                 110.0F,
                 30.0F,
                 LaneAssociationType::RIGHT);
    init_vehicle(vehicles.vehicles_right_lane[1],
                 5,
                 90.0F,
                 -30.0F,
                 LaneAssociationType::RIGHT);
}

void print_vehicle(const VehicleType &vehicle)
{
    std::cout << "ID: " << vehicle.id << '\n';
    std::cout << "Speed (m/s): " << vehicle.speed_mps << '\n';
    std::cout << "Distance (m): " << vehicle.distance_m << '\n';
    std::cout << "Lane: " << static_cast<std::int32_t>(vehicle.lane) << '\n';
}

void print_neighbor_vehicles(const NeighborVehiclesType &vehicles)
{
    print_vehicle(vehicles.vehicles_left_lane[0]);
    print_vehicle(vehicles.vehicles_left_lane[1]);
    print_vehicle(vehicles.vehicles_center_lane[0]);
    print_vehicle(vehicles.vehicles_center_lane[1]);
    print_vehicle(vehicles.vehicles_right_lane[0]);
    print_vehicle(vehicles.vehicles_right_lane[1]);
}

void print_scene(const VehicleType &ego_vehicle,
                 const NeighborVehiclesType &vehicles)
{
    std::cout << "    \t   L     C     R  \n";

    auto left_idx = std::size_t{0};
    auto center_idx = std::size_t{0};
    auto right_idx = std::size_t{0};

    const std::int32_t offset_m = 20;
    const std::int32_t view_range_m = static_cast<std::int32_t>(VIEW_RANGE_M);

    for (std::int32_t i = view_range_m; i >= -view_range_m; i -= offset_m)
    {
        const float range_m = static_cast<float>(i);

        const auto left_vehicle = (left_idx < NUM_VEHICLES_ON_LANE)
                                      ? &vehicles.vehicles_left_lane[left_idx]
                                      : nullptr;
        const auto center_vehicle =
            (center_idx < NUM_VEHICLES_ON_LANE)
                ? &vehicles.vehicles_center_lane[center_idx]
                : nullptr;
        const auto right_vehicle =
            (right_idx < NUM_VEHICLES_ON_LANE)
                ? &vehicles.vehicles_right_lane[right_idx]
                : nullptr;

        char left_string[]{"   "};
        char center_string[]{"   "};
        char right_string[]{"   "};

        if ((range_m >= ego_vehicle.distance_m) &&
            (ego_vehicle.distance_m > (range_m - offset_m)))
        {
            center_string[1] = 'E';
        }

        if ((left_vehicle != nullptr) &&
            (range_m >= left_vehicle->distance_m) &&
            (left_vehicle->distance_m > (range_m - offset_m)))
        {
            left_string[1] = 'V';
            left_idx++;
        }
        else if ((left_vehicle != nullptr) &&
                 (std::abs(left_vehicle->distance_m) > VIEW_RANGE_M))
        {
            left_idx++;
        }

        if ((center_vehicle != nullptr) &&
            (range_m >= center_vehicle->distance_m) &&
            (center_vehicle->distance_m > (range_m - offset_m)))
        {
            center_string[1] = 'V';
            center_idx++;
        }
        else if ((center_vehicle != nullptr) &&
                 (std::abs(center_vehicle->distance_m) > VIEW_RANGE_M))
        {
            center_idx++;
        }

        if ((right_vehicle != nullptr) &&
            (range_m >= right_vehicle->distance_m) &&
            (right_vehicle->distance_m > (range_m - offset_m)))
        {
            right_string[1] = 'V';
            right_idx++;
        }
        else if ((right_vehicle != nullptr) &&
                 (std::abs(right_vehicle->distance_m) > VIEW_RANGE_M))
        {
            right_idx++;
        }

        std::cout << i << "\t| " << left_string << " | " << center_string
                  << " | " << right_string << " | \n";
    }
}

void compute_future_distance(VehicleType &vehicle,
                             const float ego_driven_distance,
                             const float seconds)
{
    const float driven_distance = vehicle.speed_mps * seconds;

    vehicle.distance_m += (driven_distance - ego_driven_distance);
}

void compute_future_state(const VehicleType &ego_vehicle,
                          NeighborVehiclesType &vehicles,
                          const float seconds)
{
    const float ego_driven_distance = ego_vehicle.speed_mps * seconds;

    compute_future_distance(vehicles.vehicles_left_lane[0],
                            ego_driven_distance,
                            seconds);
    compute_future_distance(vehicles.vehicles_left_lane[1],
                            ego_driven_distance,
                            seconds);
    compute_future_distance(vehicles.vehicles_center_lane[0],
                            ego_driven_distance,
                            seconds);
    compute_future_distance(vehicles.vehicles_center_lane[1],
                            ego_driven_distance,
                            seconds);
    compute_future_distance(vehicles.vehicles_right_lane[0],
                            ego_driven_distance,
                            seconds);
    compute_future_distance(vehicles.vehicles_right_lane[1],
                            ego_driven_distance,
                            seconds);
}
