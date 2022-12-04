#include <cstdint>
#include <iostream>
#include <vector>

#include "utils.hpp"

bool all_of(const std::vector<std::int32_t> &vector, const std::int32_t value);

bool any_of(const std::vector<std::int32_t> &vector, const std::int32_t value);

bool none_of(const std::vector<std::int32_t> &vector, const std::int32_t value);

std::size_t count(const std::vector<std::int32_t> &vector,
                  const std::int32_t value);

std::vector<std::int32_t> inclusive_scan(
    const std::vector<std::int32_t> &vector);

int main()
{
    const auto vector = std::vector<std::int32_t>{3, 1, 4, 1, 5, 9, 2, 6};

    std::cout << std::boolalpha;
    std::cout << "all_of: " << all_of(vector, 5) << '\n';
    std::cout << "any_of: " << any_of(vector, 5) << '\n';
    std::cout << "none_of: " << none_of(vector, 5) << '\n';
    std::cout << "counts:  " << count(vector, 5) << '\n';
    auto scan_values = inclusive_scan(vector);
    std::cout << "inclusive_scan: " << '\n';
    print_vector(scan_values);

    return 0;
}


bool all_of(const std::vector<std::int32_t> &vector, const std::int32_t value)
{
    for(std::int32_t temp : vector)
    {
        if (temp != value)
        {
            return false;
        }
        return true;
    }
}

bool any_of(const std::vector<std::int32_t> &vector, const std::int32_t value)
{
    for(std::int32_t temp : vector)
    {
        if (temp == value)
        {
            return true;
        }
    }
    return false;
}

bool none_of(const std::vector<std::int32_t> &vector, const std::int32_t value)
{
    for(std::int32_t temp : vector)
    {
        if (temp == value)
        {
            return false;
        }        
    }
    return true;
}
std::size_t count(const std::vector<std::int32_t> &vector,
                  const std::int32_t value)
{
    std::size_t counter = 0;

    for(std::int32_t temp : vector)
    {
        if(temp == value)
        {
            counter++;
        }
    }
    return counter;

}

std::vector<std::int32_t> inclusive_scan(const std::vector<std::int32_t> &vector)
{
    std::vector<std::int32_t> result;
    std::int32_t sum = 0;
    for(std::size_t i = 0; i < vector.size(); i++)
    {
        sum += vector[i];
        result.push_back(sum);
    }
    return result;
}