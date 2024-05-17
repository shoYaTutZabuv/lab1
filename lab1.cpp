#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

void processLine(const std::string& line, std::vector<std::string>& words) {
    // Create a filtered string without punctuation
    std::string filteredLine;
    std::remove_copy_if(line.begin(), line.end(), std::back_inserter(filteredLine), [](char c) {
        return !std::isalnum(c) && !std::isspace(c);
    });

    // Use istringstream to split the filtered line into words
    std::istringstream iss(filteredLine);
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }
}

long long unsigned int maxStringLength(std::vector<std::string> words)
{
    long long unsigned maxLength = 0;
    for (const auto& word : words)
        if (word.length() > maxLength)
            maxLength = word.length();
    
    return maxLength;
}


std::vector<std::string> findLongestWords(std::vector<std::string> words)
{
    long long unsigned maxWordLength = maxStringLength(words);
    std::vector<std::string> longestWords;

    for (const auto& word : words)
        if ((word.length() == maxWordLength) && (count(longestWords.begin(), longestWords.end(), word) == 0))
            longestWords.push_back(word);

    return longestWords;
}

int main() {
    std::ifstream file("input.txt"); // Replace "input.txt" with your file name
    if (!file.is_open()) {
        std::cerr << "Unable to open file" << '\n';
        return 1;
    }

    std::string line;
    std::vector<std::string> words;
    std::vector<std::string> longestWords;

    // Read each line from the file
    while (std::getline(file, line)) {
        processLine(line, words);
    }

    file.close();

    longestWords = findLongestWords(words);
    
    std::cout << "Longest words:" << std::endl;
    for (const auto& longWord : longestWords)
        std::cout << longWord << " ";
    std::cout << '\n' << '\n';

    return 0;
}
