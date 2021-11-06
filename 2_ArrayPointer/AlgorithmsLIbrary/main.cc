#include <cstdint>
#include <iostream>

#include "utils.hpp"

bool all_of(std::int32_t *array, std::size_t length, std::int32_t value);
bool any_of(std::int32_t *array, std::size_t length, std::int32_t value);
bool none_of(std::int32_t *array, std::size_t length, std::int32_t value);
std::size_t count(std::int32_t *array, std::size_t length, std::int32_t value);
std::int32_t *inclusive_scan(std::int32_t *array, std::size_t length);

int main()
{
    std::int32_t array[]{3, 1, 4, 1, 5, 9, 2, 6};
    std::size_t length = 8;

    std::cout << std::boolalpha;
    std::cout << "all_of: " << all_of(array, length, 5) << std::endl;
    std::cout << "any_of: " << any_of(array, length, 5) << std::endl;
    std::cout << "none_of: " << none_of(array, length, 5) << std::endl;
    std::int32_t *Scan_values = inclusive_scan(array, length);
    std::cout << "inclusive_scan: " << std::endl;
    print_array(Scan_values, length);

    delete[] Scan_values;
    Scan_values = nullptr;

    return 0;
}


bool all_of(std::int32_t *array, std::size_t length, std::int32_t value)
{
    for (std::size_t i = 0; i < length; i++)
    {
        if (array[i] != value)
        {
            return false;
        }
    }

    return true;
}

bool any_of(std::int32_t *array, std::size_t length, std::int32_t value)
{
    for (std::size_t i = 0; i < length; i++)
    {
        if (array[i] == value)
        {
            return true;
        }
    }

    return false;
}

bool none_of(std::int32_t *array, std::size_t length, std::int32_t value)
{
    for (std::size_t i = 0; i < length; i++)
    {
        if (array[i] == value)
        {
            return false;
        }
    }

    return true;
}

std::size_t count(std::int32_t *array, std::size_t length, std::int32_t value)
{
    std::size_t temp = 0;

    for (std::size_t i = 0; i < length; i++)
    {
        if (array[i] == value)
        {
            temp++;
        }
    }

    return temp;
}

std::int32_t *inclusive_scan(std::int32_t *array, std::size_t length)
{
    std::int32_t *Result = new std::int32_t[length]{};

    Result[0] = array[0];

    for (std::size_t i = 1; i < length; i++)
    {
        Result[i] = Result[i - 1] + array[i];
    }

    return Result;
}
