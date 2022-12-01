#pragma once

#include "AdTypes.hpp"


float kph_to_mps(const float kph);

void init_ego_vehicle(VehicleType &ego_vehicle);

void init_vehicles(NeighbourVehiclesType &vehicles);

void print_vehicle(const VehicleType &vehicle);

void print_neighbor_vehicles(const NeighbourVehiclesType &vehicles);
