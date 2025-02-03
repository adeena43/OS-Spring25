#include "LetterCount.h"
#include <fstream>
#include <cctype>

LetterCount::LetterCount() {}

int LetterCount::countLetters(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return -1; // Error opening file
    }

    char ch;
    int letterCount = 0;
    while (file.get(ch)) {
        if (std::isalpha(ch)) {
            letterCount++;
        }
    }

    file.close();
    return letterCount;
}
