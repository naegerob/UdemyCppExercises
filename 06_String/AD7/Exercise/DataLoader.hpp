#pragma once

#include <cstdint>
#include <string_view>

#include "nlohman/json.hpp"

#include "AdTypes.hpp"

using json = nlohmann::json;

void init_ego_vehicle(std::string filepath, VehicleType &ego_vehicle);

void init_vehicles(std::string filepath, NeighborVehiclesType &vehicles);

void load_cycle(const std::uint32_t cycle, NeighborVehiclesType &vehicles);
