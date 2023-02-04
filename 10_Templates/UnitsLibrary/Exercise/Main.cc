#include <iostream>

#include "Units.hpp"

int main()
{
    const float x = 4500;
    const float y = 4.0F;
	const auto value = ms_to_s<float, int>(x);
	//std::cout << ms_to_s(x) << "\n";

    const auto deg = 10.0F;
    const auto rad = deg_to_rad(deg);

    //const auto [x_, y_] = rotate_point(rad, x, y);
    //std::cout << x_ << " " << y_ << std::endl;

    return 0;
}
