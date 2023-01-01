#define _USE_MATH_DEFINES
#include <cmath>
#include <utility>
#include "Shape.hpp"

#include "distance.hpp"
#include "utils.hpp"




    // Coordinate
    Coordinate::Coordinate(std::uint32_t x, std::uint32_t y) :
    mx(x), my(y) {}

    std::uint32_t Coordinate::get_x() const
    {
        return this->mx;
    }
    std::uint32_t Coordinate::get_y() const
    {
        return this->my;
    }

    // Shape
    double Shape::midpoint_distance(const Shape *other) const
    {
        Coordinate midpointOther = other->get_midpoint();
        Coordinate midPointThis = this->get_midpoint();
        return get_distance(midpointOther.get_x(), midpointOther.get_y(), midPointThis.get_x(), midPointThis.get_y());
    }
    // Circle
    Circle::Circle(std::uint32_t x_midpoint, std::uint32_t y_midpoint, std::uint32_t radius) :
    mx_midpoint(x_midpoint), my_midpoint(y_midpoint) , mradius(radius) {}

    double Circle::get_area() const
    {
        return static_cast<double>(M_PI * mradius * mradius);
    }
    
    Coordinate Circle::get_midpoint() const
    {
        return Coordinate(mx_midpoint, my_midpoint);
    }


    // Rectangle
    Rectangle::Rectangle(std::uint32_t x1, std::uint32_t y1, std::uint32_t x2, std::uint32_t y2)
    : mx1(x1), mx2(x2), my1(y1), my2(y2)  {}

    double Rectangle::get_area() const
    {
        return std::abs(static_cast<double>(mx2 - mx1)) * std::abs(static_cast<double>(my2 - my1));
    }
    Coordinate Rectangle::get_midpoint() const
    {
        return Coordinate((mx1 + mx2) / 2U, (my1 + my2) / 2U);
    }

