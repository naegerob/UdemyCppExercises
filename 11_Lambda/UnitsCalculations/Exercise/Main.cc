#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>

#include "Units.hpp"
#include "utils.hpp"

constexpr static std::size_t NUM_ENTRIES = 3;
constexpr static std::uint32_t TIME_SPAN = 50;

void compute_velocities(
    const std::array<float, NUM_ENTRIES> long_velocities_mps,
    const std::array<float, NUM_ENTRIES> lat_velocities_mps,
    std::array<float, NUM_ENTRIES> &velocities_mps);

void compute_heading_degrees(
    const std::array<float, NUM_ENTRIES> long_velocities_mps,
    const std::array<float, NUM_ENTRIES> lat_velocities_mps,
    std::array<float, NUM_ENTRIES> &heading_degrees);

void compute_accelerations(const std::array<float, NUM_ENTRIES> &velocities_mps,
                           std::array<float, NUM_ENTRIES> &accelerations_mps2);

void compute_rel_velocities(
    const std::array<float, NUM_ENTRIES> &velocities_mps,
    const std::array<float, NUM_ENTRIES> &ego_velocities_mps,
    std::array<float, NUM_ENTRIES> &rel_velocities_mps);

void compute_rel_accelerations(
    const std::array<float, NUM_ENTRIES> &accelerations_mps2,
    const std::array<float, NUM_ENTRIES> &ego_accelerations_mps2,
    std::array<float, NUM_ENTRIES> &rel_accelerations_mps2);

int main()
{
    const auto ego_velocities_mps =
        std::array<float, NUM_ENTRIES>{25.0F, 25.6F, 26.2F};
    const auto ego_accelerations_mps2 =
        std::array<float, NUM_ENTRIES>{0.0F, 0.6F, 0.6F};

    const auto long_velocities_mps =
        std::array<float, NUM_ENTRIES>{23.0F, 25.0F, 27.0F};
    const auto lat_velocities_mps =
        std::array<float, NUM_ENTRIES>{1.0F, 1.2F, 1.1F};

    auto velocities_mps = std::array<float, NUM_ENTRIES>{};
    auto heading_degrees = std::array<float, NUM_ENTRIES>{};
    auto accelerations_mps2 = std::array<float, NUM_ENTRIES>{};
    auto rel_velocities_mps = std::array<float, NUM_ENTRIES>{};
    auto rel_accelerations_mps2 = std::array<float, NUM_ENTRIES>{};

    compute_velocities(long_velocities_mps, lat_velocities_mps, velocities_mps);
    compute_heading_degrees(long_velocities_mps,
                            lat_velocities_mps,
                            heading_degrees);
    compute_accelerations(velocities_mps, accelerations_mps2);
    compute_rel_velocities(long_velocities_mps,
                           ego_velocities_mps,
                           rel_velocities_mps);
    compute_rel_accelerations(accelerations_mps2,
                              ego_accelerations_mps2,
                              rel_accelerations_mps2);

    std::cout << "velocities_mps: \n";
    print_array(velocities_mps);
    std::cout << "heading_degrees: \n";
    print_array(heading_degrees);
    std::cout << "accelerations_mps2: \n";
    print_array(accelerations_mps2);
    std::cout << "rel_velocities_mps: \n";
    print_array(rel_velocities_mps);
    std::cout << "rel_accelerations_mps2: \n";
    print_array(rel_accelerations_mps2);
}
