#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>

#include "lib.h"

void test_cases();

int main()
{
    std::uint32_t input_number = 0;

    std::cout << "Please enter a unsinged integer: ";
    std::cin >> input_number;

    std::cout << input_number << " % 3: " << modulo(input_number, 3) << '\n';
    std::cout << "sum_of_digits: " << sum_of_digits(input_number) << '\n';
    std::cout << "cross_sum: " << cross_sum(input_number) << '\n';

    test_cases();
}

void test_cases()
{
    assert(modulo(0, 3) == 0);
    assert(modulo(1, 3) == 1);
    assert(modulo(2, 3) == 2);
    assert(modulo(3, 3) == 0);

    assert(modulo(0, 0) == 0);
    assert(modulo(1, 0) == 0);

    assert(sum_of_digits(0) == 1);
    assert(sum_of_digits(10) == 2);
    assert(sum_of_digits(100) == 3);
    assert(sum_of_digits(1000) == 4);

    assert(cross_sum(0) == 0);
    assert(cross_sum(10) == 1);
    assert(cross_sum(100) == 1);
    assert(cross_sum(1000) == 1);
    assert(cross_sum(1234) == 10);
    assert(cross_sum(1235) == 11);
}


std::uint32_t modulo(std::uint32_t number_a, std::uint32_t number_b)
{
    return number_a % number_b;
}

std::uint32_t sum_of_digits(std::uint32_t number)
{   
    std::uint32_t counter = 0;

    while (number > 0U)
    {
        number /= 10U;
        counter++;
        if(number == 0U)
        {
            return counter;
        }
    }
}

std::uint32_t cross_sum(std::uint32_t number)
{
    std::uint32_t counter = 0;
    std::uint32_t digit = 0;
    std::uint32_t loopValue = sum_of_digits(number);
    while (counter < loopValue)
    {
        counter++;
        digit += number % 10U;
        number /= 10U;
    }
    return digit;
}
