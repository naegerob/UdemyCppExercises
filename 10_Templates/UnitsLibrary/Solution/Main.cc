#include <iostream>

#include "Units.hpp"

int main()
{
    const double x = 5.0F;
    const float y = 4.0F;

    const auto deg = 10.0F;
    const auto rad = deg_to_rad(deg);
	
    const auto [x_, y_] = rotate_point(rad, x, y);
    std::cout << x_ << " " << y_ << std::endl;

    return 0;
}
