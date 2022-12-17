# Exercise

In this exercise, we start with a project that will be extended throughout the course.

The use case is a "self-driving car" on a highway with three lanes (Left, Center, and Right lane).  
Our car is the so-called ego vehicle.  
The fictive *radars* and *cameras* of the ego vehicle detect other vehicles that are nearby.  
In total there will be 2 nearby cars on the left, 2 cars on the center, and 2 cars on the right lane.

Example image other vehicles (V) ego vehicle (E):

![vehicle](../../media/vehicle.png)

Note: this plot will be implemented in the coming exercise, here it is just for illustration.

For now, implement the following types:

```cpp
enum ... LaneAssociationType
{
    // Unknown Lane
    // Left Lane
    // Center Lane
    // Right Lane
};

struct VehicleType
{
    // Id
    // Lane
    // Speed (meter/s)
    // Relative Distance (meter)
};

struct NeighborVehiclesType
{
    // Array for nearby vehicles on left lane (2 vehicles in total)
    // Array for nearby vehicles on center lane (2 vehicles in total)
    // Array for nearby vehicles on right lane (2 vehicles in total)
};
```

Implement the following functions:

```cpp
float kph_to_mps(const float kph);

void init_ego_vehicle(VehicleType &ego_vehicle);

void init_vehicles(NeighborVehiclesType &vehicles);

void print_vehicle(const VehicleType &vehicle);

void print_neighbor_vehicles(const NeighborVehiclesType &vehicles);
```

- kph_to_mps
  - Convert the $\frac{km}{h}$ input to $\frac{m}{s}$
- init_ego_vehicle
  - Init the ego vehicle with the following attributes
    - ID=-1
    - Speed=135kmh
    - Lane=Center
- init_vehicles
  - Init the nearby vehicles for each lane
    - IDs starting at 0
    - Feel free to choose the speed and the distance
- print_vehicle
  - Print the ID, Speed, and Distance of a vehicle
- print_neighbor_vehicles
  - Iterate over all vehicles and print out their data

## Main Function

```cpp
int main()
{
    auto ego_vehicle = VehicleType{};
    auto vehicles = NeighborVehiclesType{};

    init_ego_vehicle(ego_vehicle);
    init_vehicles(vehicles);

    print_vehicle(ego_vehicle);
    print_neighbor_vehicles(vehicles);

    return 0;
}
```
