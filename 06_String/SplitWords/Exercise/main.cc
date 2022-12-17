#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "Lib.h"
#include "utils.hpp"

using WordCountPair = std::pair<std::string, std::size_t>;

const std::string_view specialChars[] {".", ",", "!", "?", "\n", "\t"};
void clean_text(std::string &text);

void replace_all(std::string &text, std::string_view what, std::string_view with);

//template <typename T>
//void split_text(const std::string &text, char delimiter, T result);

std::vector<std::string> split_text(const std::string &text, char delimiter);

int main()
{
    auto text =
        readFile("C:\\Github\\General_repository\\Programming\\C++\\UdemyCppExercises\\06_String\\SplitWords\\Exercise\\text.txt");
int main()
{
    auto text = readFile("C:/Users/Jan/OneDrive/_Coding/UdemyCppExercises/"
                         "06_String/SplitWords/Solution/text.txt");
    std::cout << text << '\n' << '\n';

    clean_text(text);
    std::cout << text << '\n' << '\n';

    const auto splittedText = split_text(text, ' ');
    print_vector(splittedText);

    return 0;
}

void replace_all(std::string &text,
                 std::string_view what,
                 std::string_view with)
{
    for (std::size_t pos = 0; pos != std::string::npos; pos += with.length())
    {
        pos = text.find(what.data(), pos, what.length());

        if (pos != std::string::npos)
        {
            text.replace(pos, what.length(), with.data(), with.length());
        }
    }
}
void clean_text(std::string &text)
{
    for(std::string_view specialchar : specialChars)
    {
        replace_all(text, specialchar, "");
    }
}



std::vector<std::string> split_text(const std::string &text, char delimiter)
{
    std::vector<std::string> wordlist;
    std::string word = "";

    std::cout << word << std::endl;
    do
    {
        word = text.substr(delimiter);
    }while(word != "");
    
    std::cout << word << std::endl;
}
