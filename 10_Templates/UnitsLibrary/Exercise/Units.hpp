#pragma once


template <typename PiType>
constexpr PiType PI = (3.14159265358979323846L);


template<typename sType, typename msType>
sType ms_to_s(msType milliseconds)
{
	static_assert(std::is_floating_point_v<sType>, "Must be floating point type.");
	static_assert(std::is_integral_v<msType>, "Must be integer type.");

	sType seconds = milliseconds / 1000;
	return seconds;

	
}

template <typename rType>
rType deg_to_rad(rType degree)
{
	static_assert(std::is_floating_point_v<rType>, "Must be floating point type.");
	rType rad = degree * PI<rType> / 180;
	return rad;
}

template <typename speedType>
speedType kph_to_mps(speedType kph)
{
	static_assert(std::is_floating_point_v<speedType>, "Must be floating point type.");
	speedType mps = kph / 3.6;
	return mps;
	
}

template <typename speedType>
speedType mps_to_kph(speedType mps)
{
	static_assert(std::is_floating_point_v<speedType>, "Must be floating point type.");
	speedType kph = mps * 3.6;
	return kph;
	
}

template<typename T>
void rotate_point(const T theta, const T x, const T y)
{
	
}