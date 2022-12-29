#include <filesystem>
#include <fstream>
#include <vector>

#include "AdTypes.hpp"
#include "DataLoader.hpp"
#include "DataLoaderConstants.hpp"
#include "DataLoaderTypes.hpp"

using json = nlohmann::json;

static VehiclesData vehicles_data = std::vector<std::vector<VehicleType>>(
    NUM_VEHICLES,
    std::vector<VehicleType>(NUM_ITERATIONS));

void init_ego_vehicle(std::string filepath, VehicleType &ego_vehicle)
{
    std::ifstream ifs = std::ifstream(filepath);
    json parsed_data = json::parse(ifs);

    ego_vehicle.id = EGO_VEHICLE_ID;
    ego_vehicle.distance_m = 0.0F;
    ego_vehicle.lane = static_cast<LaneAssociationType>(parsed_data["Lane"]);
    ego_vehicle.speed_mps = static_cast<float>(parsed_data["Speed"]);
}


// Stores the values from the json-file into the struct
void json_to_struct(const uint32_t vehicleId, const json &parsed_data)
{
    std::string vehicleIdStr = std::to_string(vehicleId);
    VehicleType vehicle = VehicleType{};
    vehicle.id = static_cast<int32_t>(vehicleId);
    vehicle.distance_m = parsed_data[vehicleIdStr]["Distance"];
    vehicle.lane = parsed_data[vehicleIdStr]["Lane"];
    for(uint16_t i = 0U; i < NUM_ITERATIONS; i++)
    {
        vehicle.speed_mps = parsed_data[vehicleIdStr]["Speed"][i];
        // push_back does not work here, idk why
        vehicles_data[vehicleId][i] = {
                    .id = vehicle.id,
                    .lane = vehicle.lane,
                    .speed_mps = vehicle.speed_mps,
                    .distance_m = vehicle.distance_m            
        };
    }
}

void init_vehicles(std::string filepath, NeighborVehiclesType &vehicles)
{
    std::ifstream ifs = std::ifstream(filepath);
    json parsed_data = json::parse(ifs);

    json_to_struct(0U, parsed_data);
    json_to_struct(1U, parsed_data);
    json_to_struct(2U, parsed_data);
    json_to_struct(3U, parsed_data);
    json_to_struct(4U, parsed_data);
    json_to_struct(5U, parsed_data);

    // store first speed values from VehicleData to vehicles
    vehicles.vehicles_left_lane[0] = vehicles_data[0][0];
    vehicles.vehicles_left_lane[1] = vehicles_data[1][0];
    vehicles.vehicles_center_lane[0] = vehicles_data[2][0];
    vehicles.vehicles_center_lane[1] = vehicles_data[3][0];
    vehicles.vehicles_center_lane[0] = vehicles_data[4][0];
    vehicles.vehicles_center_lane[1] = vehicles_data[5][0];

}

void load_cycle(const std::uint32_t cycle, NeighborVehiclesType &vehicles)
{
    vehicles.vehicles_left_lane[0].speed_mps = vehicles_data[0][cycle].speed_mps;
    vehicles.vehicles_left_lane[1].speed_mps = vehicles_data[1][cycle].speed_mps;
    vehicles.vehicles_center_lane[0].speed_mps = vehicles_data[2][cycle].speed_mps;
    vehicles.vehicles_center_lane[1].speed_mps = vehicles_data[3][cycle].speed_mps;
    vehicles.vehicles_right_lane[0].speed_mps = vehicles_data[4][cycle].speed_mps;
    vehicles.vehicles_right_lane[1].speed_mps = vehicles_data[5][cycle].speed_mps;
}
