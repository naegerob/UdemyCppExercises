#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "utils.hpp"

using WordCountPair = std::pair<std::string, std::size_t>;

const std::string_view specialChars[] {".", ",", "!", "?", "\n", "\t"};
void clean_text(std::string &text);

void replace_all(std::string &text, std::string_view what, std::string_view with);

template <typename T>
void split_text(const std::string &text, char delimiter, T result);

std::vector<std::string> split_text(const std::string &text, char delimiter);

int main()
{
    auto text =
        readFile("C:\\Github\\General_repository\\Programming\\C++\\UdemyCppExercises\\06_String\\SplitWords\\Exercise\\text.txt");
    std::cout << text << '\n' << '\n';

    clean_text(text);
    std::cout << text << '\n' << '\n';

    //const auto splittedText = split_text(text, ' ');
    //print_vector(splittedText);

    return 0;
}

void replace_all(std::string &text,
                 std::string_view what,
                 std::string_view with)
{
    std::replace(text.begin(), text.end(), what, with);
    
}
void clean_text(std::string &text)
{
    for(std::string_view specialchar : specialChars)
    {
        replace_all(text, "", specialchar);
    }
}

void replace_all(std::string &text, std::string_view what, std::string_view with);

template <typename T>
void split_text(const std::string &text, char delimiter, T result);

std::vector<std::string> split_text(const std::string &text, char delimiter);
