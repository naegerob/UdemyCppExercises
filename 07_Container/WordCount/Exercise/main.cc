#include <algorithm>
#include <filesystem>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "utils.hpp"

namespace fs = std::filesystem;

using WordVector = std::vector<std::string>;
using WordCountPair = std::pair<std::string, std::size_t>;
using WordCountVec = std::vector<WordCountPair>;
using CountedWordsMap = std::map<std::string, std::size_t>;

void clean_text(std::string &text);

void replace_all(std::string &text,
                 std::string_view what,
                 std::string_view with);

WordVector split_text(const std::string &text, char delimiter);

CountedWordsMap count_words(const WordVector &words);

WordCountVec map_to_vector(const CountedWordsMap &counted_words);

void sort_word_counts(WordCountVec &word_counts);

int main()
{
    auto current_path = fs::current_path();
    current_path /= "text.txt";

    auto text = readFile(current_path.string());
    std::cout << text << '\n' << '\n';

    clean_text(text);
    std::cout << text << '\n' << '\n';

    auto splitted_text = split_text(text, ' ');
    print_vector(splitted_text);

    auto counted_words = count_words(splitted_text);
    print_map(counted_words);

    auto countedwords_vector = map_to_vector(counted_words);

    sort_word_counts(countedwords_vector);
    print_vector(countedwords_vector);

    return 0;
}

void sort_word_counts(WordCountVec &word_counts)
{
    
}

WordCountVec map_to_vector(const CountedWordsMap &counted_words)
{
    WordCountVec wordCountvector = WordCountVec{};
    
    for (const WordCountPair &pair : counted_words)
    {
        wordCountvector.push_back(WordCountPair(pair.first, pair.second));
    }
    return wordCountvector;
}


CountedWordsMap count_words(const WordVector &words)
{
    CountedWordsMap countWords = CountedWordsMap{};

    for(const std::string word : words)
    {
        // Automatically insert an entry with word and value = 0
        countWords[word]++;
    }
    return countWords;
}