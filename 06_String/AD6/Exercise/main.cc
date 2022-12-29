#include <chrono>
#include <cstring>
#include <iostream>
#include <numeric>
#include <thread>
#include <filesystem>

#include "AdFunctions.hpp"
#include "AdTypes.hpp"

#include "utils.hpp"

namespace fs = std::filesystem;

int main(int argc, char **argv)
{
    const fs::path folderPath = fs::current_path();
    fs::path egoFile = folderPath;
    fs::path vehiclesFile = folderPath;
    if(argc == 2U)
    {
        egoFile /= argv[0];
        vehiclesFile /= argv[1];
    }
    else{
        // No data or too less paths given
        // Folder and file needs to be appended like this to be correct
        // Operator overlading: / -> appends
        egoFile.append("data"); // Folder
        egoFile.append("ego_data.json"); // File
        vehiclesFile.append("data");
        vehiclesFile.append("vehicle_data.json");
    }

    auto ego_vehicle = VehicleType{};
    auto vehicles = NeighborVehiclesType{};

    init_ego_vehicle(ego_vehicle);
    init_vehicles(vehicles);

    print_vehicle(ego_vehicle);
    print_neighbor_vehicles(vehicles);

    std::cout << "Start simulation?: ";
    auto Input = char{};
    std::cin >> Input;

    while (true)
    {
        clear_console();

        print_scene(ego_vehicle, vehicles);
        compute_future_state(ego_vehicle, vehicles, 0.100F);

        const auto ego_lane_vehicles =
            get_vehicle_array(ego_vehicle.lane, vehicles);
        longitudinal_control(ego_lane_vehicles[0], ego_vehicle);

        const auto lane_change_request =
            get_lane_change_request(ego_vehicle, vehicles);
        const auto lane_change_executed =
            lateral_control(lane_change_request, ego_vehicle);

        if (lane_change_executed)
        {
            printf("Executed lane change!");
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
