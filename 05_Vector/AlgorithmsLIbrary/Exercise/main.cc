#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

#include "lib.h"
#include "utils.hpp"

void test_cases();

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

    test_cases();

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
void test_cases()
{
    const auto vec = std::vector<std::int32_t>{2, 1, -2, 0, -1};
    const auto vec_all = std::vector<std::int32_t>{2, 2, 2, 2, 2};

    assert(all_of(vec_all, 2) == true);

    assert(count(vec, 1) == 1);
    assert(count(vec, -3) == 0);

    assert(any_of(vec, 2) == true);
    assert(any_of(vec, 1) == true);
    assert(any_of(vec, 0) == true);
    assert(any_of(vec, -1) == true);
    assert(any_of(vec, -2) == true);

    assert(none_of(vec, 3) == true);
    assert(none_of(vec, 2) == false);
    assert(none_of(vec, 1) == false);
    assert(none_of(vec, 0) == false);
    assert(none_of(vec, -1) == false);
    assert(none_of(vec, -2) == false);
    assert(none_of(vec, -3) == true);
}
