#include <fstream>
#include <vector>

#include "AdTypes.hpp"
#include "DataLoader.hpp"
#include "DataLoaderConstants.hpp"
#include "DataLoaderTypes.hpp"

static VehiclesLogData vehicles_log_data = VehiclesLogData{};

void init_ego_vehicle(std::string_view filepath, VehicleType &ego_vehicle)
{
    std::ifstream ifs(filepath.data());
    json parsed_data = json::parse(ifs);

    ego_vehicle.id = EGO_VEHICLE_ID;
    ego_vehicle.distance_m = 0.0F;

    ego_vehicle.speed_mps = static_cast<float>(parsed_data["Speed"]);
    ego_vehicle.lane = static_cast<LaneAssociationType>(parsed_data["Lane"]);
}

void set_start_values(VehicleType &vehicle, const size_t index)
{
    vehicle.id = vehicles_log_data[index].id;
    vehicle.lane = vehicles_log_data[index].lane;
    vehicle.distance_m = vehicles_log_data[index].start_distance_m;
    vehicle.speed_mps = vehicles_log_data[index].speeds_mps[0];
}

void init_vehicles(std::string_view filepath, NeighborVehiclesType &vehicles)
{
    std::ifstream ifs(filepath.data());
    json parsed_data = json::parse(ifs);

    for (std::size_t vehicle_idx = 0; vehicle_idx < NUM_VEHICLES; vehicle_idx++)
    {
        const auto &vehicle_data = parsed_data[std::to_string(vehicle_idx)];
        
        vehicles_log_data[vehicle_idx].id = static_cast<std::int32_t>(vehicle_idx);
        vehicles_log_data[vehicle_idx].lane = static_cast<LaneAssociationType>(vehicle_data["Lane"]);
        vehicles_log_data[vehicle_idx].start_distance_m = static_cast<float>(vehicle_data["Distance"]);

        vehicles_log_data[vehicle_idx].speeds_mps = vehicle_data["Speed"];
    }
    set_start_values(vehicles.vehicles_left_lane[0], 0);
    set_start_values(vehicles.vehicles_left_lane[1], 1);
    set_start_values(vehicles.vehicles_center_lane[0], 2);
    set_start_values(vehicles.vehicles_center_lane[1], 3);
    set_start_values(vehicles.vehicles_right_lane[0], 4);
    set_start_values(vehicles.vehicles_right_lane[1], 5);
}


void load_cycle(const std::uint32_t cycle, NeighborVehiclesType &vehicles)
{

    vehicles.vehicles_left_lane[0].speed_mps = vehicles_log_data[0].speeds_mps[cycle];
    vehicles.vehicles_left_lane[1].speed_mps = vehicles_log_data[1].speeds_mps[cycle];
    vehicles.vehicles_center_lane[0].speed_mps = vehicles_log_data[2].speeds_mps[cycle];
    vehicles.vehicles_center_lane[1].speed_mps = vehicles_log_data[3].speeds_mps[cycle];
    vehicles.vehicles_right_lane[0].speed_mps = vehicles_log_data[4].speeds_mps[cycle];
    vehicles.vehicles_right_lane[1].speed_mps = vehicles_log_data[5].speeds_mps[cycle];
}
