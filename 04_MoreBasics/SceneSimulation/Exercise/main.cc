#include <cstring>
#include <iostream>
#include <numeric>

#include "AdFunctions.hpp"
#include "AdTypes.hpp"

int main()
{
    auto ego_vehicle = VehicleType{};
    auto vehicles = NeighborVehiclesType{};

    init_ego_vehicle(ego_vehicle);
    init_vehicles(vehicles);

    print_vehicle(ego_vehicle);
    print_neighbor_vehicles(vehicles);
    
    print_scene(ego_vehicle, vehicles);

    float seconds;
    char Input;
    std::cout << "Insert amount of seconds: ";
    std::cin >> Input;
    seconds = static_cast<std::uint32_t> (Input) - 48U;

    compute_future_state(ego_vehicle, vehicles, seconds);

    print_neighbor_vehicles(vehicles);
    print_scene(ego_vehicle, vehicles);



    return 0;
}
