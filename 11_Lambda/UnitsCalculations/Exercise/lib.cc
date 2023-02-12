#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>

#include "Units.hpp"
#include "lib.h"

void compute_velocities(
    const std::array<float, NUM_ENTRIES> long_velocities_mps,
    const std::array<float, NUM_ENTRIES> lat_velocities_mps,
    std::array<float, NUM_ENTRIES> &velocities_mps)
{
	
	auto velocityHyp = []
						(const float x, const float y)
						{return std::sqrt(x * x + y * y);};

	std::transform(long_velocities_mps.begin(),
				   long_velocities_mps.end(),
				   lat_velocities_mps.begin(),
				   velocities_mps.begin(),
				   velocityHyp);

}

void compute_heading_degrees(
    const std::array<float, NUM_ENTRIES> long_velocities_mps,
    const std::array<float, NUM_ENTRIES> lat_velocities_mps,
    std::array<float, NUM_ENTRIES> &heading_degrees)
{
	auto headingDegree = []
						(const float vlat, const float vlong)
						{return std::atan2(vlat, vlong) / 3.14f * 180.0f; };

		std::transform(long_velocities_mps.begin(),
				   long_velocities_mps.end(),
				   lat_velocities_mps.begin(),
				   heading_degrees.begin(),
				   headingDegree);
}

void compute_accelerations(const std::array<float, NUM_ENTRIES> &velocities_mps,
                           std::array<float, NUM_ENTRIES> &accelerations_mps2)
{
	auto acceleration = []
						(const float vlat, const float vlong)
						{return std::atan2(vlat, vlong) / PI<float> * 180.0f; };

		std::transform(velocities_mps.begin(),
						velocities_mps.end(),
						velocities_mps.begin(),
						accelerations_mps2.begin(),
						acceleration);
}

void compute_rel_velocities(
    const std::array<float, NUM_ENTRIES> &velocities_mps,
    const std::array<float, NUM_ENTRIES> &ego_velocities_mps,
    std::array<float, NUM_ENTRIES> &rel_velocities_mps)
{
}

void compute_rel_accelerations(
    const std::array<float, NUM_ENTRIES> &accelerations_mps2,
    const std::array<float, NUM_ENTRIES> &ego_accelerations_mps2,
    std::array<float, NUM_ENTRIES> &rel_accelerations_mps2)
{
}
