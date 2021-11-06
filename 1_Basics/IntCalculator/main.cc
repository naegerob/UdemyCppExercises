#include <iostream>
#include <cmath>

std::uint32_t modulo(std::uint32_t number_a, std::uint32_t number_b);

std::uint32_t sum_of_digits(std::uint32_t number);

std::uint32_t cross_sum(std::uint32_t number);

void print_dec_to_bin(std::uint8_t value);

int main()
{
    std::uint32_t input_number = 0;

    std::cout << "Please enter a unsinged integer: ";
    std::cin >> input_number;

    std::cout << input_number << " % 3: " << modulo(input_number, 3) << std::endl;
    std::cout << "sum_of_digits: " << sum_of_digits(input_number) << std::endl;
    std::cout << "cross_sum: " << cross_sum(input_number) << std::endl;
}

std::uint32_t modulo(std::uint32_t number_a, std::uint32_t number_b)
{
    std::uint32_t result = 0;
    std::uint32_t divisor = number_a / number_b;

    result = number_a - number_b * divisor;

    return result;
}

std::uint32_t sum_of_digits(std::uint32_t number)
{
    std::uint32_t num_digits = 0;

    while (number > 0)
    {
        number /= 10;
        num_digits++;
    }

    return num_digits;
}

std::uint32_t cross_sum(std::uint32_t number)
{
    std::uint32_t sum = 0;

    while (number > 0)
    {
        std::uint32_t current_digit = number % 10;

        sum += current_digit;
        number /= 10;
    }

    return sum;
}
