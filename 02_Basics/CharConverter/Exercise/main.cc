#include <cassert>
#include <iostream>

#include "lib.h"

void test_cases();

int main()
{
    char input_character;

    std::cout << "Please enter any ASCII character: ";
    std::cin >> input_character;

    std::cout << std::boolalpha;
    std::cout << "numeric: " << is_numeric(input_character) << '\n';
    std::cout << "alpha: " << is_alpha(input_character) << '\n';
    std::cout << "alpha_numeric: " << is_alpha_numeric(input_character) << '\n';
    std::cout << "upper_case: " << is_upper_case(input_character) << '\n';
    std::cout << "lower_case: " << is_lower_case(input_character) << '\n';
    std::cout << std::dec;
    std::cout << "to_upper_case: " << to_upper_case(input_character) << '\n';
    std::cout << "to_lower_case: " << to_lower_case(input_character) << '\n';

    test_cases(); // These tests should not fail!

    return 0;
}


bool is_numeric(char character)
{
    return 57 >= character && character >= 48;
}


bool is_alpha(char character)
{
    return 122 >= character && character >= 65;
}


bool is_alpha_numeric(char character)
{
    return is_alpha(character) || is_numeric(character);
}

bool is_upper_case(char character)
{
    return 90 >= character && character >= 65; 
}

bool is_lower_case(char character)
{
    return 122 >= character && character >= 97; 
}

char to_upper_case(char character)
{
    if(is_upper_case(character))
    {
        return character;
    }
    return character - 32;

}

char to_lower_case(char character)
{
    if(is_lower_case(character))
    {
        return character;
    }
    return (character + 32);
}
void test_cases()
{
    const auto lowercase_alpha = 'a';
    const auto uppercase_alpha = 'A';
    const auto numeric = '5';
    const auto something_else = '#';

    assert(is_numeric(lowercase_alpha) == false);
    assert(is_numeric(uppercase_alpha) == false);
    assert(is_numeric(numeric) == true);
    assert(is_numeric(something_else) == false);

    assert(is_alpha(lowercase_alpha) == true);
    assert(is_alpha(uppercase_alpha) == true);
    assert(is_alpha(numeric) == false);
    assert(is_alpha(something_else) == false);

    assert(is_alpha_numeric(lowercase_alpha) == true);
    assert(is_alpha_numeric(uppercase_alpha) == true);
    assert(is_alpha_numeric(numeric) == true);
    assert(is_alpha_numeric(something_else) == false);

    assert(is_upper_case(lowercase_alpha) == false);
    assert(is_upper_case(uppercase_alpha) == true);
    assert(is_upper_case(numeric) == false);
    assert(is_upper_case(something_else) == false);

    assert(is_lower_case(lowercase_alpha) == true);
    assert(is_lower_case(uppercase_alpha) == false);
    assert(is_lower_case(numeric) == false);
    assert(is_lower_case(something_else) == false);

    assert(to_upper_case(lowercase_alpha) == uppercase_alpha);
    assert(to_upper_case(uppercase_alpha) == uppercase_alpha);
    assert(to_upper_case(numeric) == numeric);
    assert(to_upper_case(something_else) == something_else);
}
