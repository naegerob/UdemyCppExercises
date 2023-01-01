#pragma once

#include <cstdint>
#include <utility>


class Coordinate{

public:
    Coordinate(std::uint32_t x, std::uint32_t y);

    std::uint32_t get_x() const;
    std::uint32_t get_y() const;
private:
    std::uint32_t mx;
    std::uint32_t my;
};

class Shape
{
public:
    Shape() = default;
    virtual ~Shape() noexcept = default;

    virtual double get_area() const = 0;
    double midpoint_distance(const Shape *other) const;
    virtual Coordinate get_midpoint() const = 0;
};

class Circle : public Shape
{
public:
    Circle(std::uint32_t x_midpoint, std::uint32_t y_midpoint, std::uint32_t radius);

    ~Circle() noexcept = default;

    virtual double get_area() const final;
    virtual Coordinate get_midpoint() const final;

private:
    std::uint32_t mx_midpoint;
    std::uint32_t my_midpoint;
    std::uint32_t mradius;
};

class Rectangle : public Shape
{
public:
    Rectangle(std::uint32_t x1, std::uint32_t y1, std::uint32_t x2, std::uint32_t y2);    
    ~Rectangle() noexcept = default;

    virtual double get_area() const final;
    virtual Coordinate get_midpoint() const final;

private:
    std::uint32_t mx1;
    std::uint32_t mx2;
    std::uint32_t my1;
    std::uint32_t my2;
};

