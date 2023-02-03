#pragma once


template <typename PiType>
constexpr PiType PI = (3.14159265358979323846L);


template<typename sType, typename msType>
sType ms_to_s(msType milliseconds)
{
	if constexpr (std::is_integral_v<msType>)
	{
		if constexpr (std::is_floating_point_v<sType>)
		{
			sType seconds = milliseconds / 1000;
			return seconds;
		}
	}
	
}

template <typename rType>
rType deg_to_rad(rType degree)
{
	if constexpr (std::is_floating_point_v<rType>)
	{
		rType rad = degree * PI<rType> / 180;
		return rad;
	}
}

template <typename speedType>
speedType kph_to_mps(speedType kph)
{
	if constexpr (std::is_floating_point_v<speedType>)
	{
		speedType mps = kph / 3.6;
		return mps;
	}
}

template <typename speedType>
speedType mps_to_kph(speedType mps)
{
	if constexpr (std::is_floating_point_v<speedType>)
	{
		speedType kph = mps * 3.6;
		return kph;
	}
}

template<typename T>
void rotate_point(const T theta, const T x, const T y)
{
	
}