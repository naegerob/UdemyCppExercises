#include <cmath>
#include <cstdint>
#include <iostream>

std::uint32_t modulo(std::uint32_t number_a, std::uint32_t number_b);

std::uint32_t sum_of_digits(std::uint32_t number);

std::uint32_t cross_sum(std::uint32_t number);

int main()
{
    std::uint32_t input_number = 0;

    std::cout << "Please enter a unsinged integer: ";
    std::cin >> input_number;

    std::cout << input_number << " % 3: " << modulo(input_number, 3) << '\n';
    std::cout << "sum_of_digits: " << sum_of_digits(input_number) << '\n';
    std::cout << "cross_sum: " << cross_sum(input_number) << '\n';
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
