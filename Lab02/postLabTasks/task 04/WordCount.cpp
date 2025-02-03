#include "WordCount.h"
#include <fstream>
#include <sstream>

WordCount::WordCount() {}

int WordCount::countWords(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return -1; // Error opening file
    }

    std::string word;
    int wordCount = 0;
    while (file >> word) {
        wordCount++;
    }

    file.close();
    return wordCount;
}
