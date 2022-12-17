#include <algorithm>
#include <filesystem>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "utils.hpp"
#include "Lib.h"

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

// function header is set by std-library
// and must equal to Compare
bool sortbysec(const WordCountPair &a, const WordCountPair &b)
{
    return (a.second > b.second);
}

void sort_word_counts(WordCountVec &word_counts)
{
    // sorts the vector according to second pair entry
    std::sort(word_counts.begin(), word_counts.end(), sortbysec);
}

// This function is needed, because map is not user-defined sortable
WordCountVec map_to_vector(const CountedWordsMap &counted_words)
{
    WordCountVec wordCountvector = WordCountVec{};
    
    for (const WordCountPair &pair : counted_words)
    {
        // add a pair at the end of the vector
        wordCountvector.push_back(std::make_pair(pair.first, pair.second));
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